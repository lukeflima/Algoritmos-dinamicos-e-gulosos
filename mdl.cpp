#include "mdl.h"


int max(int a, int b)
{
	return a>b? a:b;
}

int min(int a, int b, int c)
{
	return a < b ? (a < c ? a:c): (b < c ? b:c);
}

/*
Seguindo a definição da função:
LCS(Xi,Yj) = 0, se i = 0 ou j = 0;
LCS(Xi,Yj) = LCS(X(i-1), Y(j-1)) + 1, se Xi = Yj;
LCS(Xi,Yj) = max(LCS(Xi, Y(j-1), LCS(X(i-1),Yj)), se Xi != Yj.
*/
int LCS(std::string s1, std::string s2)
{
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

/*
Seguindo a definição da função:
SSP(set, n, sum) = false, se sum > 0 e n = 0;
SSP(set, n, sum) = true, se sum = 0;
SSP(set, n, sum) = SSP(set, n-1, sum) || SSP(set, n-1, sum-set[n-1]), caso contrario.
*/
bool SSP(std::vector<int> set, int sum)
{
	int n = set.size();
	bool subset[sum+1][n+1];

	for(int i = 0; i <= n; ++i) subset[0][i] = true;

	for(int i = 0; i <= sum; ++i) subset[i][0] = false;

	for(int i = 1; i <= sum; ++i)
		for(int j = 1; j <= n; ++j){
			subset[i][j] = subset[i][j-1];
			if(i >= set[j-1]) subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
		}

	return subset[sum][n];
}

int DDP(std::string str1, std::string str2, int m, int n)
{
    int dp[m+1][n+1];    
    for (int i=0; i<=m; i++)
        for (int j=0; j<=n; j++)      
            if (i==0) dp[i][j] = j;    
            else if (j==0) dp[i][j] = i;            
            else if (str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]); 

    return dp[m][n];
}