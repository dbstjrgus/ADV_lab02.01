//
// Created by Joshua Yoon on 3/17/25.
//

#include "MorseBST.h"
#include "MorseTreeNode.h"

/**
 * default constructor for the BST
 * initializes the map using the file and the morse code tree based on the default empty node
 */
MorseBST::MorseBST()  {
    root= new MorseTreeNode('\0', "");
    map = std::unordered_map<char, std::string>();
    buildMap();
    buildMorseTree();
}

/**
 * Assignment operator overload so that deep copies of the BST can be made, where the root and its children nodes are deeply copied
 * @param other
 * @return the updated object
 */
MorseBST &MorseBST::operator=(const MorseBST &other) {
    if (this!=&other) {
        destroyTree(root);
        this->map = other.map;
        this->root = copy(other.root);
    }
    return *this;
}

/**
 * copy constructor that uses recursion to copy every node and the hierarchical structure of the tree
 * @param other
 * @returns duplicate tree
 */
MorseBST::MorseBST(const MorseBST &other) {
    this->map = other.map;
    this->root = copy(other.root);
}

/**
 * helper method to build the map that maps each character to the morse code
 */
void MorseBST::buildMap() {
    std::string text;
    std::ifstream morseFile("morsecode (1).txt");
    while (getline (morseFile, text)) {
        std::istringstream iss(text);
        std::string character, morseCode;
        getline(iss, character, '\t');
        getline(iss, morseCode, '\t');
        map.insert({character.at(0), morseCode});
    }
}


/**
 * The private insert function that explicitly declares the root node, and plots the node at the correct place for every morse code node
 * This is called a trie based insertion, normally used for search engine autocompletes
 * @param node
 * @param morseCode
 * @param letter
 * @param level
 */
void MorseBST::insert(MorseTreeNode*& node, const std::string &morseCode, char letter, int level) {
    if (!node) {
        node = new MorseTreeNode(letter, morseCode);
    }
    if (level == morseCode.length()) {
        node->morseCode = morseCode;
        node->letter = letter;
        return;
    }
    if (morseCode[level] == '.') {
        if (!node->left) node->left = new MorseTreeNode('\0', "");
        insert(node->left, morseCode, letter, level + 1);
    }else if(morseCode[level] == '-') {
        if (!node->right) node->right = new MorseTreeNode('\0', "");
        insert(node->right,morseCode,letter, level+1);
    }
}

/**
 * This public function only requires two params, so that each key value pair of the map can be inserted efficiently, referencing the private insert method
 * @param letter
 * @param morseCode
 */
void MorseBST::insertFR(const char letter, const std::string& morseCode)  {
    insert(root, morseCode, letter, 0);
}

/**
 * Builds the entire morse tree using the recursive functions of the nodes
 */
void MorseBST::buildMorseTree() {
    for (const auto& pair : map) {
        insertFR(pair.first, pair.second);
    }
}

/**
 * uses nested if statements(for some reason switches don't work) to continuously traverse the tree to find the correct node, the input delimited with spaces
 * A dot is a left in the tree, a dash is a right
 * @param morse morse code string
 * @return decoded string
 */
std::string MorseBST::morseToText(const std::string &morse) const {
    std::string text;
    MorseTreeNode* r = this->root;
    int spaceCount = 0;

    for (char c : morse ) {
        if (c == '.') {
            if (r->left) {
                r= r->left;

            } else {
                throw std::runtime_error("Invalid Morse Code");

            }
            spaceCount = 0;
        } else if (c == '-') {
            if (r->right) {
                r= r->right;
            } else {
                throw std::runtime_error("Invalid Morse Code");
            }
            spaceCount = 0;
        } else if (c == ' ') {
            text += r->letter;
            r = this->root;
            spaceCount++;
            if (spaceCount == 2) {
                if (!text.empty()){text.back() = ' ';}
                spaceCount = 0;
            }
        } else {
            text = "Error in system, more details here: Invalid Morse code entry";
            break;
        }
    }
    if (r != this->root) {
        text+= r->letter;
    }


    return text;
}

/**
 * converts the inputted text into morse code, using the traversal method, appending to each character
 * @param text
 * @return the morse code for the inputted text
 */
std::string MorseBST::textToMorse(const std::string& text) const {
    std::string result;
    for (const auto& c : text) {
        if (c == ' ') {
            result += " "; // one here?
            continue;
        }
        if (map.find(c) == map.end()) {
            result = "Error in system, more details here: Invalid input character not in International Morse subset ";
            break;
        }
        std::string s = traversefind(this->root, c);
        result += (s + " ");

    }
    if (!result.empty()) {result.pop_back(); } //check back here
    return result;
}

/**
 * Traverses the BST to search for the morse code corresponding to the target character
 * @param node root node
 * @param target character we are trying to find
 * @return The morse code string unique to each character
 */
std::string MorseBST::traversefind(MorseTreeNode *node, char target) {
    if (!node) {
        return "";
    }
    if (node->letter == target) { return node->morseCode; }
    std::string left = traversefind(node->left, target);
    if (!left.empty()) {
        return left;
    }
    return traversefind(node->right, target);



}

/**
 * Helper method to recursively destroy all the nodes of the tree, post order traversal
 * @param node root node
 */
void MorseBST::destroyTree(MorseTreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

/**
 * destructor
 */
MorseBST::~MorseBST() {
    destroyTree(root);
}

/**
 * Helper method to deep copy the tree using recursion
 * @param other
 * @return the deep-copied MorseBST, that is exactly identical to the original
 */
MorseTreeNode* MorseBST::copy(const MorseTreeNode* other) {
    if (!other) {
        return nullptr;
    }
    MorseTreeNode* result = new MorseTreeNode(other->letter, other->morseCode);
    result->left = copy(other->left);
    result->right = copy(other->right);
    return result;
}