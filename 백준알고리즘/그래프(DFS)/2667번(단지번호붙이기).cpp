#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<algorithm>

using namespace std;

int cycleNum;
int ret = 0;
int moveY[4] = { 1, -1, 0, 0 }; //하상좌우
int moveX[4] = { 0, 0, -1, 1 };
string input[25];
bool visited[25][25];
vector<int> retArr;

void dfs(int i, int j)
{
	visited[i][j] = true;
	ret++;

	for (int k = 0; k < 4; k++)
	{
		int dy = i + moveY[k];
		int dx = j + moveX[k];

		if (dx < 0 || dx >= cycleNum || dy < 0 || dy >= cycleNum)
			continue;

		if (input[dy][dx] == '1' && !visited[dy][dx])
			dfs(dy, dx);
	}
}
int main(int argc, char *argv[])
{
	cin >> cycleNum;

	for (int i = 0; i < cycleNum; i++)
		cin >> input[i];

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < cycleNum; i++)
	for (int j = 0; j < cycleNum; j++)
	{
		if (input[i][j] == '1' && !visited[i][j])
		{
			ret = 0;
			dfs(i, j);
			retArr.push_back(ret);
		}
	}

	sort(retArr.begin(), retArr.end());

	cout << retArr.size() << "\n";

	for (int i = 0; i < retArr.size(); i++)
		cout << retArr[i] << "\n";

	return 0;
}
