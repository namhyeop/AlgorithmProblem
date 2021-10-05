#include<bits/stdc++.h>

using namespace std;

struct parsing{
    string input;
    parsing(string input) : input(input) {}

    string search(){
        string ret = "";
        string tmpret = "";

        //조건1
        for(auto cur : input){
            if(cur >= 'A' && cur <= 'Z'){
                ret += cur + 32;
            }
            else
                ret += cur;
        }

        //조건2
        for(auto cur : ret){
            if(!(('a' <= cur && 'z' >= cur) || ('0' <= cur && cur <= '9') || (cur == '-') || (cur == '_') || (cur == '.')))
            {
                continue;
            }
            else{
                tmpret += cur;
            }
        }
        ret = tmpret;

        //조건3
        tmpret = "";
        for(int i = 0;  i < ret.size(); i++){
            if(ret[i] == '.' && ret[i] == ret[i + 1] && i != ret.size() - 1){
                tmpret += '.';
                while(ret[i] == '.')
                    i++;
                i--;
            }
            else{
                tmpret += ret[i];
            }
        }
        ret = tmpret;

        //조건4
        tmpret = "";
        for(int i = 0;  i < ret.size(); i++){
            if((i == 0 && ret[i] == '.') || (i == (int)ret.size() - 1 && ret[i] == '.'))
                continue;
            else
                tmpret += ret[i];
        }
        ret = tmpret;

        //조건5
        if(ret.size() == 0)
            ret += 'a';

        //조건6
        if(ret.size() >= 16){
            tmpret = "";
            for(int i = 0; i < 15; i++){
                if(i == 14 && ret[i] == '.')
                    continue;
                tmpret += ret[i];
            }
            ret = tmpret;
        }

        if(ret.size() <= 2){
            while(ret.size() != 3){
                ret += ret[ret.size() - 1];
            }
        }
        return ret;
    };
};

string solution(string input) {
    parsing s(input);
    string answer = s.search();
    return answer;
}

int main(){
    cout << solution("...!@BaT#*..y.abcdefghijklm") <<"\n";
    cout << solution("z-+.^.") <<"\n";
    cout << solution("=.=") <<"\n";
    cout << solution("123_.def") <<"\n";
    cout << solution("abcdefghijklmn.p") <<"\n";
}