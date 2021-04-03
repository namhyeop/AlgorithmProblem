#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 1e5;
int n;
set<int> s;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		s.insert(num);
	}

	typedef set<int>::iterator setiter;

	for (setiter iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << " ";
	}

	return 0;
}

