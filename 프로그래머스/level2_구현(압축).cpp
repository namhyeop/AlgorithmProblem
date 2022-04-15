#include<bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int row,col;
vector<int> cache;
map<string, int> m;
set<string> s;

vector<int> solution(string msg) {
    vector<int> answer;
    int num = 1;
    for(; num <= 26; num++){
        m[string(1,num - 1 + 'A')] = num;
        s.insert(string(1,num - 1 + 'A'));
    }
    int pos = 0;
    while(pos != msg.size()){
        string tmp = "";
        int nextWord = pos;
        while((s.count(tmp) || tmp.size() == 0)){
            tmp += msg[nextWord++];
        }
        pos = nextWord - 1;
        string curW = tmp.substr(0,tmp.size() - 1);
        answer.push_back(m[curW]);
        /**
         * 사전에 추가하여 입력방지 및 숫자 마킹
         */
        s.insert(tmp);
        m[tmp] = num++;
    }
    return answer;
}

int main(){
    vector<int> test =  solution("KAKAO");
}