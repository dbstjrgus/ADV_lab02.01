//
// Created by Joshua Yoon on 3/17/25.
//

#include "MorseTreeNode.h"

/**
 * default constructor for each node
 * @param letter the actual character
 * @param morseCode  the morse code that corresponds to the character
 */
MorseTreeNode::MorseTreeNode(char letter, std::string morseCode) {
    this->letter = letter;
    this->morseCode = morseCode;
    left = nullptr;
    right = nullptr;
}

MorseTreeNode::~MorseTreeNode() {}

