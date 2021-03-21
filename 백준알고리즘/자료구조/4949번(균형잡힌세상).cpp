#include<bits/stdc++.h>

using namespace std;

int main()
{
	while (1)
	{
		string input;
		getline(cin, input);
		if (input == ".")
			break;

		stack<char> s;
		bool isValid = true;
		for (auto c : input)
		{
			if (c == '(' || c == '[')
				s.push(c);
			else if (c == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					isValid = false;
					break;
				}
				s.pop();
			}
			else if (c == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					isValid = false;
					break;
				}
				s.pop();
			}
		}

		if (!s.empty())
			isValid = false;
		if (isValid)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
