#include <stdio.h>
#include <regex.h>

int main() {
    char pattern[100];
    printf("Enter a regular expression pattern: ");
    scanf("%s", pattern);

    regex_t regex;
    int compile_result = regcomp(&regex, pattern, REG_EXTENDED);

    if (compile_result == 0) {
        printf("Pattern is valid!\n");
    } else {
        char error_message[100];
        regerror(compile_result, &regex, error_message, sizeof(error_message));
        printf("Pattern is invalid: %s\n", error_message);
    }

    regfree(&regex);
    return 0;
}