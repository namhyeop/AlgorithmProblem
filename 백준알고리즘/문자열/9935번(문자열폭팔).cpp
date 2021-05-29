#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e6 + 1;
string ret;
string input;
int main(void)
{
	fastio;
	cin >> input;
	string explosives;
	cin >> explosives;
	
	int curidx = 0;
	int retidx = 0;
	for (int i = 0; i < input.size(); i++)
	{
		ret += input[curidx];
		bool flag = true;
		if (input[curidx] == explosives.back() && ret.size() >= explosives.size())
		{
			for (int j = 0; j < explosives.size(); j++)
			{
				if (ret[retidx - j] != explosives[explosives.size() - 1 - j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				for (int i = 0; i < explosives.size(); i++)
				{
					ret.pop_back();
					retidx--;
				}
			}
		}
		curidx++,retidx++;
	}
	if (!ret.size())
		cout << "FRULA" << "\n";
	else
		cout << ret << "\n";
}
