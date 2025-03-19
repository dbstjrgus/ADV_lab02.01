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
    std::unordered_map<char, std::string> map;
    MorseTreeNode* root;

    MorseBST(); // default constructor
    ~MorseBST(); // destructor
    MorseBST(const MorseBST& other); // copy constructor
    MorseBST& operator=(const MorseBST& other); // assignment operator overload
    void insertFR(char letter, const std::string& morseCode) const;
    void buildMorseTree() const;

    static std::string morseToText(const std::string& morse);

    static std::string textToMorse(const std::string& text);

private:
    std::string url = "/Users/25yoon/CLionProjects/ADV_Lab02.01/morsecode (1).txt";
    void buildMap();
    static void insert(MorseTreeNode* node, const std::string& morse, char letter, int level);
};

#endif //MORSEBST_H
