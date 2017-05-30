#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

static char word[MAXWORDLENGTH];

static char * _readWord();
static lexicalCategory_t _checkToken(char * word);
static int _isIntegerConstant(char * word);
static int _isIdentifier(char * word);

/* reads from standard input until a whitespace or EOF appears.
 * returns a pointer to the first char of the word.
 */
static char * _readWord(){
	int i = 0;
	while(i < MAXWORDLENGTH && !isspace(word[i] = getchar()) && word[i++] != EOF)
		;

	word[i] = '\0';
	return word;
}


/* reads a word and returns its lexicalCategory */
lexicalCategory_t readToken(){
	return _checkToken(_readWord());
}


/* returns the lexical category of the word pointed by the parameter
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


/* checks if the word pointed by the char pointer parameter is an integer constant.
 *  returns 0 if not.
 */
static int _isIntegerConstant(char * word){
	while(isdigit(*word) && *(word++) != '\0')
		;

	return *word == '\0';
}

/* checks if the word pointed by the car pointer parameter is an identifier.
 * returns 0 if not.
 * an identifier must start with a lowercase letter followed (optionally) by other lowercase letters or digits.
 */
static int _isIdentifier(char * word){
	if(islower(*word)){
		while((isdigit(*word) || islower(*word)) && *(word++) != '\0')
			;
	}

	return *word == '\0';
}
