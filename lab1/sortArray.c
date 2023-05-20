#include <stdio.h>

void shortArray(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                
            }
            
        }
    }
}

int main()
{

    int arraySize = 3;
    int arr[arraySize];
    printf("Enter  %d number in array \n", arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("------------------\n");

    shortArray(&arr, arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}