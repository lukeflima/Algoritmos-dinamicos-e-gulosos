#include <vector>
#include <string>

#ifndef __MDL_H__
#define __MDL_H__
/*
Retorna o maior entre dois inteiros.
Parametros: Numeros a serem comparados.
*/
int max(int, int);

int min(int, int, int);

/*
Aluno: Lucas Ferreira Lima - 11406537
Encontra a maior subsequência comum a duas sequências X e Y, i.e uma 
subsequência de uma sequência X de caracteres pode ser obtida removendo alguns 
caracteres dessa sequência.

Parametros: Subsequêcias a serem comparadas.
*/
int LCS(std::string, std::string);

/*
Aluno: Lucas Ferreira Lima - 11406537
Encotra em um dado conjunto de inteiros positivos se existe algum subconjunto 
cujo a soma é sum.

Parametros: Vector com conjunto de inteiros positivos e soma que deseja ser
			comparada.
*/
bool SSP(std::vector<int> , int);

/*

*/
int DDP(std::string, std::string, int, int);

#endif //__MDL_H_