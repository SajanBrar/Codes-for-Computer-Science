#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack)
{
    stack->top = -1;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int isBalanced(const char *expression)
{
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (isEmpty(&stack))
            {
                return 0;
            }
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{'))
            {
                return 0;
            }
        }
    }
    return isEmpty(&stack);
}

int main()
{
    FILE *file;
    char ch;
    char *expression;
    int size = 0;
    file = fopen("Ques4_input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    // Get the size of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    // Allocate memory for the expression
    expression = (char *)malloc((size + 1) * sizeof(char));
    // Read the file contents into the expression array
    int i = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        expression[i] = ch;
        i++;
    }
    expression[i] = '\0';
    if (isBalanced(expression))
        printf("Balanced.\n");
    else
        printf("Balanced.\n");
    fclose(file);
    free(expression);
    return 0;
}