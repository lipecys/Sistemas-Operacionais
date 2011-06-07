#include <stdio.h>
#include <stdlib.h>
#include <Judy.h>
#include <string.h>

#define MAX 1000		// tamanho máximo da compra
#define MAXLINE 100		// tamanho máximo da string

Pvoid_t PJArray = (PWord_t) NULL;	// Judy array.
PWord_t PValue;			// Judy array element.

uint8_t Index[MAXLINE];		// string to insert
uint8_t temp[MAXLINE];		// temporary string to insert 

typedef struct cel
{
    int cont;
    int p1;
    int p2;
} elem;

//-------------------------------------
int compara (const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int compara2 (const void *a, const void *b)
{
    elem *ia = (elem *) a;
    elem *ib = (elem *) b;
    return (int) (ib->cont - ia->cont);
}

//-------------------------------------
void processa_lista (int *vetor, int cont, int N, elem * pares)
{
    int i, j, k, pos;

    qsort (vetor, cont, sizeof (int), compara);

//       for(i=0;i<cont;i++)
//      printf("%d ", vetor[i]);
//       printf("\n");

    for (i = 0; i < cont; i++)
    {
        for (j = i + 1; j < cont; j++)
        {
            sprintf (Index, "%010d,%010d\0", vetor[i], vetor[j]);

            JSLI (PValue, PJArray, Index);	// store string into array

            if (PValue == PJERR)	// if out of memory?
	        {			// so do something
                printf ("Malloc failed -- get more ram\n");
                exit (1);
	        }
    
            if (*PValue != 0)
	        {
                *PValue += 1;
                //printf("-----------> %s %li\n",Index,*PValue);
	        }
            else
	        {
                *PValue = 1;
                //printf("%s %li\n",Index,*PValue);
	        }
    
            pos = N;
            for (k = 0; k < N; k++)
	        {
                if ((pares[k].p1 == vetor[i]) && (pares[k].p2 == vetor[j]))
                {
                    pos = k;
                    break;
                }
	        }
    
            pares[pos].p1 = vetor[i];
            pares[pos].p2 = vetor[j];
            pares[pos].cont = *PValue;
    
            qsort (pares, N + 1, sizeof (elem), compara2);

        }
    }
}


//-------------------------------------
int main (void)
{
    char *line = NULL;
    size_t len = 0;
    int read;
    int K, N;
    char *token, *tok;
    int value;
    
    int cont, iter;
    int i;
//vetor que armazena os dados de uma compra
    int array[MAX];
    int p1, p2;
    elem *pares;

//leitura de K e N      
    scanf ("%d\n", &N);
    scanf ("%d\n", &K);

    pares = (elem *) calloc (N + 1, sizeof (elem));

    iter = 1;
//parser para os codigos das mercadorias        
    while ((read = getline (&line, &len, stdin)) != -1)
    {
        cont = 0;
        token = strtok (line, " ");

        while (token != NULL)
        {
            value = atoi (token);
            array[cont] = value;
            cont++;
            //printf("->%i\n", value);
            token = strtok (NULL, " ");
        }

//chama função para processar a lista   

        processa_lista (array, cont, N, pares);

        if (N == 0)
        {
            printf ("Rodada %d\n", iter);

            Index[0] = '\0';
            JSLF (PValue, PJArray, Index);	// get first string
            while (PValue != NULL)
            {
                strcpy (temp, Index);
                tok = strtok (temp, ",");
                p1 = atoi (tok);

                tok = strtok (NULL, ",");
                p2 = atoi (tok);

                printf ("%d %d\n", p1, p2);
                //printf("%s\n", Index);
                JSLN (PValue, PJArray, Index);	// get next string
            }

        }
        else if ((iter % K) == 0)
        {
            printf ("Rodada %d\n", iter);

            for (i = 0; i < N; i++)
            {
                printf ("%d %d\n", pares[i].p1, pares[i].p2);
            }
        }
        iter++;
    }
    return 0;
}
