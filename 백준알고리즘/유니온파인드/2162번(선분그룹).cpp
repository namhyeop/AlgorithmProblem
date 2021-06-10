#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 3001;
int n;
bool visited[MAX];
vector<int> board[MAX];
vector<pair<int, int>> v[MAX];
queue<int> q;
int parent[MAX];
int group_all_max = INT_MIN;

int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int tmp = a.first * b.second + b.first * c.second + c.first * a.second;
	tmp -= b.first * a.second + c.first * b.second + a.first * c.second;
	if (tmp > 0) //반시계 방향
		return 1;
	else if (tmp == 0)//일직선 방향
		return 0;
	else if (tmp < 0) //시계 방향
		return -1;
}

bool check(pii A, pii B, pii C, pii D) // 두 선분 교차 여부
{
	int ans1 = CCW(A, B, C) * CCW(A, B, D);
	int ans2 = CCW(C, D, A) * CCW(C, D, B);

	if (ans1 == 0 && ans2 == 0) // 평행 혹은 양 끝점이 접촉해 있을 때
	{
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);

		if (A <= D && B >= C) return true;
		else return false;
	}
	else
	{
		// 교차 혹은 한 점이 선분 위에 있을 때(끝점 제외)
		if (ans1 <= 0 && ans2 <= 0) return true;
		else return false;
	}
}

void BFS(int x)
{
	int num = 1;
	q.push(x);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		visited[now] = true;
		for (auto next : board[now])
		{
			if (!visited[next])
			{
				num++;
				q.push(next);
			}
		}
	}
	group_all_max = max(group_all_max, num);
}

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
	return parent[x] = find(parent[x]);
}

bool merge(int u, int v)
{
	u = find(u);
	v = find(v);

	if (u == v)
		return false;
	else
	{
		parent[u] = v;
		board[u].push_back(v);
		board[v].push_back(u);
		return true;
	}
}

int main(void)
{
	fastio;
	cin >> n;
	int x1, x2, y1, y2;
	for (int i = 1; i <= n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		v[i].push_back({ x1, y1 });
		v[i].push_back({ x2, y2 });
	}

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			bool state = check(v[i][0], v[i][1], v[j][0], v[j][1]);
			if (state == true)
				merge(i, j);
		}
	}

	int group_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			group_cnt++;
			BFS(i);
		}
	}
	cout << group_cnt << "\n";
	cout << group_all_max << "\n";
}
