#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 100000;
int n, k;
bool visited[MAX + 1];

int main(void)
{
	fastio;
	cin >> n >> k;

	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited[n] = true;
	int minTime = INT_MIN;
	int retcnt = 0;
	while (!q.empty())
	{
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		visited[cur] = true;
		if (cur == k)
		{
			if (minTime == INT_MIN)
			{
				minTime = cnt;
				retcnt++;
			}
			else if(minTime == cnt)
				retcnt++;
			visited[cur] = false;
			continue;
		}

		if (cur - 1 >= 0 && cur - 1 <= MAX && !visited[cur - 1])
		{
			q.push({ cur - 1, cnt + 1 });
		}

		if (cur + 1 >= 0 && cur + 1 <= MAX && !visited[cur + 1])
		{
			q.push({ cur + 1, cnt + 1 });
		}
		if (cur * 2 >= 0 && cur * 2 <= MAX && !visited[cur * 2])
		{
			q.push({ cur * 2, cnt + 1 });
		}
	}

	cout << minTime << "\n";
	cout << retcnt << "\n";
}
