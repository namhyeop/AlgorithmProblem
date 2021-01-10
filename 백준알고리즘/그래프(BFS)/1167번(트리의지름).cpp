#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

int nodeSize;
bool visited[100001];
int length[100001];
vector<pair<int,int>> board[100001];

void BFS(int node)
{
	//fill(visited, visited + 100001, false);
	//fill(length, length + 100001, 0);
	memset(visited, false, sizeof(visited));
	memset(length, 0, sizeof(length));

	queue<int> q;

	visited[node] = true;
	q.push(node);

	while (!q.empty())
	{	
		int cur = q.front();
		q.pop();

		for (int i = 0; i < board[cur].size(); i++)
		{
			int nextNode = board[cur][i].first;
			if (!visited[nextNode])
			{
				length[nextNode] = length[cur] + board[cur][i].second;
				q.push(nextNode);
				visited[nextNode] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> nodeSize;

	for (int i = 1; i <= nodeSize; i++)
	{
		int node;
		int tmp1;
		int tmp2;

		cin >> node;
		while (1)
		{
			cin >> tmp1;
			if (tmp1 == -1)
				break;
			cin >> tmp2;
			board[node].push_back({ tmp1, tmp2 });
		}
	}

	BFS(1);
	
	int max = 1;
	for (int i = 2; i <= nodeSize; i++)
	if (length[i] > length[max])
		max = i;

	BFS(max);

	//for (int i = 0; i < 10; i++)
	//	cout << length[i] << "\n";

	int ret = length[1];
	for (int i = 2; i <= nodeSize; i++)
	{
		if (ret < length[i])
			ret = length[i];
	}
	cout << ret << "\n";

	return 0;
}
