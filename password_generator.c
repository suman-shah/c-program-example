/* A program to generate strong passwords. */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%%^&*()\\/";

    srand(time(NULL));

    int password_length;

    // check if password length is in the program arguments.
    if (argc == 2) {
        // convert argument to int.
        password_length = atoi(argv[1]);
    } else {
        // get password length from user
        printf("Enter password length: ");
        scanf("%d", &password_length);
    }

    // generate password with given length
    for (int i = 0; i < password_length; i++) {
        char c = characters[rand() % strlen(characters)];
        printf("%c", c);
    }

    printf("\n");

    return 0;
}