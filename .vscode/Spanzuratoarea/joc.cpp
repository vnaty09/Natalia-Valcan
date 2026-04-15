#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::string> words = {
        "programare",
        "calculator",
        "hangman",
        "cuvant",
        "educatie",
        "matematica",
        "stea"
    };

    std::string secret = words[std::rand() % words.size()];
    std::string guessed(secret.size(), '_');

    int maxErrors = 6;
    int errors = 0;
    std::vector<char> usedLetters;

    std::cout << "--- Joc: Spanzuratoarea ---\n";
    std::cout << "Ghiceste literele din cuvant. Ai " << maxErrors << " incercari gresite.\n\n";

    while (errors < maxErrors && guessed != secret) {
        std::cout << "Cuvant: ";
        for (char c : guessed) {
            std::cout << c << ' ';
        }
        std::cout << "\n";

        std::cout << "Litere folosite: ";
        for (char c : usedLetters) {
            std::cout << c << ' ';
        }
        std::cout << "\n";

        std::cout << "Alege o litera: ";
        char letter;
        std::cin >> letter;

        if (!std::isalpha(letter)) {
            std::cout << "Te rog introduce o litera valida.\n\n";
            continue;
        }

        letter = std::tolower(letter);
        if (std::find(usedLetters.begin(), usedLetters.end(), letter) != usedLetters.end()) {
            std::cout << "Ai mai incercat deja litera '" << letter << "'.\n\n";
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
            std::cout << "Litera '" << letter << "' nu exista in cuvant. "
                      << "Ai " << (maxErrors - errors) << " incercari ramase.\n\n";
        } else {
            std::cout << "Corect!\n\n";
        }
    }

    if (guessed == secret) {
        std::cout << "Felicitari! Ai ghicit cuvantul: " << secret << "\n";
    } else {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
        std::cout << "Ai pierdut. Cuvantul era: " << secret << "/n";
    }