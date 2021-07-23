#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
int n, m, k;
int cache[MAX][MAX];
bool noWordFlag;
string retWord;

int search(int A, int Z)
{
	if (A == 0 || Z == 0)
		return 1;

	int &ret = cache[A][Z];

	if (ret != -1)
		return ret;

	ret = min(search(A - 1, Z) + search(A, Z - 1), 1000000000 + 1);
	return ret;
}

void getWord(int A, int Z, int skip)
{
	if (A == 0)
	{
		for (int i = 0; i < Z; i++)
			retWord += 'z';
		return;
	}
	if (Z == 0)
	{
		for (int i = 0; i < A; i++)
			retWord += 'a';
		return;
	}

	int idx = search(A - 1, Z);
	if (skip < idx)
	{
		retWord += 'a';
		getWord(A - 1, Z, skip);
	}
	else
	{
		retWord += 'z';
		getWord(A, Z - 1, skip - idx);
	}
}

int main(void)
{
	fastio;
	cin >> n >> m >> k;
	memset(cache, -1, sizeof(cache));
	if (k > search(n, m))
		noWordFlag = true;
	else
		getWord(n, m, k - 1);

	if (noWordFlag)
		cout << -1 << "\n";
	else
		cout << retWord << "\n";
	return 0;
}
