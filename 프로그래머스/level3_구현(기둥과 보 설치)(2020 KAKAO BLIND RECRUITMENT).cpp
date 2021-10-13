#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
#define isExist(q) (building.find(test[q])) != building.end()

bool isValid(set<vector<int>> &building) {
    for (auto build : building) {
        int x = build[0], y = build[1], a = build[2];
        if (a == 0) {
            //현재 위치 밑에 기둥이 있는 경우, 현재 위치에 보가 있는 경우, 현재 위치의 x - 1좌표에 보가 있는 경우중 하나라도 만족하면 설치 조건에 만족한다.
            vvi test = {{x,     y - 1, 0},
                        {x,     y,     1},
                        {x - 1, y,     1}};
            if (y == 0 || isExist(0) || isExist(1) || isExist(2))
                continue;
            return false;
        } else {
            //현재 위치의 y좌표 밑에 기둥이 있는 경우, 현재 위치의 x좌표 + 1에 기둥이 있는 경우, 현재 위치의 x - 1 좌표에 보가 있는 경우, 현재 위치의 x + 1 위치에 보가 있는 경우 보의 조건을 만족한다.
            vvi test = {{x,     y - 1, 0},
                        {x + 1, y - 1, 0},
                        {x - 1, y,     1},
                        {x + 1, y,     1}};
            if (isExist(0) || isExist(1) || (isExist(2) && isExist(3)))
                continue;
            return false;
        }
    }
    return true;
}

struct play {
    int n;
    vvi buildFrame;
    set<vi> building;

    play(int n, vvi buildFrame) : n(n), buildFrame(buildFrame) {}

    vvi simulation() {
        vvi ret;
        for (auto list : buildFrame) {
            vi v = {list[0], list[1], list[2]};
            //삭제하는 경우
            if (list[3] == 0) {
                building.erase(v);
                if (!isValid(building))
                    building.insert(v);
            }
            //설치하는 경우
            else {
                building.insert(v);
                if (!isValid(building))
                    building.erase(v);
            }
        }

        for (auto v: building) {
            ret.push_back(v);
        }
        return ret;
    }
};

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    play op(n, build_frame);
    answer = op.simulation();
    return answer;
}

int main() {
    int n = 5;
    vvi build_frame = {{1, 0, 0, 1},
                       {1, 1, 1, 1},
                       {2, 1, 0, 1},
                       {2, 2, 1, 1},
                       {5, 0, 0, 1},
                       {5, 1, 0, 1},
                       {4, 2, 1, 1},
                       {3, 2, 1, 1}};
    vvi ret = solution(n, build_frame);

    for (auto v : ret) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}