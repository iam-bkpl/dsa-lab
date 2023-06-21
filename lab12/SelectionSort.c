#include <stdio.h>

void printArray(int array[], int size)
{
    int i;
    printf("{");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
    printf("}\n");
}

void selection_sort(int arr)
int main()
{
    int size;
    printf("Enter the size of array :\n");
    scanf("%d", &size);

    int array[size];

    printf("Enter the elements of array :\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Original array: \n");
    printArray(array, size);

    return 0;
}