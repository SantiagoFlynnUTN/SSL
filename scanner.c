#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

typedef enum{ESPACIO, ID, NUMERO, OTRO, FINAL, ESTADOFINAL = 10, ESTADOIDENTIFICADOR, ESTADOCONSTANTE, ESTADOERROR} estados_t;

static char _matrizDeEstados[4][5] = {
		{ESPACIO, 				ID, 				NUMERO, 		OTRO, 					ESTADOFINAL},
		{ESTADOIDENTIFICADOR, 	ID, 				ID, 			ESTADOIDENTIFICADOR, 	ESTADOIDENTIFICADOR},
		{ESTADOCONSTANTE, 		ESTADOCONSTANTE, 	NUMERO, 		ESTADOCONSTANTE, 		ESTADOCONSTANTE},
		{ESTADOERROR, 			ESTADOERROR, 		ESTADOERROR, 	OTRO, 					ESTADOERROR}
};

estados_t _tipoCaracter(char c);
int _estadoConCentinela(estados_t estado);
lexicalCategory_t _estadoToToken(estados_t estado);

/* Devuelve el lexema al que pertenece el caracter*/
estados_t _tipoCaracter(char c){
	int tipoChar = OTRO;
	if (isspace(c)) tipoChar = ESPACIO;
	if (islower(c)) tipoChar = ID;
	if (isdigit(c)) tipoChar = NUMERO;
	if (c == EOF) tipoChar = FINAL;
	return tipoChar;
}

lexicalCategory_t readToken(){
	estados_t estadoActual = 0;
	char c;
	while(estadoActual < ESTADOSACEPTORES){	//lee cada token
		c = getchar();
		estadoActual = _matrizDeEstados[estadoActual][_tipoCaracter(c)];
	}

	if (_estadoConCentinela(estadoActual)){
		ungetc(c, stdin);
	}

	return _estadoToToken(estadoActual);
}

int _estadoConCentinela(estados_t estado){
	return estado - ESTADOSACEPTORES;
}


lexicalCategory_t _estadoToToken(estados_t estado){
	return estado - ESTADOSACEPTORES;
}
