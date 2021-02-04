#include<bits/stdc++.h>
#define MAX 10
using namespace std;
int n, m;
vector<int> v;
vector<int> ret;
bool check[MAX];

void func(int N)
{
	if (N == m)
	{
		for (int i = 0; i < ret.size(); i++)
			cout << ret[i] << " ";
		cout << "\n";
		return;
	}

	bool visited[10000] = { false ,};

	for (int i = 0; i < n; i++)
	{
		if (!visited[v[i]] && !check[i])
		{
			check[i] = true;
			visited[v[i]] = true;
			ret.push_back(v[i]);
			func(N + 1);
			ret.pop_back();
			check[i] = false;
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	
	if (n == 1 && m == 1)
	{
		cout << v[0] << "\n";
		return 0;
	}
	func(0);
}
