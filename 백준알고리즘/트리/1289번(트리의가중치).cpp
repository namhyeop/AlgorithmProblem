#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
#define X first
#define Y second
#define MAX 100001
using namespace std;

const ll MOD = 1000000007ll;
ll distan[MAX];
ll cost = 0;
vector<pair<int, int>> v[MAX];
bool visited[MAX];
int N;

ll mod(ll a)
{
	if (a % MOD < 0) //
		return a%MOD + MOD; //
	return a%MOD;
}

ll square(ll a)
{
	return mod(a*a);
}

void calc(int root)
{
	ll subtree_sum = 0;
	ll add_cost = 0;
	for (auto c : v[root])
	{
 		if (visited[c.X])
			continue;
		visited[c.X] = true;
		calc(c.X);
		ll elem = mod((distan[c.X] + 1) * c.Y);
		subtree_sum = mod(subtree_sum + elem);
		add_cost = mod(add_cost - square(elem));
	}
	add_cost = mod(add_cost + square(subtree_sum));
	if (add_cost % 2 == 0)
		cost = mod(cost + add_cost / 2);
	else
		cost = mod(cost + (add_cost + MOD) / 2);

	distan[root] = mod(subtree_sum);
	cost = mod(cost + distan[root]);
}

int main(int argc, char *argv[])
{
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int node1, node2, value;
		cin >> node1 >> node2 >> value;
		v[node1].push_back({ node2, value });
		v[node2].push_back({ node1, value });
	}
	visited[1] = true;
	calc(1);

	cout << cost << "\n";
	return 0;
}
