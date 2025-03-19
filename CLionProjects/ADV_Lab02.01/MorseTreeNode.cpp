//
// Created by Joshua Yoon on 3/17/25.
//

#include "MorseTreeNode.h"

MorseTreeNode::MorseTreeNode(char letter, std::string morseCode) {
    this->letter = letter;
    this->morseCode = morseCode;
    left = nullptr;
    right = nullptr;
}

MorseTreeNode::~MorseTreeNode() {
    delete left;
    delete right;

}

