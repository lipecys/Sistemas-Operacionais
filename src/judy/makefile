all: mercado_judy.c gera_entrada.c
	gcc -o gera_entrada gera_entrada.c 
	gcc -o mercado_judy mercado_judy.c -lJudy

clean: 
	rm -f *.o *.*~ *~ mercado_judy
	rm -f *.o *.*~ *~ gera_entrada