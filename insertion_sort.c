#include <stdio.h>
#include <stdlib.h>

void    insertion_sort(int *arr, int size)
{
    int i;
    int j;
    int k;
    int temp;

    i = 0;
    while (i < size)
    {
        j = i + 1;
        if (arr[j] < arr[i])
        {
            if (arr[j] < arr[0])
            {
                temp = arr[j];
                while (j > 0)
                {
                    arr[j] = arr[j - 1];
                    j--;
                }
                arr[0] = temp;
            }
            else
            {
                k = i;
                while (k < 0)
                {
                    if ((arr[j] < arr[k]) && (arr[j] > arr[k + 1]))
                    {
                        while (j > k + 1)
                        {
                            temp = arr[j];
                            arr[j] = arr[j - 1];
                            j--;
                        }
                        arr[k + 1] = temp;
                        break ;
                    }
                    k--;
                }
            }
        }
        i++;
    }
}

int main(int argc, char *argv)
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