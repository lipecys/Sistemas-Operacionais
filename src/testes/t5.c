#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define PACKAGE "mmap"

int main ( int argc, char **argv )
{
    int input, output;
    size_t filesize;
    char *source, *target;

    if ( ( input = open ("ex_entrada", O_RDONLY) ) == -1 )
        fprintf ( stderr, "%s: Error: opening file: %s\n", PACKAGE, argv[1] ), exit (1);

    filesize = lseek(input, 0, SEEK_END);

    if ( ( source = mmap (0, filesize, PROT_READ, MAP_SHARED, input, 0) ) == (void *) -1 )
        fprintf ( stderr, "Error mapping input file: %s\n", argv[1] ), exit (1);

    int i, x, j = 0;
    char c;
    char *y;
    y = malloc ( 20 * sizeof (char) );
    for ( i = 0; i <= filesize; i++ )
    {
        //putchar (source[i]);
        c = source[i];
        if ( c != ' ' && c != '\n' )
        {
            y[j] = c;
            j++;
        }
        else
        {
            y[j+1] = '\0';
            x = atoi (y);
            printf ("%d\n", x);
            j = 0;
        }
    }

    munmap (source, filesize);

    close (input);

    return 0;
}
