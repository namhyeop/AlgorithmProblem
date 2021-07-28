#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 31;
const int INF = INT_MAX;
int moveY[] = { 1, -1, 0, 0 };
int moveX[] = { 0, 0, -1, 1 };
bool cycleFlag;
int board[MAX][MAX];
ll dist[MAX][MAX];

struct edge
{
	pair<int, int> start, end;
	int cost;

	edge(pair<int, int> start, pair<int, int> end, int cost) : start(start), end(end), cost(cost) {};
};
vector<edge> v;

int main(void)
{
	fastio;
	while (1)
	{
		fill(&board[0][0], &board[MAX - 1][MAX], 0);
		v.clear();
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		//묘비 부분
		int g;
		cin >> g;
		for (int i = 0; i < g; i++)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = -1; //묘비가 설치 되어있는 곳은 -1로 설정
		}
		//귀신구멍 부분
		int e;
		cin >> e;
		for (int i = 0; i < e; i++)
		{
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			board[y1][x1] = 1; //귀신구멍 체크
			v.push_back({ { y1, x1 }, { y2, x2 }, t });
		}

		auto addEdge = [&]()
		{
			for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				//길이 아니거나(묘비이거나), 귀신구멍이거나 도착지이면 continue;
				if (board[i][j] != 0 || (i == h - 1 && j == w - 1))
					continue;
				for (int k = 0; k < 4; k++)
				{
					int nextY = i + moveY[k];
					int nextX = j + moveX[k];
					if (nextY >= 0 && nextY < h && nextX >= 0 && nextX < w && board[nextY][nextX] >= 0)
					{
						v.push_back({ { i, j }, { nextY, nextX }, 1 });
					}
				}
			}
		};

		auto BellmanFord = [&]()
		{
			//시작지점이 0일때부터 탐색해야하므로 모든 배열을 INF로 초기화
			for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				dist[i][j] = INF;

			//시작 거리 0 설정
			dist[0][0] = 0;
			//n - 1번 동안 간선 w을 모두 확인, 마지막 W*h가 되는 순간에는 사이클을 검사
			for (int i = 0; i <= w * h; i++)
			{
				for (edge cur : v)
				{
					pair<int, int> start = cur.start;
					pair<int, int> end = cur.end;
					int cost = cur.cost;

					//귀신구멍 출발지가 현재 무한대가 아니고, 무한대면 아직 탐색순서가 아님
					//마지막 검사시에 값이 변경될 경우 cycle이 발생한것이므로 탐색 불가능
					if (dist[start.first][start.second] != INF && dist[end.first][end.second] > dist[start.first][start.second] + cost)
					{
						dist[end.first][end.second] = dist[start.first][start.second] + cost;
						if (w * h == i)
							cycleFlag = true;
					}
				}
			}
		};

		cycleFlag = false;
		addEdge();
		BellmanFord();

		if (cycleFlag)
			cout << "Never\n";
		else if (dist[h - 1][w - 1] == INF)
			cout << "Impossible\n";
		else
			cout << dist[h - 1][w - 1] << "\n";
	}
}
