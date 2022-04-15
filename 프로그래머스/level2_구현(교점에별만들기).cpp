#include<bits/stdc++.h>

#define ll long long
using namespace std;

int row;

vector<string> solution(vector<vector<int>> line) {
    ll maxX = LLONG_MIN, minX = LLONG_MAX, maxY = LLONG_MIN, minY = LLONG_MAX;

    vector<string> answer;
    row = line.size();

    vector<pair<ll, ll>> pos;
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < row; j++) {
            ll A = line[i][0], B = line[i][1], E = line[i][2];
            ll C = line[j][0], D = line[j][1], F = line[j][2];

            if (((A * D) - (B * C)) == 0)
                continue;

            ll xValue = ((B * F) - (E * D)) / ((A * D) - (B * C));
            ll xMod = ((B * F) - (E * D)) % ((A * D) - (B * C));

            ll yValue = ((E * C) - (A * F)) / ((A * D) - (B * C));
            ll yMod = ((E * C) - (A * F)) % ((A * D) - (B * C));

            if (xMod != 0 || yMod != 0)
                continue;

            maxX = max(xValue, maxX);
            minX = min(xValue, minX);
            maxY = max(yValue, maxY);
            minY = min(yValue, minY);

            pos.push_back({xValue, yValue});
        }
    }

    ll height = maxY - minY + 1;
    ll weight = maxX - minX + 1;

    for (int i = 0; i < height; i++) {
        string tmp = "";
        for (int j = 0; j < weight; j++) {
            tmp += ".";
        }
        answer.push_back(tmp);
    }

    for (const auto &item: pos) {
//        answer[(height / 2) - item.second][(weight / 2) + item.first] = '*';
        answer[maxY - item.second][item.first - minX] = '*';
    }

/**
 * 그림 출력 확인
 */
//    for(int i = 0; i <answer.size(); i++){
//        for(int j = 0; j < answer[i].size(); j++)
//            cout << answer[i][j] << " ";
//        cout <<"\n";
//    }
    return answer;
}

int main() {
    vector<vector<int>> test1 = {{2,  -1, 4},
                                 {-2, -1, 4},
                                 {0,  -1, 1},
                                 {5,  -8, -12},
                                 {5,  8,  12}};
    vector<string> ret1 = solution(test1);
    cout << "=====" << "\n";
    vector<vector<int>> test2 = {{0, 1, -1},
                                 {1, 0, -1},
                                 {1, 0, 1}};
    vector<string> ret2 = solution(test2);
    cout << "=====" << "\n";

    vector<vector<int>> test3 = {{1, -1, 0},
                                 {2, -1, 0}};
    vector<string> ret3 = solution(test3);
    cout << "=====" << "\n";

    vector<vector<int>> test4 = {{1, -1, 0},
                                 {2, -1, 0},
                                 {4, -1, 0}};
    vector<string> ret4 = solution(test4);

}