#include<bits/stdc++.h>

using namespace std;
const int MAX = 1025;
int cache[MAX][MAX];
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	int tmp;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> tmp;
		cache[i + 1][j + 1] = cache[i][j + 1] + cache[i + 1][j] - cache[i][j] + tmp;
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << cache[y2][x2] - cache[y2][x1 - 1] - cache[y1 - 1][x2] + cache[y1 - 1][x1 - 1] << "\n";
	}

	return 0;
}
