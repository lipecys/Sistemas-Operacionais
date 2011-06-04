/* memmove example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char str[] = "memcpy can be very useful......";
    char *teste = (char *)malloc(strlen(str) * sizeof(char));

    //Copia 11 posições da string str a partir da posição 15 da str e joga na posição 20 da str
    //memmove (str+20,str+15,11);

    memcpy (teste,str,strlen(str));
    puts ("str original");
    puts (str);

    puts ("str copiada");
    puts (teste);

    return 0;
}
