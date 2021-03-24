#include<bits/stdc++.h>

using namespace std;
const int MAX = 41;
int arr[41];
int cache[41];
int n,m;
int VIP[MAX];
int main(void)
{
	cin >> n;
	cin >> m;
	cache[0] = 1;
	cache[1] = 1;

	for (int i = 2; i <= n; i++)
		cache[i] = cache[i - 1] + cache[i - 2];

	for (int i = 1; i <= m ; i++)
	{
		int tmp;
		cin >> tmp;
		VIP[i] = tmp;
	}

	int ret = 1;
	for (int i = 1; i <= m; i++)
	{
		ret *= cache[VIP[i] - VIP[i - 1] - 1];
	}
	ret *= cache[n - VIP[m]];

	cout << ret << "\n";
	return 0;
}
