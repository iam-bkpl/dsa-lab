#include <stdio.h>

void binary_search(int arr[], int size_of_array)
{
        
    while (/* condition */)
    {
        /* code */
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

    binary_search(arr, size_of_array);
}