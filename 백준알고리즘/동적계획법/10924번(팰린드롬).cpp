#include<bits/stdc++.h>

using namespace std;
const int MAX = 2001;
int n,m;
int arr[MAX];
bool cache[MAX][MAX]; // i ~j까지의 팰린드롬이 true인가 false인가

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> m;

	//길이가 1인 경우의 팰린드롬
	for (int i = 1; i <= n; i++)
		cache[i][i] = true;

	//길이가 2인 경우의 팰린드롬
	for (int i = 1; i < n; i++)
	if (arr[i] == arr[i + 1])
		cache[i][i + 1] = true;

	//길이가 3이상인 경우의 팰린드롬
	for (int i = 2; i < n; i++)//i를 활용해서 길이가 3,4,5...뒤에 있는것이 같은지 확인
	{
		for (int j = 1; j <= n - i; j++)
		{
			//앞 뒤가 같고 앞 뒤 사이에 있는 수가 팰린드롬인가
			if (arr[j] == arr[j + i] && cache[j + 1][j + i - 1])
				cache[j][j + i] = true;
		}

				/*for (int i = 0; i <= n; i++)
				{
					for (int j = 0; j <= n; j++)
					{
						printf("%2d ", cache[i][j]);
					}
					cout << "\n";
				}
				cout << "\n";*/
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		
		cout << cache[start][end] << "\n";
	}
	return 0;
}
