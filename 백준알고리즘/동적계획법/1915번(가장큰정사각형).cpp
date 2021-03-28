#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int cache[MAX][MAX];
string arr[MAX];
int n, m;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int side = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (i == 0 || j == 0)
			cache[i][j] = arr[i][j] - '0';
		else if (arr[i][j] == '1')
			cache[i][j] = min(min(cache[i][j - 1], cache[i - 1][j - 1]), cache[i - 1][j]) + 1;
		side = max(side, cache[i][j]);

		/*경로 확인
		cout << side <<" i: "<< i << " j: " << j << "\n";
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				printf("%2d ", cache[i][j]);
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	}

	cout << side * side <<"\n";
	return 0;
}
