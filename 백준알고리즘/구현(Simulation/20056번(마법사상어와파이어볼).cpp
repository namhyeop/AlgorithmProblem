#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAX = 55;

int my[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int mx[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct fire {
    int m, s, d;
};

struct play {
    int n, m, k;
    vector<fire> board[MAX][MAX];
    play(int n, int m, int k) : n(n), m(m), k(k) {}

    void init() {
        for (int i = 0; i < m; i++) {
            int y, x, m, s, d;
            cin >> y >> x >> m >> s >> d;
            y--, x--;
            board[y][x].push_back({m, s, d});
        }
    }

    void moveFire() {
        vector<fire> tmpboard[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (auto f : board[i][j]) {
                    int ny = i, nx = j;
                    for (int i = 0; i < f.s; i++) {
                        ny += my[f.d];
                        if (ny == n)
                            ny = 0;
                        else if (ny == -1)
                            ny = n - 1;

                        nx += mx[f.d];
                        if (nx == n)
                            nx = 0;
                        else if (nx == -1)
                            nx = n - 1;
                    }
                    tmpboard[ny][nx].push_back({f.m, f.s, f.d});
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = tmpboard[i][j];
    }

    void mergefire() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j].size() < 2)
                    continue;

                int msum = 0, ssum = 0;
                int size = board[i][j].size();
                int cnt = 0;
                vector<int> dlist;
                for (auto f : board[i][j]) {
                    msum += f.m;
                    ssum += f.s;
                    f.m = 0;
                    dlist.push_back(f.d);
                }
                board[i][j].clear();

                if(msum / 5 == 0)
                    continue;

                int m = msum / 5;
                int s = ssum / size;
                int dir = getDir(dlist);

                for (int d = dir; d <= 7; d += 2) {
                    board[i][j].push_back({m, s, d});
                }
            }
        }
    }

    int getDir(vector<int> &dlist) {
        int cre = dlist[0] % 2;
        for (int i = 1; i < dlist.size(); i++) {
            int num = dlist[i] % 2;
            if (cre != num) //모두 같지 않으면 1 3 5 7
                return 1;
        }
        return 0;//모두 같으면 0 2 4 6
    }
};

int main() {
    fastio;
    int n, m, k;
    cin >> n >> m >> k;
    play op(n, m, k);
    op.init();
    for (int i = 0; i < k; i++) {
        op.moveFire();
        op.mergefire();
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto f : op.board[i][j]) {
                sum += f.m;
            }
        }
    }
    cout << sum << "\n";

    return 0;
}

