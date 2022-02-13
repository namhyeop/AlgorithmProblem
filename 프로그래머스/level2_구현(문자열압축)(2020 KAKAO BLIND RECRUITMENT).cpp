//어떻게 된게 과거에 푼게 더 잘풀었
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int minSize = INT_MAX;

    if(s.size() == 1)
        return 1;

    int sSize = s.size();
    int searchSize = s.size() / 2;
    for (int i = 1; i <= searchSize; i++) {
        string jStr = "";
        int curCnt = 1;
        for(int j = 0; j < sSize; j+= i){ //시작부터 전체 탐색 위치
            if(j + i > s.size()) {
                jStr += s.substr(j);
                break;
            }
            string curStr = s.substr(j, i);
            string nextStr = s.substr(j + i , i);
            if(curStr == nextStr){
                curCnt++;
            }
            else{
                if(curCnt == 1){
                    jStr += curStr;
                }
                else{
                    jStr += to_string(curCnt) + curStr;
                    curCnt = 1;
                }
            }
        }
        if(minSize > jStr.size())
            minSize = jStr.size();
    }
    return minSize;
}

int main() {
    string tCase1 = "aabbaccc";
    string tCase2 = "ababcdcdababcdcd";
    string tCase3 = "abcabcdede";
    string tCase4 = "abcabcabcabcdededededede";
    string tCase5 = "xababcdcdababcdcd";

    cout << solution(tCase1) <<"\n";
    cout << solution(tCase2) << "\n";
    cout << solution(tCase3) <<"\n";
    cout << solution(tCase4) <<"\n";
    cout << solution(tCase5) <<"\n";

    return 0;
}

// #include<bits/stdc++.h>

// using namespace std;
// int solution(string s) {
//     int answer = 987654321;

//     int maxLength = s.size();
//     int sLen = s.size();
//     int inValue = 1; //몇 칸으로 나눌지를 결정하는 변수
//     for(int i = 0; i < (sLen / 2) + 1; i++){ //문자열의 중첩되는 최대 경우는 절반이므로 절반만 탐색을 진행한다.
//         vector<string> sArr;
//         for(int j = 0; j < sLen; j += inValue){ //나눠준 문자열을 sArr에 넣어준다.
//             sArr.push_back(s.substr(j, inValue));
//         }
//         int cnt = 1;
//         string makeS;
//         for(int i = 1; i < sArr.size(); i++){ //문자열이 같다면 갯수를 증가시켜주고 아니라면 갱신과정을 진행한다.
//             if(sArr[0] == sArr[i]){
//                 cnt++;
//             }
//             else{
//                 //문제의 조건에 따른 예외처리
//                 if(cnt == 1)
//                     makeS += sArr[0];
//                 else
//                     makeS += to_string(cnt) + sArr[0];
//                 //탐색이 진행된 부분은 sArr에서 삭제를 진행한다.
//                 sArr.erase(sArr.begin(), sArr.begin() + i);
//                 i = 0, cnt = 1;
//             }
//         }
//         if(cnt == 1)
//             makeS += sArr[0];
//         else
//             makeS += to_string(cnt) + sArr[0];

//         //문자열의 길이를 갱신해준다.
//         answer = min(answer, (int)makeS.size());
//         inValue++;
//     }
//     return answer;
// }
