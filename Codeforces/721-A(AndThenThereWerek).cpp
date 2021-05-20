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
		int num;
		cin >> num;
		
		int cycleNum = num;
		while (cycleNum)
		{
			int curNum = cycleNum & cycleNum - 1;
			if (curNum == 0)
			{
				cout << cycleNum -1 << "\n";
				break;
			}
			cycleNum = curNum;
		}
	}
}
