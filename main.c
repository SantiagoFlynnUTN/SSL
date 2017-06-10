#include <stdio.h>
#include "scanner.h"

static int tipoToken[4] = {0,0,0,0};



void mostrarCategoriaLexica(lexicalCategory_t estado){
	switch (estado){
		case IDENTIFICADOR: printf("\nIdentificador.\n");
		break;
		case CONSTANTE: printf("\nConstante.\n");
		break;
		case ERROR: printf("\nError.\n");
		break;
		default: printf("\nNo se encontraron más tokens para leer\n");
	}
}

int main(){
	stdin = fopen("cadenas.txt", "r");
	lexicalCategory_t token = INICIO;
	while(token != FINARCHIVO){	//lee el flujo de bytes
		token = readToken();

		tipoToken[token]++;
		mostrarCategoriaLexica(token);
	}

	printf("IDENTIFICADORES: %d\n", tipoToken[IDENTIFICADOR]);
	printf("CONSTANTES ENTERAS: %d\n", tipoToken[CONSTANTE]);
	printf("ERRORES: %d\n", tipoToken[ERROR]);
	return 0;
}
