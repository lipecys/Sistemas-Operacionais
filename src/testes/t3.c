#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PACKAGE "mmap"

int main (int argc, char *argv[])
{
    FILE *input;
    int *source;
    size_t filesize;

    input = fopen ("ex_entrada", "r");
    if ( !input )
        perror ("ERROR"), exit (-1); // A função perror imprime o erro encontrado
    
    fseek (input, 0, SEEK_END);
    filesize = ftell (input);
    
    fread (source, sizeof (int), filesize, input);

    fwrite (source, sizeof (int), filesize, stdout);
    
    fclose (input);

    return 0;
}

