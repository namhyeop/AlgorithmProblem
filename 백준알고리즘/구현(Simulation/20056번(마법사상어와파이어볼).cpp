#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 51;

struct Fireball
{
	int r, c, m, s, d;
	Fireball(int r, int c, int m, int s, int d) : r(r), c(c), m(m), s(s), d(d) {}
};

int n, m, k;
vector<Fireball> board[MAX][MAX];

int moveY[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int moveX[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(void)
{
	fastio;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		r--, c--;
		board[r][c].push_back({ r, c, m, s, d });
	}

	auto move = [&]()
	{
		vector<Fireball> tmpboard[50][50];

		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			for (auto unit : board[i][j])
			{
				for (int i = 0; i < unit.s; i++)
				{
					unit.r += moveY[unit.d];
					if (unit.r == n)
						unit.r = 0;
					else if (unit.r == -1)
						unit.r = n - 1;

					unit.c += moveX[unit.d];
					if (unit.c == n)
						unit.c = 0;
					else if (unit.c == -1)
						unit.c = n - 1;
				}
				tmpboard[unit.r][unit.c].push_back({ unit.r, unit.c, unit.m, unit.s, unit.d });
			}
		}
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = tmpboard[i][j];
	};

	auto merge = [&]()
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j].size() < 2)
				continue;

			int size = board[i][j].size();
			int mSum = 0;
			int sSum = 0;
			//모두 홀수면 4 짝수면 -4;
			int cnt = 0;
			for (auto unit : board[i][j])
			{
				sSum += unit.s;
				mSum += unit.m;
				unit.m = 0;
				if (unit.d & 1)
					cnt++;
				else
					cnt--;
			}

			board[i][j].clear();

			if (mSum / 5 == 0)
				continue;

			int dir = (abs(cnt) == size ? 0 : 1);
			for (int k = 0; k < 4; k++)
			{
				board[i][j].push_back({ i, j, mSum / 5, sSum / size, dir});
				dir += 2;
			}
		}
	};

	for (int t = 0; t < k; t++)
	{
		move();
		merge();
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	for (auto unit : board[i][j])
		ret += unit.m;

	cout << ret << "\n";
}

/*
#include<bits/stdc++.h>

using namespace std;

int n, m, k;

int moveY[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int moveX[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct Fire
{
	int r, c, m, s, d;
	Fire(int r, int c, int m, int s, int d) : r(r), c(c), m(m), s(s), d(d) {}
};

vector<Fire> board[50][50];

Fire move(Fire f)
{
	for (int i = 0; i < f.s; i++)
	{
		f.r += moveY[f.d];
		if (f.r == n) // 1행과 n번 행은 열결 되어 있으므로
			f.r = 0;
		else if (f.r == -1)
			f.r = n - 1;

		f.c += moveX[f.d];//1번열과 n번 열은 연결 되어 있으므로
		if (f.c == n)
			f.c = 0;
		else if (f.c == -1)
			f.c = n - 1;
	}
	return f;
}

void moveFireballs()
{
	vector<Fire> newBoard[50][50];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (Fire f : board[i][j])
			{
				Fire next = move(f);
				newBoard[next.r][next.c].push_back(next);
			}
		}
	}

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		board[i][j] = newBoard[i][j];
}

void unionFireballs()
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (board[i][j].size() < 2)
			continue;
		
		int size = board[i][j].size();	
		int sumM = 0;
		int sumS = 0;
		int check = 0;

		for (Fire f : board[i][j])
		{
			sumM += f.m;
			sumS += f.s;
			if (f.d % 2 == 0) //2-3번 조건의 합쳐지는 파이어볼의 방향이 모두 홀수이거나 짝수일 경우
				check++;
			else
				check--;
		}

		board[i][j].clear();

		if (sumM / 5 == 0)
			continue;

		for (int k = 0; k < 4; k++)
		{
			if (abs(check) == size)
				board[i][j].push_back({ i, j, sumM / 5, sumS / size, k * 2 });
			else
				board[i][j].push_back({ i, j, sumM / 5, sumS / size, k * 2 + 1 });
		}
	}
}
int main(void)
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		board[r - 1][c - 1].push_back({ r - 1, c - 1, m, s, d });
	}

	while (k--)
	{
		moveFireballs();
		unionFireballs();
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	for (Fire f : board[i][j])
		ans += f.m;

	cout << ans << "\n";

	return 0;
}
*/
