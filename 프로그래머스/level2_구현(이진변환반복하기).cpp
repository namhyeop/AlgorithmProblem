#include<bits/stdc++.h>

#define ll long long
using namespace std;
string decimalToTwo(int Num){
    string ret = "";

    while(Num != 0){
        int mod = Num % 2;
        Num /=2;
        ret.push_back(mod + '0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer(2);
    string cur = s;
    int cycleCount = 0, zeroCnt = 0;

    while(cur.size() != 1){
        cout << cur <<"\n";
        string tmpCur = "";
        for (const auto &item: cur) {
            if(item != '0')
                tmpCur +=item;
            else
                zeroCnt++;
        }

        int decimalNum = tmpCur.size();
        cur = decimalToTwo(decimalNum);
        cycleCount++;
    }

    answer[0] = cycleCount, answer[1] = zeroCnt;
    return answer;
}