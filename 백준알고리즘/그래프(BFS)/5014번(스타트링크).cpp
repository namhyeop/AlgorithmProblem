#include<iostream>
#include<queue>

using namespace std;

#define MAX 1000001

int fullSize;
int here;
int targethere;
int upSize;
int downSize;
int cache[MAX];

int BFS(void)
{
	queue<int> q;
	q.push(here);
	cache[here] = 1;

	while (!q.empty())
	{
		int nowHere = q.front();
		q.pop();

		if (nowHere == targethere)
			return cache[nowHere] - 1;

		int nextFloor[2] = { nowHere + upSize, nowHere - downSize };
		for (int i = 0; i < 2; i++)
		{
			if (1 <= nextFloor[i] && nextFloor[i] <= fullSize && cache[nextFloor[i]] == 0)
			{
				cache[nextFloor[i]] = cache[nowHere] + 1;
				q.push(nextFloor[i]);
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{	
	cin >> fullSize >> here >> targethere >> upSize >> downSize;

	int ret = BFS();
	if (ret == -1)
		cout << "use the stairs" << "\n";
	else
		cout << ret << "\n";
	return 0;
}
