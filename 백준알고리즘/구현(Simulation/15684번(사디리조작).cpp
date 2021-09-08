#include<bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X, Y) make_pair(X,Y)
#define mt(X, Y) make_tuple(X,Y)
#define mtt(X, Y, Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAXN = 11;
const int MAXH = 31;
int board[MAXH][MAXN];
int n, m, h;
int boardCnt;
bool flag;

int main(void) {
    fastio;
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        board[a - 1][b] = true;
    }

    auto DFS = [&](int y, int cnt, auto&& DFS) -> void{
        if (flag)
            return;

        if (boardCnt == cnt) {
            bool possibleFlag = true;
            //맨 좌측 col부터 시작해서 맨 우측 col까지 사다리를 타면서 내려간다.
            for (int i = 0; i < n; i++) {
                int row = i;
                for (int j = 0; j < h; j++)
                    //오른쪽으로 사다리를 놓은 경우라면
                    if (board[j][row])
                        row++;//출구 위치 증가
                        //좌측으로 사다리가 놓여져 있는 경우라면
                        else if (1 < row && board[j][row - 1])
                            row--;//출구 위치 감소

                            //출구 위치와 사다리를 타기 시작한 i위치가 다르다면 멈춤
                            if (i != row) {
                                possibleFlag = false;
                                break;
                            }
            }
            //출구 위치와 사다리를 타기 시작한 위치가 true라면 참
            if (possibleFlag)
                flag = true;
            return;
        }
        for(int i = y; i < h; i++){
            for(int j = 1; j <n; j++){
                //2개의 가로선이 연속하거나 서로 접하면 안된다.
                if(!board[i][j -1] && !board[i][j] && !board[i][j + 1]){
                    board[i][j] = true;
                    DFS(i, cnt + 1, DFS);
                    board[i][j] = false;
                }
            }
        }
        return;
    };

    for (int i = 0; i <= 3; i++) {
        boardCnt = i;
        DFS(0, 0, DFS);
        if (flag) {
            cout << boardCnt << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
}

/*
#include<bits/stdc++.h/*>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 31;
int board[MAX][11];
int n, m, h;
int boardCnt;
bool flag;

int main(void)
{
	fastio;
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int y, x;
		cin >> y >> x;
		board[y - 1][x] = true;
	}

	function<void(int, int)> DFS = [&](int y, int cnt)
	{
		if (flag)
			return;

		if (boardCnt == cnt)
		{
			bool possibleflag = true;
			for (int i = 1; i <= n; i++)
			{
				int row = i;
				for (int j = 0; j < h; j++)
				if (board[j][row])
					row++;
				else if (1 < row && board[j][row -1])
					row--;
				
				if (i != row)
				{
					possibleflag = false;
					break;
				}
			}
			if (possibleflag)
				flag = true;
			return;
		}

		for (int i = y; i < h; i++) //순서대로 한 개씩 사디리를 놓아보는 과정 
		for (int j = 1; j < n; j++)
		if (!board[i][j - 1] && !board[i][j] && !board[i][j + 1])
		{
			board[i][j] = true;
			DFS(i, cnt + 1);
			board[i][j] = false;
		}
		return;
	};

	for (int i = 0; i <= 3; i++)
	{
		boardCnt = i;
		DFS(0, 0);
		if (flag)
		{
			cout << boardCnt << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}*/
/*
#include<bits/stdc++.h>
#define MAX 30
using namespace std;

int n, m, h;

int ladder[MAX][11];
int ladderCnt;
bool flag;

void DFS(int y, int cnt)
{
	if (flag)
		return;

	if (ladderCnt == cnt)
	{
		bool possible = true;
		for (int i = 1; i <= n; i++)
		{
			int row = i;
			for (int j = 0; j < h; j++)
			if (ladder[j][row])
				row++;
			else if (row > 1 && ladder[j][row - 1])
				row--;

			if (row != i)
			{
				possible = false;
				break;
			}
		}
		if (possible)
			flag = true;
		return;
	}

	for (int i = y; i < h; i++)
	for (int j = 1; j < n; j++)
	if (!ladder[i][j - 1] && !ladder[i][j] && !ladder[i][j + 1])
	{
		ladder[i][j] = true;
		DFS(i, cnt + 1);
		ladder[i][j] = false;
	}
	return;
}

int main(void)
{
	cin >> n >> m >> h;

	for (int i = 0; i < m; i++)
	{
		int y, x;
		cin >> y >> x;
		ladder[y - 1][x] = true;
	}

	for (int i = 0; i <= 3; i++)
	{
		ladderCnt = i;
		DFS(0, 0);
		if (flag)
		{
			cout << ladderCnt << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
}
*/
