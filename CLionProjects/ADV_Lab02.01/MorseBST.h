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
     * inserts the node into the bst from just the letter and the morse code
     * @param letter
     * @param morseCode
     */
    void insertFR(char letter, const std::string& morseCode);
    void buildMorseTree();
    std::string morseToText(const std::string& morse) const;
    std::string textToMorse(const std::string& text) const;

private:
    std::string url = "/Users/25yoon/CLionProjects/ADV_Lab02.01/morsecode (1).txt";
    void buildMap();

    /**
     * The public insert function references this
     * @param node
     * @param morse
     * @param letter
     * @param level
     */
    static void insert(MorseTreeNode*& node, const std::string &morse, char letter, int level);
    static std::string traversefind(MorseTreeNode* node, char target);
    void destroyTree(MorseTreeNode* node);
    MorseTreeNode* copy(const MorseTreeNode* other);


};

#endif //MORSEBST_H
