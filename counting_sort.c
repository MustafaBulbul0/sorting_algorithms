#include <stdio.h>
#include <stdlib.h>

int biggest_num(int *arr, int size)
{
    int i;
    int big_num;

    i = 0;
    big_num = arr[i];
    while (i < size)
    {
        if (big_num < arr[i])
            big_num = arr[i];
        i++;
    }
    return (big_num);
}

void    counting_sort(int *arr, int size)
{
    int big_num;
    int *big_arr;
    int i;
    int k;

    k = 0;
    i = 0;
    big_num = biggest_num(arr, size);
    big_arr = (int *)calloc((big_num + 1), sizeof(int));
    if (!big_arr)
        return ;
    while (i < size)
    {
        big_arr[arr[i]]++;
        arr[i] = 0;
        i++;
    }
    i = 0;
    while (i <= big_num)
    {
            while (big_arr[i]-- > 0)
            {    
                arr[k] = i;
                k++;
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
    num_arr = (int *)malloc((argc - 1) * sizeof(int));
    if (!num_arr)
        return (2);
    while (i < argc - 1)
    {
        num_arr[i] = atoi(argv[i + 1]);
        i++;
    }
    counting_sort(num_arr, argc -1);
    i = 0;
    while (i < argc - 1)
    {
        printf("%d ", num_arr[i]);
        i++;
    }
    free(num_arr);
    return (0);
}