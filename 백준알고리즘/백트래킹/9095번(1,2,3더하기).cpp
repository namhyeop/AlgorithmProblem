#include<bits/stdc++.h>

using namespace std;

int Goal, cnt;

void func(int sum, int level)
{
	if (sum == Goal)
	{
		cnt++;
		return;
	}

	if (sum > Goal)
		return;

	for (int i = 1; i < 4; i++)
		func(sum + i, level + 1);
}

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> Goal;
		cnt = 0;
		func(0,0);
		cout << cnt << "\n";
	}

}
