#include<bits/stdc++.h>

using namespace std;

int Testcase;
int n;

void backtrack(int level, int sign, int sum, int num, string str)
{
	if (n == level)
	{
		sum += (num * sign);
		if (sum == 0)
			cout << str << "\n";
	}
	else
	{
		backtrack(level + 1, sign, sum, num * 10 + (level + 1), str + ' ' + char(level + 1 + '0'));
		backtrack(level + 1, 1, sum + (sign * num), level + 1, str + '+' + char(level + 1 + '0'));
		backtrack(level + 1, -1, sum + (sign * num), level + 1, str + '-' + char(level + 1 + '0'));
	}
}
int main()
{
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> n;
		backtrack(1, 1, 0, 1, "1");
		cout << "\n";
	}
	return 0;
}
