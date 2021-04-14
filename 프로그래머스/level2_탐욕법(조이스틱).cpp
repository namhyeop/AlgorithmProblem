#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 20;

int solution(string name)
{
	int answer = 0;

	int num[MAX];
	int i, j, left, right, lidx, ridx, change = 0;

	for (i = 0; i < name.length(); i++)
	{
		char target = name[i];
		num[i] = min(target - 'A', 'Z' - target + 1);
		if (num[i] != 0)
			change++;
		answer += num[i];
	}

	i = 0;
	int pos = 0;

	if (num[i] != 0)
	{
		num[i] = 0;
		change--;
	}

	while (change > 0)
	{
		for (i = pos + 1; i < name.length(); i++)
		{
			if (num[i] != 0)
				break;
		}


		right = i - pos;
		ridx = i;

		for (i = pos - 1; i >= 0; i--)
		if (num[i] != 0)
			break;

		if (i < 0)
		{
			for (j = name.length() - 1; j > pos; j--)
			if (num[j] != 0)
				break;
			left = pos + (name.length() - j);
			lidx = j;
		}
		else
		{
			left = pos - i;
			lidx = i;
		}

		if (left > right)
		{
			answer += right;
			num[ridx] = 0;
			pos = ridx;
		}
		else
		{
			answer += left;
			num[lidx] = 0;
			pos = lidx;
		}

		change--;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a("JAANN");

	cout << solution(a);
}
