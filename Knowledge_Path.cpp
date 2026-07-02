#include <iostream>
#include <cstdlib>
#include <ctime>

int generateQuestion() {
    return std::rand() % 3 + 1;
}

void showProgress(int score, int level) {
    std::cout << "\nLevel " << level << " complete.\n";
    std::cout << "Score: " << score << "\n";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int score = 0;

    std::cout << "=== Knowledge Path Simulator ===\n";

    for (int level = 1; level <= 8; level++) {
        int correct = generateQuestion();
        int answer;

        std::cout << "\nLesson " << level << "\n";
        std::cout << "Solve (1-3): ";
        std::cin >> answer;

        if (answer == correct) {
            std::cout << "Correct understanding!\n";
            score += 10;
        } else {
            std::cout << "Review needed.\n";
            score += 2;
        }

        if (level <= 3)
            std::cout << 
