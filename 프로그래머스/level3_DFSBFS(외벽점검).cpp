#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()
#define INF 987654321
using namespace std;

int N, minCnt;
vector<int> Weak;
vector<int> Dist;

void solve(int cnt, int pos, int visited) //사용한 친구수, 이 친구의 시작위치(배열의 위치를 의미하는 idx값), 방문여부
{
	/*cout << "======================================" <<"\n";
	cout << "cnt : " << cnt << " Pos: " << pos << " visited: " << visited << "\n";*/
	if (cnt > Dist.size())
		return;
	if (cnt >= minCnt)
		return;

	for (int i = 0; i < Weak.size(); i++)
	{
		int nextPos = (pos + i) % Weak.size();
		int diff = Weak[nextPos] - Weak[pos];
		if (nextPos < pos)
			diff += N;
		
	/*	cout << "nextPos : " << nextPos << " diff : " << diff << "\n";*/
		if (diff > Dist[Dist.size() - cnt])
			break;

		visited |= 1 << nextPos;
		/*cout << "visited : " << visited << "\n";*/
	}

	if (visited == (1 << Weak.size()) - 1)
	{
		minCnt = cnt;
		/*cout << "minCnt : " << minCnt << "\n";*/
		return;
	}

	for (int i = 0; i < Weak.size(); i++)
	{
		if (visited & (1 << i))
			continue;

		solve(cnt + 1, i, visited);
	}
}

int solution(int n, vector<int> weak, vector<int> dist) 
{
	sort(dist.begin(), dist.end());
	N = n;
	Weak = weak;
	Dist = dist;
	minCnt = INF;

	for (int i = 0; i < Weak.size(); i++) //i는 시작위치
	{
		solve(1, i, 0);
	}

	if (minCnt == INF)
		return -1;

	return minCnt;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n = 12;
	vector<int> a = { 1, 5, 6, 10 };
	vector<int> b = { 1, 2, 3, 4 };

	cout << solution(n, a, b) << "\n";

	return 0;
}
