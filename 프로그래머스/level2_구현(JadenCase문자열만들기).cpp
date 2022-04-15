#include<bits/stdc++.h>

using namespace std;

string str_lower(string tmp){
    string ret ="";
    for(int i = 0; i < tmp.size(); i++){
        if('A' <= tmp[i] && tmp[i] <= 'Z')
            ret += tolower(tmp[i]);
        else
            ret += tmp[i];
    }
    return ret;
}

vector<string> split(string str, char delimiter){
    vector<string> ret;
    stringstream ss(str);
    string tmp;
    while(getline(ss, tmp, delimiter)){
        tmp = str_lower(tmp);
        if(tmp[0] >= '0' && tmp[0] < '9'){
            ret.push_back(tmp);
        }else{
            if(tmp[0] >= 'a' && tmp[0] <= 'z'){
                tmp[0] = toupper(tmp[0]);
            }
            ret.push_back(tmp);
        }
    }
    return ret;
}

string solution(string s) {
    string answer = "";
    vector<string> ret = split(s,' ');

    for(int i = 0; i < ret.size() - 1; i++){
        answer += ret[i] + " ";
    }
    answer += ret.back();

    /**
     * 마지막 글자에 공백이 있을수 있으므로 원본 s와 사이즈가 같지 않다는건 마지막 글자에 공백이 있는것을 의미
     */
    if(answer.size() != s.size()){
        answer.push_back(' ');
    }
    return answer;
}

int main(){
    cout << solution("3people unFollowed      me     ") <<"\n";
}