#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 60001;
const int mod = 1000000007;
int cache[MAX];
int search(int n)
{
	if (n < 0)
		return 0;

	if (n == 0)
		return 1;

	int &ret = cache[n];

	if (ret != -1)
		return cache[n];

	ret = (search(n - 1) + search(n - 2)) % mod;
	return ret;
}

int solution(int n)
{
	int answer = 0;
	memset(cache, -1, sizeof(cache));
	answer = search(n);
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n = 4;
	cout << solution(n) << "\n";
}
