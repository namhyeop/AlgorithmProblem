
#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1e4 * 2;

bool visited[MAX];
vector<vector<int>> board(MAX);
vector<int> dist(MAX, 0);

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		int start = edge[i][0];
		int end = edge[i][1];
	
		board[start].push_back(end);
		board[end].push_back(start);
	}

	queue<int> q;
	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		int curNode = q.front();
		q.pop();

		for (int i = 0; i < board[curNode].size(); i++)
		{
			int endNode = board[curNode][i];
			if (!visited[endNode])
			{
				visited[endNode] = true;
				q.push(endNode);
				dist[endNode] = dist[curNode] + 1;
			}
		}
	}

	sort(dist.begin(), dist.end(), greater<int>());

	for (auto a : dist)
	{
		if (a == dist[0])
			answer++;
	}
	
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 6;
	vector<vector<int>> v = { { 3, 6 }, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 } };

	cout << solution(n, v) << "\n";
}
