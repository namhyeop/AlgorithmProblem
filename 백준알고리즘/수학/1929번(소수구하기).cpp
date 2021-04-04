#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 1e7;
long long m, n;
bool visited[MAX+2];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;

	visited[1] = true;
	long long value = sqrt(MAX);
	for (int i = 2; i <= value; i++)
	{
		if (visited[i] == false)
		{
			for (int j = i*i; j <= MAX; j += i)
				visited[j] = true;
		}
	}

	for (int i = m; i <= n; i++)
		if (!visited[i])
			cout << i << "\n";
	
	return 0;
}
