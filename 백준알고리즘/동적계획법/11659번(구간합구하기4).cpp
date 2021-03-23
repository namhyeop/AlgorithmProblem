#include<bits/stdc++.h>

using namespace std;

int cache[100001];
int arr[100001];
int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		cache[i] = cache[i - 1] + arr[i];
	}

	while (m--)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		cout << cache[tmp2] - cache[tmp1 -1] << "\n";
	}

	return 0;
}
