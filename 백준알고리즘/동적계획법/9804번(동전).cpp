#include<bits/stdc++.h>

using namespace std;
const int MAX = 21;

int Testcase;
int n;
int arr[MAX];
int cache[MAX][10001];
int main(void)
{
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int goalValue;
		//memset(cache, 0, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		cin >> goalValue;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= goalValue; j++)
			{
				if (j == arr[i])
					cache[i][j] = 1;
				else
					cache[i][j] = 0;
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			int coin = arr[i];
			for (int j = coin + 1; j <= goalValue; j++)
			{
				int cnt = 0;
				for (int k = 0; k <= i; k++)
				{
					cnt += cache[k][j - coin];
				}
				cache[i][j] = cnt;
			}
		}

		int ret = 0;
		for (int i = 0; i < n; i++)
			ret += cache[i][goalValue];
		
		cout << ret << "\n";
	}
}
/*
1
2
10 20
30
*/
