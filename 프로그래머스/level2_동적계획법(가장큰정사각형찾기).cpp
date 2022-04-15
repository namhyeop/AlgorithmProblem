#include<bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int row,col;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    row = board.size();
    col = board[0].size();
    if(row == 1 || col == 1) {
        answer = 1;
        return answer;
    }
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(board[i][j] != 0){
                board[i][j] = min({board[i-1][j - 1], board[i - 1][j],board[i][j - 1]}) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    answer = (answer) * (answer);
    return answer;
}

int main(){
    cout << solution({{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}}) <<"\n";
}