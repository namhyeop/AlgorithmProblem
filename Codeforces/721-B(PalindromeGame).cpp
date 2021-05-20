#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int Testcase;

int main(void)
{
	fastio;
	cin >> Testcase;

	while (Testcase--)
	{
		int strSize;
		string str;
		cin >> strSize >> str;

		int zeroCnt = 0;
		for (int i = 0; i < strSize; i++)
		{
			if(str[i] == '0')
			zeroCnt++;
		}
		if (zeroCnt == 1 || zeroCnt % 2 == 0)
			cout << "BOB" << "\n";
		else
			cout << "ALICE" << "\n";
	}
}
