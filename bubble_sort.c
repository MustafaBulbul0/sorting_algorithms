#include <stdio.h>
#include <stdlib.h>


void    bubble_sort(int *arr, int arr_size)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = 0;
    while (i < arr_size)
    {
        j = i + 1;
        while (j < arr_size)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int *num_arr;
    int i;

    i = 0;
    if (argc < 2)
        return (1);
    num_arr = (int *)calloc((argc - 1), sizeof(int));
    if (!num_arr)
        return (2);
    while(i < argc - 1)
    {
        num_arr[i] = atoi(argv[i + 1]);
        i++;
    }
    bubble_sort(num_arr , argc - 1);
    i = -1;
    while (++i < argc - 1)
        printf("%d ", num_arr[i]);
    printf("\n");
    free(num_arr);
    return (0);
}
