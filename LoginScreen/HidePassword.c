#include<stdio.h>
#include<string.h>


struct user {
    char fullName[50];
    char email[50];
    char username[50];
    char password[50];
    char phone[50];
};

//FUNCTIONS
void takeInput(char ch[50]) {  // take input
    fgets(ch, 50, stdin);
    ch[strlen(ch)-1] = '\0'; 
}
void generateUsername(char email[50], char username[50]) { // get username
    //charlie123@gmail.com
    for (int i = 0; i<strlen(email); i++) {
        if ((email[i] = '@')) {
            break;
        } else username[i] = email[i];
    }
}
void clearInput(void) { // Clear buffer
    while (getchar() != '\n') {
        ; //do nothing
    }
}
//Hide password function
void takePassword(char pwd[50]) {
    int i;
    char ch;
    while (1) {
        ch = getc;
    }
}

int main() {

    int opt;
    struct user user;

    printf("\n\t\t\t\t-----Welcome to authentication system-----");
    printf("\nPlease choose your operation");
    printf("\n1.Sign up");
    printf("\n2.Login");
    printf("\n3.Exit");

    //user input
    printf("\n\nOption: ");
    scanf("%d", &opt);
    clearInput();

    //switch statement
    switch (opt) {
        case 1: 
            printf("\n\t\t\t\t\tBegin sign up process");
            printf("\nEnter your full name: ");
            takeInput(user.fullName);
            printf("\nEnter email: ");
            takeInput(user.email);
            printf("\nEnter your phone number: ");
            takeInput(user.phone);
            printf("\nEnter your password: ");
            takeInput(user.password);
    }




    return 0;
}