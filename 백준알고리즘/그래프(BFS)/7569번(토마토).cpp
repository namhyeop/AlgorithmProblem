#include<iostream>
#include<queue>

using namespace std;

#define MAX 100

int width;//가로
int height;//세로
int level;//상자의 층수
int moveZ[6] = {1, -1, 0, 0, 0, 0};
int moveY[6] = { 0, 0, -1, 1, 0, 0 };
int moveX[6] = { 0, 0, 0, 0, -1, 1 };
queue<pair<int, pair<int, int>>> q;
int board[MAX][MAX][MAX];
int notomato;

bool check()
{
	int vaildtomato = 0;
	for (int i = 0; i < level; i++)
	for (int j = 0; j < height; j++)
	for (int k = 0; k < width; k++)
	if (board[i][j][k] == 1)
		vaildtomato++;

	return vaildtomato == ((height * width * level) - notomato);
}
int BFS()
{
	int day = 0;

	if (q.empty())
		return -1;
	
	while (!q.empty())
	{
		int curSize = q.size();

		for (int i = 0; i < curSize; i++)
		{
			int z = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int dz = z + moveZ[i];
				int dy = y + moveY[i];
				int dx = x + moveX[i];

				if (0 <= dz && dz < level && 0 <= dy && dy < height && 0 <= dx && dx < width)
				if (board[dz][dy][dx] == 0)
				{
					board[dz][dy][dx] = 1;
					q.push(make_pair(dz, make_pair(dy, dx)));
				}
 			}

			if (q.size() == 0 && check())
				return day;
			else if (q.size() == 0 && !check())
				return -1;
		}
		day++;
	}
}
int main(int argc, char *argv[])
{
	cin >> width >> height >> level;

	for (int i = 0; i < level; i++)
	for (int j = 0; j < height; j++)
	for (int k = 0; k < width; k++)
	{
		cin >> board[i][j][k];
		if (board[i][j][k] == 1)
			q.push(make_pair(i,make_pair(j, k)));
		else if (board[i][j][k] == -1)
			notomato++;
	}

	if (q.size() == height * width - notomato)
		cout << 0 << "\n";
	else
	{
		int ret = BFS();
		cout << ret << "\n";
	}

	return 0;
}
