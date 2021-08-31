#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()
 
using namespace std;
constexpr int INF = 1e9 + 7;
 
int moveY[] ={0,1,0,-1};
int moveX[] ={1,0,-1,0};
struct Block{
    int n, m;
    vector<vector<int>> v;
    Block(int n, int m) : n(n), m(m), v(n, vector<int>(m)) {}
 
    Block Rotate(){
        Block ret(m, n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ret[j][n -1 - i] = v[i][j];
            return ret;
    }
 
    int GetCnt() const{
        int ret = 0;
        for (vector<int> i : v)
            ret += reduce(i.begin(), i.end()); // 도형의 전체 값들을 반환하는 과정
        return ret;
    }
 
    friend bool operator == (const Block& a, const Block& b)
    {
        if (a.GetCnt() != b.GetCnt())
            return 0;
        Block t = a;
        for(int i = 0; i < 4; i++)
        {
            if(t.n == b.n && t.m == b.m && t.v == b.v) //블럭 하나당 비교해주는 과정, 블럭의 y축 x축이 같고 Block의 값이 같다면
                {
//디버깅 과정
//                for(int i = 0; i < t.n; i++)
//                {
//                    for(int j = 0 ; j < t.m; j++)
//                    {
//                        cout << t.v[i][j] <<" ";
//                    }
//                    cout<<"\n";
//                }
//                cout <<"--------------------" << "\n";
//                for(int i = 0; i < b.n; i++)
//                {
//                    for(int j = 0 ; j < b.m; j++)
//                    {
//                        cout << b.v[i][j] <<" ";
//                    }
//                    cout<<"\n";
//                }
//                cout <<"=====================" <<"\n";
                return 1;
            }
            t = t.Rotate();
        }
        return 0;
    }
 
    vector<int>& operator[] (int i) { return v[i];}
};
 
vector<Block> Extract(vector<vector<int>> board, bool flag)
{
    //Flag는 밑에서 BFS탐색을 할 때 visited 역할을 한다.
    vector<Block> ret;
    int n = board.size(); //board의 y축
    int m = board[0].size();//board의 x출
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] != flag) //탐색해야 하는 경우가 아니라면 continue!
                continue;
            vector<pii> v; //나중에 반환해줄 도형 배열에 값을 체크해주기 위한 vector
            queue<pii> Q;// BFS탐색을 위한 queue
 
            //밑에서 반환해줄 2차원 도형의 배열값 맨 좌측 상단 위치와 맨 우측 하단 값을 구한뒤 서로 좌표를 빼주면 도형의 전체크기가 나옴
            //114줄을 보면 이해하기 쉽다.
            int x_mn = INF, x_mx = -INF;
            int y_mn = INF, y_mx = -INF;
 
            v.push_back({i, j});
            Q.push({i, j});
            board[i][j] = !flag;
            while(Q.size())
            {
                auto[x, y] = Q.front();
                Q.pop();
                x_mn = min(x_mn, x),x_mx = max(x_mx, x);
                y_mn = min(y_mn, y),y_mx = max(y_mx, y);
 
                for(int d = 0; d < 4; d++)
                {
                    int nextX = x + moveX[d];
                    int nextY = y + moveY[d];
                    if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                        continue;
                    if(board[nextX][nextY] != flag)
                        continue;
                    v.push_back({nextX, nextY});
                    Q.push({nextX, nextY});
                    board[nextX][nextY] = !flag;
                }
            }
 
            //반한해줄 도형을 의미하는 2차원 배열에 값들을 체크한뒤 반환하는 과정
            Block cur(x_mx - x_mn + 1, y_mx - y_mn + 1);
            for (auto &[x, y] : v)
                cur[x - x_mn][y - y_mn] = 1;
            ret.push_back(cur);
        }
    return ret;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table)
{
    int ret = 0;
    // Block 구조체는 사실상 2차원 배열이다.
    // v1는 문제에서 주어지는 game_board 배열에서 도형을 둘 수 있는 자리를 저장하는 vector이다.
    // v2는 문제에서 주어지는 table 배열에서 도형의 크기와 인덱스값들을 저장하는 vector이다.
    vector<Block> v1 = Extract(game_board, 0);
    vector<Block> v2 = Extract(table, 1);
    for(Block& i : v1)
    {
        for(int j = 0; j < v2.size(); j++)
        {
            //v1과 v2를 비교하면서 v2 도형과 v1의 테이블 위치가 일치하다면 v2를 지워준다. 그리고 그만큼 수치는 결과값에 저장한다.
            if(i == v2[j])
            {
                ret += i.GetCnt();
                v2.erase(v2.begin() + j);
                break;
            }
        }
    }
    return ret;
}
 
using board = vector<vector<int>>;
board game_board = {
        { 1, 1, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 1, 1, 0, 0, 1 },
        { 1, 1, 0, 1, 1, 1 },
        { 1, 0, 0, 0, 1, 0 },
        { 0, 1, 1, 1, 0, 0 },
        };
board table = {
        { 1, 0, 0, 1, 1, 0 },
        { 1, 0, 1, 0, 1, 0 },
        { 0, 1, 1, 0, 1, 1 },
        { 0, 0, 1, 0, 0, 0 },
        { 1, 1, 0, 1, 1, 0 },
        { 0, 1, 0, 0, 0, 0 },
        };
 
int main(void)
{
    fastio;
    cout << solution(game_board, table) << '\n';
}
