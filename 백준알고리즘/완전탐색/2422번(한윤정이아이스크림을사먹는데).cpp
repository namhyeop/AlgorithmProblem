#include<iostream>
#define MAX 201
using namespace std;

int n, m;
bool check[MAX][MAX];

int main(int argc, char *argv[])
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		check[tmp1][tmp2] = check[tmp2][tmp1] = true;
	}

	int ret = 0;

	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
	for (int k = j + 1; k <= n; k++)
	{
		if (check[i][j] || check[i][k] || check[j][k])
			continue;
		ret++;
	}

	cout << ret << "\n";

	return 0;
}
