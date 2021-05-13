#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

const int MAX = 101;
int N, M, R;
int board[MAX][MAX];
vector<tuple<int,int,char>> attack;
vector<tuple<int, int>> shild;
map<char, pair<int, int>> m;
bool visited[MAX][MAX];
int cnt = 0;
int main(void)
{
	m['E'] = { 0, 1 };
	m['W'] = { 0, -1 };
	m['S'] = { 1, 0 };
	m['N'] = { -1, 0 };

	auto operate_attack = [&](int y, int x, char dir)
	{
		queue<tuple<int, int, char>> q;
		q.push(make_tuple(y, x, dir));

		while (!q.empty())
		{
			int curY = get<0>(q.front());
			int curX = get<1>(q.front());
			tuple<int,int> d = m[get<2>(q.front())];
			q.pop();

			if (!visited[curY][curX])
			{
				visited[curY][curX] = true;
				cnt++;
			}

			int nextY = curY;
			int nextX = curX;
			for (int i = 0; i < board[curY][curX] - 1; i++)
			{
				nextY += get<0>(d);
				nextX += get<1>(d);

				if (!visited[nextY][nextX] && nextY <= N && nextX <= M && nextX >= 1 && nextY >= 1)
				{
					visited[nextY][nextX] = true;
					cnt++;
					q.push(make_tuple(nextY, nextX, dir));
				}
			}
		}
	};

	auto operate_shild = [&](int y, int x)
	{
		visited[y][x] = false;
	};

	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
	for (int j = 1; j <= M; j++)
		cin >> board[i][j];

	for (int i = 0; i < R; i++)
	{
		int tmp1, tmp2, tmp4, tmp5;
		char tmp3;
		cin >> tmp1 >> tmp2 >> tmp3;
		attack.push_back(make_tuple(tmp1, tmp2, tmp3 ));
		cin >> tmp4 >> tmp5;
		shild.push_back(make_tuple(tmp4, tmp5));
	}

	for (int i = 0; i < R; i++)
	{
		operate_attack(get<0>(attack[i]), get<1>(attack[i]), get<2>(attack[i]));
		operate_shild(get<0>(shild[i]), get<1>(shild[i]));
	}

	cout << cnt << "\n";
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visited[i][j] == false)
				cout << "S" << " ";
			else
				cout << "F" << " ";
		}
		cout << "\n";
	}

	return 0;
}
