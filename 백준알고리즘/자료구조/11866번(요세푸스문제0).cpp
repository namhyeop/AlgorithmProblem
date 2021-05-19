#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n, k;

int main()
{
	fastio;
	cin >> n >> k;

	queue<int> q;
	
	for (int i = 1; i <= n; i++)
		q.push(i);

	cout << "<";
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		q.pop();

		if (!q.empty())
			cout << ", ";
	}
	cout << ">" << "\n";
	return 0;
}
