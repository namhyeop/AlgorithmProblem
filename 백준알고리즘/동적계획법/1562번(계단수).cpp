#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 100 + 1;
const int MOD = 1e9;

int n;
int cache[10][MAX][1024]; //시작수, 자리수길이, 한자리숫자 체크 배열

int stairNum(int start, int length, int number)
{
	if (length == n)
		return number == (1 << 10) - 1 ? 1 : 0; //0 ~9 모두 등장했으면 기저사례이다.

	int &ret = cache[start][length][number];
	if (ret != -1)
		return ret;

	ret = 0;
	if (start - 1 >= 0)
		ret += stairNum(start - 1, length + 1, number | 1 << (start - 1));
	if (start + 1 < 10)
		ret += stairNum(start + 1, length + 1, number | 1 << (start + 1));
	ret %= MOD;
	return ret;
}

int main(void)
{
	fastio;
	cin >> n;
	int ret = 0;
	
	for (int start = 1; start <= 9; start++)
	{
		memset(cache, -1, sizeof(cache));
		ret += stairNum(start, 1, 1 << start);
		ret %= MOD;
	}
	cout << ret << '\n';
	return 0;
}
