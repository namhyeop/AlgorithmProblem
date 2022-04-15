#include<bits/stdc++.h>

using namespace std;
//예외 교집합 공집합이 0 일때는 1로 정의

/**
 * 문자열을 일단 대문자로 통일 시키기 위한 함수 
 */
string strToupper(string str){
    string rstr = "";
    for(int i = 0; i < str.size(); i++){
        rstr += toupper(str[i]);
    }
    return rstr;
}

/**
 * 두 글자씩 끊어주는 함수 
 */
vector<string> sliceStr(string str){
    vector<string> rStr;

    int count = 0;
    for(int i = 0; i < str.size() - 1; i++){
        if(!('A' <= str[i] && str[i] <= 'Z') || !('A' <= str[i + 1] && str[i + 1] <= 'Z'))
            continue;
        string tmpStr = str.substr(i, 2);
        rStr.push_back(tmpStr);
    }
    return rStr;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = strToupper(str1);
    str2 = strToupper(str2);

    vector<string> vStr1 = sliceStr(str1);
    vector<string> vStr2 = sliceStr(str2);

    sort(vStr1.begin(), vStr1.end());
    sort(vStr2.begin(), vStr2.end());

    int vStr1Size = vStr1.size();
    int vStr2Size = vStr2.size();

    int intersectionCount = 0;
    int CombinationCount = 0;

    /**
     * 교집합 숫자를 구해주는 과정. 존재할 시 재검색 불가능하게 삭제를 진행해준다.
     */
    for(int i = 0; i < vStr1.size(); i++){
        auto it = find(vStr2.begin(), vStr2.end(), vStr1[i]);
        if(it == vStr2.end()){
            continue;
        }
        else{
            vStr2.erase(it);
            intersectionCount++;
        }
    }

    /**
     * 전체집합수에서 교집합 수를 빼주면 합집합의 개수가 나온다.
     */
    CombinationCount = ((vStr1Size + vStr2Size) - intersectionCount);

    /**
     * 예외처리 과정
     */
    if(CombinationCount == 0 && intersectionCount == 0)
        answer = 65536;
    else{
        double tmpanswer = intersectionCount * 65536 / CombinationCount;
//        double tmpanswer = (((double)intersectionCount * 100/ (double)CombinationCount) * 0.01) * 65536;
        tmpanswer = trunc(tmpanswer);
        answer = tmpanswer;
    }

    return answer;
}

int main() {
    string str1 = "FRANCE";
    string str2 = "french";

//    string str1 = "handshake";
//    string str2 = "shake hands";

//    string str1 = "aa1+aa2";
//    string str2 = "AAAA12";

//    string str1 = "E=M*C^2";
//    string str2 = "e=m*c^2";

    int answer = solution(str1, str2);
    cout <<answer <<"\n";
}