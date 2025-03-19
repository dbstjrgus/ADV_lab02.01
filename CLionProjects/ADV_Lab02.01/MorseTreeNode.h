//
// Created by Joshua Yoon on 3/17/25.
//

#ifndef MORSETREENODE_H
#define MORSETREENODE_H

#include <iostream>
class MorseTreeNode {

public:
    char letter;
    std::string morseCode;
    MorseTreeNode* left;
    MorseTreeNode* right;

    MorseTreeNode(char letter, std::string morseCode);
    ~MorseTreeNode();



};
#endif //MORSETREENODE_H
