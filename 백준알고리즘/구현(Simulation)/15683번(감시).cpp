#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X, Y) make_pair(X,Y)
#define mt(X, Y) make_tuple(X,Y)
#define mtt(X, Y, Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()
/*
4 6
0 0 0 0 0 0
0 0 6 0 0 0
0 6 3 6 0 0
0 0 6 0 0 0
 */
using namespace std;
const int MAX = 9;
int n, m;
int board[MAX][MAX];
int ret = INT_MAX;

vector<pair<int, int>> cctv;

int main(void) {
    cout << (1 << 6) <<"\n";
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5)
                cctv.push_back({i, j});
        }
    }

    //board의 안전구역을 탐핵한다.
    auto search = [&](int b[MAX][MAX]) -> int {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (b[i][j] == 0)
                    cnt++;
                return cnt;
    };

    //y축인 경우에 0이 아니라면 음수 연산을 취한뒤 변경해주면 4방향으로 회전이 가능하다.
    auto rotate = [&](vector<pair<int, int>> &dir) {
        for (int i = 0; i < dir.size(); i++) {
            if(dir[i].first != 0)
            {
                dir[i].first *= -1;
                dir[i].second *= -1;
                swap(dir[i].first, dir[i].second);
            }
            else
                swap(dir[i].first, dir[i].second);
        }
    };

    //방향 값을 가지고 안전구역을 체크한다.
    auto check = [&](int level, int tmpboard[MAX][MAX], vector<pair<int, int>> &dir) {
        pair<int, int> pos = cctv[level];

        for (int i = 0; i < dir.size(); i++) {
            int ny = pos.first;
            int nx = pos.second;
            while (1) {
                ny += dir[i].first;
                nx += dir[i].second;
                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    break ;
                if(tmpboard[ny][nx] == 6)
                    break ;
                if (tmpboard[ny][nx] == 0)
                    tmpboard[ny][nx] = 23002300;
            }
        }
    };

    auto DFS = [&](int level, int b[MAX][MAX], auto &&DFS) -> void {
        if (cctv.size() == level) {
            ret = min(ret, search(b));
            return;
        }
        int cycle = 0;
        vector<pair<int, int>> dir;

        if (board[cctv[level].first][cctv[level].second] == 1) { //1번 CCTV인 경우
            cycle = 4;
            dir.push_back({0, 1});
        } else if (board[cctv[level].first][cctv[level].second] == 2) { //2번 CCTV인 경우
            cycle = 2;
            dir.push_back({0, 1}), dir.push_back({0, -1});
        } else if (board[cctv[level].first][cctv[level].second] == 3) { //3번 CCTV인 경우
            cycle = 4;
            dir.push_back({-1, 0}), dir.push_back({0, 1});
        } else if (board[cctv[level].first][cctv[level].second] == 4) { //4번 CCTV인 경우
            cycle = 4;
            dir.push_back({-1, 0}), dir.push_back({0, 1}), dir.push_back({0, -1});
        } else if (board[cctv[level].first][cctv[level].second] == 5) { //5번 CCTV인 경우
            cycle = 1;
            dir.push_back({-1, 0}), dir.push_back({0, 1}), dir.push_back({1, 0}), dir.push_back({0, -1});
        }

        int tmpboard[MAX][MAX];
        for (int i = 0; i < cycle; i++) {
            memcpy(tmpboard, b, sizeof tmpboard);
            //방향 값들을 회전 시킨다.
            rotate(dir);
            //보드의 방향으로 감시영역을 체크해준다.
            check(level, tmpboard, dir);
            //다음 CCTV에서 탐색이 가능한 경우를 위해 DFS 탐색에 들어간다.
            DFS(level + 1, tmpboard, DFS);
        }
        return;
    };

    DFS(0, board, DFS);

    cout << ret << "\n";
    return 0;
}

