//
// Created by Joshua Yoon on 5/20/25.
// Tests and checks
//

#include <gtest/gtest.h>
#include "MorseBST.h"

TEST(MorseBSTTest, TextToMorse_SimpleWord) {
    MorseBST tree;
    std::string input = "SOS";
    std::string expected = "... --- ...";
    EXPECT_EQ(tree.textToMorse(input), expected);
}

TEST(MorseBSTTest, TextToMorse_InvalidCharacter) {
    MorseBST tree;
    std::string input = "HI!";
    std::string expected = "Error in system, more details here: Invalid input character not in International Morse subset";
    EXPECT_EQ(tree.textToMorse(input), expected);
}

TEST(MorseBSTTest, TextToMorse_WithSpace) {
    MorseBST tree;
    std::string input = "HI THERE";
    std::string expected = ".... ..  - .... . .-. .";  // double space between words
    EXPECT_EQ(tree.textToMorse(input), expected);
}

TEST(MorseBSTTest, MorseToText_Simple) {
    MorseBST tree;
    std::string input = "... --- ...";
    std::string expected = "SOS";
    EXPECT_EQ(tree.morseToText(input), expected);
}

TEST(MorseBSTTest, MorseToText_WithSpace) {
    MorseBST tree;
    std::string input = "... --- ...  .... . .-.. .--.  ..- ...";
    std::string expected = "SOS HELP US";
    EXPECT_EQ(tree.morseToText(input), expected);
}