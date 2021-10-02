#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int t;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		int num;
		string str;
		cin >> num >> str;

		for (int k = 0; k < sz(str); k++)
		{
			for (int i = 0; i < num; i++)
				cout << str[k];
		}
		cout << "\n";
	}
}
