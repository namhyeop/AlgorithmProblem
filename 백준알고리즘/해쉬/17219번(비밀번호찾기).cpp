#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

map<string, string> s;
int main(void)
{
	fastio;

	int n, m;
	cin >> n >> m;

	while (n--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		s[str1] = str2;
	}

	while (m--)
	{
		string str1;
		cin >> str1;
		cout << s[str1] << "\n";
	}
}
