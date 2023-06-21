#include <stdio.h>

void bubbleSort(int array[], int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

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

    bubbleSort(array, size);

    printf("Sorted array: \n");
    printArray(array, size);

    return 0;
}
