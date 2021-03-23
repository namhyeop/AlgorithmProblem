#include<bits/stdc++.h>

using namespace std;

int DP[1001][3];
int r[1001];
int g[1001];
int b[1001];
int n;

int main(void)
{
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> r[i] >> g[i] >> b[i];

	DP[1][0] = r[1];
	DP[1][1] = g[1];
	DP[1][2] = b[1];

	for (int i = 2; i <= n; i++)
	{
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + r[i];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + g[i];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1])  + b[i];
	}
	cout << *min_element(DP[n], DP[n] + 3);
}
