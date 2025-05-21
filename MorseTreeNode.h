//
// Created by Joshua Yoon on 3/17/25.
//

#ifndef MORSETREENODE_H
#define MORSETREENODE_H

#include <iostream>
class MorseTreeNode {

public:
    /**
     * class attributes for node, the letter, morse code, and left and right node of the bst
     */
    char letter;
    std::string morseCode;
    MorseTreeNode* left;
    MorseTreeNode* right;

    /**
     * default constructor for the tree node
     * @param letter
     * @param morseCode
     */
    MorseTreeNode(char letter, std::string morseCode);
    ~MorseTreeNode();
};
#endif //MORSETREENODE_H
