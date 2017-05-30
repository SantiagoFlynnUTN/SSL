#include <stdio.h>
#include "scanner.h"

static int tokensRead[3] = {0,0,0};

int main(){
	char control;
	while((control = getchar()) != EOF){ /* checks if there is more input */
		ungetc(control, stdin); /* returns a char to standard input */

		lexicalCategory_t lexicalCategory = readToken();

		if(lexicalCategory == IDENTIFICADOR){
			tokensRead[0]++;
			printf("IDENTIFICADOR\n");
		}else if(lexicalCategory == CONSTANTE){
			tokensRead[1]++;
			printf("CONSTANTE ENTERA\n");
		}else{
			tokensRead[2]++;
			printf("ERROR\n");
		}
	}

	printf("IDENTIFICADORES: %d\n", tokensRead[0]);
	printf("CONSTANTES ENTERAS: %d\n", tokensRead[1]);
	printf("ERRORES: %d\n", tokensRead[2]);
}
