#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int INF = 23002300;
const int MAX = 2505;
string str;
char s[MAX];
int cache[MAX][MAX];
int minResult[MAX];

bool isPalindrom(int start, int end)
{
	if (start >= end)
		return 1;

	int &ret = cache[start][end];

	if (ret != -1)
		return ret;

	if (s[start] != s[end])
	{
		ret = 0;
		return ret;
	}
	return ret = isPalindrom(start + 1, end - 1);
}

int getminValue()
{
	minResult[0] = 0;
	for (int i = 1; i <= str.length(); i++)
	{
		minResult[i] = INF;
		for (int j = 1; j <= i; j++)
		{
			if (isPalindrom(j, i))
			{
				minResult[i] = min(minResult[i], minResult[j - 1] + 1);
			}
		}
	}
	return minResult[str.length()];
}

int main(void)
{
	fastio;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		s[i + 1] = str[i];
	memset(cache, -1, sizeof(cache));
	cout << getminValue() << "\n";
}
