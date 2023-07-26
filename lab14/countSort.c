#include <stdio.h>
#include <stdlib.h>

void count_sort(int arr[], int largest_element_of_array, int size_of_array)
{

    int arr_count_size = largest_element_of_array + 1;
    int arr_b[size_of_array];
    // int arr_count[arr_count_size] = {0};
    int arr_count = [size_of_array];

    for (int i = 0; i < arr_count_size; i++)
    {
        arr_count[i] = 0;
    }

    for (int i = 0; i < size_of_array; i++)
    {
        arr_count[arr[i]]++;
    }
    for (int i = 1; i <= largest_element_of_array; i++)
    {
        arr_count[i] = arr_count[i] + arr_count[i - 1];
    }
    for (int i = size_of_array; i >= 0; i--)
    {
        arr_b[--arr_count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < size_of_array; i++)
    {
        arr[i] = arr_b[i];
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

    int largest_element_of_array = arr[0];
    // finding the largest element of array
    for (int i = 0; i < size_of_array; i++)
    {
        if (largest_element_of_array <= arr[i])
        {
            largest_element_of_array = arr[i];
        }
    }

    printf("Orginal Array :\n");
    for (int i = 0; i < size_of_array; i++)
    {
        printf("%d\n", arr[i]);
    }

    count_sort(arr, largest_element_of_array, size_of_array);

    printf("Sorted Array is :\n");
    for (int i = 0; i < size_of_array; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}