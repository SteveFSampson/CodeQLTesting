#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int *array, int len, int index)
{
    // Check if index is within bounds
    if (index < 0 || index >= len / sizeof(int))
    {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    // Return the element from the array at the specified index
    return array[index];
}

int main(int argc, char **argv)
{
    int items[] = {902, 903, 904, 905, 906};
    int retVal = 0;

    for (int i = 0; i <= 15; i++)
    {
        retVal = getValueFromArray(items, sizeof(items), i);
        printf("Returned value at index %d is %d\n", i, retVal);
    }
}
