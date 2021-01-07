#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N;
int vrcom;
int board[101][101];
bool visited[101];
int ret = 0;
queue<int> q;

void bfs()
{	
	q.push(1);
	visited[1] = true;

	while (!q.empty())
	{
		ret++;
		int dirtyCum = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (!visited[i] && board[dirtyCum][i] == 1)
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> N;
	cin >> vrcom;
	for (int i = 0; i < vrcom; i++)
	{
		int node1;
		int node2;
		cin >> node1 >> node2;
		board[node1][node2] = 1;
		board[node2][node1] = 1;
	}

	bfs();

	cout << ret -1 << "\n";
}
