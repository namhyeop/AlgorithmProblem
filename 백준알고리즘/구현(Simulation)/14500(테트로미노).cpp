#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()
using namespace std;
const int MAX = 505;
int board[MAX][MAX];
int n, m;
int ret;
int moveY[] = {-1,1,0,0};
int moveX[] = {0,0,-1,1};
bool visited[MAX][MAX];
bool isValid(int y, int x){
    return (y < 0 || y >= n || x < 0 || x >= m);
}
int main(void)
{
    fastio;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    auto DFS = [&](int level, int y, int x, auto &&DFS) -> int{
        if(level == 4){
            return board[y][x];
        }
        int sum = 0;
        for(int d = 0; d < 4; d++){
            int ny = y + moveY[d];
            int nx = x + moveX[d];
            if(!isValid(ny, nx))
                if(!visited[ny][nx]){
                    visited[ny][nx] = true;
                    sum = max(sum, board[y][x] + DFS(level + 1, ny, nx, DFS));
                    visited[ny][nx] = false;
                }
        }
        return sum;
    };
    /*
     *  ㅁ      ㅁ
     * ㅁㅁㅁ   ㅁㅁ
     *          ㅁ
     * ㅁ
     * ㅁㅁ    ㅁㅁㅁ
     * ㅁ       ㅁ
     */
    auto subSearch = [&](int y , int x) -> int{
        int ret = 0;
        if (y - 1 >= 0 && 0 <= x - 1 && x + 1 < m)
            ret = max(ret, board[y][x] + board[y - 1][x] + board[y][x - 1] + board[y][x + 1]);
        if (x - 1>= 0 && y - 1>= 0 && y + 1 < n)
            ret = max(ret, board[y][x] + board[y - 1][x] + board[y + 1][x] + board[y][x - 1]);
        if (y - 1 >= 0 && y + 1< n && x + 1 < m)
            ret = max(ret, board[y][x] + board[y - 1][x] + board[y + 1][x] + board[y][x + 1]);
        if (x - 1 >= 0 && x + 1 < m && y + 1 < n)
            ret = max(ret, board[y][x] + board[y][x - 1] + board[y][x + 1] + board[y + 1][x]);
        return ret;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true;
            ret = max(ret,DFS(1, i, j, DFS));
            ret = max(ret, subSearch(i, j));
            visited[i][j] = false;
        }
    }
    cout << ret <<"\n";
}