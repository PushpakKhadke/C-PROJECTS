// Header File
#include <stdio.h> // for puts prinf and scanf
#include <stdlib.h> // for rand
#include <time.h> // 1234



// Data Definations
int user_choice;
int computer_choice;
int user_score = 0;
int computer_score = 0;


// Call function
void show_Info();
void check_valid_Userinput();
int win();

int main(void)
{
    
    // Seed for random number generation
    srand(time(0));


    while (1)
    {
       show_Info();

        // User Section
        printf("Your Turn --> Enter Your Choice = ");
        if(scanf("%d", &user_choice) != 1 || (user_choice < 1 || user_choice > 4))
        {
            while(getchar() != '\n');
            puts("Invalid Choice!");
            continue;
        }

        printf("Your Choice Is  = %d\n", user_choice);

        // Exit Game
        check_valid_Userinput();

        printf("\n");

        // Get random choice for computer
        // Generates a random number between 1 and 3
        computer_choice = rand() % 3 + 1;

        // Computer Section
        printf("Computer Choice Is = %d\n", computer_choice);

        // Win Section
        win();
    }
    

    return (0);
}

void show_Info(void)
{

    puts("\n1. Press For Rock");
    puts("2. Press for Paper");
    puts("3. Press For Scissor");
    puts("4. Exit Game");
}

int win()
{
    if (user_choice == computer_choice)
    {
        puts("It's a tie!");
    }

    else if (
        (user_choice == 1 && computer_choice == 3) ||
        (user_choice == 2 && computer_choice == 1) ||
        (user_choice == 3 && computer_choice == 2))
    {
        puts("You Win!");
        user_score = user_score + 10;
        
    }
    else
    {
        puts("Computer Win!");
        computer_score = computer_score + 10;
        
    }

    // Score Print
    printf("\nYour Score = %d\n", user_score);
    printf("Computer Score = %d\n", computer_score);

    return (0);
}

void check_valid_Userinput()
{
    if (user_choice == 4) 
    {
        puts("Exiting Game!");
        exit(0);
    }
}
