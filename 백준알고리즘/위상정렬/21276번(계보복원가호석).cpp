#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main(void)
{
	fastio;
	int n;
	cin >> n;
	vector<string> v(n);
	vector<vector<int>> inp(n);
	vector<vector<int>> adj(n);
	vector<int> indegree(n), check(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	auto IDX = [&](string& s){ return lower_bound(v.begin(), v.end(), s) - v.begin(); };

	int m;
	cin >> m;

	while (m--)
	{
		string a, b;
		cin >> a >> b;
		int nodeA = IDX(a);
		int nodeB = IDX(b);
		indegree[nodeA]++;
		inp[nodeB].push_back(nodeA);
	}

	queue<int> q;
	for (int i = 0; i < n; i++)
	if (!indegree[i])
		q.push(i), check[i] = 1;
	while (sz(q))
	{
		auto cur = q.front();
		q.pop();
		for (const auto & next : inp[cur])
		{
			if (!--indegree[next]) //0개면 그것은 그 노드에 속하는 트리, 남아 있으면 트리 하단에 존재 가능
			{
				q.push(next);
				adj[cur].push_back(next);
			}
		}
	}

	vector<int> root;
	for (int i = 0; i < n; i++)
	if (check[i])
		root.push_back(i);
	cout << sz(root) << "\n";
	for (const auto& i : root) //root 출력
		cout << v[i] << " ";
	cout << "\n";

	for (int i = 0; i < n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
		cout << v[i] << " " << sz(adj[i]) << " ";
		for (const auto& next : adj[i])
			cout << v[next] << " ";
		cout << "\n";
	}
}

//#include<bits/stdc++.h>
//#define pill pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//const int MAX = 1001;
//int n, m;
//map<string, pair<int, int>> u_info; //숫자치환번호, 부모번호
//map<int, string> u_info_num;
//vector<string> user;
//vector<string> tree[MAX];
//vector<string> grand;
//bool visited[MAX];
//
//
//int main(void)
//{
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//		cin >> str;
//		user.push_back(str);
//		u_info_num[i] = str;
//		u_info[str] = { i, -1 };
//	}
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		string str1, str2;
//		cin >> str1 >> str2;
//		u_info[str1].second = u_info[str2].first;
//		tree[u_info[str2].first].push_back(str1);
//	}
//	
//	for (int i = 0; i < user.size(); i++)
//	{
//		if (u_info[user[i]].second == -1)
//			grand.push_back(u_info_num[i]);
//	}
//	sort(grand.begin(), grand.end());
//	sort(user.begin(), user.end());
//	for (int i = 0; i < n; i++)
//		sort(tree[i].begin(), tree[i].end());
//
//	for (int i = 0; i < grand.size(); i++)
//		cout << grand[i] << " ";
//	cout << "\n";
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << user[i] << " " << tree[u_info[user[i]].first].size() << " ";
//
//		for (auto i : tree[u_info[user[i]].first])
//			cout << i << " ";
//		cout << "\n";
//	}
//	
//
//}
