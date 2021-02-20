#include<bits/stdc++.h>
#define MAX 100
using namespace std;

struct shark
{
	int s, d, z;
};

shark board[MAX][MAX];
shark tmpboard[MAX][MAX];
int R, C, M;
int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, 1, -1 };

/*
   1
4     3
   2
*/

int main(void)
{
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		r -= 1;
		c -= 1;
		d -= 1;
		board[r][c] = { s, d, z };
	}
	
	int sum = 0;
	for (int t = 0; t < C; t++)
	{
		for (int i = 0; i < R; i++)
		{
			if (board[i][t].z > 0)
			{
				sum += board[i][t].z;
				board[i][t].z = 0;
				break;
			}
		}

		memcpy(tmpboard, board, sizeof(tmpboard));
		memset(board, 0, sizeof(board));

		for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
		{
			shark &curr = tmpboard[i][j];
			if (curr.z > 0)
			{
				int nextY = i + curr.s * moveY[curr.d];
				int nextX = j + curr.s * moveX[curr.d];
				if (nextY < 0)
				{
					nextY = -nextY; //남쪽으로 가다가 부호 바꿔주고 방향 바꿔준거니가 방향을 북쪽으로 바꿔준다
					curr.d = 1;
				}
				if (nextY > R - 1) //영역을 초과해줬다면, 짝수일때(왕복할 겨우), 홀수일때(가기만한 경우)
				{
					int a = nextY/(R - 1);
					int b = nextY % (R - 1);
					if (a % 2 == 0)
					{
						nextY = b;
					}
					else
					{
						nextY = R - 1 - b;
						curr.d = 0;
					}
				}
				if (nextX < 0)
				{
					nextX = -nextX;
					curr.d = 2;
				}
				if (nextX > C - 1)
				{
					int a = nextX / (C - 1);
					int b = nextX % (C - 1);
					if (a % 2 == 0)
						nextX = b;
					else
					{
						nextX = C - 1 - b;
						curr.d = 3; 
					}
				}
				if (board[nextY][nextX].z < curr.z)
					board[nextY][nextX] = curr;
				
			}
		}
	}

	cout << sum << "\n";

	return 0;
}
