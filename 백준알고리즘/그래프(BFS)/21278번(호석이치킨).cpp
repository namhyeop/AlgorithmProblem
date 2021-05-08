#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
int dist[MAX][MAX];
vector<int> tree[MAX];
int n, m;
pair<int, pair<int, int>> minret = { INT_MAX, { INT_MAX, INT_MAX } };

void BFS()
{
	for (int i = 1; i <= n; i++)
	{
		queue<int> q;
		q.push(i);
		dist[i][i] = 0;

		while (!q.empty())
		{
			int cur = q.front();
			int d = dist[i][cur];
			q.pop();

			for (auto next : tree[cur])
			{
				if (dist[i][next] != -1)
					continue;
				dist[i][next] = d + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}

	fill(&dist[0][0], &dist[MAX][0], -1);
	BFS();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			int tmpret = 0;
			for (int k = 1; k <= n; k++)
			{
				tmpret += 2 * min(dist[i][k], dist[j][k]);
			}
			minret = min(minret, make_pair(tmpret, make_pair( i, j )));
		}
	}

	cout << minret.second.first << ' ' << minret.second.second << ' ' << minret.first << "\n";
}
const int MAX = 100 + 1;
int n, m;
vector<int> tree[MAX];
string ret = "9999";
int retValue = INT_MAX;
bool visited[MAX];
bool chicken[MAX];

void BFS(string curHouse)
{
	int testret = 0;
	for (int i = 1; i <= n; i++)
	{
		memset(visited, false, sizeof(visited));
		queue<pair<int, int>> q;
		if (chicken[i] || visited[i])
			continue;
		
		/*cout << i << "번째 노드를 방문합니다." << "\n";*/
		visited[i] = true;
		q.push({ i, 0 });
		
		while (!q.empty())
		{
			int cur = q.front().first;
			int value = q.front().second;
			q.pop();

			if (chicken[cur])
			{
				/*cout << "cur은 " << cur << "value는 " << value << "\n";*/
				testret += value * 2;
				break;
			}

			for (int i = 0; i < tree[cur].size(); i++)
			{
				if (!visited[tree[cur][i]])
				{
					if (!chicken[tree[cur][i]])
						visited[tree[cur][i]] = true;
					q.push({ tree[cur][i], value + 1 });
				}
			}
		}
	/*	cout << "\n";*/
	}
	if (testret < retValue)
	{
		ret = curHouse;
		retValue = testret;
	}
	else if (testret == retValue)
	{
		if (ret > curHouse)
		{
			ret = curHouse;
		}
	}
	//cout << " retValue는 " << retValue << "\n";

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}

	for (int i = 1; i < n; i++)
	for (int j = i + 1; j <= n; j++)
	{	
		string house = to_string(i) + to_string(j);
	/*	cout << "==============" << house << "====================" << "\n";*/
		chicken[i] = true;
		chicken[j] = true;
		BFS(house);
		chicken[i] = false;
		chicken[j] = false;
		//cout << "=======================================" << "\n";
		//cout << "\n";
	}

	cout << ret[0] << " " << ret[1] <<" " << retValue;
}
