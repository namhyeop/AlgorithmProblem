#include<bits/stdc++.h>

using namespace std;

int k;
int main(void)
{
	cin >> k;

	stack<int> s;
	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == 0)
		{
			if (s.size() == 0)
				continue;
			s.pop();
		}
		else
			s.push(tmp);
	}

	int ret = 0;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		ret += s.top();
		s.pop();
	}
	cout << ret << "\n";
	
	return 0;
}
