#include <stdio.h>
#include <stdlib.h>

void    selection_sort(int *arr, int size)
{
    int i;
    int j;
    int k;
    int temp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        k = i;
        temp = arr[i];
        while (j < size)
        {
            if (temp > arr[j])
            {
                temp = arr[j];
                k = j;
            }
            j++;
        }
        if (k != i)
        {
            temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
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
    while (i < argc - 1)
    {
        num_arr[i] = atoi(argv[i + 1]);
        i++;
    }
    selection_sort(num_arr, argc - 1);
    i = 0;
    while (i < argc - 1)
    {
        printf("%d ", num_arr[i]);
        i++;
    }
    return (0);
}