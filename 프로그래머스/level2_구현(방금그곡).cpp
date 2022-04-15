#include<bits/stdc++.h>

#define ll long long

using namespace std;

struct songInfo {
    int playTime;
    string name;
    vector<string> note;
};

vector<songInfo> info;

/**
 * 정답 가능한 악보 후보가 많은 경우 가장 긴 시간을 반환해주기 위한 정렬 알고리즘.
 * 현재 알고리즘에서는 악보 순서대로 탐색을 하기 때문에 시간이 같은 경우 가장 먼저 나온 악보를 사용한다는 조건은 신경 안써줘도 된다.
 */
bool cmp(int i, int j) {
    if (info[i].playTime != info[j].playTime)
        return info[i].playTime > info[j].playTime;
    return false;
}

/**
 *  음표 + '#'을 한 개의 string으로 묶어주는 과정.
 *  token화 과정이라 생각하면 이해하기 쉽다.
 */
vector<string> token_str(string str) {
    vector<string> ret;
    for (int i = 0; i < str.size(); i++) {
        if (str[i + 1] == '#') {
            ret.push_back(str.substr(i, 2));
            i++;
        } else {
            ret.push_back(str.substr(i, 1));
        }
    }
    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    vector<string> parseM = token_str(m);

    /**
     * musicinfos 정보들을 파싱해주는 과정이다.
     * 00:00 형식이지만 0:00 형식도 패스 해줄수 있게 slice 하도록 구현했다.
     */
    for (auto str: musicinfos) {
        int pos1 = str.find(':');
        int pos2 = str.find(",", pos1);
        int pos3 = str.find(":", pos2);
        int pos4 = str.find(",", pos3);
        int pos5 = str.rfind(",");

        int s = stoi(str.substr(0, pos1 - 0)) * 60 + stoi(str.substr(pos1 + 1, pos2 - pos1));
        int e = stoi(str.substr(pos2 + 1, pos3 - pos2)) * 60 + stoi(str.substr(pos3 + 1, pos4 - pos3));

        int time = e - s;
        if (time < 0) {
            time *= -1;
        }
        string name = str.substr(pos4 + 1, pos5 - pos4 - 1);
        string singNote = str.substr(pos5 + 1);
        vector<string> token_note = token_str(singNote);
        info.push_back({time, name, token_note});
    }

    vector<int> candidate;
    int cNum = 0;

    /**
     * 위에서 곡 정보들을 songinfo로 변환 시킨 이후 곡 정보에서 시작 가능한 모든 경우를 음표 부분과 일치한지 완전 탐색해주었다.
     * 곡의 정보가 긴 경우 원형 리스트처럼 정보가 계속 탐색되어야 하기 때문에 %연산을 사용해서 구현해주었다.
     */
    for (auto cur: info) {
        auto[time, name, note] = cur;
        for (int i = 0; i < note.size(); i++) {
            bool flag = false;
            int idx = 0;
            int count = 0;
            for (int j = i; j < time; j++) {
                if (note[j % note.size()] == parseM[idx % parseM.size()]) {
                    count++;
                    idx++;
                } else {
                    break;
                }
                /**
                 * 찾으려는 음표의 개수가 일치하면 찾으려하는 곡이 맞는 경우므로 vector에 넣어준다.
                 */
                if (count == parseM.size()) {
                    candidate.push_back(cNum);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        cNum++;
    }
    if (candidate.size() != 0) {
        sort(candidate.begin(), candidate.end(), cmp);
        answer = info[candidate[0]].name;
    }
    return answer;
}