#include <stdio.h>
#include <stdlib.h>

//quantidade máxima de produtos
#define MAX_PROD 50000

//quantidade máxima de produtos por compra (MAX_LIST+3)
#define MAX_LIST 50



int na_lista(int array[], int cont, int number)
{
    int i;
    
    for(i=0;i<cont;i++)
    {
	    if(array[i]==number)
	    {
	      return 1;
	    }
    }
    
    return 0;
}

//./gera_entrada <N> <K> <n_entradas>
int main(int argc, char *argv[])
{
	int i,j;
	int K, N, entries, buy_size;
	
	int array[MAX_LIST+2];
	int cont, number, ok, inlist;
	
	N=atoi(argv[1]);
	K=atoi(argv[2]);
	entries=atoi(argv[3]);
	
	printf("%d\n",N);
	printf("%d\n",K);

	srand (time(NULL));
	
	for(i=0;i<entries;i++)
	{
	    buy_size=(rand()%MAX_LIST) +2; 
	    cont=0;
	    
	    for(j=0;j<buy_size;j++)
	    {
		    ok=0;
		    do
		    {
		        number=rand()%MAX_PROD;
		        inlist=na_lista(array,cont,number);
		        
		        if(inlist==0)
		        {
		          ok=1;
		          array[cont]=number;
		          cont++;
		        }
		    }
		    while(ok==0);
		      
		    printf("%d", number );
		
		    if(j<buy_size-1)
		      printf(" "); //tirar espaço do final da linha
	    }
	    printf("\n");
	}
}
