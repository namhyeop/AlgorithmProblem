#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const long long MAX = 2*1e6;
int Testcase;
bool visited[MAX + 1];
vector<long long> primeV;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> Testcase;

	
	visited[1] = true;
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		if (!visited[i])
		{
			for (int j = i * i; j <= MAX; j+=i)
				visited[j] = true;
		}
	}

	for (int i = 2; i <= MAX; i++)
	if (!visited[i])
		primeV.push_back(i);

	for (int i = 0; i < Testcase; i++)
	{
		long long num1, num2;
		cin >> num1 >> num2;
		long long sum = num1 + num2;
		bool check = false;
		if (sum < 4)
		{
			cout << "NO" << "\n";
			continue;
		}
		if (sum % 2 == 0)
		{
			cout << "YES" << "\n";
		}
		else
		{
			long long searchValue = sum - 2;

			for (int j = 0; j < primeV.size() && primeV[j] * primeV[j] <= searchValue; j++)
			{
				//소수의 곱셈은 소수가 아니다. 에라토스테네스의 체를 만들때를 기억하자 
				if (searchValue % primeV[j] == 0)
				{
					check = true;
					cout << "NO" << "\n";
					break;
				}
			}
			if (!check)
				cout << "YES" << "\n";
		}
	}
}
