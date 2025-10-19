#include <iostream>
#include <print>
#include <random>
#include <stdexcept>
#include <string>

void guessing_game()
{
    std::println("Guess the number!");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    int secret_number = dist(gen);

    while (true) {
        std::println("Please input your guess.");
        std::string guess_str;
        if (!std::getline(std::cin, guess_str)) {
            std::cerr << "Failed to read line.\n";
        }

        if (guess_str == "quit" || guess_str == "q") {
            std::println("Bye.");
            break;
        }

        try {
            const int guess = std::stoi(guess_str);
            if (guess < 1 || guess > 100) {
                std::println("You have to pick a number between 1 and 100.");
                continue;
            }

            std::println("You guessed {}", guess);

            if (guess < secret_number)
                std::println("Too small!");
            else if (guess > secret_number)
                std::println("Too big!");
            else {
                std::println("You win!");
                return;
            }
        } catch (const std::invalid_argument&) {
            std::println("Please enter a valid number.");
            continue;
        } catch (const std::out_of_range&) {
            std::println("Number out of range, try again.");
            continue;
        }
    }
}
