#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int MAX = 500;
const int UNIT_MAX = 1e5 + 1;

int row;

bool cmp(vector<string> &a, vector<string> &b){
    return a.size() < b.size();
}

vector<vector<string>> parse(string s){
    vector<vector<string>> ret(MAX);
    string tmp ="";
    row = 0;
    for(int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <='9'){
            tmp += s[i];
        }
        else if(s[i] == '{'){
            continue;
        }
        else if(s[i] == ',' && !tmp.empty()){
            ret[row].push_back(tmp);
            tmp ="";
        }
        else if(s[i] == '}' && !tmp.empty()){
            ret[row].push_back(tmp);
            tmp ="";
            row++;
        }
    }
    return ret;
}
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<string>> strArr = parse(s);

    sort(strArr.begin(), strArr.begin() + row, cmp);

    vector<bool> visited(UNIT_MAX, false);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < strArr[i].size(); j++){
            int testValue = stoi(strArr[i][j]);
            if(!visited[testValue]){
                answer.push_back(testValue);
                visited[testValue] = true;
            }
        }
    }
    return answer;
}

int main(){
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    string s1 = "{{20,111},{111}}";
    string s2 = "{{123}}";

    return 0;
}