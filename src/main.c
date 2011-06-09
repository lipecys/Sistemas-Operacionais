#include "main.h"

// Variávris que irão armazenar os valores de N e K
unsigned int n, k;
// Variável que guarda a linha que está sendo analizada no momento
unsigned int current_line = 0;
// Variável que guarda a iteração atual
unsigned int iter = 0;
// Mutex para o contador de linhas
pthread_mutex_t mutex_lines;

// Mutex para o contador de iterações
pthread_mutex_t mutex1;

// Estrutura que irá armazenar os dados
nossaEstrutura st;


// Responsável por ler a linha e armazenar numa estrutura
// que ainda será definida
nossaEstrutura *readLine ( void )
{
    /*
     * Lê a linha e armazena numa estrutura
     * que ainda será definida
     */
    return NULL;
}

// Responsável por processar a linha
int processLine ( nossaEstrutura *st )
{
    /*
     * Vai processar a linha lida e armazenar os resultados em 
     * algum lugar
     */
    return 0;
}

// Responsável por mostrar a saída do programa
void *printResult ( void *args )
{
    /*
     * Responsável pela saída do programa
     */
     
    pthread_mutex_lock (&mutex1);
    if ( n == 0  )
        // Do this
        puts ("N == 0");
    else if ( (iter % k) == 0 )
        // Or this
        puts ("Imprimir algo");
    pthread_mutex_unlock (&mutex1);
        
    puts ("Saída");
}



// Sub-rotina que as threads irão executar
void *execute ( void *args )
{
    nossaEstrutura *st1;
    pthread_mutex_lock (&mutex_lines);
        /*
         * A idéia inicial era usar um contador para a pŕoxima
         * linha a ser tratada. Eu acho que isso acaba sendo 
         * demorado, pois a thread terá de navegar até a linha dada.
         * Minha idéia é usar a região crítica para ler a linha.
         */
         st1 = readLine ();
         iter++;
    pthread_mutex_unlock (&mutex_lines);
    
    // Processa a linha
    processLine (st1);
    
    // Imprime resultado se for a hora
    printResult (st1);
    
    pthread_exit (NULL);
}

int main ( int argc, char **argv )
{
    // Lendo N e K
    scanf ("%u", &n);
    scanf ("%u", &k);
    
    unsigned int i;
    pthread_t tid;
    pthread_mutex_init (&mutex_lines, NULL);
    
    for ( i = 0; i < MAX_THREADS - 1 ; i++ )
        pthread_create ( &tid, TH_ATTR, execute, NULL );

    pthread_create ( &tid, TH_ATTR, printResult, st );
        
    pthread_mutex_destroy (&mutex1);
    pthread_mutex_destroy (&mutex_lines);
    return 0;
}
