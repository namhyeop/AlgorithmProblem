#include<bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    //문자열의 길이가 오름차순으로
    if(a.size() != b.size())
        return a.size() < b.size();
    //같다면 알파벳순으로
    if(a.size() == b.size())
        return a < b;
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> rwords = words;
    for(int i = 0; i < rwords.size(); i++){
        reverse(rwords[i].begin(), rwords[i].end());
    }
    //접두사에 ?가 있는 경우를 위한 배열
    sort(rwords.begin(), rwords.end(), cmp);
    sort(words.begin(), words.end(), cmp);

    for(auto &q : queries){
        int lowIndex, hiIndex;
        //query의 접두사에 ?가 있는 경우
        if(q[0] == '?'){
            //query도 뒤집어준다.
            reverse(q.begin(), q.end());
            int idx = q.find('?');
            for(int i = idx; i < q.size(); i++){
                q[i] = 'a';
            }
            lowIndex = lower_bound(rwords.begin(), rwords.end(), q,cmp) - rwords.begin();
            for(int i = idx; i < q.size(); i++){
                q[i] = 'z';
            }
            hiIndex = upper_bound(rwords.begin(), rwords.end(), q,cmp) - rwords.begin();
        }
        else{
            int idx = q.find('?');
            for(int i = idx; i < q.size(); i++){
                q[i] = 'a';
            }
            lowIndex = lower_bound(words.begin(), words.end(), q,cmp) - rwords.begin();
            for(int i = idx; i < q.size(); i++){
                q[i] = 'z';
            }
            hiIndex = upper_bound(words.begin(), words.end(), q, cmp) - rwords.begin();
        }
        //찾으려는 문자열의 뒤이 위치와 앞의 위치를 빼주면 개수가 나온다.
        answer.push_back(hiIndex - lowIndex);
    }
    return answer;
}

int main(){
    vector<string> str= {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    vector<int> ret =  solution(str, queries);
    for(auto n : ret)
        cout << n << " ";
}