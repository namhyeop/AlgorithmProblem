#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 32 + 1;
int n;
int moveY[] = { 0, 1, 1};
int moveX[] = { 1, 1, 0};

int board[MAX][MAX];
ll cache[MAX][MAX][3];

bool isValid(int y, int x, int dir)
{
    //가로  방향으로 나가기 위해서는 우측만 검사 필요
    if (dir == 0)
    {
       for(int k = 0; k < 1; k++)
       {
           int nextY = y + moveY[k];
           int nextX = x + moveX[k];
           if(!(nextY > 0 && nextY <= n && nextX > 0 && nextX <= n && board[nextY][nextX] == 0))
               return false;
       }
    }
    //대각선 방향으로 나가기 위해서는 우측 , 우측 아래, 밑에 모두 검사 필요
    else if(dir == 1)
    {
        for(int k = 0; k < 3; k++)
        {
            int nextY = y + moveY[k];
            int nextX = x + moveX[k];
            if(!(nextY > 0 && nextY <= n && nextX > 0 && nextX <= n && board[nextY][nextX] == 0))
                return false;
        }
    }
    //세로  방향으로 나가기 위해서는 아래만 검사 필요
    else if(dir == 2)
    {
        for(int k = 2; k < 3; k++)
        {
            int nextY = y + moveY[k];
            int nextX = x + moveX[k];
            if(!(nextY > 0 && nextY <= n && nextX > 0 && nextX <= n && board[nextY][nextX] == 0))
                return false;
        }
    }

    return true;
}
ll search(int y, int x, int dir)
{
    if(y == n  && x == n)
        return 1;

    ll &ret = cache[y][x][dir];

    if(ret != -1)
        return ret;

    ret = 0;
    //진행중인 방향이 가로 방향이라면, 가로 방향은 우측으로 한 칸 대각선으로 한 칸 갈 수 있다.
    if (dir == 0)
    {
        for(int k = 0; k < 2; k++)
        {
            if(isValid(y, x, k))
            {
                ret += search(y + moveY[k], x + moveX[k], k);
            }
        }
    }
    //진행중인 방향이라 대각선 방향이라면, 대각선 방향은 우상, 우, 우하로 갈 수 있다.
    else if(dir == 1)
    {
        for(int k = 0; k < 3; k++)
        {
            if(isValid(y, x, k))
                ret += search(y + moveY[k], x + moveX[k], k);
        }
    }
    //진행중인 방향이 세로 방향이라면, 세로 방향은 하, 우하 방향으로 갈 수 있다.
    else if (dir == 2)
    {
        for(int k = 1; k < 3; k++)
            if(isValid(y, x, k))
                ret += search(y + moveY[k], x + moveX[k], k);
    }

    return ret;
}

int main(void)
{
    fastio;
    cin >> n;

    memset(cache, -1, sizeof(cache));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i + 1][j + 1];

        cout << search(1, 2, 0) << "\n";
}
