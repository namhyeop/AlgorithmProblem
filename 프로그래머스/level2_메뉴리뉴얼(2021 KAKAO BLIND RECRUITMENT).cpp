#include<bits/stdc++.h>

using namespace std;

int cnt[21];//cnt[i] : i개의 글자로 만들어진것들 중 가장 많이 나온 갯수, i개의 글자로 만들어진 최대 갯수를 사용하여 board값에 i개의 글자로 만들어진것만 추출할 것
unordered_map<string, int> stCnt;//만들어진 조합이 나온 갯수
vector<string> board[21][21]; //board[i][j] = n : i개로 이루어진 글자가 j번 나온 경우 경우의 갯수 n

void comb(string s, int idx, string menu){
    if(menu.size() > 1){
        stCnt[menu]++;
        cnt[menu.size()] = max(stCnt[menu], cnt[menu.size()]);
        board[menu.size()][stCnt[menu]].push_back(menu);
    }

    for(int i = idx + 1; i < s.size(); i++){
        menu.push_back(s[i]);
        comb(s, i, menu); //반복문 내의 i를 활용하여 위치값을 1개씩 증가시킴
        menu.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course){
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        comb(orders[i], -1, "");
    }

    for(auto cor : course){
        if(cnt[cor] > 1)
        for(auto s : board[cor][cnt[cor]]){
            answer.push_back(s);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main(){
    vector<string> ret1 = solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2,3,4});
    for(auto cur: ret1)
        cout << cur << " ";
    cout << "\n";
}
