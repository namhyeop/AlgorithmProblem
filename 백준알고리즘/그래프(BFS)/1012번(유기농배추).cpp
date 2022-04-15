#include <bits/stdc++.h>

using namespace std;

int t, r, c, ea;
const int MAX = 50;
int board[MAX][MAX];
bool visited[MAX][MAX];

int moveY[] = {-1, 0, 1, 0};
int moveX[] = {0,-1,0,1};

void BFS(int i, int j){
    queue<pair<int,int>> q;
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){
        auto[y, x] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + moveY[i];
            int nx = x + moveX[i];
            if(ny >= 0 && ny < r && nx >= 0 && nx < c)
                if(!visited[ny][nx] && board[ny][nx] == 1){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
        }
    }
}

int pro(){
    int count = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(!visited[i][j] && board[i][j] == 1){
                BFS(i, j);
                count++;
            }
        }
    }
    return count;
}

void input(){
    cin >> t;
    vector<int> ret;
    while(t--){
        cin >> r >> c >> ea;
        fill(&board[0][0], &board[r][c + 1], 0);
        memset(visited, false, sizeof(visited));
        while(ea--) {
            int y, x;
            cin >> y >> x;
            board[y][x] = 1;
        }
        cout << pro() <<"\n";
    }
}

int main(){
    input();
}