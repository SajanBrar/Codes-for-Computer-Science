#include <stdio.h>
#define PI 3.14159
#define MAX_VALUE 100

int main()
{
    float radius = 5.0;
    float area = PI * radius * radius;
    int maxValue = MAX_VALUE;
    printf("Area of the circle: %f", area);
    printf("\n");
    printf("Max value: %f", maxValue);
    printf("\n");
    return 0;
}