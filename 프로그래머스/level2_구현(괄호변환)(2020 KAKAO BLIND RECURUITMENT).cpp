#include<bits/stdc++.h>

#define sz(v) (int)(v).size()
using namespace std;

//올바른 문자열인지 검사하는 함수
bool isValid(string s) {
    stack<char> a, b;

    for (auto c : s) {
        a.push(c);
    }
    for (int i = 0; i < sz(a); i++) {
        if (a.top() == ')') {
            b.push(a.top());
        }
        else{
            if (b.empty())
                return false;
            //같은 경우
            else if (b.top() == ')'){
                b.pop();
            }
            //같지 않은 경우
            else
                return false;
        }
        a.pop();
    }
    return true;
}

string divide(string p) {
    //기저사례: 빈 문자열일 경우 재귀 종료
    if (p.empty())
        return "";

    string ret;
    int leftParen = 0, rightParen = 0;
    string str1, str2;
    //괄호의 종류에 맞게 개수를 측정한 뒤 두 종류의 개수를 측정하는 변수가 같으면 균일한 문자열 완성을 의미하고 반복문 종료
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            leftParen++;
        else
            rightParen++;
        str1 += p[i];
        if (leftParen == rightParen) {
            str2 = p.substr(i + 1);
            break;
        }
    }
    //올바른 문자열이라면 str2(문제에서 v)를 재귀한뒤 결과를 뒤에 붙쳐준다.
    if (isValid(str1)){
        ret += str1 + divide(str2);
    //올바른 문자열이 아니라면 맨 앞과 맨 뒤의 문자를 지워주고 괄호를 붙쳐준뒤 v에 대한 재귀와 u를 결합해준다.
    }else{
        str1.erase(str1.begin() + 0), str1.erase(str1.begin() + str1.size() - 1);

        for(auto &c : str1){
            if(c == ')')
                c = '(';
            else
                c = ')';
        }
        ret += '(' + divide(str2) + ')' + str1;
    }
    return ret;
};

string solution(string p) {
    string answer = "";
    answer = divide(p);
    return answer;
}

int main() {
    string p = "(()())()";
    cout << solution(p) <<"\n";

    string p1 = ")(";
    cout << solution(p1) <<"\n";

    string p2 = "()))((()";
    cout << solution(p2) <<"\n";
}
