#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 10001;
int v, e, order, ret;
vector<int> adjlist[MAX];
int visited[MAX];
bool isValidDjj[MAX];

int dfs(int id, bool isRoot, int parent)
{
	//1.방문 순서 기록 후 자식과 비교 준비
	visited[id] = order;
	order++;

	int ret = visited[id];
	int child = 0;

	//2.자식 DFS
	int len = adjlist[id].size();
	for (int i = 0; i < len; i++)
	{
		int next = adjlist[id][i];

		//왔던길 돌아가기 방지
		if (next == parent)
			continue;

		if (visited[next] == 0)
		{
			child++;

			int low = dfs(next, false, id);
			
			if (!isRoot && low >= visited[id])
				isValidDjj[id] = true;
			ret = min(ret, low);
		}
		else
			ret = min(ret, visited[next]);
	}
	if (isRoot & child >= 2)
		isValidDjj[id] = true;
	return ret;
}

int main(void)
{
	fastio;
	cin >> v >> e;
	
	//양방향 간선 입력받기
	for (int i = 1; i <= e; i++)
	{
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}

	order = 1;
	for (int i = 1; i <= v; i++)
	{
		if (visited[i] == 0)
			dfs(i, true, 0);
	}

	vector<int> arr;
	//단절점의 개수 count 및 출력
	for (int i = 1; i <= v; i++)
	if (isValidDjj[i])
		ret++, arr.push_back(i);

	cout << ret << "\n";
	for (auto tmp : arr)
		cout << tmp << " ";
}
