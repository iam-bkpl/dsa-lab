#include <stdio.h>

float area(float length, float breadth)
{
    return length * breadth;
}

int main()
{
    float result = area(2.2, 4.4);
    printf("Area of rectangle is : %f \n", result);
}