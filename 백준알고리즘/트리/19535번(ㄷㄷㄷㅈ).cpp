#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int MAX = 3 * 1e5 + 1;

int n;

vector<int> v[MAX];
int c_num[MAX];
ll dSize = 0;
ll gSize = 0;

inline ll ncr(ll n, ll r)
{
	if (n < r)
		return 0;
	if (r == 2LL)
		return n *(n - 1) / 2LL;
	if (r == 3LL)
		return n * (n - 1) * (n - 2) / 6LL;
}

void DFS(int node, int p)
{
	for (auto next : v[node])
	{
		if (next != p)
		{
			c_num[node] += 1;
			for (int i = 0; i < n; i++)
				cout << c_num[i] << " ";
			cout << "\n";
			DFS(next, node);
		}
	}

	cout << "p는 " << p << " "<< ~p <<"\n";
	if (~p) 
	{
		gSize += ncr(c_num[node], 2LL);
		for (auto next : v[node])
		{
			if (next != p)
				dSize += c_num[next];
		}
	}

	gSize += ncr(c_num[node], 3LL);
	for (auto next : v[node])
	{
		if (next != p)
		{
			dSize += c_num[next] * (c_num[node] - 1);
		}
	}
	return;
}

int main()
{
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(1, -1);

	if (dSize == gSize * 3)
	{
		cout << "DUDUDUNGA" << "\n";
	}
	else
	{
		if (dSize > gSize * 3)
			cout << "D";
		else
			cout << "G";
	}
}
