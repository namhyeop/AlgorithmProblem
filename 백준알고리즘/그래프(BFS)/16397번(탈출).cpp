#include<iostream>
#include<queue>

using namespace std;

#define MAX 100000

int N;//LED로 표현된 수
int T;// 버튼을 누를 수 있는 최대 횟수
int G;// 탈출을 위해 똑같이 만들어야 하는 수
bool visited[MAX];

int bfs()
{
	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty())
	{
		int curNum = q.front().first;
		int curCnt = q.front().second;
		q.pop();

		if (curCnt > T)
			break;
		if (curNum == G)
			return curCnt;

		int bottonA = curNum + 1;
		if (bottonA < MAX && !visited[bottonA])
		{
			visited[bottonA] = 1;
			q.push(make_pair(bottonA, curCnt + 1));
		}
		int bottonB = curNum * 2;

		if (bottonB >= MAX)
			continue;

		int tmp = bottonB;
		int tmpnum = 1;
		while (tmp)
		{
			tmp /= 10;
			tmpnum *= 10;
		}

		tmpnum /= 10;
		bottonB -= tmpnum;

		if (bottonB < MAX && !visited[bottonB])
		{
			visited[bottonB] = true;
			q.push(make_pair(bottonB, curCnt + 1));
		}
	}
	return -1;
}
int main(int argc, char *argv[])
{
	cin >> N >> T >> G;

	int ret	= bfs();

	if (ret == -1)
		cout << "ANG" << "\n";
	else
		cout << ret << "\n";
}
