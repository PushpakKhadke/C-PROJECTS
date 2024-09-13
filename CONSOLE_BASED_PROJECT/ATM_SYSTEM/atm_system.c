#include <stdio.h>1
#include <stdlib.h>


// Function prototypes
void Showinfo(void);
int Deposit(int pin_number, int balance);
int Withdraw(int pin_number, int balance);
int Check_balance(int account_number, int balance);

int main(void)
{
    int choice;
    int balance = 0;
    int pin_number = 123;
    int account_number = 123456;

    puts("\n\t\t\t\tATM MANAGEMENT SYSTEM!");

    while (1) // Infinite loop
    {
        Showinfo(); // Display menu

        printf("\tEnter Your Choice = ");
        if (scanf("%d", &choice) != 1 || (choice < 1 || choice > 4))
        {
            // Invalid input or out of range
            while (getchar() != '\n'); // Clear input buffer
            puts("\t\tINVALID CHOICE!\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                balance = Deposit(pin_number, balance);
                break;
            case 2:
                balance = Withdraw(pin_number, balance);
                break;
            case 3:
                balance = Check_balance(account_number, balance);
                break;
            case 4:
                puts("EXIT APPLICATION!");
                exit(0); // Exit program
            default:
                puts("\t\tINVALID CHOICE!\n");
        }
    }

    return 0;
}

void Showinfo(void)
{
    puts("1. Deposit");
    puts("2. Withdraw");
    puts("3. Check Balance");
    puts("4. Exit");
}

int Deposit(int pin_number, int balance)
{
    int money;
    printf("\tEnter How Many Money You Want To Deposit = ");
    scanf("%d", &money);

    if (money <= 0)
    {
        puts("\t\tINVALID AMOUNT!\n");
        return balance;
    }

    printf("\tEnter Pin Number = ");
    if (scanf("%d", &pin_number) != 1 || pin_number != 123)
    {
        puts("\t\tWRONG PIN NUMBER!\n");
        return balance;
    }

    balance += money;
    printf("\t\t%d RS DEPOSIT IN ACCOUNT!\n", money);
    return balance;
}

int Withdraw(int pin_number, int balance)
{
    int money;
    printf("\tEnter How Many Money You Want To Withdraw = ");
    scanf("%d", &money);

    if (money <= 0)
    {
        puts("\t\tINVALID AMOUNT!\n");
        return balance;
    }

    printf("\tEnter Pin Number = ");
    if (scanf("%d", &pin_number) != 1 || pin_number != 123)
    {
        puts("\t\tWRONG PIN NUMBER!\n");
        return balance;
    }

    if (balance < money)
    {
        puts("\t\tINSUFFICIENT BALANCE!\n");
        return balance;
    }

    balance -= money;
    printf("\t\t%d RS WITHDRAW IN ACCOUNT!\n", money);
    return balance;
}

int Check_balance(int account_number, int balance)
{
    printf("\tYOUR ACCOUNT BALANCE IS = %d\n", balance);
    return balance;
}
