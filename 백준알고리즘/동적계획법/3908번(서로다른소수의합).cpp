#include<bits/stdc++.h>
#define MAX 1120
using namespace std;

int Testcase;

bool visited[MAX + 1];
//int tmpboard[MAX + 1];
vector<int> prime;
int primeSize;
int cache[MAX + 1][15];

int main(void)
{
	cin >> Testcase;

	/*에라토스테네스의 체를 만드는 방법 1
	for (int i = 2; i < MAX; i++)5
		tmpboard[i] = i;
	
	for (int i = 2; i <= MAX; i++)
	{
		if (tmpboard[i] == 0)
			continue;
		for (int j = i + i; j <= MAX; j += j)
			tmpboard[j] = 0;
	}
	for (int i = 2; i <= MAX; i++)
	{
		if (tmpboard[i])
			prime.push_back(true);
	}*/

	//에라토스테스의 체를 만드는 방법 2 (제곱근으로 범위를 줄여 더 빠름)
	int sqrt_value = (int)sqrt(MAX);
	for (int i = 2; i <= sqrt_value; i++)
	{
		if (visited[i] == false)
		{
			for (int j = i * i; j <= 1120; j += i)
				visited[j] = true;
		}
	}
	for (int i = 2; i <= MAX; i++)
	{
		if (!visited[i])
			prime.push_back(i);
	}

	primeSize = prime.size();
	cache[0][0] = 1;
	for (int i = 0; i < primeSize; i++)
	{
		for (int j = MAX; j >= prime[i]; j--)
		{
			for (int k = 1; k <= 14; k++)
			{
				cache[j][k] += cache[j - prime[i]][k - 1];
			}
		}
	}

	while (Testcase--)
	{
		int n, k;
		cin >> n >> k;
		cout << cache[n][k] << "\n";
	}
	return 0;

}
