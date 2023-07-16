#include <stdio.h>

int main()
{
    int size_of_array;
    int arr[size_of_array];
    printf("Enter the size of array :\n");
    scanf("%d", &size_of_array);

    printf("Enter the elements of array :\n");
    for (int i = 0; i < size_of_array; i++)
    {
        scanf("%d", &arr[i]);
    }

}   