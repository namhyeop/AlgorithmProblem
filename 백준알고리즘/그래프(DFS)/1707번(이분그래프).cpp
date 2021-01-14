#include<iostream>
#include<vector>
#include<cstring>
#define MAX 20001

using namespace std;

int Testcase;
int node;
int edge;
int vsNodecolor[MAX];
vector<int> board[MAX];

void DFS(int nodeNum, int color)
{
	vsNodecolor[nodeNum] = color;

	for (int i = 0; i < board[nodeNum].size(); i++)
	{
		int next = board[nodeNum][i];
		if (!vsNodecolor[next])
			DFS(next, 3 - color);
	}
}

bool isBipartiteGraph(void)
{
	for (int i = 1; i <= node; i++)
	for (int j = 0; j < board[i].size(); j++)
	{
		int next = board[i][j];
		if (vsNodecolor[i] == vsNodecolor[next])
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		for (int j = 1; j < MAX; j++)
			board[j].clear();
		memset(vsNodecolor, 0, sizeof(vsNodecolor));

		cin >> node >> edge;

		for (int k = 0; k < edge; k++)
		{
			int tmp1;
			int tmp2;
			cin >> tmp1 >> tmp2;
			board[tmp1].push_back(tmp2);
			board[tmp2].push_back(tmp1);
		}

		for (int l = 1; l <= node; l++)
		if (vsNodecolor[l] == 0)
			DFS(l, 1);

		if (isBipartiteGraph())
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}
