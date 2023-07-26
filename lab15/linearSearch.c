#include <stdio.h>

int linear_search(int arr[], int size_of_array, int item)
{
    for (int i = 0; i < size_of_array; i++)
    {
        if (arr[i] == item)
            return i;
        else
            return -1;
    }
}

int main()
{
    int size_of_array;
    printf("Enter the size of array :\n");
    scanf("%d", &size_of_array);

    int arr[size_of_array];
    printf("Enter the elements ");
    for (int i = 0; i < size_of_array; i++)
    {
        scanf("%d", &arr[i]);
    }
}