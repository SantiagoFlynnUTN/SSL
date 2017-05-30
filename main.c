#include <stdio.h>
#include "scanner.h"

static int cantidadIdentificadores = 0;
static int cantidadConstantesEnteras = 0;
static int cantidadErrores = 0;

int main(){
	char unCaracter;
	while((unCaracter = getchar()) != EOF){ 	/* Lee hasta que llega al EOF */
		ungetc(unCaracter, stdin); 				/* Entré, entonces no es EOF. Devuelve el char.*/

		lexicalCategory_t categoriaLexica = readToken();

		switch(categoriaLexica){
			case IDENTIFICADOR:
				cantidadIdentificadores++;
				printf("IDENTIFICADOR\n");
				break;
			case CONSTANTE:
				cantidadConstantesEnteras++;
				printf("CONSTANTE ENTERA\n");
				break;
			case ERROR:
				cantidadErrores++;
				printf("ERROR\n");
				break;
		}
	}

	printf("IDENTIFICADORES: %d\n", cantidadIdentificadores);
	printf("CONSTANTES ENTERAS: %d\n", cantidadConstantesEnteras);
	printf("ERRORES: %d\n", cantidadErrores);
	return 0;
}
