//20210904 객체지향적 코드
#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 50;
int board[MAX][MAX];
int n, m;

//+3 % 4
//북동남서
//남서북동
int moveY[] = {-1,0,1,0};
int moveX[] = {0,1,0,-1};
int backY[] = {1,0,-1,0};
int backX[] = {0,-1,0,1};

struct Robot{
    int n, m, dir,cnt;
    pair<int,int> pos;
    vector<vector<int>> board;
    bool visited[MAX][MAX];

    Robot(int n, int m) : n(n), m(m), cnt(1), board(n,vector<int>(m)){}

    void init()
    {
        memset(visited, false, sizeof visited); //?
        cin >> pos.first >> pos.second >> dir;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cin >> board[i][j];
        }
        visited[pos.first][pos.second] = true;
    }

    void search(int y, int x, int d)
    {

        for(int i = d; i > d - 4; i--)
        {
            int tmpd = (i + 3) % 4;
            int ny = y + moveY[tmpd];
            int nx = x + moveX[tmpd];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if(!visited[ny][nx] && board[ny][nx] == 0)
            {
                cnt++;
                visited[ny][nx] = true;
                search(ny, nx, tmpd);
                return;
            }
        }

        if(board[y + backY[d]][x + backX[d]] == 1)
            return;
        else
            search(y + backY[d], x + backX[d], d);
    }
};

int main(void)
{
    fastio;
    cin >> n >> m;
    Robot R(n, m);
    R.init();
    R.search(R.pos.first, R.pos.second, R.dir);
    cout << R.cnt <<"\n";
}
/*
//20210609
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
int board[MAX][MAX];
int moveY[] = { -1, 0, 1, 0 };
int moveX[] = { 0, 1, 0, -1 };
int backY[] = { 1, 0, -1, 0 };
int backX[] = { 0, -1, 0, 1 };
int n, m;
int cnt;
int main(void)
{
	fastio;
	cin >> n >> m;

	int y, x, dir;
	cin >> y >> x >> dir;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	function<void(int, int, int)> dfs = [&](int y, int x, int d)
	{
		if (board[y][x] == 0)
		{
			cnt++;
			board[y][x] = 23002300;
		}

		for (int i = d; i > d - 4; i--)
		{
			int dir = (i + 3) % 4;
			int nextY = y + moveY[dir];
			int nextX = x + moveX[dir];

			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m)
			if (board[nextY][nextX] == 0)
			{
				dfs(nextY, nextX, dir);
				return;
			}
		}

		if (board[y + backY[d]][x + backX[d]] == 1)
			return;
		else
			dfs(y + backY[d], x + backX[d], d);
	};
	dfs(y, x, dir);
	cout << cnt << "\n";
}
*/

/*
#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int n, m;
pair<int, int> start;
int dir;
int board[MAX][MAX];
int moveY[] = { -1, 0, 1, 0 };
int moveX[] = { 0, 1, 0, -1 };
int backY[] = { 1, 0, -1, 0 };
int backX[] = { 0, -1, 0, 1 };
bool visited[MAX][MAX];
int testvisited[MAX][MAX];
int cnt = 0;

void search(int y, int x, int cur)
{
	if (board[y][x] == 0)
	{
		cnt++;
		board[y][x] = 2;
	}
	for (int k = cur-1; k >cur -5; k--)
	{
		int nk = (k + 4) % 4;
		int nextY = y + moveY[nk];
		int nextX = x + moveX[nk];

		if (0 <= nextY && nextY < n - 1 && 0 <= nextX && nextX < m -1)
		if (board[nextY][nextX] == 0)
		{
			search(nextY, nextX, nk);
			return;
		}
	}
	
		if (board[y + backY[cur]][x + backX[cur]] == 1)
			return;
		else
			search(y + backY[cur], x + backX[cur], cur);
	
}
int main(void)
{
	cin >> n >> m;
	cin >> start.first >> start.second >> dir;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> board[i][j];

	search(start.first, start.second, dir);

	cout << cnt << "\n";
	return 0;
}
*/
