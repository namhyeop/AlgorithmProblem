#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int mod = 1000000007;
int cache[101][101];

int search(int y, int x, int &endY, int &endX)
{
	if (y >= endY || x >= endX || cache[y][x] == INT_MIN)
		return 0;

	if (y == endY - 1 && x == endX - 1)
	{
		return 1;
	}
	
	int &ret = cache[y][x];
	
	if (ret != -1)
		return cache[y][x];

	ret = (search(y + 1, x, endY, endX) + search(y, x + 1, endY, endX)) % mod;
	return ret;
}

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < puddles.size(); i++)
		cache[puddles[i][0]-1][puddles[i][1]-1] = INT_MIN;
	answer = search(0, 0,m,n);
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m = 4;
	int n = 3;
	vector<vector<int>> pul = { { 2, 2 } };
	cout << solution(m, n, pul);
}
