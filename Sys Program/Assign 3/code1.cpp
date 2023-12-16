#include <bits/stdc++.h>
using namespace std;

bool matchesPattern1(const char *input) // a(a|b)*b
{
    if (input[0] != 'a')
    {
        return false;
    }
    int i = 1;
    while (input[i] != '\0')
    {
        if (input[i] != 'a' && input[i] != 'b')
        {
            return false;
        }
        i++;
    }
    return input[i - 1] == 'b';
}

bool matchesPattern2(const char *input) // (a+b)*a|b
{
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] != 'a' && input[i] != 'b')
        {
            return false;
        }
        i++;
    }
    return input[i - 1] == 'b' || input[i - 1] == 'a';
}

bool matchesPattern3(const char *input) // (100)*(1+0)(1|0)*1
{
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] != '100' && input[i] != 'b')
        {
            return false;
        }
        i++;
    }
    return input[i - 1] == '1';
}

void removeSpaces(char input[], int length)
{
    int j = 0;
    for (int i = 0; i < length; i++)
    {
        if (input[i] != ' ')
        {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
}

int main()
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    int length = strlen(input);
    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
        length--;
    }
    removeSpaces(input, length);
    if (matchesPattern1(input))
    {
        printf("String matches the pattern.\n");
    }
    else
    {
        printf("String does not match the pattern.\n");
    }
    return 0;
}