#include <stdio.h>

void countNum(int *num)
{
    *num = *num + 1;
    printf("current count : %d\n", *num);
}

int main()
{
    int count = 1;
    printf("before count : %d\n", count);

    countNum(&count);

    printf("After count : %d\n", count);
}