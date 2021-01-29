#include<iostream>
#include<vector>
#define MAX 4001
using namespace std;

int n, m;
int frien[MAX];
bool visited[MAX][MAX];

int main(int argc, char * argv[])
{
	cin >> n >> m;
	int ans = -1;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		frien[a] += 1;
		frien[b] += 1;
		visited[a][b] = true;
		visited[b][a] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (visited[i][j])
			{
				for (int k = j + 1; k <= n; k++)
				{
					if (visited[i][k] && visited[j][k])
					{
						int sum = frien[i] + frien[j] + frien[k] - 6;
						if (ans == -1 || ans > sum)
							ans = sum;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
