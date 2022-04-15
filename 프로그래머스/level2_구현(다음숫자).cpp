#include<bits/stdc++.h>

using namespace std;

string binaryNum(int n){
    int cur = n;

    string tmp ="";
    while(cur != 0){
        int mod = cur % 2;
        cur /= 2;
        tmp += to_string(mod);
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
}

int solution(int n) {
    int answer = 0;
    string start = binaryNum(n);

    int one = 0, zero = 0;
    for (const auto &item: start) {
        if(item == '1'){
            one++;
        }
        else{
            zero++;
        }
    }

    for(int i = n + 1; i < 1000000; i++){
        int cmpOne = 0, cmpZero = 0;
        string cmpStart = binaryNum(i);
        for (const auto &item: cmpStart) {
            if(item == '1'){
                cmpOne++;
            }
            else{
                cmpZero++;
            }
        }
        if(one == cmpOne){
            answer = i;
            break;
        }
    }
    return answer;
}

int main() {
    cout << 0x01 <<"\n";
    cout << solution(78) <<"\n";
//    cout << solution(")()(");
//    cout << solution("(()(");
}