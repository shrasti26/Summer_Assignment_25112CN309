#include <stdio.h>
#include <ctype.h>

// Structure to define a quiz question object
typedef struct {
    char question[256];
    char options[4][64];
    char correct_option;
} QuizQuestion;

int main() {
    // 1. Initialize the array of quiz questions
    QuizQuestion quiz[] = {
        {
            "Which programming language is known as the mother of all languages?",
            {"A. Python", "B. Java", "C. C Language", "D. C++"},
            'C'
        },
        {
            "What is the only bird that can fly backwards?",
            {"A. Hummingbird", "B. Ostrich", "C. Eagle", "D. Sparrow"},
            'A'
        },
        {
            "How many bits make up one byte in computer memory?",
            {"A. 4 bits", "B. 8 bits", "C. 16 bits", "D. 32 bits"},
            'B'
        }
    };

    // Calculate total questions dynamically
    int total_questions = sizeof(quiz) / sizeof(quiz[0]);
    int score = 0;
    char user_answer;

    printf("=========================================\n");
    printf("     WELCOME TO THE SIMPLE QUIZ GAME     \n");
    printf("=========================================\n\n");

    // 2. Loop through all available questions
    for (int i = 0; i < total_questions; i++) {
        printf("Question %d: %s\n", i + 1, quiz[i].question);
        
        // Print the 4 multiple-choice options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        // Get user answer and handle trailing whitespaces safely
        printf("Your Answer (A, B, C, or D): ");
        scanf(" %c", &user_answer);

        // Convert lowercase answers to uppercase safely
        user_answer = toupper(user_answer);

        // 3. Validate user response and calculate score
        if (user_answer == quiz[i].correct_option) {
            printf("✅ Correct!\n\n");
            score++;
        } else {
            printf("❌ Wrong! The correct answer was %c.\n\n", quiz[i].correct_option);
        }
        printf("-----------------------------------------\n");
    }

    // 4. Display final results and performance percentage
    float percentage = ((float)score / total_questions) * 100;
    
    printf("\n=========================================\n");
    printf("               GAME OVER                 \n");
    printf("=========================================\n");
    printf("Your Final Score: %d out of %d\n", score, total_questions);
    printf("Percentage: %.2f%%\n", percentage);
    printf("=========================================\n");

    return 0;
}
