#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateCFG(char regex[])
{
    printf("Generated CFG rules:\n");
    int state = 0;
    int production = 1;
    printf("S -> ");
    for (int i = 0; i < strlen(regex); i++)
    {
        if (regex[i] == '(')
        {
            printf("S%d", production);
            state++;
        }
        else if (regex[i] == ')')
        {
            printf("S%d", production);
            printf("S -> e\n");
            printf("S%d -> e\n", production);
            state--;
            production++;
        }
        else if (regex[i] == '*')
        {
            printf("S%d", production - 1);
            printf("S%d -> e\n", production - 1);
            printf("S%d -> S%dS%d\n", production - 1, production - 1, production);
            printf("S%d -> e\n", production);
            state--;
            production++;
        }
        else if (regex[i] == '+')
        {
            printf("S%d", production - 1);
            printf("S%d -> S%dS%d\n", production - 1, production - 1, production);
            state++;
        }
        else
        {
            printf("%cS%d", regex[i], production);
            printf("S%d -> %cS%d\n", production, regex[i], production);
            state++;
            production++;
        }
        if (i != strlen(regex) - 1 && regex[i + 1] != '*' && regex[i + 1] != ')' && regex[i] != '(' && regex[i + 1] != '+')
        {
            printf("| ");
        }
    }
    while (state > 0)
    {
        printf("S%d", production);
        printf("S -> S%d\n", production);
        state--;
        production++;
    }
}

int main()
{
    char regex[100];
    printf("Enter a regular expression (with concatenation, Kleene star (*), and one or more (+) operations):\n");
    scanf("%s", regex);
    generateCFG(regex);
    return 0;
}