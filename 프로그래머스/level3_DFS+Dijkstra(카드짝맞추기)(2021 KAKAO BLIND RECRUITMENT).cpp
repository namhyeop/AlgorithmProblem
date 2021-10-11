#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;
using vi = vector<int>;
using vvi = vector<vi>;
int moveY[] = {-1, 1, 0, 0};
int moveX[] = {0, 0, -1, 1};

struct Point {
    int dist, y, x;

    Point(int y, int x) : y(y), x(x) {}

    Point(int dist, int y, int x) : dist(dist), y(y), x(x) {}
};

bool operator < (Point a, Point b) {
    return a.dist > b.dist;
}

struct play {
    vvi board;
    int r, c;

    play(vvi board, int r, int c) : board(board), r(r), c(c) {}

    //범위 체크
    bool isValid(int y, int x) {
        return y >= 0 && y < 4 && x >= 0 && x < 4;
    }

    //다이젝스트라를 활용한 최단거리 구하기
    int getDist(vvi &board, int y1, int x1, int y2, int x2) {
        priority_queue<Point> pq;
        pq.push({0, y1, x1});
        //값 갱신을 위한 최대값 초기화
        int dist[4][4];
        fill(&dist[0][0], &dist[3][4], INF);
        dist[y1][x1] = 0;

        while (!pq.empty()) {
            Point cur = pq.top();
            pq.pop();

            int curDist = cur.dist;

            if (dist[cur.y][cur.x] < cur.dist)
                continue;

            //찾고자 하는 카드면 거리를 반환하고 종료
            if (cur.y == y2 && cur.x == x2) {
                return cur.dist;
            }

            for (int d = 0; d < 4; d++) {
                int cnt = 0;
                int nextY = cur.y;
                int nextX = cur.x;
                while (isValid(nextY + moveY[d], nextX + moveX[d])) {
                    cnt++;
                    nextY += moveY[d];
                    nextX += moveX[d];

                    if (board[nextY][nextX] != 0)
                        break;

                    //한칸씩 가는 경우
              우     if (dist[nextY][nextX] > curDist + cnt) {
                        dist[nextY][nextX] = curDist + cnt;
                        pq.push({curDist + cnt, nextY, nextX});
                    }
                }
                //Ctrl을 활용한 한 번에 가는경우
                if (dist[nextY][nextX] > curDist + 1) {
                    dist[nextY][nextX] = curDist + 1;
                    pq.push({curDist + 1, nextY, nextX});
                }
            }
        }
    }

    bool check(vvi &board){
        for(auto v : board){
            for(auto n : v){
                if(n != 0)
                    return false;
            }
        }
        return true;
    }
    int DFS(vvi &board, int y, int x) {
        if(check(board)){
            return 0;
        }
        int ret = INF;
        //카드를 1부터 6까지 놓을 수 있는 순서의 모든 경우를 테스트 하기
        for (int k = 1; k <= 6; k++) {
            vector<Point> point;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (board[i][j] == k) {
                        point.push_back({i, j});
                    }
                }
            }
            if(point.size() == 0)
                continue;

            //두 개의 카드중 첫 번째 카드를 먼저 뒤집고 두 번째 카드를 뒤집는 경우의 거리 값
            int tCase1 = getDist(board, y, x, point[0].y, point[0].x)
                    + getDist(board, point[0].y, point[0].x, point[1].y, point[1].x) + 2;
            //두 개의 카드중 두 번째 카드를 먼저 뒤집고 첫 번째 카드를 먼저 뒤집는 경우의 거리 값
            int tCase2 = getDist(board, y, x, point[1].y, point[1].x)
                    + getDist(board, point[1].y, point[1].x, point[0].y, point[0].x) + 2;

            //카드를 찾은 경우 board 값을 갱신하고 다음 백트래킹을 진행한다.
            board[point[0].y][point[0].x] = 0;
            board[point[1].y][point[1].x] = 0;
            ret = min(ret, min(tCase1 + DFS(board, point[1].y, point[1].x), tCase2 + DFS(board, point[0].y, point[0].x)));
            board[point[0].y][point[0].x] = k;
            board[point[1].y][point[1].x] = k;
        }
        return ret;
    }
};

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    play op(board, r, c);
    answer = op.DFS(op.board, op.r, op.c);
    return answer;
}

int main() {
    cout << solution({{1, 0, 0, 3},
                      {2, 0, 0, 0},
                      {0, 0, 0, 2},
                      {3, 0, 1, 0}}, 1, 0) << "\n";
}
