#include<iostream>
#include<queue>
#include<vector>
#include<string>
#define MAX 50
using namespace std;

typedef struct
{
	pair<int, int> a, b, c;
	int dir;
}Log;

int N;
Log treeLog;
string board[50];
queue<pair<Log, int>> q;
bool visited[MAX][MAX][2];

int BFS()
{
	while (!q.empty())
	{
		Log cur = q.front().first;
		int cnt = q.front().second;
		int y = cur.a.first; //나무의 첫번째 블락 Y축
		int x = cur.a.second;//나무의 첫 번째 타일 X축
		int y2 = cur.b.first;//나무의 두 번째 타일 Y축
		int x2 = cur.b.second;//나무의 두 번째 타일 X축
		int y3 = cur.c.first;//나무의 세 번째 타일 Y축
		int x3 = cur.c.second;//나무의 세 번째 타일 X축
		int dir = cur.dir;//나무 기둥의 방향
		q.pop();

		//프로그램 종료 조건
		if (board[y][x] == 'E' && board[y2][x2] == 'E' && board[y3][x3] == 'E')
		{
			return cnt;
		}

		for (int i = 0; i < 5; i++)
		{
			Log temp;
			switch (i)
			{
			case 0://U
				//범위 체크
				if (y == 0 || y2 == 0 || y3 == 0)
					break;
				//움직일려는 칸이 상이니까 위에 1이 있으면 안되니까 확인한다
				if (board[y - 1][x] == '1' || board[y2 - 1][x2] == '1' || board[y3 - 1][x3] == '1')
					break;
				temp = { { y - 1, x }, { y2 - 1, x2 }, { y3 - 1, x3 }, dir };
				//방문한 여부가 있었는지 확인한다.
				if (!visited[temp.b.first][temp.b.second][temp.dir])
				{
					q.push({ temp, cnt + 1 });
					visited[temp.b.first][temp.b.second][temp.dir] = true;
				}
				break;
			case 1://D
				//맨 끝에서는 더 이상 내려갈 수 없다.
				if (y == N - 1 || y2 == N - 1 || y3 == N - 1)
					break;
				//밑이 1이라면 더 이상 내려갈 수 없다.
				if (board[y + 1][x] == '1' || board[y2 + 1][x2] == '1' || board[y3 + 1][x3] == '1')
					break;
				temp = { { y + 1, x }, { y2 + 1, x2 }, { y3 + 1, x3 }, dir };
				//방문한 여부가 있었는지 확인한다.
				if (!visited[temp.b.first][temp.b.second][temp.dir])
				{
					q.push({ temp, cnt + 1 });
					visited[temp.b.first][temp.b.second][temp.dir] = true;
				}
				break;
			case 2: //L
				//X가 맨 왼쪽이면 더 이상 왼쪽으로 움직일 수 없다.
				if (x == 0 || x2 == 0 || x3 == 0)
					break;
				//왼쪽으로 이동하려는곳이 1이면 움직일 수 없다.
				if (board[y][x - 1] == '1' || board[y2][x2 - 1] == '1' || board[y3][x3 - 1] == '1')
					break;
				temp = { { y, x - 1 }, { y2, x2 - 1 }, { y3, x3 - 1 }, dir };
				if (!visited[temp.b.first][temp.b.second][temp.dir])
				{
					q.push({ temp, cnt + 1 });
					visited[temp.b.first][temp.b.second][temp.dir] = true;
				}
				break;
			case 3: //R
				//오른쪽 끝인 상태라면 오른쪽으로 움직일 수 없다.
				if (x == N - 1 || x2 == N - 1 || x3 == N - 1)
					break;
				//오른쪽으로 진행시에 1이 있으면 움직일 수 없다.
				if (board[y][x + 1] == '1' || board[y2][x2 + 1] == '1' || board[y3][x3 + 1] == '1')
					break;
				temp = { { y, x + 1 }, { y2, x2 + 1 }, { y3, x3 + 1 }, dir };
				if (!visited[temp.b.first][temp.b.second][temp.dir])
				{
					q.push({ temp, cnt + 1 });
					visited[temp.b.first][temp.b.second][temp.dir] = true;
				}
				break;
			case 4: //T
				//가로와 세로일 경우로 나누어 진다.
				if (dir == 0) //세로일 경우
				{
					//board의 범위를 벗어나는 경우
					if (x - 1 < 0 || x2 - 1 < 0 || x3 - 1 < 0)
						break;
					if (x + 1 >= N || x2 + 1 >= N || x3 + 1 >= N)
						break;
					//세로에서 가로로 바꾸려는데 1이라 안되면 탈출
					if (board[y][x - 1] == '1' || board[y][x + 1] == '1')
						break;
					if (board[y2][x2 - 1] == '1' || board[y2][x2 + 1] == '1')
						break;
					if (board[y3][x3 - 1] == '1' || board[y3][x3 + 1] == '1')
						break;
					temp = { { y + 1, x - 1 }, { y2, x2 }, { y3 - 1, x3 + 1 }, 1 - dir };
				}
				else
				{
					if (y - 1 < 0 || y2 - 1 < 0 || y3 - 1 < 0)
						break;
					if (y + 1 >= N || y2 + 1 >= N || y3 + 1 >= N)
						break;
					if (board[y - 1][x] == '1' || board[y + 1][x] == '1')
						break;
					if (board[y2 - 1][x2] == '1' || board[y2 + 1][x2] == '1')
						break;
					if (board[y3 - 1][x3] == '1' || board[y3 + 1][x3] == '1')
						break;
					temp={ { y - 1, x + 1 }, { y2, x2 }, { y3 + 1, x3 - 1 }, 1 - dir };
				}
				if (!visited[temp.b.first][temp.b.second][temp.dir])
				{
					q.push({ temp, cnt + 1 });
					visited[temp.b.first][temp.b.second][temp.dir] = true;
				}
				break;
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	cin >> N;

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{ 
		cin >> board[i];

		for (int j = 0; j < N; j++)
		if (board[i][j] == 'B')
		{
			switch (cnt++)
			{
			case 0:
				treeLog.a = { i, j };
				break;
			case 1:
				treeLog.b = { i, j };
				break;
			case 2:
				treeLog.c = { i, j };
				if (treeLog.a.first == treeLog.b.first) // 가로
					treeLog.dir = 1;
				else
					treeLog.dir = 0; // 세로
				q.push({ treeLog, 0 });
				visited[treeLog.b.first][treeLog.b.second][treeLog.dir] = true;
				break;
			}
		}
	}

	cout << BFS() << "\n";

	return 0;
}
