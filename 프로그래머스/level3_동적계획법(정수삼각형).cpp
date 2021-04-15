#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 501;
int cache[MAX][MAX];

int search(vector<vector<int>> &t ,int y, int x)
{
	if (y >= t.size() || x >= t.size())
		return 0;

	int &ret = cache[y][x];

	if (ret != -1)
		return ret;

	ret = max(search(t, y + 1, x) + t[y][x], search(t, y + 1, x + 1) + t[y][x]);
	return ret;
}

int solution(vector<vector<int>> t)
{
	int answer = 0;
	memset(cache, -1, sizeof(cache));
	answer = search(t, 0, 0);
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> t =  { { 7 }, { 3, 8 }, { 8, 1, 0 }, { 2, 7, 4, 4 }, { 4, 5, 2, 6, 5 } };
	
	cout << solution(t) << "\n";
}
