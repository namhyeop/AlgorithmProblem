#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#define MAX 100000+1

using namespace std;
int sister;
int oldBrother;
bool visited[MAX];

int BFS(int sec, int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(sec, start));
	visited[start] = true;

	while (!q.empty())
	{
		int cnt = q.top().first;
		int cur = q.top().second;
		q.pop();

		if (oldBrother == cur)
		{
			//cout << cnt << "\n";
			return cnt;
		}

		if (cur * 2 < MAX && !visited[cur * 2])
		{
			q.push(make_pair(cnt, cur * 2));
			visited[cur * 2] = true;
		}
		if (cur + 1 < MAX && !visited[cur + 1])
		{
			q.push(make_pair(cnt + 1, cur + 1));
			visited[cur + 1] = true;
		}
		if (cur - 1 >= 0 && !visited[cur - 1])
		{
			q.push(make_pair(cnt + 1, cur - 1));
			visited[cur - 1] = true;
		}
	}
}

int main(int argc, char *argv[])
{
	cin >> sister >> oldBrother;

	cout << BFS(0, sister) << "\n";

	return 0;
}
