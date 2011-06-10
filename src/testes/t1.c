#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PACKAGE "mmap"

int main (int argc, char *argv[])
{
    FILE *input;
    int x;

    input = fopen ("ex_entrada", "r");
    if ( !input )
        perror ("ERROR"), exit (-1); // A função perror imprime o erro encontrado
    
    while ( !feof (input) )
    {
        fscanf (input, "%d", &x);
        printf ("%d ", x);
    }
    
    fclose (input);

    return 0;
}

