#include<bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int figure[5][6][2]{
    {{0, 0}, {1, 0}, {1, 1},  {1, 2},  {0, 1},  {0, 2}},
    {{0, 0}, {1, 0}, {2, 0},  {2, -1}, {0, -1}, {1, -1}},
    {{0, 0}, {1, 0}, {2, 0},  {2, 1},  {0, 1},  {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}, {1, -2}, {0, -1}, {0, -2}},
    {{0, 0}, {1, 0}, {1, -1}, {1, 1},  {0, -1}, {0, 1}}
};

struct master {
    int n, retCnt;
    vvi board;
    int figureDir;

    master(vvi board) : board(board), n(board.size()), retCnt{} {}

    bool isValid(int y, int x) {
        return y >= 0 && y < n && x >= 0 && x < n;
    }

    bool isPossible(int y, int x) {
        int curValue = board[y][x];
        figureDir = -1;
        for (int i = 0; i < 5; i++) {
            bool flag = true;
            for (int j = 0; j < 4; j++) {
                int ny = y + figure[i][j][0];
                int nx = x + figure[i][j][1];
                if (!isValid(ny, nx) || board[ny][nx] != curValue) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                figureDir = i;
                bool flag2 = true;
                //검은 도형을 두는 것이 가능한지 불가능하다면 탐색종료
                for (int i = 4; i < 6; i++) {
                    int ny = y + figure[figureDir][i][0];
                    int nx = x + figure[figureDir][i][1];
                    if (!isValid(ny, nx) || board[ny][nx] != 0) {
                        flag2 = false;
                        break;
                    }
                    //x축값 위에 도형이 막힐수 있는 경우 탐색
                    for(int k = ny; k >= 0; k--){
                        if(board[k][nx] != 0){
                            flag2 = false;
                            break;
                        }
                    }
                    if(flag2 == false)
                        break;
                }
                if(flag2 == true)
                    return true;
            }
        }
        return false;
    }

    void simulation() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0)
                    continue;
                if (isPossible(i, j)) {
                    retCnt++;
                    auto erase = [&](int y, int x, int dir) {
                        for (int i = 0; i < 4; i++) {
                            int ny = y + figure[dir][i][0];
                            int nx = x + figure[dir][i][1];
                            board[ny][nx] = 0;
                        }
                    };
                    erase(i, j, figureDir);
                    j = -1;
                }
            }
        }
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    master op(board);
    op.simulation();
    answer = op.retCnt;
    return answer;
}

int main() {
    vvi board = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
                 {0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
                 {0, 0, 0, 0, 3, 0, 4, 0, 0, 0},
                 {0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
                 {1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
                 {1, 1, 1, 0, 0, 0, 0, 0, 0, 5}};
    cout << solution(board) << "\n";
}