/*
규칙을 찾기 위해 식을 대입하다보면 짝수마다 음수가 나오는 경우확인 가능
f(1) = f(0) + f(-1) -> f(-1) = 1;
f(0) = f(-1) + f(-2) -> f(-2) = -1;
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e6;
const int MOD = 1e9;
long long cache[MAX];
int n;
int main()
{
	cin >> n;
	
	cache[0] = 0;
	cache[1] = 1;

	for (int i = 2; i <= abs(n); i++)
	{
		cache[i] = (cache[i - 1] + cache[i - 2]) % MOD;
	}

	if (n == -1)
	{
		cout << 1 << "\n";
		cout << 1 << "\n";
		return 0;
	}
	else if (n < -1)
	{
		n *= -1;
		if (n % 2 == 0)
		{
			cout << -1 << "\n";
			cout << cache[n] << "\n";
		}
		else
		{
			cout << 1 << "\n";
			cout << cache[n] << "\n";
		}
		return 0;
	}
	else
	{
		if (cache[n] > 0)
		{
			cout << 1 << "\n";
			cout << cache[n] << "\n";
		}
		else if (cache[n] == 0)
		{
			cout << 0 << "\n";
			cout << 0 << "\n";
		}
	}
}
