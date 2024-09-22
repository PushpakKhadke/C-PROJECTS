// Header File
#include <stdio.h>1
#include <stdlib.h>
#include <time.h>

// Function Call
void showInfo(void);
int c(void);
int cpp(void);
int python(void);
void delay(int milliseconds);
void clear(void);

// Main Function
int main(void)
{
    // Data Defination
    int i;
    i = 1;
    int switch_user_choice;
    switch_user_choice = 0;

    while (1)
    {

        clear();
        showInfo();

        printf("\nEnter your choice = ");
        if (scanf("%d",&switch_user_choice) != 1 || (switch_user_choice < 1 || switch_user_choice > 4))
        {
            while(getchar() != '\n');
            puts("Invalid Input!");
            delay(1000);
            continue;
        }
        

        switch (switch_user_choice)
        {
        case 1:
            c();
            break;

        case 2:
            cpp();
            break;

        case 3:
            python();
            break;

        case 4:
            puts("Exiting the application");
            // delay function
            delay(1000);
            exit(0); // exit app when user select choice 4
            break;

        default:
            puts("Invalid choice, enter valid choice\n");
            delay(1000);
            exit(0);
        }

    }

    return (0);
}

// Info Function
void showInfo(void)
{
    puts("1. C QUIZ");
    puts("2. CPP QUIZ");
    puts("3. PYTHON QUIZ");
    puts("4. EXIT");
}

// C Quiz Function
int c(void)
{
    char c_answer1;
    int c_score;
    c_score = 0;

    // To clear screen
    clear();

    puts("\t\t\t\t\tC QUIZ IS START!");
    puts("\n\t\tYou have 5 question if your answer is correct then plus(+) 5 marks for each question!\n");

    // Question 1
    puts("1. Which data type is used to store a single character in C?\t5marks\n");
    puts(" 1) char\n 2) float\n 3) double\n 4) int\n");

    printf("Enter your answer = ");
    scanf(" %c", &c_answer1);

    printf("Your choose = %c\n", c_answer1);

    // Check answer is correct or not
    if (c_answer1 == '1')
    {
        puts("\tCorrect answer!");
        c_score = c_score + 5;
    }
    else if (c_answer1 == '2' || c_answer1 == '3' || c_answer1 == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) char");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) char");
    }

    // Question 2
    puts("\n2. Which data type is used to allocate 4byte memory?\t5marks\n");
    puts(" 1) char\n 2) short\n 3) double\n 4) int\n");

    printf("Enter your answer = ");
    scanf(" %c", &c_answer1);

    printf("Your choose = %c\n", c_answer1);

    // Check answer is correct or not
    if (c_answer1 == '4')
    {
        puts("\tCorrect answer!");
        c_score = c_score + 5;
    }
    else if (c_answer1 == '1' || c_answer1 == '2' || c_answer1 == '3')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) int");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) int");
    }

    // Question 3
    puts("\n3. Which of the following is a correct way to access the 3rd element of an array named 'arr' in C?\t5marks\n");
    puts(" 1) arr(3)\n 2) arr[3]\n 3) arr[2]\n 4) arr{3}\n");

    printf("Enter your answer = ");
    scanf(" %c", &c_answer1);

    printf("Your choose = %c\n", c_answer1);

    // Check answer is correct or not
    if (c_answer1 == '2')
    {
        puts("\tCorrect answer!");
        c_score = c_score + 5;
    }
    else if (c_answer1 == '1' || c_answer1 == '3' || c_answer1 == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 2) arr[3]");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 2) arr[3]");
    }

    // Question 4
    puts("\n4. What is the correct syntax to define a function in C?\t5marks\n");
    puts(" 1) int function_name(parameters){}\n 2) void function_name(parameters){}\n 3) function_name(parameters){}\n 4) int function_name(){}\n");

    printf("Enter your answer = ");
    scanf(" %c", &c_answer1);

    printf("Your choose = %c\n", c_answer1);

    // Check answer is correct or not
    if (c_answer1 == '1')
    {
        puts("\tCorrect answer!");
        c_score = c_score + 5;
    }
    else if (c_answer1 == '2' || c_answer1 == '3' || c_answer1 == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) int function_name(parameters){}");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) int function_name(parameters){}");
    }

    // Question 5
    puts("\n5. What is the correct way to initialize an array in C?\t5marks\n");
    puts(" 1) int arr[5] = {1, 2, 3, 4, 5};\n 2) int arr[5];\n 3) arr[] = {1, 2, 3, 4, 5};\n 4) int arr[] = (1, 2, 3, 4, 5);\n");

    printf("Enter your answer = ");
    scanf(" %c", &c_answer1);

    printf("Your choose = %c\n", c_answer1);

    // Check answer is correct or not
    if (c_answer1 == '1')
    {
        puts("\tCorrect answer!");
        c_score = c_score + 5;
    }
    else if (c_answer1 == '2' || c_answer1 == '3' || c_answer1 == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) int arr[5] = {1, 2, 3, 4, 5};");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) int arr[5] = {1, 2, 3, 4, 5};");
    }

    printf("\nYour marks is = %d\n", c_score);

    puts("Ending the c quiz\n");

    // delay function
    delay(1000);

    return (0);
}

