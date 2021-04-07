#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1000;
int n, k;
bool visited[MAX + 1];
pill arr[MAX + 1];
ll ret = LLONG_MAX;

double getLength(int endY, int endX, int y, int x)
{
	return sqrt((endY - y) * (endY - y) + (endX - x) * (endX - x)) /10;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	
	int left = 0;
	int right = 1500;
	
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		bool flag = false;
		queue<pair<pill, int>> q;
		q.push({ { 0, 0 }, k });
		
		memset(visited, false, sizeof(visited));

		while (!q.empty())
		{
			int curY = q.front().first.first;
			int curX = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			if (cnt < 0)
				continue;

			if (getLength(10000, 10000, curY, curX) <= mid)
			{
				flag = true;
				break;
			}

			for (int i = 0; i < n; i++)
			{
				if (visited[i])
					continue;

				int nextY = arr[i].first;
				int nextX = arr[i].second;

				if (getLength(nextY, nextX, curY, curX) <= mid)
				{
					visited[i] = true;
					q.push({ { nextY, nextX }, cnt - 1 });
				}
			}
		}

		if (flag)
		{
			ret = min(ret, mid);
			//if (ret > mid)
			//	ret = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ret << "\n";
}
