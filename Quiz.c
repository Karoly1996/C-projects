#include <stdio.h>
#include <ctype.h>

int main () 
{
    char questions[][100] = {
                             "1. What fish will i buy V?: ",
                             "2. What graphic card do i have?: ",
                             "3. What laptop am i using?: "};
    char options [][100] =  {
                            "A. Shark", "B. Nothing", "C. Gold Fish", "D. Puffer fish",
                            "A. 3060", "B. 3080", "C. 3090", "D. 4090",
                            "A. Windows", "B. Mac", "C. None", "D. Phone"};
    char answers[3] = {'C', 'C', 'B'};
    int numberOfQuestions = sizeof(questions)/sizeof(questions[0]);

    char guess;
    int score = 0;

    printf("Quiz Game\n");

    for (int i = 0; i < numberOfQuestions; i++) 
    {
        printf("******************\n");
        printf("%s\n", questions[i]);
        printf("******************\n");

        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s\n", options[j]);
        }

        printf("Guess: ");
        scanf(" %c", &guess); //added space before c in order to skip \n buffer to not skip questions

        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("Correctt hehe!\n");
            score++;
        } else 
        {
            printf("WRONG dumbo\n"); 
        }
    }

    printf("******************\n");
    printf("Final Score: %d/%d\n", score, numberOfQuestions);
    printf("******************\n");


    return 0;
}