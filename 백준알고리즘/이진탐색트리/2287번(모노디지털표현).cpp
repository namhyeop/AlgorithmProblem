#include<iostream>
#include<set>
#include<bits\stdc++.h>
using namespace std;

typedef long long ll;

set<int> dp[9];

int check(int n)
{
	for (int i = 1; i <= 8; i++)
	{
		if (dp[i].count(n))
			return i;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int k;
	int Testcase;
	int n;
	
	cin >> k;
	cin >> Testcase;

	int num = 0;

	for (int i = 1; i <= 8; i++)
	{
		num = 10 * num + k; 
		dp[i].insert(num);
	}

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int count = i + j;
			if (count > 8)
				continue;

			for (int a : dp[i])
			{
				for (int b : dp[j])
				{
					dp[count].insert(a + b);
					dp[count].insert(abs(a - b));
					dp[count].insert(a * b);
					if (b != 0)
						dp[count].insert(a / b);
					if (a != 0)
						dp[count].insert(b / a);
				}
			}
		}
	}

	for (int i = 0; i < Testcase; i++)
	{
		cin >> n;
		int ret = check(n);
		if (ret)
			cout << ret << "\n";
		else
			cout << "NO\n";
	}
} 
