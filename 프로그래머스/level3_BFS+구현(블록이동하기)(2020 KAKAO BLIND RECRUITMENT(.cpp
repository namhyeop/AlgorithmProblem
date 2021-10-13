//블록이동하기 실패 코드
//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 101;
//int N;
//struct plane {
//    int x1, y1, x2, y2;
//};
//
//int moveX[] = {-1, 0, 1, 0};
//int moveY[] = {0, 1, 0, -1};
//
//
//bool visited[MAX][MAX][MAX][MAX];
//
//bool isValid(int x, int y) {
//    return (x >= 0 && x < N && y >= 0 && y < N);
//}
//
//void Rotate(vector<vector<int>> &board, int x1, int y1, int x2, int y2, queue<plane> &q) {
//    int taildir;
//    if (y1 == y2 && x1 > x2) {
//        taildir = 0;
//    } else if (y1 == y2 && x1 < x2) {
//        taildir = 2;
//    } else if (x1 == x2 && y1 > y2) {
//        taildir = 3;
//    } else if (x1 == x2 && y1 < y2) {
//        taildir = 1;
//    }
//
//
//    if (taildir == 0) {
//        //북쪽을 바라볼 때
//        if (isValid(x1, y1 + 1)) {
//            //북쪽에서 동쪽으로
//            if (!visited[x1][y1][x1][y1 + 1] && board[x1 - 1][y1 + 1] != 1) {
//                q.push({x1, y1, x1, y1 + 1});
//                visited[x1][y1][x1][y1 + 1] = true;
//            }
//        }
//
//        if(isValid(x1 , y1 - 1)){
//            //북쪽에서 서쪽으로
//            if (!visited[x1][y1][x1][y1 - 1] && board[x1 - 1][y1 - 1] != 1) {
//                q.push({x1, y1, x1, y1 - 1});
//                visited[x1][y1][x1][y1 - 1] = true;
//            }
//        }
//    } else if (taildir == 1) {
//        //동쪽을 바라볼 때
//        if (isValid(x1 - 1, y1)) {
//            //동쪽에서 북쪽으로
//            if (!visited[x1][y1][x1 - 1][y1] && board[x1 - 1][y1 + 1] != 1) {
//                q.push({x1, y1, x1 - 1, y1});
//                visited[x1][y1][x1 - 1][y1] = true;
//            }
//        }
//        if(isValid(x1 + 1, y1)){
//            //동쪽에서 남쪽으로
//            if (!visited[x1][y1][x1 + 1][y1] && board[x1 + 1][y1 + 1] != 1) {
//                q.push({x1, y1, x1 + 1, y1});
//                visited[x1][y1][x1 + 1][y1] = true;
//            }
//        }
//    } else if (taildir == 2) {
//        //남쪽을 바라볼 때
//        if (isValid(x1, y1 - 1)) {
//            //남쪽에서 서쪽으로
//            if (!visited[x1][y1][x1][y1 - 1] && board[x1 + 1][y1 - 1] != 1) {
//                q.push({x1, y1, x1, y1 - 1});
//                visited[x1][y1][x1][y1 - 1] = true;
//            }
//        }
//        if(isValid(x1, y1 + 1)){
//            //남쪽에서 동쪽으로
//            if (!visited[x1][y1][x1][y1 + 1] && board[x1 + 1][y1 + 1] != 1) {
//                q.push({x1, y1, x1, y1 + 1});
//                visited[x1][y1][x1][y1 + 1] = true;
//            }
//        }
//    } else if (taildir == 3) {
//        //서쪽을 바라볼 때
//        if (isValid(x1 - 1, y1)) {
//            //서쪽에서 북쪽으로
//            if (!visited[x1][y1][x1 - 1][y1] && board[x1 - 1][y1 - 1] != 1) {
//                q.push({x1, y1, x1 - 1, y1});
//                visited[x1][y1][x1 - 1][y1] = true;
//            }
//        }
//        if (isValid(x1 + 1, y1)){
//            //서쪽에서 남쪽으로
//            if (!visited[x1][y1][x1 + 1][y1] && board[x1 + 1][y1 - 1] != 1) {
//                q.push({x1, y1, x1 + 1, y1});
//                visited[x1][y1][x1 + 1][y1] = true;
//            }
//        }
//    }
//}
//
//
//int solution(vector<vector<int>> board) {
//    N = board.size();
//    int answer = 0;
//    queue<plane> q;
//    q.push({0, 0, 0, 1});
//    visited[0][0][0][1] = true;
//    int cnt = 0;
//    while (!q.empty()) {
//        int qSize = q.size();
//        for (int c = 0; c < qSize; c++) {
//            auto[x1, y1, x2, y2] = q.front();
//            q.pop();
//
//            if ((x1 == N - 1 && y1 == N - 1) || (x2 == N - 1 && y2 == N - 1)) {
//                answer = cnt;
//                return answer;
//            }
//
//            for (int d = 0; d < 4; d++) {
//                int nextX1 = x1 + moveX[d];
//                int nextY1 = y1 + moveY[d];
//                int nextX2 = x2 + moveX[d];
//                int nextY2 = y2 + moveY[d];
//
//                if (isValid(nextX1, nextY1) && isValid(nextX2, nextY2)) {
//                    if (!visited[nextX1][nextY1][nextX2][nextY2]) {
//                        q.push({nextX1, nextY1, nextX2, nextY2});
//                        visited[nextX1][nextY1][nextX2][nextY2];
//                    }
//                }
//            }
//            Rotate(board, x1, y1, x2, y2, q);
//        }
//        cnt++;
//    }
//}
//
//int main() {
//    cout << solution({{0, 0, 0, 1, 1},
//                      {0, 0, 0, 1, 0},
//                      {0, 1, 0, 1, 1},
//                      {1, 1, 0, 0, 1},
//                      {0, 0, 0, 0, 0}}) << "\n";
//}

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
int n;
int moveY[] = {-1,1,0,0};
int moveX[] = {0,0,-1,1};

struct Robot{
    int y1, x1, y2, x2;
    Robot(int y1, int x1, int y2, int x2) : y1(y1), x1(x1), y2(y2), x2(x2) {}

    Robot move(int dir){
        return Robot{y1 + moveY[dir], x1 + moveX[dir] , y2 + moveY[dir], x2 + moveX[dir]};
    }

    pair<Robot,Robot> rotate(int dir){
        return {{y1, x1, y1 + moveY[dir], x1 + moveX[dir]}, {y2, x2, y2 + moveY[dir], x2 +moveX[dir]}};
    }

    bool isValid(){
        return y1 >= 0 && x1 >= 0 && y2 >= 0 && x2 >= 0 && y1 < n && x1 < n && y2 < n && x2 < n  && !board[y1][x1] && !board[y2][x2];;

    }
};

bool operator < (Robot a, Robot b){
    return tie(a.y1, a.x1, a.y2, a.x2) < tie(b.y1, b.x1, b.y2, b.x2);
}

bool operator == (Robot a, Robot b){
    return tie(a.y1, a.x1, a.y2, a.x2) == tie(b.y1, b.x1, b.y2, b.x2)
    || tie(a.y1, a.x1, a.y2, a.x2) == tie(b.y2, b.x2, b.y1, b.x1);
}

map<Robot, int> dist;

vector<Robot> moveRobot(Robot &r){
    vector<Robot> ret;
    for(int i = 0; i < 4; i++){
        ret.push_back(r.move(i));
    }
    return ret;
}

vector<Robot> rotateRobot(Robot &r){
    vector<Robot> ret;
    for(int i = 0; i < 4; i++){
        //이동 방향으로 전진이 가능하면 그 방향으로 회전이 가능하다. 그림을 그려보면 이해가 잘간다.
        if(r.move(i).isValid()){
            pair<Robot, Robot> tmp = r.rotate(i);
            ret.push_back(tmp.first);
            ret.push_back(tmp.second);
        }
    }
    return ret;
}

bool isFinishCheck(Robot r){
    return r.y1 == n - 1 && r.x1 == n - 1 || r.y2 == n - 1 && r.x2 == n - 1;
}

int BFS(Robot protoType){
    dist[protoType] = 0;

    //초기 (0,0)(0,1)지점의 로봇을 탐색 시작값으로 한다.
    queue<Robot> q;
    q.push(protoType);

    while(!q.empty()){
        Robot cur = q.front();
        q.pop();

        int curDist = dist[cur];

        //로봇의 일부가 도착지점에 하나라도 도착하면 종료
        if(isFinishCheck(cur)){
            return curDist;
        }

        //움직이는 경우, 회전하는 경우를 구해준다.
        vector<Robot> next[2] = {{moveRobot(cur)}, {rotateRobot(cur)}};
        for(int i = 0; i < 2; i++){
            for(Robot R : next[i]){
                //탐색한적이없고 범위이내의 값이라면 거리를 갱신하고 다음 탐색을 진행한다.
                if(!dist.count(R) && R.isValid()){
                    dist[R] = curDist + 1;
                    q.push(R);
                }
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> Board) {
    board = Board;
    int answer = 0;
    n = board.size();
    answer = BFS({0,0,0,1});
    return answer;
}
int main() {
    cout << solution({{0, 0, 0, 1, 1},
                      {0, 0, 0, 1, 0},
                      {0, 1, 0, 1, 1},
                      {1, 1, 0, 0, 1},
                      {0, 0, 0, 0, 0}}) << "\n";
}