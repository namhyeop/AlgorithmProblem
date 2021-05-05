#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int Testcase;

map<char, int> m;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> Testcase;

	int n;
	string input;
	while (Testcase--)
	{
		cin >> n;
		cin >> input;

		string input_list = input;
		sort(input_list.begin(), input_list.end());
		input_list.resize(unique(input_list.begin(), input_list.end()) - input_list.begin());

		for (auto i : input_list)
			m[i] = 0;
		
		bool flag = true;
		for (int i = 0; i < input.size(); i++)
		{
			if (m[input[i]] == 0)
				m[input[i]] = 1;
			else if (m[input[i]] == 1 && input[i - 1] == input[i])
				continue;
			else
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}
