#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
const int mod = 1e9 + 3; 
int cache[MAX][MAX];
int n, k;

int main()
{
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
	{
		cache[i][1] = i;
		cache[i][0] = 1;
	}

	for (int i = 2; i <= n; i++)
	for (int j = 2; j <= k; j++)
		cache[i][j] = (cache[i - 2][j - 1] + cache[i - 1][j]) % mod;

	int ans = (cache[n - 1][k] + cache[n - 3][k - 1]) % mod;
	cout << ans << "\n";

	return 0;
}
