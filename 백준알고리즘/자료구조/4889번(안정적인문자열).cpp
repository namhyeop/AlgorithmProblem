#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	string input;
	int cycleNum = 1;
	while (1)
	{
		cin >> input;
		if (input[0] == '-')
			return 0;
		stack<char> s;
		int cnt = 0;
		for (int i = 0; i < input.size(); i++)
		{
			if (s.empty() && input[i] == '}')
			{
				input[i] == '{';
				s.push(input[i]);
				cnt++;
			}
			else if (!s.empty() && input[i] == '}')
			{
				s.pop();
			}
			else
				s.push(input[i]);
		}
		cnt += s.size() / 2;
		cout << cycleNum << ". " << cnt << "\n";
		cycleNum++;
	}
}
