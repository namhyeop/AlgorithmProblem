level2_완전탐색+백트래킹(후보키)(2019 KAKAO BLIND RECRUITMENT)
#include <bits/stdc++.h>

using namespace std;

int cLen, retCnt;
vector<vector<string>> Board;
vector<vector<int>> candidate;
vector<int> v;
bool visited[9];

//A fuction that returns a true or false, if combination have only one as a candidate key
bool isUnique(){
    vector<string> evaltionList;
    for(int i = 0; i < Board.size(); i++){
        string sentance;
        for(int j = 0; j < v.size(); j++){
            int pos = v[j];
            sentance += Board[i][pos];
        }
        if (find(evaltionList.begin(), evaltionList.end(), sentance) == evaltionList.end())
            evaltionList.push_back(sentance);
        else
            //if the candidate key comes out once again, it does not satisfy the unique conditions
            return false;

    }
    return true;
}

//A funtion isMinimalty return a true, if combination have most small of the key
bool isMinimalty(){
    for(int i = 0; i < candidate.size(); i++){
        bool outFlag = false;
        for(int j = 0; j < candidate[i].size(); j++){
            int testNum = candidate[i][j];
            if(find(v.begin(), v.end(), testNum) == v.end()){
                outFlag = true;
                break;
            }
        }
        if(outFlag == false)
            return false;
    }
    return true;
}

bool check(){
    if(isUnique() && isMinimalty()){
        return true;
    }
    else
        return false;
}

void DFS(int idx, int cnt , int totalCnt){
    if(cnt == totalCnt){
        if(check()){
            //Candidate keys that have come out at least onece must be stored. cos when they are needed to verity the minimun
            candidate.push_back(v);
            retCnt++;
        }
        return;
    }

    for(int i = idx; i < cLen; i++){
        //only checked unused arr
        if(!visited[i]){
            visited[i] = true;
            //process of putting the combination factor
            v.push_back(i);
            DFS(idx + 1, cnt + 1, totalCnt);
            v.pop_back();
            visited[i] = false;
        }
    }
}
int solution(vector<vector<string>> board) {
    cLen =  board[0].size();
    Board = board;
    //this is circumstance of make of all of the combination
    for(int i = 1; i <= cLen; i++)
        DFS(0, 0, i);
    return retCnt;
}

int main() {
    int a = solution({{"100", "ryan",   "music",    "2"},
                      {"200", "apeach", "math",     "2"},
                      {"300", "tube",   "computer", "3"},
                      {"400", "con",    "computer", "4"},
                      {"500", "muzi",   "music",    "3"},
                      {"600", "apeach", "music",    "2"}});
    cout << a << "\n";
}
