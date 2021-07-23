#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const ll MAX = 1e6 + 1;
bool visited[MAX + 1];
ll minFactor[MAX];
vector<int> prime;

void eratos(int k)
{
	for (int i = 2; i * i < k; i++)
	{
		if (visited[i] == false)
		{
			for (int j = i * i; j < k; j += i)
				visited[j] = true;
		}
	}
	for (int i = 2; i < k; i++)
	if (!visited[i])
		prime.push_back(i);
}

int main()
{
	fastio;
	string p;
	int k;
	cin >> p >> k;

	eratos(k);

	for (auto primeNumber : prime)
	{
		int div = 0, tmp = 1;
		for (int i = p.length() - 1; i >= 0; i--)
		{
			div = (div + (p[i] - '0') * tmp) % primeNumber;
			tmp *= 10;
			tmp %= primeNumber;
		}
		if (div == 0)
		{
			cout << "BAD" << " " << primeNumber << "\n";
			return 0;
		}
	}
	cout << "GOOD" << "\n";
	return 0;
}

/*
div = (div + 6 * (1 % 7) % 7) % 7
div = (div + 5 * (10 % 7) % 7) % 7
div = (div + 4 * (100 % 7) % 7) % 7
...
*/
