#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const ll MAX = 1e9 + 1;
int n, m;

int main(void)
{
	fastio;
	cin >> n >> m;

	auto BFS = [&](int n) -> int
	{
		queue<pair<ll, ll>> q;
		q.push({ n, 0 });

		while (!q.empty())
		{
			ll cur = q.front().first;
			ll cnt = q.front().second;
			q.pop();
	
			if (cur > MAX)
				break;
	
			if (cur == m)
				return cnt;

			if (cur * 10 + 1 <= MAX)
				q.push({ cur * 10 + 1, cnt + 1 });

			if (cur * 2 <= MAX)
				q.push({ cur * 2, cnt + 1 });
		}
		return -1;
	};

	ll ret = BFS(n);
	if (ret == -1)
		cout << -1 << "\n";
	else
		cout << ret + 1 << "\n";

	return 0;
}
