#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string containing only '0' and '1': ");
    scanf("%s", input);

    int state = 0;  // Initial state

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '0') {
            if (state == 0)
                state = 1;
            else if (state == 2)
                state = 1;
        } else if (input[i] == '1') {
            if (state == 0)
                state = 0;
            else if (state == 1)
                state = 2;
        } else {
            printf("Invalid input: Only '0' and '1' are allowed.\n");
            return 0;
        }
    }

    if (state == 2) {
        printf("String accepted: Ends with '01'\n");
    } else {
        printf("String rejected: Does not end with '01'\n");
    }

    return 0;
}
