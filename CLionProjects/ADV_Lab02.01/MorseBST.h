//
// Created by Joshua Yoon on 3/17/25.
//



#ifndef MORSEBST_H
#define MORSEBST_H

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "MorseTreeNode.h"

class MorseBST {

public:
    std::unordered_map<char, std::string> map; // map of char to morse code
    MorseTreeNode *root; // root node
    MorseBST(); // default constructor
    ~MorseBST(); // destructor
    MorseBST(const MorseBST& other); // copy constructor
    MorseBST& operator=(const MorseBST& other); // assignment operator overload

    /**
     * inserts the node into the bst from just the letter and the morse code, referencing the private method
     * @param letter
     * @param morseCode
     */
    void insertFR(char letter, const std::string& morseCode);

    /**
     * simply builds the morse tree using the insert functions
     */
    void buildMorseTree();

    /**
     * Converts a Morse code string to text.
     *
     * This function takes a Morse code sequence as input. It traverses the Morse tree to find
     * corresponding letters and reconstructs the original text.
     *
     * @param morse The input Morse code string
     * @return A string containing the decoded text.
     */
    std::string morseToText(const std::string& morse) const;

    /**
     *
     * Converts a text string to Morse code.
     * This function takes a string of alphanumeric characters and converts each character
     * into its corresponding Morse code representation.
     * @param text The input string containing characters to convert
     * @return A string containing the Morse code representation.
     */
    std::string textToMorse(const std::string& text) const;

private:
    std::string url = "/Users/25yoon/CLionProjects/ADV_Lab02.01/morsecode (1).txt";

    /**
     * makes the map
     */
    void buildMap();

    /**
     * The public insert function references this method, where the root node is explicitly mentioned to insert the nodes in the right place 
     * @param node
     * @param morse
     * @param letter
     * @param level used to see if the depth of the current node is equal to the length of the morse code
     */
    static void insert(MorseTreeNode*& node, const std::string &morse, char letter, int level);

    /**
     * 
     * @param node 
     * @param target 
     * @return 
     */
    static std::string traversefind(MorseTreeNode* node, char target);

    /**
     * recursively destroys the nodes of the trees using post order traversal
     * @param node 
     */
    void destroyTree(MorseTreeNode* node);

    /**
     * generates a deep copy of the tree, recursively copying the child nodes 
     * @param other 
     * @return duplicate 
     */
    MorseTreeNode* copy(const MorseTreeNode* other);


};

#endif //MORSEBST_H
