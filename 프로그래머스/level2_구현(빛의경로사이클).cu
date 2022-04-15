#include<bits/stdc++.h>

using namespace std;
const int MAX = 501;
bool visited[MAX][MAX][4];

int moveY[] = {-1, 0, 1, 0};
int moveX[] = {0, -1, 0, 1};

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    int row = grid.size();
    int col = grid[0].size();

    auto BFS = [&](int y, int x, int dir) -> int {
        int count = 0;

        while(1){

            /**
             * 탐색 값(ex:)S, L, R)의 방향에 방문한적이 있다면 탐색을 종료한다.
             */
            if(visited[y][x][dir]){
                break;
            }
            visited[y][x][dir] = true;
            count++;

            /**
             * 방향 전환
             */

            if(grid[y][x] == 'L'){
                dir = dir ? dir - 1 : 3;
            }

            else if(grid[y][x] == 'R'){
                dir = dir == 3 ? 0 : dir + 1;
            }

            y = (y + moveY[dir] + row) % row;
            x = (x + moveX[dir] + col) % col;
        }
        return count;
    };

    /**
     * grid내의 모든 값들의 4가지 방향을 탐색해준다.
     */

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            for(int k = 0; k < 4; k++) {
                if (!visited[i][j][k]) {
                    int count = BFS(i, j,k);
                    answer.push_back(count);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<int> a = solution({"SL", "LR"});
//    vector<int> a = solution({"R,R"});

    for (const auto &item: a) {
        cout << item << " ";
    }
}