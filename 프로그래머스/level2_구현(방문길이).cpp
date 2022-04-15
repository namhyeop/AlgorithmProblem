#include<bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX = 11;
//fromY, fromX, toY, toX
bool visited[MAX][MAX][MAX][MAX];

int solution(string dirs) {
    int count = 0;

    int curY = 5;
    int curX = 5;
    for (int i = 0; i < dirs.size(); i++) {
        int tmpCurY = curY;
        int tmpCurX = curX;
        if (dirs[i] == 'U') {
            tmpCurY -= 1;
        } else if (dirs[i] == 'L') {
            tmpCurX -= 1;
        } else if (dirs[i] == 'R') {
            tmpCurX += 1;
        } else {//D
            tmpCurY += 1;
        }

        if (tmpCurY >= 0 && tmpCurY <= 10 && tmpCurX >= 0 && tmpCurX <= 10) {
            if (!visited[curY][curX][tmpCurY][tmpCurX]) {
                visited[curY][curX][tmpCurY][tmpCurX] = true;
                visited[tmpCurY][tmpCurX][curY][curX] = true;
                count++;
            }
            curY = tmpCurY, curX = tmpCurX;
        }
    }
    return count;
}

int main() {
//    solution("ULURRDLLU");
    solution("LULLLLLLU");
}