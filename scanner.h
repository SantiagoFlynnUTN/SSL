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

#define ESTADOFINARCHIVO 10
#define CENTINELA 11

/* enumera las posibles categorias lexicas */
typedef enum{SPACE, IDENTIFICADOR, CONSTANTE, ERROR, FINARCHIVO} lexicalCategory_t;

lexicalCategory_t _tipoCaracter(char c);

#endif /* SCANNER_H_ */

