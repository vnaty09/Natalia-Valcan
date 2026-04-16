#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>

void drawHangman(int errors) {
    const char* stages[] = {
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========\n",
        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "=========\n"
    };

    if (errors < 0) errors = 0;
    if (errors > 6) errors = 6;
    std::cout << stages[errors];
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::string> words = {
        "programming",
        "computer",
        "hangman",
        "word",
        "education",
        "mathematics",
        "star"
    };

    std::string secret = words[std::rand() % words.size()];
    std::string guessed(secret.size(), '_');

    int maxErrors = 6;
    int errors = 0;
    std::vector<char> usedLetters;

    std::cout << "--- Game: Hangman ---\n";
    std::cout << "Guess the letters in the word. You have " << maxErrors << " wrong attempts.\n\n";

    while (errors < maxErrors && guessed != secret) {
        drawHangman(errors);

        std::cout << "Word: ";
        for (char c : guessed) {
            std::cout << c << ' ';
        }
        std::cout << "\n";

        std::cout << "Used letters: ";
        for (char c : usedLetters) {
            std::cout << c << ' ';
        }
        std::cout << "\n";

        std::cout << "Choose a letter: ";
        char letter;
        std::cin >> letter;

        if (!std::isalpha(letter)) {
            std::cout << "Please enter a valid letter.\n\n";
            continue;
        }

        letter = std::tolower(letter);
        if (std::find(usedLetters.begin(), usedLetters.end(), letter) != usedLetters.end()) {
            std::cout << "You already tried the letter '" << letter << "'.\n\n";
            continue;
        }

        usedLetters.push_back(letter);

        bool found = false;
        for (size_t i = 0; i < secret.size(); ++i) {
            if (secret[i] == letter) {
                guessed[i] = letter;
                found = true;
            }
        }

        if (!found) {
            errors++;
            std::cout << "The letter '" << letter << "' is not in the word. "
                      << "You have " << (maxErrors - errors) << " attempts left.\n\n";
        } else {
            std::cout << "Correct!\n\n";
        }
    }

    if (guessed == secret) {
        std::cout << "Congratulations! You guessed the word: " << secret << "\n";
    } else {
        std::cout << "You lost. The word was: " << secret << "\n";
    }
    return 0;
}