#include<bits/stdc++.h>

using namespace std;
const int MAX = 101;

int moveY[] = {-1, 0, 1, 0};
int moveX[] = {0, -1, 0, 1};
int row, col;

int solution(vector<vector<int> > maps) {
    int answer = 0;
    row = maps.size();
    col = maps[0].size();

    auto BFS = [&]() -> int {
        queue<pair<int, int>> q;
        q.push({0, 0});

        bool visited[MAX][MAX];
        memset(visited, false, sizeof(visited));
        visited[0][0] = true;

        int count = 1;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                auto[cy, cx] = q.front();
                q.pop();

                if (row - 1 == cy && col - 1 == cx) {
                    return count;
                }

                for (int d = 0; d < 4; d++) {
                    int ny = cy + moveY[d];
                    int nx = cx + moveX[d];
                    if (ny >= 0 && ny < row && nx >= 0 && nx < col) {
                        if (!visited[ny][nx] && maps[ny][nx] == 1) {
                            q.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }
            }
            count++;
        }
        /*
         * 탐색 실패시 -1 반환
         */
        return -1;
    };

    answer = BFS();
    return answer;
}

int main() {
    int a = solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}});

    cout << a << "\n";
}