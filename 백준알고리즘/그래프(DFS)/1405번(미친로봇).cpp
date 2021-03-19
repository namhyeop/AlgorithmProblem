#include<bits/stdc++.h>

using namespace std;
const int MAX = 15 * 2;

int moveY[] = { 0, 0, 1, -1 };
int moveX[] = { 1, -1, 0, 0 };
int n;
double arr[4];
bool visited[MAX][MAX];
double ret;

void DFS(int y, int x, double accumulProbity)
{
	if (n == 0)
	{
		ret += accumulProbity;
		return;
	}

	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		if (!visited[nextY][nextX])
		{
			n -= 1;
			DFS(nextY, nextX, accumulProbity * arr[i]);
			n += 1;
			visited[nextY][nextX] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
		arr[i] *= 0.01;
	}

	DFS(15, 15, 1.0); //y축 x축 누적 확률

	cout << fixed;
	cout << setprecision(9) << ret << "\n";
	return 0;
}
