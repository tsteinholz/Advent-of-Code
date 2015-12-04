#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////////
// Purpose: Load file from the file system.
//
// param : loc - location of the file that should be loaded
// param : ret - the returned data from the file
//
// returns : the size of the file in bytes or the error codes...
//              -1 for opening fail
//              -2 for reading fail
///////////////////////////////////////////////////////////////////////////////////
int load_file(const char *loc, char **ret)
{
    FILE *file = fopen(loc, "rb");
    if (file == NULL)
    {
        printf("Failed to load %s!\n", loc);
        return -1;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    *ret = (char *)malloc(size + 1);
    if (size != fread(*ret, sizeof(char), size, file))
    {
        free(*ret);
        printf("Failed to open %s!\n", loc);
        return -2;
    }
    fclose(file);
    (*ret)[size] = 0;
    return size;
}

int main(int arc, char **argv)
{
    if (arc < 2)
    {
        printf("Not enough args\n");
        return EXIT_FAILURE;
    }
    char *input;
    if (load_file(argv[1], &input) < 0)
    {
        printf("Failed to load %s!\n", argv[1]);
        return EXIT_FAILURE;
    }
    printf("%s", input);
    return EXIT_SUCCESS;
}
