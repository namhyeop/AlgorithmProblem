#include<iostream>
#include<deque>
using namespace std;

#define MAX 1000

int height;
int width;
int moveY[4] = { -1, 1, 0, 0 };
int moveX[4] = { 0, 0, -1, 1 };
int tomato[MAX][MAX];
deque<pair<int, int>> dq;
int notomato;

bool check()
{
	int possible = height * width - notomato;
	int tomatoCnt = 0;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	if (tomato[i][j] == 1)
		tomatoCnt++;

	return possible == tomatoCnt;
}
int BFS()
{
	int day = 0;

	if (dq.empty())
		return -1;

	while (!dq.empty())
	{
		int curSize = dq.size();

		for (int i = 0; i < curSize; i++)
		{
			int y = dq.front().first;
			int x = dq.front().second;
			dq.pop_front();
			for (int i = 0; i < 4; i++)
			{
				int dy = y + moveY[i];
				int dx = x + moveX[i];

				if (0 <= dy && dy < height && 0 <= dx && dx < width)
				if (tomato[dy][dx] == 0)
				{
					tomato[dy][dx] = 1;
					dq.push_back(make_pair(dy, dx));
				}
			}

			if (dq.size() == 0 && check())
				return day;
			else if (dq.size() == 0 && !check())
				return -1;
		}
		day++;
	}
}
int main(int argc, char *argv[])
{
	cin >> width >> height;

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		cin >> tomato[i][j];
		if (tomato[i][j] == 1)
			dq.push_back(make_pair(i, j));
		else if (tomato[i][j] == -1)
			notomato++;
	}

	if (dq.size() == height * width - notomato)
		cout << 0 << "\n";
	else
	{
		int result = BFS();
		cout << result << "\n";
	}

	return 0;
}
