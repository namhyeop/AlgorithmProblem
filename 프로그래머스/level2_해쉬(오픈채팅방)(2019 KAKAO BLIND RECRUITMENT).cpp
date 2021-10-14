#include<bits/stdc++.h>

using namespace std;

map<string, string> db;
vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string, string>> log;
    for(auto s : record){
        string cmd, id, name;
        stringstream ss(s);
        ss >> cmd >> id >> name;

        if(cmd == "Enter"){
            db[id] = name;
            log.push_back({id, "님이 들어왔습니다."});
        }
        else if(cmd == "Leave"){
            log.push_back({id, "님이 나갔습니다."});
        }
        else if(cmd == "Change"){
            db[id] = name;
        }
    }

    for(auto p : log){
        answer.push_back(db[p.first] + p.second);
    }
    return answer;
}

int main(){
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> ret = solution(record);
    for(auto s : ret){
        cout << s <<"\n";
    }
}