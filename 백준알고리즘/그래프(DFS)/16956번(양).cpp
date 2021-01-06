/*
문제가 늑대가 접근만 못하게 하면 된다는걸 몰랐다.
실행결과 처럼 나오지 않고 늑대가 양에게만 접근 못하게 하면 정답 처리다.
문제를 잘못 이해했고 좀 더 잘 작성한 코드가 시간초과가 나버려서 
화가 매우 차 올라 그만 늑대를 가둬 버렸다.
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define MAX 500

int height;
int width;
string board[MAX];
int moveY[4] = { 0, 0, -1, 1 };
int moveX[4] = { -1, 1, 0, 0 };

int main(int argc, char *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> height >> width;

	for (int i = 0; i < height; i++)
		cin >> board[i];

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		if (board[i][j] == 'W')
		{
			for (int k = 0; k < 4; k++)
			{
				int dy = i + moveY[k];
				int dx = j + moveX[k];

				if (0 <= dy && dy < height && 0 <= dx && dx < width)
				if (board[dy][dx] == 'S')
				{
					cout << "0" << "\n";
					return 0;
				}
			}
		}
	}

	cout << 1 << "\n";
	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		if (board[i][j] == 'W')
		for (int k = 0; k < 4; k++)
		{
			int dy = i + moveY[k];
			int dx = j + moveX[k];

			if (0 <= dy && dy < height && 0 <= dx && dx < width)
			if (board[dy][dx] == '.')
				board[dy][dx] = 'D';
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << board[i][j];
		cout << "\n";
	}


	return 0;
}

/*시간초과 코드
#include<iostream>
#include<queue>
#include<string>

using namespace std;

#define MAX 500

int height;
int width;
string board[MAX];
int moveY[4] = { 0, 0, -1, 1 };
int moveX[4] = { -1, 1, 0, 0 };

int main(int argc, char *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> height >> width;

	for (int i = 0; i < height; i++)
		cin >> board[i];

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		if (board[i][j] == 'W')
		{
			for (int k = 0; k < 4; k++)
			{
				int dy = i + moveY[i];
				int dx = j + moveX[i];

				if (0 <= dy && dy < height && 0 <= dx && dx < width)
				if (board[dy][dx] == 'S')
				{
					cout << "0" << "\n";
					return 0;
				}
			}
		}
	}

	cout << 1 << "\n";

	for (int i = 0; i < height; i++)
	for (int j = 0; j < width; j++)
	{
		if (board[i][j] == 'W')
		for (int k = 0; k < 4; k++)
		{
			int dy = i + moveY[k];
			int dx = j + moveX[k];


			if (0 <= dy && dy < height && 0 <= dx && dx < width)
			if (board[dy][dx] == '.')
				board[dy][dx] = 'D';
		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << board[i][j];
		cout << "\n";
	}


	return 0;
}
*/
