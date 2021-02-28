#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    int SIZE = NULL;
    do
    {
        printf("how many  array's elements you want: ");
        scanf("%d", &SIZE);
    } while(SIZE > 21); // max = 20

    // memory allocation for array in heap segement
    int *array = malloc(SIZE * sizeof(int));
    array_init(array, SIZE);
    array_print(array, SIZE);
    selection_sort(array, SIZE);
    // print after sort
    array_print(array, SIZE);
    free(array);
    return 0;
}
void array_init(int *array, int SIZE)
{
    printf("add values to your array:\n");
    int i;
    for(i = 0 ; i < SIZE ; i++)
    {
        scanf("%d", &array[i]);
    }

}

void array_print(int *array, int SIZE)
{
    int i;
    for(i = 0 ; i < SIZE ; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selection_sort(int *array, int SIZE)
{
    int i, j, small, actual_index, temp, n = 0;
    for(j = 0 ; j < SIZE ; j++)
    {
        small = array[j]; //
        for(i = n /* 0 */ ; i < SIZE ; i++)
        {
            if(array[i] <= small)
            {
                small = array[i];
                actual_index = i;
            }
        }

        temp = array[j];
        array[j] = small;
        array[actual_index] = temp;

        
        // here i tried to optimize the space complexity
        // by swapping the elements without temp variable
        // it didn't work : open for contribution
        /*
        array[actual_index]+=array[j];
        array[j] = array[actual_index] - array[j];
        array[actual_index]-=array[j];
        */
        n++;
    }
}
