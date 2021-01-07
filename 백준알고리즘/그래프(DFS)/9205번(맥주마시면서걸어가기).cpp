#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

const int MAX = 100 + 2;
int N;
vector<int> board[MAX];
bool visited[MAX];

int Mdistance(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void DFS(int node)
{
	visited[node] = true;

	for (int i = 0; i < board[node].size(); i++)
	{
		int next = board[node][i];
		if (!visited[next])
			DFS(next);
	}
}

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		for (int j = 0; j < MAX; j++)
			board[j].clear();
		memset(visited, false, sizeof(visited));

		cin >> N;
		vector<pair<int, int>> marketP;

		for (int j = 0; j < N + 2; j++)
		{
			int y, x;
			cin >> y >> x;
			marketP.push_back(make_pair(y, x));
		}

		for (int k = 0; k < N + 2; k++)
		for (int l = k + 1; l < N + 2; l++)
		{
			if (Mdistance(marketP[k], marketP[l]) <= 1000)
			{
				board[k].push_back(l);
				board[l].push_back(k);
			}
		}

		DFS(0);

		if (visited[N + 1])
			cout << "happy" << "\n";
		else
			cout << "sad" << "\n";
	}
	return 0;
}
