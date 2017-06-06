#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

lexicalCategory_t _tipoCaracter(char c);

/* Devuelve el lexema al que pertenece el caracter*/
lexicalCategory_t _tipoCaracter(char c){
	int tipoChar = ERROR;
	if (isspace(c)) tipoChar = SPACE;
	if (islower(c)) tipoChar = IDENTIFICADOR;
	if (isdigit(c)) tipoChar = CONSTANTE;
	if (c == EOF) tipoChar = FINARCHIVO;
	return tipoChar;
}

