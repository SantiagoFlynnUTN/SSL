#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

static char word[MAXWORDLENGTH];

static char * _readWord();
static lexicalCategory_t _checkToken(char * word);
static int _isIntegerConstant(char * word);
static int _isIdentifier(char * word);

/* lee del standard input hasta que un espacio o EOF aparece.
 * retorna el puntero a la palabra que encontró.
 */

static char * _readWord(){
	int i = 0;

	while(i < MAXWORDLENGTH && !isspace(word[i] = getchar()) && word[i++] != EOF)
		;

	word[i] = '\0';
	return word;
}


/* Lee una palabra y retorna su categoría léxica */
lexicalCategory_t readToken(){
	return _checkToken(_readWord());
}


/* retorna la categoría lexica de la palabra apuntada como parámetro
 */
static lexicalCategory_t _checkToken(char * word){
	if(_isIdentifier(word)){
		return IDENTIFICADOR;
	}

	if(_isIntegerConstant(word)){
		return CONSTANTE;
	}

	return ERROR;
}


/* chequea si la palabra aputnada por el parametro es una constante entera.
 * return 0 si no lo es.
 */
static int _isIntegerConstant(char * word){
	while(isdigit(*word) && *(word++) != '\0')
		;

	return *word == '\0';
}

/* chequea si la palabra aputnada por el parametro es un identificador.
 * return 0 si no.
 * un identificador debe empezar con una letra minuscula y seguirle (opcionalmente) otra minuscula o un dígito.
 */

static int _isIdentifier(char * word){
	if(islower(*word)){
		while((isdigit(*word) || islower(*word)) && *(word++) != '\0')
			;
	}

	return *word == '\0';
}
