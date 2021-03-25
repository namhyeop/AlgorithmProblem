#include<bits/stdc++.h>

using namespace std;
const long long MOD = 1000000007;
const int MAX = 1516;
int n;
long long cache[3][MAX];

int main()
{
	cin >> n;

	if (n == 1)
	{
		cout << 0 << "\n";
		return 0;
	}

	cache[0][2] = 1;
	cache[1][2] = 1;

	for (int i = 3; i <= n; i++)
	{
		cache[0][i] = (cache[1][i - 1] + cache[2][i - 1]) % MOD;
		cache[1][i] = (cache[0][i - 1] + cache[2][i - 1]) % MOD;
		cache[2][i] = (cache[0][i - 1] + cache[1][i - 1]) % MOD;
	}
	
	cout << cache[0][n] << "\n";
}
/*
조건: 끝이 5로 끝나야 되고, 각 자릿수의 합을 3으로 나눈게 0이어야 함.


<정의>
dp[i][j] : 위 조건을 만족하면서 각 자릿수의 합을 3으로 나눈 나머지가 i이고, j자리인 수의 개수


<기저사례>
dp[0][2] : 1 (15가 가능)
dp[1][2] : 1 (55가 가능)


<점화식>
dp[i][j] = dp[(i+1)%3][j-1] + dp[(i+2)%3][j-1]
*/
