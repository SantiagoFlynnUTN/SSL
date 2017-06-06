#include <stdio.h>
#include "scanner.h"

static int tipoToken[3];

char matrizDeEstados[4][5] = {
		{0, 1, 2, 3, 10},
		{11, 1, 1, 11, 11},
		{11, 11, 2, 11, 11},
		{11, 11, 11, 3, 11}
};

void mostrarCategoriaLexica(lexicalCategory_t estado, lexicalCategory_t * tipoToken){
	switch (estado){
		case SPACE: printf("\nNo se encontraron más tokens para leer\n");
		break;
		case IDENTIFICADOR: printf("\nIdentificador. Total: %i\n", tipoToken[IDENTIFICADOR]);
		break;
		case CONSTANTE: printf("\nConstante. Total: %i\n", tipoToken[CONSTANTE]);
		break;
		case ERROR: printf("\nError. Total: %i\n", tipoToken[ERROR]);
		break;
	}
}

int main(){
	int estadoAnterior, c;
	int estadoActual = 0;
	while(estadoActual != 10){	//lee el flujo de bytes
		estadoActual = 0;

		while(estadoActual < 10){	//lee cada token
			estadoAnterior = estadoActual;
			c = getchar();
			estadoActual = matrizDeEstados[estadoAnterior][_tipoCaracter(c)];
		}

		if (estadoActual == CENTINELA){
			ungetc(c, stdin);
			tipoToken[estadoAnterior]++;
		}

		mostrarCategoriaLexica(estadoAnterior, tipoToken);
	}

	printf("IDENTIFICADORES: %d\n", tipoToken[IDENTIFICADOR]);
	printf("CONSTANTES ENTERAS: %d\n", tipoToken[CONSTANTE]);
	printf("ERRORES: %d\n", tipoToken[ERROR]);
	return 0;
}
