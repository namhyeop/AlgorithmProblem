#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 1e6 * 4;

int arr[MAX + 1];
bool visited[MAX + 1];
vector<int> primeV;
int n;
int ret;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (!visited[i])
		{
			for (int j = i*i; j <= n; j += i)
			{
				visited[j] = true;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	if (!visited[i])
		primeV.push_back(i);

	int left = 0, right = 0;
	int sum = 0;
	while (1)
	{
		if (sum >= n)
		{
			sum -= primeV[left++];
		}
		else if (right == primeV.size())
			break;
		else
			sum += primeV[right++];

		if (sum == n)
			ret++;
	}
	/*
	시간초과발생 투 포인터 슬라이딩 으로 해결해야함 입력값은 1000000이면 n안에 해결해야한다
	for (int i = 0; i < primeV.size(); i++)
	{
		int sum = 0;
		for (int j = i; j < primeV.size(); j++)
		{
			if (sum < n)
				sum += primeV[j];
		}

		if (sum == n)
			ret++;
	}*/

	cout << ret << "\n";

	return 0;
}
