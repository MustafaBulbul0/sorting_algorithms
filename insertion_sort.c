#include <stdio.h>
#include <stdlib.h>

void    insertion_sort(int *arr, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size)
    {
         temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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
    num_arr = (int *)malloc((argc - 1) * sizeof(int));
    if (!num_arr)
        return (2);
    while (i < argc - 1)
    {
        num_arr[i] = atoi(argv[i + 1]);
        i++;
    }
    insertion_sort(num_arr, argc - 1);
    i = 0;
    while (i < argc - 1)
    {
        printf("%d ", num_arr[i]);
        i++;
    }
    free(num_arr);
    return (0);
}