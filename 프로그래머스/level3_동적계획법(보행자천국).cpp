#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

const int MAX = 501;
int MOD = 20170805;

int downV[MAX][MAX];
int rightV[MAX][MAX];

int solution(int m, int n,vector<vector<int>> city_map)
{
	memset(downV, 0, sizeof(downV));
	memset(rightV, 0, sizeof(rightV));
	downV[1][1] = rightV[1][1] = 1;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (city_map[i - 1][j - 1] == 0)
			{
				downV[i][j] += (downV[i - 1][j] + rightV[i][j - 1]) % MOD;
				rightV[i][j] += (downV[i - 1][j] + rightV[i][j - 1]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 1)
			{
				downV[i][j] = 0;
				rightV[i][j] = 0;
			}
			else
			{
				downV[i][j] = downV[i - 1][j];
				rightV[i][j] = rightV[i][j - 1];
			}
		}
	}

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << city_map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//for (int i = 0; i <= m; i++)
	//{
	//	for (int j = 0; j <= n; j++)
	//	{
	//		cout << downV[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	//cout << "\n";
	//for (int i = 0; i <= m; i++)
	//{
	//	for (int j = 0; j <= n; j++)
	//	{
	//		cout << rightV[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	return (downV[m][n] % MOD);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 6;
	int m = 3;
	vector<vector<int>> v = { {0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0} };
	cout << solution(m, n, v) << "\n";
	int n1 = 3;
	int m1 = 3;
	vector<vector<int>> v1 = { { 0, 0, 0}, { 0, 0, 0 }, { 0, 0, 0 } };
	cout << solution(m1, n1, v1);
}
