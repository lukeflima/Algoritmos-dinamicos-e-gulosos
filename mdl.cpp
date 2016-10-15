#include "mdl.h"
#include <iostream>

int max(int a, int b){
	return a>b? a:b;
}

/*
Seguindo a definição da função:
LCS(Xi,Yj) = 0, se i = 0 ou j = 0;
LCS(Xi,Yj) = LCS(X(i-1), Y(j-1)) + 1, se Xi = Yj;
LCS(Xi,Yj) = max(LCS(Xi, Y(j-1), LCS(X(i-1),Yj)), se Xi != Yj.
*/

int LCS(std::string s1, std::string s2){
	int x = s1.length(), y = s2.length();
	int L[x+1][y+1];
	for(int i = 0; i<=x; i++){
		for(int j = 0; j<=y; j++){
			if(!j || !i) L[i][j] = 0;
			else if(s1[i-1] == s2[j-1]) L[i][j] = L[i-1][j-1] + 1;
			else L[i][j] = max(L[i][j-1], L[i-1][j]);
		}
	}
	return L[x][y];
}