#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *items[] = {"boat", "car", "truck", "train"};
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <index>\n", argv[0]);
        return 1;
    }
    int index = atoi(argv[1]);
    if (index < 0 || index >= sizeof(items) / sizeof(items[0]))
    {
        fprintf(stderr, "Error: index out of bounds\n");
        return 1;
    }
    printf("You selected %s\n", items[index]);
}