//#include<bits/stdc++.h>
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pii pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define mt(X,Y) make_tuple(X,Y)
//#define mtt(X,Y,Z) make_tuple(X,Y,Z)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//const int MAX = 51;
//
//struct Fireball
//{
//	int r, c, m, s, d;
//	Fireball(int r, int c, int m, int s, int d) : r(r), c(c), m(m), s(s), d(d) {}
//};
//
//int n, m, k;
//vector<Fireball> board[MAX][MAX];
//
//int moveY[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int moveX[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//
//int main(void)
//{
//	fastio;
//	cin >> n >> m >> k;
//
//	for (int i = 0; i < m; i++)
//	{
//		int r, c, m, s, d;
//		cin >> r >> c >> m >> s >> d;
//		r--, c--;
//		board[r][c].push_back({ r, c, m, s, d });
//	}
//
//	auto move = [&]()
//	{
//		vector<Fireball> tmpboard[50][50];
//
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			for (auto unit : board[i][j])
//			{
//				for (int i = 0; i < unit.s; i++)
//				{
//					unit.r += moveY[unit.d];
//					if (unit.r == n)
//						unit.r = 0;
//					else if (unit.r == -1)
//						unit.r = n - 1;
//
//					unit.c += moveX[unit.d];
//					if (unit.c == n)
//						unit.c = 0;
//					else if (unit.c == -1)
//						unit.c = n - 1;
//				}
//				tmpboard[unit.r][unit.c].push_back({ unit.r, unit.c, unit.m, unit.s, unit.d });
//			}
//		}
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			board[i][j] = tmpboard[i][j];
//	};
//
//	auto merge = [&]()
//	{
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			if (board[i][j].size() < 2)
//				continue;
//
//			int size = board[i][j].size();
//			int mSum = 0;
//			int sSum = 0;
//			//모두 홀수면 4 짝수면 -4;
//			int cnt = 0;
//			for (auto unit : board[i][j])
//			{
//				sSum += unit.s;
//				mSum += unit.m;
//				unit.m = 0;
//				if (unit.d & 1)
//					cnt++;
//				else
//					cnt--;
//			}
//
//			board[i][j].clear();
//
//			if (mSum / 5 == 0)
//				continue;
//
//			int dir = (abs(cnt) == size ? 0 : 1);
//			for (int k = 0; k < 4; k++)
//			{
//				board[i][j].push_back({ i, j, mSum / 5, sSum / size, dir});
//				dir += 2;
//			}
//		}
//	};
//
//	for (int t = 0; t < k; t++)
//	{
//		move();
//		merge();
//	}
//
//	int ret = 0;
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//	for (auto unit : board[i][j])
//		ret += unit.m;
//
//	cout << ret << "\n";
//}
//
///*
//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n, m, k;
//
//int moveY[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int moveX[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//
//struct Fire
//{
//	int r, c, m, s, d;
//	Fire(int r, int c, int m, int s, int d) : r(r), c(c), m(m), s(s), d(d) {}
//};
//
//vector<Fire> board[50][50];
//
//Fire move(Fire f)
//{
//	for (int i = 0; i < f.s; i++)
//	{
//		f.r += moveY[f.d];
//		if (f.r == n) // 1행과 n번 행은 열결 되어 있으므로
//			f.r = 0;
//		else if (f.r == -1)
//			f.r = n - 1;
//
//		f.c += moveX[f.d];//1번열과 n번 열은 연결 되어 있으므로
//		if (f.c == n)
//			f.c = 0;
//		else if (f.c == -1)
//			f.c = n - 1;
//	}
//	return f;
//}
//
//void moveFireballs()
//{
//	vector<Fire> newBoard[50][50];
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			for (Fire f : board[i][j])
//			{
//				Fire next = move(f);
//				newBoard[next.r][next.c].push_back(next);
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//		board[i][j] = newBoard[i][j];
//}
//
//void unionFireballs()
//{
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//	{
//		if (board[i][j].size() < 2)
//			continue;
//
//		int size = board[i][j].size();
//		int sumM = 0;
//		int sumS = 0;
//		int check = 0;
//
//		for (Fire f : board[i][j])
//		{
//			sumM += f.m;
//			sumS += f.s;
//			if (f.d % 2 == 0) //2-3번 조건의 합쳐지는 파이어볼의 방향이 모두 홀수이거나 짝수일 경우
//				check++;
//			else
//				check--;
//		}
//
//		board[i][j].clear();
//
//		if (sumM / 5 == 0)
//			continue;
//
//		for (int k = 0; k < 4; k++)
//		{
//			if (abs(check) == size)
//				board[i][j].push_back({ i, j, sumM / 5, sumS / size, k * 2 });
//			else
//				board[i][j].push_back({ i, j, sumM / 5, sumS / size, k * 2 + 1 });
//		}
//	}
//}
//int main(void)
//{
//	cin >> n >> m >> k;
//
//	for (int i = 0; i < m; i++)
//	{
//		int r, c, m, s, d;
//		cin >> r >> c >> m >> s >> d;
//		board[r - 1][c - 1].push_back({ r - 1, c - 1, m, s, d });
//	}
//
//	while (k--)
//	{
//		moveFireballs();
//		unionFireballs();
//	}
//
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//	for (Fire f : board[i][j])
//		ans += f.m;
//
//	cout << ans << "\n";
//
//	return 0;
//}
//*/