// CPP Quiz Function
int cpp(void)
{
    char cpp_answer;
    int cpp_score;
    cpp_score = 0;

    // To clear screen
    clear();

    puts("\t\t\t\t\tCPP QUIZ IS START!");
    puts("\n\t\tYou have 5 question if your answer is correct then plus(+) 5 marks for each question!\n");

    // Question 1
    puts("1. Which keyword is used to create an object of a class in CPP?\t5marks\n");
    puts(" 1) new\n 2) class\n 3) object\n 4) none of above\n");

    printf("Enter your answer = ");
    scanf(" %c", &cpp_answer);

    printf("Your choose = %c\n", cpp_answer);

    // Check answer is correct or not
    if (cpp_answer == '1')
    {
        puts("\tCorrect answer!");
        cpp_score = cpp_score + 5;
    }
    else if (cpp_answer == '2' || cpp_answer == '3' || cpp_answer == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) new");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) new");
    }

    // Question 2
    puts("\n2. What is the correct syntax for a constructor in CPP?\t5marks\n");
    puts(" 1) class MyClass{}\n 2) MyClass {}\n 3) MyClass()\n 4) MyClass::MyClass()\n");

    printf("Enter your answer = ");
    scanf(" %c", &cpp_answer);

    printf("Your choose = %c\n", cpp_answer);

    // Check answer is correct or not
    if (cpp_answer == '4')
    {
        puts("\tCorrect answer!");
        cpp_score = cpp_score + 5;
    }
    else if (cpp_answer == '1' || cpp_answer == '2' || cpp_answer == '3')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) MyClass::MyClass()");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) MyClass::MyClass()");
    }

    // Question 3
    puts("\n3. Which operator is used to access the member functions and variables of an object in CPP?\t5marks\n");
    puts(" 1) .\n 2) ->\n 3) ::\n 4) :\n");

    printf("Enter your answer = ");
    scanf(" %c", &cpp_answer);

    printf("Your choose = %c\n", cpp_answer);

    // Check answer is correct or not
    if (cpp_answer == '1')
    {
        puts("\tCorrect answer!");
        cpp_score = cpp_score + 5;
    }
    else if (cpp_answer == '2' || cpp_answer == '3' || cpp_answer == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) .");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) .");
    }

    // Question 4
    puts("\n4. What does the '<<' operator do in CPP?\t5marks\n");
    puts(" 1) Bitwise left shift\n 2) Bitwise right shift\n 3) Output stream insertion\n 4) Input stream extraction\n");

    printf("Enter your answer = ");
    scanf(" %c", &cpp_answer);

    printf("Your choose = %c\n", cpp_answer);

    // Check answer is correct or not
    if (cpp_answer == '3')
    {
        puts("\tCorrect answer!");
        cpp_score = cpp_score + 5;
    }
    else if (cpp_answer == '1' || cpp_answer == '2' || cpp_answer == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 3) Output stream insertion");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 3) Output stream insertion");
    }

    // Question 5
    puts("\n5. Which of the following is used to dynamically allocate memory in CPP?\t5marks\n");
    puts(" 1) malloc()\n 2) calloc()\n 3) delete operator\n 4) new operator\n");

    printf("Enter your answer = ");
    scanf(" %c", &cpp_answer);

    printf("Your choose = %c\n", cpp_answer);

    // Check answer is correct or not
    if (cpp_answer == '4')
    {
        puts("\tCorrect answer!");
        cpp_score = cpp_score + 5;
    }
    else if (cpp_answer == '1' || cpp_answer == '2' || cpp_answer == '3')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) new operator");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) new operator");
    }

    printf("\nYour marks is = %d\n", cpp_score);

    puts("Ending the cpp quiz\n");

    // delay function
    delay(1000);

    return (0);
}
// Python Quiz Function
int python(void)
{
    char python_answer;
    int python_score;
    python_score = 0;

    // To clear screen
    clear();

    puts("\t\t\t\t\tPYTHON QUIZ IS START!");
    puts("\n\t\tYou have 5 question if your answer is correct then plus(+) 5 marks for each question!\n");

    // Question 1
    puts("1. What is Python?\t5marks\n");
    puts(" 1) A high-level programming language\n 2) A low-level programming language\n 3) An assembly language\n 4) A markup language\n");

    printf("Enter your answer = ");
    scanf(" %c", &python_answer);

    printf("Your choose = %c\n", python_answer);

    // Check answer is correct or not
    if (python_answer == '1')
    {
        puts("\tCorrect answer!");
        python_score = python_score + 5;
    }
    else if (python_answer == '2' || python_answer == '3' || python_answer == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) A high-level programming language");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) A high-level programming language");
    }

    // Question 2
    puts("\n2. What is the purpose of indentation in Python?\t5marks\n");
    puts(" 1) To make the code look neat and organized\n 2)To improve readability\n 3) To define blocks of code\n 4) All of the above\n");

    printf("Enter your answer = ");
    scanf(" %c", &python_answer);

    printf("Your choose = %c\n", python_answer);

    // Check answer is correct or not
    if (python_answer == '4')
    {
        puts("\tCorrect answer!");
        python_score = python_score + 5;
    }
    else if (python_answer == '1' || python_answer == '2' || python_answer == '3')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) All of the above");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 4) All of the above");
    }

    // Question 3
    puts("\n3. What is a lambda function in Python?\t5marks\n");
    puts(" 1) A function defined using the def keyword.\n 2) A function defined using the lambda keyword, which allows for creating anonymous functions.\n 3) A function that cannot accept arguments.\n 4)A function used for handling exceptions.\n");

    printf("Enter your answer = ");
    scanf(" %c", &python_answer);

    printf("Your choose = %c\n", python_answer);

    // Check answer is correct or not
    if (python_answer == '2')
    {
        puts("\tCorrect answer!");
        python_score = python_score + 5;
    }
    else if (python_answer == '1' || python_answer == '3' || python_answer == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 2) A function defined using the lambda keyword, which allows for creating anonymous functions.");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 2) A function defined using the lambda keyword, which allows for creating anonymous functions.");
    }

    // Question 4
    puts("\n4. What does the 'import' keyword do in Python?\t5marks\n");
    puts(" 1) It is used to include a module in the current Python script.\n 2) It is used to declare variables.\n 3) It is used to define functions.\n 4) It is used to assign values to variables.\n");

    printf("Enter your answer = ");
    scanf(" %c", &python_answer);

    printf("Your choose = %c\n", python_answer);

    // Check answer is correct or not
    if (python_answer == '1')
    {
        puts("\tCorrect answer!");
        python_score = python_score + 5;
    }
    else if (python_answer == '2' || python_answer == '3' || python_answer == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) It is used to include a module in the current Python script.");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 1) It is used to include a module in the current Python script.");
    }

    // Question 5
    puts("\n5. What is the purpose of the 'try' and 'except' blocks in Python?\t5marks\n");
    puts(" 1) To define loops in Python.\n 2) To handle exceptions and perform error handling.\n 3) To define conditional statements.\n 4) To define function definitions.\n");

    printf("Enter your answer = ");
    scanf(" %c", &python_answer);

    printf("Your choose = %c\n", python_answer);

    // Check answer is correct or not
    if (python_answer == '2')
    {
        puts("\tCorrect answer!");
        python_score = python_score + 5;
    }
    else if (python_answer == '1' || python_answer == '3' || python_answer == '4')
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 2) To handle exceptions and perform error handling.");
    }
    else
    {
        puts("\tWrong answer!");
        puts("\tCorrect answer ---> 2) To handle exceptions and perform error handling.");
    }

    printf("\nYour marks is = %d\n", python_score);

    puts("Ending the python quiz\n");

    // delay function
    delay(1000);

    return (0);
}

// Clear Screen Function
void clear(void)
{
    printf("\e[1;1H\e[2J");
}

// Delay Function
void delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}
