/*
 * scanner.h
 *
 *  Created on: 30/5/2017
 *      Author: utnso
 */

#ifndef SCANNER_H_
#define SCANNER_H_

/* defines the longest word allowed */
#define MAXWORDLENGTH 100

/* enumartion type for the lexical categories recognized */
typedef enum{IDENTIFICADOR, CONSTANTE, ERROR} lexicalCategory_t;

/* reads a word and returns its lexicalCategory */
lexicalCategory_t readToken();

#endif /* SCANNER_H_ */

