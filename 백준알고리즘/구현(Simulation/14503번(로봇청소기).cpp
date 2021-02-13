#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int n, m;
pair<int, int> start;
int dir;
int board[MAX][MAX];
int moveY[] = { -1, 0, 1, 0 };
int moveX[] = { 0, 1, 0, -1 };
int backY[] = { 1, 0, -1, 0 };
int backX[] = { 0, -1, 0, 1 };
bool visited[MAX][MAX];
int testvisited[MAX][MAX];
int cnt = 0;

void search(int y, int x, int cur)
{
	if (board[y][x] == 0)
	{
		cnt++;
		board[y][x] = 2;
	}
	for (int k = cur-1; k >cur -5; k--)
	{
		int nk = (k + 4) % 4;
		int nextY = y + moveY[nk];
		int nextX = x + moveX[nk];

		if (0 <= nextY && nextY < n - 1 && 0 <= nextX && nextX < m -1)
		if (board[nextY][nextX] == 0)
		{
			search(nextY, nextX, nk);
			return;
		}
	}
	
		if (board[y + backY[cur]][x + backX[cur]] == 1)
			return;
		else
			search(y + backY[cur], x + backX[cur], cur);
	
}
int main(void)
{
	cin >> n >> m;
	cin >> start.first >> start.second >> dir;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	search(start.first, start.second, dir);

	cout << cnt << "\n";
	return 0;
}

