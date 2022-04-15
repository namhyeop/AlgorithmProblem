#include<bits/stdc++.h>

using namespace std;

vector<int> make_num(int n, int t, int m) {
    vector<int> dic;
    int num = 0;
    while (dic.size() < t * m) {
        int tmpnum = num;

        if (tmpnum == 0) {
            dic.push_back(0);
        } else {
            vector<string> tmpStr;
            while (tmpnum != 0) {
                int mod = tmpnum % n;
                tmpnum /= n;
                tmpStr.push_back(to_string(mod));
            }
            reverse(tmpStr.begin(), tmpStr.end());
            for (const auto &str: tmpStr) {
                dic.push_back(stoi(str));
            }
        }
        num++;
    }
    return dic;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    vector<int> dic;
    while (dic.size() < t) {
        dic = make_num(n, t, m);
    }
    int pushPos = p - 1;
    for (int i = 0; i < t; i++) {
        if (dic[pushPos] >= 10){
            answer += 'A' + dic[pushPos] - 10;
        }
        else
            answer += to_string(dic[pushPos]);
        pushPos += m;
    }
    return answer;
}

int main() {
    cout << solution(2, 4, 2, 1) <<"\n";
    cout << solution(16,16,2,1);
//    cout << solution(")()(");
//    cout << solution("(()(");
}