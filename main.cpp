#include <iostream>
#include <sstream>
#include <limits>

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
    while (true) {
        std::cout << "Please select from the following menu options:" << std::endl;
        std::cout <<"\t" << "1. Morse to Text" << std::endl;
        std::cout << "\t" << "2. Text to Morse" << std::endl;
        std::cout << "\t" << "3. Quit the program" << std::endl;

        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Error in system, more details here: Invalid menu input, value must be integer in range 1-3";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 3) {
            std::cout << "Your selection: " << choice << std::endl;
            std::cout << "* End of program *" << std::endl;
            break;
        }
        switch (choice) {
            case 1:
                std::cout << "Your selection: " << choice << std::endl;
            std::cout << "Input Morse: " << std::endl;
            std::getline(std::cin, input);
            std::cout <<input<< " ==> " <<bst.morseToText(input) << std::endl;
            break;
            case 2:
                std::cout << "Your selection: " << choice << std::endl;
            std::cout << "Input text: " << std::endl;
            std::getline(std::cin, input);
            std::transform(input.begin(), input.end(), input.begin(), ::toupper);
            std::cout <<input << " ==> "<< bst.textToMorse(input) << std::endl;
            break;

            default:
                std::cout << "Error in system, more details here: Invalid menu input, value must be integer in range 1-3" << std::endl;
            break;
        }

    }
    return 0;
}
