#include<bits/stdc++.h>
#define MAX 22
using namespace std;

int board[MAX][MAX];
int visited[22];
int team1[10];
int tmeam2[10];
int ret = INT_MAX;
int n;

void DFS(int cur, int cnt)
{
	if (cnt == n / 2)
	{
		vector<int> linkTeam;
		vector<int> startTeam;

		for (int i = 0; i < n; i++)
		{
			if (visited[i])
				startTeam.push_back(i);
			else
				linkTeam.push_back(i);
		}

		int startRet = 0;
		int linkRet = 0;
		for (int i = 0; i < startTeam.size(); i++)
		{
			for (int j = i + 1; j < startTeam.size(); j++)
			{
				int start_y = startTeam[i];
				int start_x = startTeam[j];
				int link_y = linkTeam[i];
				int link_x = linkTeam[j];

				startRet += board[start_y][start_x] + board[start_x][start_y];
				linkRet += board[link_y][link_x] + board[link_x][link_y];
			}
		}
		ret = min(ret, abs(startRet - linkRet));

	}
	for (int i = cur + 1; i < n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			DFS(i, cnt + 1);
			visited[i] = false;
		}
	}
}
int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		cin >> board[i][j];

	DFS(0, 0);
	
	cout << ret << "\n";
	return 0;
}
