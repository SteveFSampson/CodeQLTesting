#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes

long get_file_size(const char *file_path)
{
    FILE *file;
    long file_size;

    // Open the file in binary mode
    file = fopen(file_path, "rb");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", file_path);
        return -1;
    }

    // Seek to the end of the file
    if (fseek(file, 0, SEEK_END) != 0)
    {
        fprintf(stderr, "Could not seek to the end of file %s.\n", file_path);
        fclose(file);
        return -1;
    }

    // Get the file size
    file_size = ftell(file);
    if (file_size == -1)
    {
        fprintf(stderr, "Could not get the size of file %s.\n", file_path);
        fclose(file);
        return -1;
    }

    // Close the file
    fclose(file);

    return file_size;
}

int main(int argc, char **argv)
{
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    // Check if the input parameter is a valid file
    if (access(argv[1], F_OK) == -1)
    {
        fprintf(stderr, "File %s does not exist.\n", argv[1]);
        return -1;
    }

    // Get the file size
    long file_size = get_file_size(argv[1]);
    if (file_size == -1)
    {
        return -1;
    }

    // Print the file size
    printf("Size of file %s: %ld bytes\n", argv[1], file_size);

    return 0;
}