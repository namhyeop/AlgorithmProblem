#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1e4;
int n, m, maxValue = INT_MIN;
int start, finish;
bool visited[MAX + 1];
vector<pair<int, int>> v[MAX + 1];

bool BFS(int value)
{
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		int curFt = q.front();
		q.pop();

		if (curFt == finish)
			return true;

		for (int i = 0; i < v[curFt].size(); i++)
		{
			int nextFt = v[curFt][i].first;
			int cost = v[curFt][i].second;

			if (value <= cost && !visited[nextFt])
			{
				visited[nextFt] = true;
				q.push(nextFt);
			}
		}
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{ 
		int num1, num2, value;
		cin >> num1 >> num2 >> value;

		v[num1].push_back(mp(num2, value));
		v[num2].push_back(mp(num1, value));
		if (maxValue < value)
			maxValue = value;
	}
	cin >> start >> finish;

	int left = 0, right = maxValue;

	while (left <= right)
	{
		memset(visited, false, sizeof(visited));
		int mid = (left + right) / 2;
		if (BFS(mid))
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << right; //

	return 0;
}
