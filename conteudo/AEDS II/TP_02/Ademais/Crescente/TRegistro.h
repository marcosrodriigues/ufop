#ifndef __TREGISTRO_H_INCLUDED__
#define __TREGISTRO_H_INCLUDED__

//Definição de um item do arquivo de dados
typedef struct {
	long matricula;
	float nota;
	char estado[3];
	char cidade[51];
	char curso[31];
} TRegistro;

#endif
