#include <bits/stdc++.h>

using namespace std;


using namespace std;
const int MAX = 1001;
map<string,int> userInfo;
map<int,string> iuserInfo;
int countReport[MAX];
set<string> reportSet[MAX];

vector<string> token_report(string str, char delimiter){
    vector<string> ret;
    string tmp;
    stringstream ss(str);
    while(getline(ss, tmp, delimiter)){
        ret.push_back(tmp);
    }
    return ret;
}
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    int num = 0;
    for(auto s : id_list){
        iuserInfo[num] = s;
        userInfo[s] = num++;
    }
    for(int i = 0; i < report.size(); i++){
        vector<string> cur = token_report(report[i], ' ');
        if(!(reportSet[userInfo[cur[0]]].count(cur[1]))) {
            reportSet[userInfo[cur[0]]].insert(cur[1]);
            countReport[userInfo[cur[1]]]++;
        }
    }
    for(int i = 0; i < id_list.size(); i++){
        if(countReport[i] >= k){
            for(int j = 0; j < id_list.size(); j++){
                if(reportSet[j].count(iuserInfo[i])) {
                    answer[j]++;
                }
            }
        }
    }
    return answer;
}

int main() {
//    vector<int> test1 = solution({"muzi", "frodo", "apeach", "neo"}, {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"},2);
    vector<int> test2 = solution({"con", "ryan"}, {"ryan con", "ryan con", "ryan con", "ryan con"},3);

}