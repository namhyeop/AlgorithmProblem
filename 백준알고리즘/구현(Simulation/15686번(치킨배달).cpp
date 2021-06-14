#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 51;

int n, m;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
bool visited[MAX];
int board[MAX][MAX];
int ret = INT_MAX;

int calculator(pair<int, int> a, pair<int, int> b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
};

void DFS(int level, int cnt)
{
	if (cnt == m)
	{
		int tmpRet = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int dist = INT_MAX;
			for (int j = 0; j < chicken.size(); j++)
			if (visited[j])
				dist = min(dist, calculator(house[i], chicken[j]));
			tmpRet += dist;
		}
		ret = min(ret, tmpRet);
		return;
	}

	if (level == chicken.size()) //생각해보자. DFS 트리를 만들면서 아무것도 선택하지 않아서 level이 치킨집들의 갯수를 초과하여 무한 루프에 빠지는 예외처리를 해줘야 하는 경우가 있다.
		return;

	visited[level] = true;
	DFS(level + 1, cnt + 1); //해당 치킨집을 선택하는 경우
	visited[level] = false;
	DFS(level + 1, cnt); //선택하지 않는 경우
	
	//오답. 저는 위에 아래가 같은 DFS라 생각하는데 내부로직은 그렇지 않는데 이유를 모르겠습니다.
	//답 : 이렇게 하면 정답은 똑같이 나오는데 각 탐색마다 위에 방법은 두 가지만 논하면 되는데 이 방식은
	//치킨의 갯수만큼 탐색을 들어가면서 시간초과가 발생함. 비효율적인 방법
	/*for (int i = level; i < chicken.size(); i++)
	{
		visited[level] = true;
		DFS(level + 1, cnt + 1);
		visited[level] = false;
		DFS(level + 1, cnt);
	}*/
}

int main(void)
{
	fastio;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 2)
			chicken.push_back({ i, j });
		else if (board[i][j] == 1)
			house.push_back({ i, j });
	}

	DFS(0, 0);
	cout << ret << "\n";
}

/*
#include<bits/stdc++.h>

using namespace std;

int board[55][55];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 1)
			house.push_back({ i, j });
		if (board[i][j] == 2)
			chicken.push_back({ i, j });
	}
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);

	int mn = INT_MAX;
	do
	{
		int dist = 0;
		for (auto h : house) //집 마다 배치한 치킨집 과의 거리중 가장 짧은것들만 더해서 더한뒤 조합중에 가장 거리가 작은 값을 구한다
		{
			int tmp = INT_MAX;
			for (int i = 0; i < chicken.size(); i++)
			{
				if (brute[i] == 0)
					continue;
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	} while (next_permutation(brute.begin(), brute.end()));
	cout << mn;

	return 0;
}
*/
