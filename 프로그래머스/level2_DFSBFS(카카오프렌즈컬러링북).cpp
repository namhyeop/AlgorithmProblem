#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int numArea = 0, maxArea = 0;
    vector<int> answer(2);
    queue<pair<int, int>> q;
    int moveY[] = {-1, 1, 0, 0};
    int moveX[] = {0, 0, -1, 1};

    //preprocess_picture에 0이 아닌 값들은 탐색 대상이므로 queue에 넣어주는 과정
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0)
                q.push({i, j});
        }
    }

    auto BFS = [&]() {
        bool visited[105][105];
        memset(visited, false, sizeof(visited));

        while (!q.empty()) {
            auto[y, x] = q.front();
            q.pop();

            if (visited[y][x])
                continue;

            numArea++;
            queue<pair<int, int>> tmpq;
            int areaSize = 1;
            tmpq.push({y, x});
            visited[y][x] = true;

            while (!tmpq.empty()) {
                auto[curY, curX] = tmpq.front();
                tmpq.pop();

                for (int d = 0; d < 4; d++) {
                    int nextY = curY + moveY[d];
                    int nextX = curX + moveX[d];
                    if (nextY >= 0 && nextY < m && nextX >= 0 && nextX < n)
                        if (!visited[nextY][nextX] && picture[nextY][nextX] == picture[curY][curX]) {
                            tmpq.push({nextY, nextX});
                            visited[nextY][nextX] = true;
                            areaSize++;
                        }
                }
            }
            maxArea = max(maxArea, areaSize);

        }
    };
    BFS();
    answer[0] = numArea;
    answer[1] = maxArea;
    return answer;
}

int main() {
    int a = 6, b = 4;


    xcxse
    vector<vector<int>> c = {{1, 1, 1, 0},
                             {1, 2, 2, 0},
                             {1, 0, 0, 1},
                             {0, 0, 0, 1},
                             {0, 0, 0, 3},
                             {0, 0, 0, 3}};
    vector<int> ret = solution(a, b, c);
    cout << ret[0] << "\n";
    cout << ret[1] << "\n";
}