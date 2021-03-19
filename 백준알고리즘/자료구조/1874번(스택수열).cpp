#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;
int n;
int arr[MAX];
int main()
{
	cin >> n;

	int cur = 1;
	string ret;
	stack<int> s;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n + 1; i++)
	{
		if (!s.empty())
		{
			if (arr[cur] == s.top())
			{
				while (!s.empty() && arr[cur] == s.top())
				{
					s.pop();
					cur++;
					ret += '-';
				}
			}
		}

		if (i != n + 1)
		{
			s.push(i);
			ret += '+';
		}
	}

	if (!s.empty())
		cout << "NO" << "\n";
	else
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";

	return 0;

}
