#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long


using namespace std;

map<char, char> m;

int solution(string s)
{
	m['('] = ')';
	m['['] = ']';
	m['{'] = '}';

	auto f = [&](string s) -> bool
	{
		stack<char> S;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (S.empty())
					return 0;
				if (s[i] != m[S.top()])
					return 0;
				S.pop();
			}
			else
				S.push(s[i]);
		}
		return S.empty();
	};

	int ret = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ret += f(s);
		s.push_back(s[0]);
		s.erase(0, 1);
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s = "(){{]]";
	cout << solution(s) << "\n";
}
