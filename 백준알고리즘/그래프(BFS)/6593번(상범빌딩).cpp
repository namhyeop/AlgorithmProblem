#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

#define MAX 31

struct node
{
	int z;
	int y;
	int x;
	node() {}
	node(int _z, int _y, int _x) : z(_z), y(_y), x(_x) {}
};

node s, e;
int L;//건물 층수
int R;//행의 갯수
int C;//열의 갯수
char board[MAX][MAX][MAX];
bool chcked[MAX][MAX][MAX];
int distan[MAX][MAX][MAX];
int moveY[6] = { -1, 1, 0, 0, 0, 0 };
int moveX[6] = { 0, 0, -1, 1, 0, 0 };
int moveZ[6] = { 0, 0, 0, 0, 1, -1 };

void bfs()
{
	queue<node> q;
	q.push(s);
	chcked[s.z][s.y][s.x] = true;
	distan[s.z][s.y][s.x] = 0;

	while (!q.empty())
	{
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		if (z == e.z && y == e.y && x == e.x)
		{
			cout << "Escaped in " << distan[z][y][x] << " minute(s)." << "\n";
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			int dz = z + moveZ[i];
			int dy = y + moveY[i];
			int dx = x + moveX[i];

			if (dz >= 0 && dz < L && dy >= 0 && dy < R && dx >= 0 && dx < C)
			if (!chcked[dz][dy][dx] && board[dz][dy][dx] != '#')
			{
				chcked[dz][dy][dx] = true;
				distan[dz][dy][dx] = distan[z][y][x] + 1;
				q.push(node(dz, dy, dx));
			}
		}
	}
	cout << "Trapped!" << "\n";
}

int main(int argc, char *argv[])
{
	while (1)
	{
		cin >> L >> R >> C;
		
		if (L == 0 && R == 0 && C == 0)
			break;
		
		memset(chcked, false, sizeof(chcked));
		memset(distan, 0, sizeof(distan));
		memset(board, 0, sizeof(board));

		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					cin >> board[i][j][k];

					if (board[i][j][k] == 'S')
					{
						s.z = i;
						s.y = j;
						s.x = k;
					}
					else if (board[i][j][k] == 'E')
					{
						e.z = i;
						e.y = j;
						e.x = k;
					}
				}
			}
		}
		bfs();
	}
}
