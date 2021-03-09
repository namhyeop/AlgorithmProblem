#include<bits/stdc++.h>
#define MAX 64
using namespace std;

int N, Q;
int board[MAX][MAX];
int temp[MAX][MAX];
bool checkMelt[MAX][MAX];
bool visited[MAX][MAX];

int moveY[] = { -1, 1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };

int validRange(int nextY, int nextX)
{
	return nextY >= 0 && nextX >= 0 && nextY < N && nextX < N;
}

int dfs(int y, int x)
{
	visited[y][x] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];
		if (validRange(nextY, nextX) && !visited[nextY][nextX])
		if (board[nextY][nextX] > 0)
			ret += dfs(nextY, nextX);
	}
	return ret;
}

int maxValue()
{
	int ret = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	{
		if (board[i][j] > 0 && !visited[i][j])
			ret = max(ret, dfs(i, j));
	}
	return ret;
}

int allSum()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		sum += board[i][j];
	return sum;
}

void rotate(int y, int x, int L)
{
	for (int i = 0; i < L; i++)
	for (int j = 0; j < L; j++)
		temp[i][j] = board[y + L - 1 - j][x + i];

	for (int i = 0; i < L; i++)
	for (int j = 0; j < L; j++)
		board[y + i][x + j] = temp[i][j];
}

void solve(int L)
{
	L = (1 << L);

	for (int i = 0; i < N; i+= L)
	for (int j = 0; j < N; j+= L)
		rotate(i, j, L);

	memset(checkMelt, false, sizeof(checkMelt));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0)
				continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++)
			{
				int nextY = i + moveY[k];
				int nextX = j + moveX[k];
				if (!validRange(nextY, nextX))
					continue;
				if (board[nextY][nextX] > 0)
					cnt++;
			}
			if (cnt < 3)
				checkMelt[i][j] = true;
		}
	}

	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	if (checkMelt[i][j])
		board[i][j]--;
}

int main()
{
	cin >> N >> Q;

	N = (1 << N);
	
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> board[i][j];

	for (int i = 0; i < Q; i++)
	{
		int L;
		cin >> L;	
		solve(L);
	}

	cout << allSum() << "\n";
	cout << maxValue() << "\n";

	return 0;
}
