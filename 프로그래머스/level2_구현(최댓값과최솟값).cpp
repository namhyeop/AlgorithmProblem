#include<bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> numArr;
    string str = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            numArr.push_back(stoi(str));
            str = "";
        }
        str += s[i];
    }
    if(str.size()){
        numArr.push_back(stoi(str));
    }
    answer += to_string(*min_element(numArr.begin(), numArr.end())) + " " + to_string(*max_element(numArr.begin(), numArr.end()));
    return answer;
}

int main() {
    cout << solution("1 2 3 4") <<"\n";
}