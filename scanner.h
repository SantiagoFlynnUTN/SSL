/*
 * scanner.h
 *
 *  Created on: 30/5/2017
 *      Author: utnso
 */

#ifndef SCANNER_H_
#define SCANNER_H_

/* define el tamaño maximo de la string */
#define MAXWORDLENGTH 100

/* enumera las posibles categorias lexicas */
typedef enum{IDENTIFICADOR, CONSTANTE, ERROR} lexicalCategory_t;

/* lee una palabra y retorna su categoría léxica */
lexicalCategory_t readToken();

#endif /* SCANNER_H_ */

