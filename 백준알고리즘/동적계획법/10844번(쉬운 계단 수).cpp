#include<bits/stdc++.h>

using namespace std;
const int MAX = 101;
const int mod = 1e9;
int cache[MAX][11];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
		cache[1][i] = 1;


	for (int i = 2; i <= n; i++)
	for (int j = 0; j <= 9; j++)
	{
		if (j == 0)
			cache[i][0] = cache[i - 1][1] % mod;
		else if (j == 9)
			cache[i][9] = cache[i - 1][8] % mod;
		else
			cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % mod;
	}

	int ret = 0;
	for (int i = 1; i <= 9; i++)
		ret = (ret + cache[n][i]) % mod;

	cout << ret % mod<< "\n";
}

/*#include<iostream>

using namespace std;

int main(int argc, char * argv[])
{
	int n;
	int cache[101][10];
	int ret = 0;

	cin >> n;

	for (int i = 0; i < 10; i++)
		cache[1][i] = 1;
	
	for (int i = 2; i <= n; i++)
	for (int j = 0; j < 10; j++)	
	{
		if (j == 9)
			cache[i][j] = cache[i - 1][8] % 1000000000;
		else if (j == 0)
			cache[i][j] = cache[i - 1][1] % 1000000000;
		else
			cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % 1000000000;
	}

		for (int i = 1; i < 10; i++)
			ret = (ret+cache[n][i]) % 1000000000;

		cout << ret  << endl;

		return 0;
}
*/
