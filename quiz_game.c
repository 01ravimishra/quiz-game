#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For toupper function

#define NUM_QUESTIONS 7

typedef struct {
    char question[256];
    char options[4][256];
    char answer;
} Question;

void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%c. %s\n", 'A' + i, q.options[i]);
    }
    printf("Enter your answer (A/B/C/D): ");
}

void displayIntro() {
    printf("Welcome to the Quiz Game!\n");
    printf("You will be asked %d questions.\n", NUM_QUESTIONS);
    printf("Press any key to start the quiz or 'q' to exit.\n");
}

int main() {
    displayIntro();

    char choice;
    choice = getchar(); // Wait for user input

    // Check if the user wants to quit
    if (choice == 'q' || choice == 'Q') {
        printf("Exiting the game. Goodbye!\n");
        return 0;
    }

    Question quiz[NUM_QUESTIONS] = {
        {
            "What is the capital of France?",
            {"Berlin", "Madrid", "Paris", "Rome"},
            'C'
        },
        {
            "Which planet is known as the Red Planet?",
            {"Earth", "Mars", "Jupiter", "Venus"},
            'B'
        },
        {
            "What is the largest ocean on Earth?",
            {"Atlantic", "Indian", "Arctic", "Pacific"},
            'D'
        },
        {
            "Who wrote 'Romeo and Juliet'?",
            {"Charles Dickens", "Mark Twain", "William Shakespeare", "Jane Austen"},
            'C'
        },
        {
            "What is the hardest natural substance on Earth?",
            {"Gold", "Iron", "Diamond", "Quartz"},
            'C'
        },
        {
            "Which gas do plants absorb from the atmosphere?",
            {"Oxygen", "Nitrogen", "Carbon Dioxide", "Helium"},
            'C'
        },
        {
            "What is the smallest prime number?",
            {"0", "1", "2", "3"},
            'C'
        }
    };

    char answer;
    int score = 0;

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        displayQuestion(quiz[i]);
        scanf(" %c", &answer); // Note the space before %c to consume any leftover whitespace
        answer = toupper(answer); // Convert to uppercase

        if (answer == quiz[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c. %s\n", quiz[i].answer, quiz[i].options[quiz[i].answer - 'A']);
        }
        printf("\n");
    }

    printf("Your score: %d out of %d\n", score, NUM_QUESTIONS);
    return 0;
}
