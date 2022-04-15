#include <bits/stdc++.h>

using namespace std;

vector<int> Ryan;
vector<int> apeach;
int maxDiff = INT_MIN;
vector<int> ret;

bool isMinimum(vector<int> curRet, vector<int> Ryan) {
    for (int i = 10; i >= 0; i--) {
        if (curRet[i] == Ryan[i])
            continue;
        if (curRet[i] > Ryan[i])
            return true;
        else
            return false;
    }
}

pair<int, int> getPoint(vector<int> apeach, vector<int> Ryan) {
    int retApeachPoint = 0;
    int retRyanPoint = 0;

    for (int i = 0; i < 11; i++) {
        if (apeach[i] == 0 && Ryan[i] == 0)
            continue;
        if (apeach[i] < Ryan[i]) {
            retRyanPoint += 10 - i;
        } else {
            retApeachPoint += 10 - i;
        }
    }
    return {retApeachPoint, retRyanPoint};
}

void search(int arrows, int idx) {
    if (arrows == 0 || idx == 11) {
        Ryan[10] += arrows;
        pair<int, int> pointInfo = getPoint(apeach, Ryan);
        int diff = pointInfo.second - pointInfo.first;
        if (diff > 0 && diff >= maxDiff) {
            if (maxDiff == diff && !isMinimum(ret, Ryan)) {
                ret = Ryan;
            } else if (maxDiff < diff) {
                ret = Ryan;
                maxDiff = diff;
            }
        }
        Ryan[10] -= arrows;
        return;
    }

    if (arrows > apeach[idx]) {
        Ryan[idx] += apeach[idx] + 1;
        search(arrows - apeach[idx] - 1, idx + 1);
        Ryan[idx] -= apeach[idx] + 1;
    }
    search(arrows, idx+ 1);
}


vector<int> solution(int n, vector<int> info) {
    apeach = info;
    Ryan.resize(11, 0);
    search(n, 0);

    if (maxDiff == INT_MIN)
        return {-1};
    else
        return ret;
}

int main() {
    vector<int> ret = solution(5, {2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0});
    for (const auto &item: ret) {
        cout << item << " ";
    }
    cout << "\n";
}