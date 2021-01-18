#include<iostream>
#include<queue>
#define MAX 500001

using namespace std;
int N;
int K;
int visited[MAX][2];
int value = 0;

int sum(int n)
{
	return n*(n + 1) / 2;
}

void BFS()
{
	queue<pair<int,int>> q;
	q.push({ N, 0});
	visited[N][0] = true;

	int nk;
	while (!q.empty())
	{
		int curSize = q.size();
		nk = K + sum(value);
		if (nk < 0 || nk > 500000)
			break;

		for (int i = 0; i < curSize; i++)
		{
			int curN = q.front().first;
			int curTime = q.front().second;
			q.pop();

			if (curN == nk || visited[nk][value%2] == true)
			{
				cout << value << "\n";
				return;
			}

			if (curN + 1 <= MAX && !visited[curN+1][(curTime +1) % 2])
			{
				q.push({ curN + 1, curTime + 1});
				visited[curN + 1][(curTime + 1) % 2] = true;
			}
			if (curN - 1 >= 0 && !visited[curN -1][(curTime +1) % 2])
			{
				q.push({ curN - 1, curTime + 1});
				visited[curN - 1][(curTime + 1) % 2] = true;
			}
			if (curN * 2 <= MAX && !visited[curN * 2][(curTime +1) % 2])
			{
				q.push({ curN * 2, curTime + 1});
				visited[curN * 2][(curTime + 1) % 2] = true;
			}
		}
		value++;
	}
	cout << -1 << "\n";
}

int main(int argc, char *argv[])
{
	cin >> N >> K;
	BFS();
}
