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
            std::cout << "school stage exercise.\n";
        else if (level <= 6)
            std::cout << "university level thinking.\n";
        else
            std::cout << "advanced book-based challenge.\n";

        showProgress(score, level);
    }

    std::cout << "\nFinal Score: " << score << "\n";

    if (score > 60)
        std::cout << "Excellent learner!\n";
    else
        std::cout << "Keep studying!\n";

    return 0;
}
