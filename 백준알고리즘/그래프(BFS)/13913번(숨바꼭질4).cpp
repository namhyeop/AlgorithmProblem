#include<iostream>
#include<queue>
#include<vector>
#define MAX 100001

using namespace std;

int N;
int K;
bool visited[MAX];
int parent[MAX]; //방문지점을 역순으로 등록하게 해준다. 시간 제한, 메모리 제한에서 좀 더 자유로워지는 방법
vector<int> path;

int BFS(int N, int K)
{
	queue<pair<int,int>> q;
	visited[N] = true;
	q.push({ N, 0 });

	while (!q.empty())
	{
		int curValue = q.front().first;
		int curCnt = q.front().second;
		q.pop();

		if (curValue == K)
		{
			int i = curValue;

			while (i != N)
			{
				path.push_back(i);
				i = parent[i];
			}
			path.push_back(N);
			return curCnt;
		}

		if (curValue + 1 < MAX && !visited[curValue + 1])
		{
			q.push({ curValue + 1, curCnt + 1});
			visited[curValue + 1] = true;
			parent[curValue + 1] = curValue;
		}
		if (curValue - 1 >= 0 && !visited[curValue - 1])
		{
			q.push({ curValue - 1, curCnt +1});
			visited[curValue - 1] = true;
			parent[curValue - 1] = curValue;
		}
		if (curValue * 2 < MAX && !visited[curValue * 2])
		{
			q.push({ curValue *2, curCnt + 1 });
			visited[curValue * 2] = true;
			parent[curValue * 2] = curValue;
		}
	}
}
int main(int argc, char * argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	cout << BFS(N, K) << "\n";

	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << "\n";

	return 0;
}

/*vector 사용으로 인한 시간 초과
#include<iostream>
#include<queue>
#include<vector>
#define MAX 100001

using namespace std;

int N;
int K;
bool visited[MAX];

void BFS(int N, vector<int> v)
{
	queue<pair<int, vector<int>>> q;
	visited[N] = true;
	q.push({ N, v });

	while (!q.empty())
	{
		int curValue = q.front().first;
		vector<int> curv = q.front().second;
		q.pop();

		if (curValue == K)
		{
			cout << curv.size() - 1 << "\n";
			for (int i = 0; i < curv.size(); i++)
				cout << curv[i] << " ";
			break;
		}

		if (curValue + 1 < MAX && !visited[curValue + 1])
		{
			curv.push_back(curValue + 1);
			q.push({ curValue + 1, curv });
			curv.pop_back();
			visited[curValue + 1] = true;
		}
		if (curValue - 1 >= 0 && !visited[curValue - 1])
		{
			curv.push_back(curValue - 1);
			q.push({ curValue - 1, curv });
			curv.pop_back();
			visited[curValue - 1] = true;
		}
		if (curValue * 2 < MAX && !visited[curValue * 2])
		{
			curv.push_back(curValue * 2);
			q.push({ curValue * 2, curv });
			curv.pop_back();
			visited[curValue * 2] = true;
		}
	}
}
int main(int argc, char * argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	vector<int> v;
	v.push_back(N);
	BFS(N, v);

	return 0;
}
*/
