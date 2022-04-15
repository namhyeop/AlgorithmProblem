#include<bits/stdc++.h>

using namespace std;
#define ll long long
/**
 * 주의. 계산 결과가 음수라면  해당 숫자의 절대값으로 변환하여 제출
 */

/**
 * 주어진 문자열을 token화 하는 과정
 */
vector<string> strTotoken(string expression) {
    vector<string> ret;
    string tmp = "";
    for (auto s: expression) {
        if (!('0' <= s && s <= '9')) {
            ret.push_back(tmp);
            ret.push_back(string(1, s));
            tmp = "";
            continue;
        }
        tmp += s;
    }
    ret.push_back(tmp);
    return ret;
}

/**
 * 조합의 경우(0 == +, 1 == -, 2 == *)를 실제 연산해주는 함수
 */
vector<string> opParsing(vector<string> op) {
    vector<string> ret;
    for (int i = 0; i < 3; i++) {
        if (op[i] == "0")
            ret.push_back("+");
        else if (op[i] == "1")
            ret.push_back("-");
        else
            ret.push_back("*");
    }
    return ret;
}

ll calculator(string num1, string num2, string op){
    ll arg1 = stoll(num1), arg2 = stoll(num2);
    if(op == "+") return arg1  + arg2;
    else if(op == "-") return arg1 - arg2;
    else return arg1 * arg2;
}

/**
 * 디버깅용 함수
 */
void print_vector(vector<string> str){
    for (const auto &item: str) {
        cout << item << " ";
    }
    cout <<"\n";
}

/**
 * next_permutaion을 활용하여 모든 조합의 경우 수를 구해준다.
 */
long long solution(string expression) {
    long long answer = 0;
    vector<string> op = {"0", "1", "2"};
    do {
        vector<string> str = strTotoken(expression);
        vector<string> sop = opParsing(op);

        for (int i = 0; i < 3; i++) {
            while (1) {
                auto it = find(str.begin(), str.end(), sop[i]);
                if (it == str.end()) {
                    break;
                }
                int pos = it - str.begin();
                /**
                 * calculator 함수를 사용해서
                 * 우선순위에 맞는 계산을 해준 이후
                 * 삽입해줄 위치(우선순위 연산자의 앞)에 삽입해준 뒤
                 * 기존에 있던 연산자, 피연산자2의 범위를 삭제해준다.
                 */
                ll num = calculator(str[pos-1], str[pos + 1], str[pos]);
                str.insert(str.begin()+pos - 1, to_string(num));
                str.erase(str.begin() + pos, str.begin() + pos + 3);
            }
        }
        answer = max(answer, abs(stoll(str[0])));
    } while (next_permutation(op.begin(), op.end()));
    return answer;
}

int main() {
    cout << solution("100-200*300-500+20");
}