#include<bits/stdc++.h>

#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

const int MAX = 1001;

int n, k;
int cache[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	cache[0][0] = 1;
	cache[1][0] = 1;
	cache[1][1] = 1;

	for (int i = 2; i < MAX; i++)
	for (int j = 0; j <= i; j++)
	{
		cache[i][j] = (cache[i - 1][j-1] + cache[i - 1][j]) % 10007;
	}

	cout << cache[n][k] % 10007 << "\n";
}

/*
#include<iostream>
#include<cstring>

using namespace std;

int cache[1001][1001];
int mod = 10007;
int search(int n, int k)
{
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= k; j++)
	{
		if (i == j || j == 0)
			cache[i][j] = 1;
		else
		cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j]) % mod;
	}

	return cache[n][k];
}

int main(int argc, char * argv[])
{
	int n,k;
	cin >> n >> k;
	
	memset(cache, 0, sizeof(cache));
	cout << search(n, k) << endl;
	
	return 0;
}
*/
