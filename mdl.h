#ifndef __MDL_H__
#define __MDL_H__
/*
Retorna o maior entre dois inteiros.
Parametros: Numeros a serem comparados.
*/
int max(int a, int b);

/*
Aluno: Lucas Ferreira Lima - 11406537
Encontra a maior subsequência comum a duas sequências X e Y, i.e uma 
subsequência de uma sequência X de caracteres pode ser obtida removendo alguns 
caracteres dessa sequência.

Parametros: Subsequêcias a serem comparadas.
*/
int LCS(std::string s1, std::string s2);

bool SSP(std::vector<int> set, int sum);

#endif //__MDL_H_