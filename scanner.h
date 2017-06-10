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

#define ESTADOSACEPTORES 10

/* enumera las posibles categorias lexicas */
typedef enum{FINARCHIVO, IDENTIFICADOR, CONSTANTE, ERROR, INICIO} lexicalCategory_t;


lexicalCategory_t readToken();

#endif /* SCANNER_H_ */