//#include<bits/stdc++.h>
//#define MAX 8
//#define BLOCK 6
//using namespace std;
//
//int n, m;
//vector <pair<pair<int, int>, int> > input;
//int board[MAX][MAX];
//int ret = INT_MAX;
//int direction [5][4][2] =
//{
//	{ { 0, 1 } },
//	{ { 0, -1 }, { 0, 1 } },
//	{ { -1, 0 }, { 0, 1 } },
//	{ { -1, 0 }, { 0, 1 }, { 0, -1 } },
//	{ { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } }
//};
//
//void search(int level, int board[][MAX])
//{
//	if (input.size() == level)
//	{
//		int cnt = 0;
//
//		for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//		{
//			if (board[i][j] == 0)
//				cnt++;
//		}
//		ret = min(ret, cnt);
//		return;
//	}
//
//	int cctvNum = input[level].second;
//	int cycleValue;
//	int cursor;
//	switch (cctvNum)
//	{
//	case 0:
//		cycleValue = 4;
//		cursor = 1;
//		break;
//	case 2:
//		cycleValue = 4;
//		cursor = 2;
//		break;
//	case 3:
//		cycleValue = 4;
//		cursor = 3;
//		break;
//	case 1:
//		cycleValue = 2;
//		cursor = 2;
//		break;
//	default:
//		cycleValue = 1;
//		cursor = 4;
//		break;
//	}
//
//	for (int i = 0; i < cycleValue; i++)
//	{
//		int y = input[level].first.first;
//		int x = input[level].first.second;
//
//
//		int tmpboard[MAX][MAX];
//		memcpy(tmpboard, board, sizeof(tmpboard));
//		for (int j = 0; j < cursor; j++)
//		{
//			int nextY = y + direction[cctvNum][j][0];
//			int nextX = x + direction[cctvNum][j][1];
//			while (1)
//			{
//				if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m)
//				{
//					if (tmpboard[nextY][nextX] != 6)
//						tmpboard[nextY][nextX] = '#';
//					else
//						break;
//				}
//				else
//					break;
//
//				nextY += direction[cctvNum][j][0];
//				nextX += direction[cctvNum][j][1];
//			}
//		}
//
//		search(level + 1, tmpboard);
//
//		for (int i = 0; i < cursor; i++)
//		{
//			int tmp = - 1 * direction[cctvNum][i][0];
//			direction[cctvNum][i][0] = direction[cctvNum][i][1];
//			direction[cctvNum][i][1] = tmp;
//		}
//	}
//}

int main(int argc, char *argv[])
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> board[i][j];
		if (board[i][j] != 0 && board[i][j] != 6)
		{
			input.push_back({ { i, j }, board[i][j] -1 });
		}
	}

	search(0, board);

	cout << ret << "\n";

	return 0;
}

/*
조합론을 활용한 풀이
#include<bits/stdc++.h>
#define MAX 10
using namespace std;

int board1[MAX][MAX];
int board2[MAX][MAX];
int n, m;
int moveY[] = { -1, 0, 1, 0 };
int moveX[] = { 0, 1, 0, -1 };
vector<pair<int, int>> cctv;


bool isValid(int y, int x)
{
	if (y >= 0 && y < n && x >= 0 && x < m)
		return true;
	return false;
}
void upd(int y, int x, int dir)
{
	dir %= 4;
	while (1)
	{
		y += moveY[dir];
		x += moveX[dir];
		if (!isValid(y, x) || board2[y][x] == 6)
			return;
		if (board2[y][x] != 0)
			continue;
		board2[y][x] = 7;
	}
}

int main(void)
{
	cin >> n >> m;

	int mn = 0;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		cin >> board1[i][j];
		if (board1[i][j] != 0 && board1[i][j] != 6)
			cctv.push_back({ i, j });
		if (board1[i][j] == 0)
			mn++;
	}

	for (int tmp = 0; tmp < (1 << (2 * cctv.size())); tmp++)
	{
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board2[i][j] = board1[i][j];
		int brute = tmp;

		for (int i = 0; i < cctv.size(); i++)
		{
			int dir = brute % 4;
			brute /= 4;
			int y = cctv[i].first;
			int x = cctv[i].second;

			if (board1[y][x] == 1)
			{
				upd(y, x, dir);
			}
			else if (board1[y][x] == 2)
			{
				upd(y, x, dir);
				upd(y, x, dir + 2);
			}
			else if (board1[y][x] == 3)
			{
				upd(y, x, dir);
				upd(y, x, dir + 1);
			}
			else if (board1[y][x] == 4)
			{
				upd(y, x, dir);
				upd(y, x, dir + 1);
				upd(y, x, dir + 2);
			}
			else
			{
				upd(y, x, dir);
				upd(y, x, dir + 1);
				upd(y, x, dir + 2);
				upd(y, x, dir + 3);
			}
		}

		int ret = 0;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		if (board2[i][j] == 0)
			ret++;

		mn = min(mn, ret);
	}
	cout << mn;
	
	return 0;
}
*/
