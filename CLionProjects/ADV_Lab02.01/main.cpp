#include <iostream>
#include <sstream>

#include "MorseTreeNode.h"
#include "MorseBST.h"


/**
 * main entry point, I didn't do the whole do-while loop to run it repeatedly
 * @return
 * Two functionalities of morse to text or text to morse
 */
int main() {
    MorseBST bst;
    int choice;
    std::string input;
    std::cout <<bst.textToMorse("L") << std::endl;
    std::cout << "Which functionality do you want use?" << std::endl;
    std::cout << "1. Morse to String" << std::endl;
    std::cout << "2. String to Morse" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout << "Enter morse code, one space between characters, two spaces for space" << std::endl;
            std::cin >> input;
            std::cout << bst.morseToText(input) << std::endl;
            break;
        case 2:
            std::cout << "Enter text:" << std::endl;
            std::cin >> input;

            std::transform(input.begin(), input.end(), input.begin(), ::toupper);
            std::cout << bst.textToMorse(input) << std::endl;
            break;
        default:
            std::cout << "Enter valid choice, a number 1 or 2" << std::endl;
    }

    return 0;
}
