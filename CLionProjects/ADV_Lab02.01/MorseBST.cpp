//
// Created by Joshua Yoon on 3/17/25.
//

#include "MorseBST.h"


#include "MorseTreeNode.h"
MorseBST::MorseBST() {
    root = new MorseTreeNode('\0', "");
    map = std::unordered_map<char, std::string>();
    buildMap();

}
/**
MorseBST::~MorseBST() {  // TODO do i have to destroy the rest of the nodes recursively??
    delete root;
}
*/

void MorseBST::buildMap() {
    std::string text;
    std::ifstream morseFile(url);
    while (getline (morseFile, text)) {
        std::istringstream iss(text);
        std::string character, morseCode;
        getline(iss, character, '\t');
        getline(iss, morseCode, '\t');
        map.insert({character.at(0), morseCode});
    }

}

/**
 *
 * @param node
 * @param morseCode
 * @param letter
 * @param level
 */
void MorseBST::insert(MorseTreeNode* node, const std::string& morseCode, char letter, int level) {
    if (!node)
        node = new MorseTreeNode(letter, morseCode);

    if (level == morseCode.length()) {
        node->morseCode = morseCode;
        node->letter = letter;
    }
    if (morseCode[level] == '.') {
        insert(node->left, morseCode, letter, level + 1);
    }else if(morseCode[level] == '-') {
        insert(node->right,morseCode,letter, level+1);
    }

}

void MorseBST::insertFR(const char letter, const std::string& morseCode) const {
    insert(root, morseCode, letter, 0);
}

void MorseBST::buildMorseTree() const {
    for (const auto& pair : map) {
        insertFR(pair.first, pair.second);
    }
}

std::string MorseBST::morseToText(const std::string &morse) {
    return "";
}

std::string MorseBST::textToMorse(const std::string& text) {
    return "";
}


