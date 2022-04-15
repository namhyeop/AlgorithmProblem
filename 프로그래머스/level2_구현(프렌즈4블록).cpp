#include<bits/stdc++.h>

using namespace std;
const int MAX = 31;
int row, col;
bool visited[MAX][MAX];
bool flag = false;

void search(int y, int x, vector<string> board) {
    if (y + 1 < row && x + 1 < col && board[y][x] != '*') {
        if (board[y][x] == board[y + 1][x] && board[y][x] == board[y][x + 1] &&board[y][x] == board[y + 1][x + 1]) {
            visited[y][x] = true;
            visited[y + 1][x] = true;
            visited[y][x + 1] = true;
            visited[y+1][x+1] = true;
        }
    }
}

void erase_map(vector<string> &board, int &answer){
    flag = true;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(visited[i][j]) {
                board[i][j] = '*';
                answer++;
                flag = false;
            }
        }
    }
}

void move_map(vector<string> &board){

    for(int i = 0; i < col; i++){
        int pos = row - 1;
        for(int j = row - 1; j >= 0; j--){
            if(board[j][i] != '*')
                board[pos--][i] = board[j][i];
        }
        while(pos >= 0){
            board[pos--][i] = '*';
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    row = board.size();
    col = board[0].size();

    while (!flag) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                search(i, j, board);
            }
        }

        erase_map(board, answer);
        move_map(board);
        memset(visited, false, sizeof(visited));
    }
    return answer;
}

int main() {
    cout << solution(6,6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"}) << "\n";
}