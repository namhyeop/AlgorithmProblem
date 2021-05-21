#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int m;
int main(void)
{
	fastio;
	cin >> m;

	int tmp = 0;
	while (m--)
	{
		string str;
		int num;
		cin >> str;

		if (str == "add")
		{
			cin >> num;
			tmp |= (1 << num);
		}
		else if (str == "remove")
		{
			cin >> num;
			tmp &= ~(1 << num);
		}
		else if (str == "check")
		{
			cin >> num;
			int check = tmp & (1 << num);
			if (check)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (str == "toggle")
		{
			cin >> num;
			tmp ^= (1 << num);
		}
		else if (str == "all")
		{
			tmp = (1 << 21) - 1;
		}
		else if (str == "empty")
		{
			tmp = 0;
		}
	}
}
