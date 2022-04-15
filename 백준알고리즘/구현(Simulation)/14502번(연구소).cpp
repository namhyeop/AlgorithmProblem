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
//const int MAX = 9;
//int board[MAX][MAX];
//int moveY[] = {-1,1,0,0};
//int moveX[] = {0,0,-1,1};
//int ret = INT_MIN;
//int n, m;
//
//int main(void)
//{
//    fastio;
//
//    cin >> n >> m;
//
//    for(int i =0; i < n; i++){
//        for(int j = 0; j < m; j++){
//            cin >> board[i][j];
//        }
//    }
//
//    auto BFS = [&]() -> int {
//        queue<pair<int,int>> q;
//        int tmpboard[MAX][MAX];
//        memcpy(tmpboard, board, sizeof tmpboard);
//
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < m; j++){
//                if(tmpboard[i][j] == 2){
//                    q.push({i,j});
//                }
//            }
//        }
//
//        while(!q.empty()){
//            auto [y, x] = q.front();
//            q.pop();
//
//            for(int i = 0; i < 4; i++){
//                int ny = y + moveY[i];
//                int nx = x + moveX[i];
//
//                if(ny < 0 || ny >= n || nx < 0 || nx >= m)
//                    continue;
//                if(tmpboard[ny][nx] == 0){
//                    q.push({ny, nx});
//                    tmpboard[ny][nx] = 2;
//                }
//            }
//        }
//
//        int cnt = 0;
//        for(int i = 0; i < n ; i++){
//            for(int j = 0; j < m; j++){
//                if(tmpboard[i][j] == 0)
//                    cnt++;
//            }
//        }
//        return cnt;
//    };
//
//    auto DFS =[&](int cnt, auto&& DFS) -> void {
//        if(cnt == 3)
//        {
//            ret = max(ret, BFS());
//            return ;
//        }
//
//        for(int i = 0; i < n ; i++){
//            for(int j = 0; j < m; j++){
//                if(board[i][j] == 0)
//                {
//                    board[i][j] = 1;
//                    DFS(cnt + 1, DFS);
//                    board[i][j] = 0;
//                }
//            }
//        }
//    };
//
//    DFS(0, DFS);
//    cout <<  ret << "\n";
//}

#include <bits/stdc++.h>

using namespace std;
const int MAX = 8;
int n,m;
int board[MAX][MAX];
bool visited[MAX][MAX];
int maxCnt;
int wallCnt;
vector<pair<int,int>> start;

int moveY[]={-1,0,1,0};
int moveX[] = {0,-1,0,1};

int BFS(){
    memset(visited, false, sizeof(visited));
    queue<tuple<int,int>> q;
    for(int i = 0; i < start.size(); i++){
        q.push({start[i].first,start[i].second});
        visited[start[i].first][start[i].second]= true;
    }
    vector<pair<int,int>> arr;
    int cnt = q.size();
    while(!q.empty()){
        auto[y,x] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + moveY[i];
            int nx = x + moveX[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(board[ny][nx] == 0 && !visited[ny][nx]){
                    visited[ny][nx] = true;
                    arr.push_back({ny, nx});
                    q.push({ny, nx});
                    cnt++;
                }
            }
        }
    }
    //0의 공간에 3개의 벽을 세우기 때문에 3을 더해줘야한다.
    return (n*m) - (cnt + wallCnt + 3);
}
void DFS(int level){
    if(level == 3){
        maxCnt = max(maxCnt, BFS());
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0){
                board[i][j] = 1;
                DFS(level + 1);
                board[i][j] = 0;
            }
        }
    }
}

void pro(){
    DFS(0);
    cout << maxCnt <<"\n";
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                start.push_back({i, j});
            }
            else if(board[i][j] == 1){
                wallCnt++;
            }
        }
    }
}

int main(){
    input();
    pro();
}