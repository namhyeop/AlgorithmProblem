//자물쇠 영역 내에서 열쇠의 돌기 부분과 자물쇠의 홈 부분이 정확히 일치해야 한다.
//열시의 돌기와 자물쇠의 돌기가 만나서는 안된다.
//자물쇠의 모든 홈을 채워 비어있는 곳이 없어야 한다.

level3_완전탐색(자물쇠와열쇠)(2020 KAKAO BLIND RECRUITMENT)
#include<bits/stdc++.h>

using namespace std;
const int MAX = 21 * 2 + 1;

using vi = vector<int>;
using vvi = vector<vi>;

struct play{
    int board[MAX][MAX];
    vvi key, lock;
    play(vvi key, vvi lock) : key(key), lock(lock), board{} {}

    void rotate(){
        vvi tmp = key;
        int N = key.size();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                key[i][j] = tmp[N - j - 1][i];
            }
        }
    }

    bool check(){
        int lockSize = lock.size();
        int lockN = lock.size() - 1;
        for(int i = lockN; i < lockSize + lockN; i++){
            for(int j = lockN; j < lockSize + lockN; j++){
                if(board[i][j] != 1)
                    return false;
            }
        }
        return true;
    }

    bool simulation(){
        int N = lock.size();
        int NK = key.size();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                board[i + N - 1][j + N - 1] = lock[i][j];
            }
        }
       // printBoard();

        int oriBoard[MAX][MAX];
        memcpy(oriBoard, board, sizeof oriBoard);
        int totalN = lock.size() * 2 + 1;
        for(int r = 0; r < 4; r++){
            rotate();
            for(int i = 0; i < totalN; i++){
                for(int j = 0; j < totalN; j++){
                    int keyY = 0;
                    for(int l = i; l < i + NK; l++){
                        int keyX = 0;
                        for(int k = j; k < j + NK; k++){
                            board[l][k] += key[keyY][keyX];
                            keyX++;
                        }
                        keyY++;
                    }
                    if(check()){
                        return true;
                    }
                    //printBoard();
                    memcpy(board, oriBoard, sizeof(board));
                }
            }
        }
        return false;
    }
    void printBoard(){
        int totalN = lock.size() * 2 + 1;
        for(int i = 0; i < totalN ; i++){
            for(int j = 0; j < totalN; j++)
                cout << board[i][j]  << " ";
            cout << "\n";
        }
        cout <<"==============board===========" << "\n";
    }
};

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    play op(key, lock);
    answer = op.simulation();
    return answer;
}

int main(){
    vvi key = {{0,0,0}, {1,0,0}, {0,1,1}};
    vvi lock = {{1,1,1}, {1,1,0}, {1,0,1}};
    cout << solution(key, lock) <<"\n";
}
