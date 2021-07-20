#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 50;
string word[MAX];
bool visited[26];
int n, k;
int ret;

int main(void)
{
	fastio;
	cin >> n >> k;

	if (k < 5)
	{
		cout << 0 << "\n";
		return 0;
	}
	
	if (k == 26)
	{
		cout << n << "\n";
		return 0;
	}

	k -= 5;
	for (int i = 0; i < n; i++)
	{
		cin >> word[i];
		word[i] = word[i].substr(4, word[i].length() - 1 - 4);
	}

	visited['a' - 'a'] = true;
	visited['c' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;

	function<void(int, int)> DFS = [&](int alpha, int cnt)
	{
		if (cnt == k)
		{
			int tmpCnt = 0;
			for (int i = 0; i < n; i++)
			{
				bool flag = false;
				for (int j = 0; j < word[i].length(); j++)
				{
					if (!visited[word[i][j] - 'a'])
					{
						flag = true;
						break;
					}
				}
				if (!flag)
					tmpCnt++;
			}
			ret = max(ret, tmpCnt);
			return;
		}

		for (int i = alpha; i < 26; i++)
		{
			if (!visited[i])
			{
				visited[i] = true;
				DFS(i, cnt + 1);
				visited[i] = false;
			}
		}
	};
	DFS(0, 0);

	cout << ret << "\n";
}
