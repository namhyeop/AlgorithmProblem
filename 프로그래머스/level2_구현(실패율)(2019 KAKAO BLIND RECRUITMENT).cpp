/**
 * 실패율 : 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어의 수
 */
#include<bits/stdc++.h>

using namespace std;
const int MAX = 502;
int remainPeople[MAX];
int tryPeople[MAX];

bool cmp(pair<int,double> a, pair<int,double> b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else if(a.second == b.second){
        return a.first < b.first;
    }
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for(auto n : stages){
        remainPeople[n]++;
        //n개의 층까지 도달한것은 n이전의 층들을 도달한것이므로 점수를 더해준다.
        for(int i = 1; i <= n; i++){
            tryPeople[i]++;
        }
    }
    vector<pair<int,double>> info;
    for(int i = 1; i <= N; i++){
        //시도한 사람이 없는 경우 실패율은 0이므로 예외처리
        if(tryPeople[i] == 0){
            info.push_back({i, 0});
            continue;
        }
        //문제의 조건을 활용하여 정보를 갱신한다.
        info.push_back({i,remainPeople[i] / double(tryPeople[i])});
    }
    //실패율에 비례한 정렬(문제조건)
    sort(info.begin(), info.end(), cmp);
    for(int i = 0; i < info.size(); i++){
        answer.push_back(info[i].first);
    }
    return answer;
}

int main(){
    vector<int> ret = solution(5, {2,1,2,6,2,4,3,3});
    for(auto a : ret)
        cout << a << " ";
    cout <<"\n";
}