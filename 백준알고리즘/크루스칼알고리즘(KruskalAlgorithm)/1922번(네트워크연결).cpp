/*우선순위큐를 사용한 구현
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
int n, m;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
bool visited[MAX];
vector<pair<int, int>> board[MAX];

int main(void)
{
	fastio;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		board[a].push_back({ c, b });
		board[b].push_back({ c, a });
	}

	//가중치가 0이고 1번 노드부터 탐색을 시작한다.
	pq.push({ 0, 1 });
	int ret = 0;

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (!visited[curNode])
		{
			//방문한 노드에 대해서 체크
			visited[curNode] = true;
			ret += cost;
			for (int i = 0; i < board[curNode].size(); i++)
			{
				int nextCost = board[curNode][i].first;
				int nextNode = board[curNode][i].second;
				if (!visited[nextNode])
					pq.push({ nextCost, nextNode });
			}
		}
	}
	cout << ret << "\n";
}
*/

/*union-find 기반 구현
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;

int n, m;
int parent[MAX];

struct node
{
	int a, b, c;
	node(int a, int b, int c) : a(a), b(b), c(c) {};
};

bool operator <(node a, node b)
{
	return a.c < b.c;
}

int find(int c)
{
	if (parent[c] == c)
		return c;
	else
		return parent[c] = find(parent[c]);
}

bool merge(int p, int c)
{
	p = find(p);
	c = find(c);

	if (p == c)
		return false;

	if (p < c)
		parent[p] = c;
	else
		parent[c] = p;

	return true;
}

int main(void)
{
	fastio;
	cin >> n >> m;
	vector<node> v;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a, b, c });
	}

	for (int i = 1; i <= n; i++)
		parent[i] = i;
	
	sort(v.begin(), v.end());
	int ret = 0;

	for (auto cur : v)
	{
		if (merge(cur.a, cur.b))
			ret += cur.c;
	}

	cout << ret << "\n";
}
*/
