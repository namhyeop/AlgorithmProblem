#include<bits/stdc++.h>

using namespace std;

int main()
{
	string input;
	cin >> input;

	stack<int> s;
	bool laserFlag = false;
	int cnt = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			s.push('(');
			laserFlag = true;
		}
		else if (!s.empty() && input[i] == ')' && s.top() == '(' && laserFlag == true)
		{
			if (s.empty())
			{
				laserFlag = false;
				continue;
			}
			cnt += s.size() - 1;
			laserFlag = false;
			s.pop();
		}
		else if (input[i] == ')' && s.top() == '(' && laserFlag == false)
		{
			s.pop();
			cnt += 1;
		}
	}
	cout << cnt << "\n";
}
