#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    char name[50];
    int accountNumber;
    double balance;
    char accountType[10]; // Savings or Checking
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account newAccount;

    printf("Enter name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter initial balance: ");
    scanf("%lf", &newAccount.balance);
    printf("Enter account type (Savings/Checking): ");
    scanf("%s", newAccount.accountType);

    accounts[accountCount++] = newAccount;
    printf("Account created successfully.\n");
}

void deposit() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Amount deposited successfully.\n");
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully.\n");
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }

    printf("Account not found.\n");
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void calculateInterest() {
    int accountNumber;
    double interestRate;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter interest rate (%%): ");
    scanf("%lf", &interestRate);

    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            double interest = accounts[i].balance * (interestRate / 100);
            printf("Interest: %.2lf\n", interest);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                calculateInterest();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
