#include<bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int cols, vector<vector<int>> queries) {
    vector<int> answer;

    /**
     * 회전시킬 Board 생성
     */
    vector<vector<int>> board(rows + 1, vector<int>(cols + 1, 0));
    int count = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            board[i][j] = count;
            count++;
        }
    }

    for (int i = 0; i < queries.size(); i++) {
        /**
         * 회전시킬 queries에 대한 정보 변수 저장
         */
        int y1 = queries[i][0];
        int x1 = queries[i][1];
        int y2 = queries[i][2];
        int x2 = queries[i][3];

        int minValue = INT_MAX;
        vector<vector<int>> tmpboard = board;

        /**
         * 영역별로 회전 시키기(상, 우, 하, 좌 순서로 진행)
         */
        for (int i = x1 + 1; i <= x2; i++) {
            board[y1][i] = tmpboard[y1][i - 1];
            minValue = min(minValue, board[y1][i]);
        }
        for (int i = y1 + 1; i <= y2; i++) {
            board[i][x2] = tmpboard[i - 1][x2];
            minValue = min(minValue, board[i][x2]);
        }
        for (int i = x2 - 1; i >= x1; i--) {
            board[y2][i] = tmpboard[y2][i + 1];
            minValue = min(minValue, board[y2][i]);
        }
        for (int i = y2 - 1; i >= y1; i--) {
            board[i][x1] = tmpboard[i + 1][x1];
            minValue = min(minValue, board[i][x1]);
        }
        answer.push_back(minValue);
    }
    return answer;
}

int main() {
    int rows = 6;
    int cols = 6;
    vector<vector<int>> v = {{2, 2, 5, 4},
                             {3, 3, 6, 6},
                             {5, 1, 6, 3}};
    solution(rows, cols, v);

}