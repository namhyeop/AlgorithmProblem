#include<bits/stdc++.h>
#define pil pair<int,int>
#define mp(X, Y) make_pair(X, Y)

using namespace std;

const int MAX = 1e5* 2 + 1;
int n,m;
queue<pil> q, qq;
vector<int> v[MAX];
vector<pil> nearnode;
int visited[MAX];
int main()
{
	cin >> n;
	
	memset(visited, -1, sizeof(visited));
	nearnode.resize(n+1, mp(0,0));
	for (int i = 1; i <= n; i++)
	{
		int num;
		while (1)
		{
			cin >> num;

			if (num == 0)
				break;
			nearnode[i].first++;
			v[i].push_back(num);
		}
	}

	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		int num;
		cin >> num;
		visited[num] = 0;
		q.push(mp(num, 0));
	}

	while (!q.empty())
	{
		while (!q.empty())
		{
			int curnode = q.front().first;//현재 노드
			int curcnt = q.front().second; //현재 시간(분)
			q.pop();

			for (int i = 0; i < v[curnode].size(); i++)
			{
				int nextNode = v[curnode][i];
				if (visited[nextNode] == -1)//아직 cnt가 정해지지 않은 경우
				{
					qq.push(mp(nextNode, curcnt + 1));
					nearnode[nextNode].second++;
				}
			}
		}

		while (!qq.empty())
		{
			int curnode = qq.front().first;
			int curcnt = qq.front().second;
			qq.pop();
			if (visited[curnode] == -1 && nearnode[curnode].second*2 >= nearnode[curnode].first)//올림문제 때문에 더블을 사용하든가 분자에 곱해주던가
			{
				visited[curnode] = curcnt;
				q.push(mp(curnode, curcnt));
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << visited[i] << " ";
}
