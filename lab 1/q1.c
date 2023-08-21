#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string containing only 'a' and 'b': ");
    scanf("%s", input);

    int state = 0;  // Initial state

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'a') {
            switch (state) {
                case 0: state = 1; break; // From even 'a's to odd 'a's
                case 1: state = 0; break; // From odd 'a's to even 'a's
                case 2: state = 3; break; // From even 'b's to odd 'a's
                case 3: state = 2; break; // From odd 'b's to even 'a's
            }
        } else if (input[i] == 'b') {
            switch (state) {
                case 0: state = 2; break; // From even 'a's to even 'b's
                case 1: state = 3; break; // From odd 'a's to odd 'b's
                case 2: state = 0; break; // From even 'b's to even 'a's
                case 3: state = 1; break; // From odd 'b's to odd 'a's
            }
        }
    }

    if (state == 1) {
        printf("String accepted: Odd 'a's and even 'b's\n");
    } else {
        printf("String rejected\n");
    }

    return 0;
}
