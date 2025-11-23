// copyright Maximiliano Fairman Nov 20th, 2025
// all rights reserved
// Created on Nov 20th, 2025

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random correct guess between 1 and 10
    int correct_guess = std::rand() % 10 + 1;
    int user_guess = 0;

    // Process & output
    while (user_guess != correct_guess) {
        std::cout << "Guess a number between 1 and 10: ";
        std::string user_input;
        std::getline(std::cin, user_input);

        try {
            user_guess = std::stoi(user_input);
            if (user_guess < 1 || user_guess > 10) {
                std::cout << "Please enter a number," << std::endl;
                std::cout << "Within the range." << std::endl;
            } else {
                if (user_guess != correct_guess) {
                    std::cout << "Incorrect guess. Try again." << std::endl;
                }
            }
        } catch (std::invalid_argument&) {
            std::cout << "That's not a valid number." << std::endl;
            std::cout << "Please try again." << std::endl;
        } catch (std::out_of_range&) {
            std::cout << "That number is out of range." << std::endl;
            std::cout << "Please try again." << std::endl;
        }
    }

    std::cout << "Congratulations! Your guess " << std::endl;
    std::cout << correct_guess << "was the correct number!";
    std::cout << "\nThanks for playing!." << std::endl;

    return 0;
}

