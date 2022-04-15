#include<bits/stdc++.h>

using namespace std;

set<string> sBag;

int cur_people = 0;
int gameCycle = 1;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    string prev_word = words[0];
    for(int i = 0; i < words.size(); i++){
        if(i == 0) {
            sBag.insert(words[i]);
            continue;
        }
        cur_people = (i % n) + 1;

        if(i % n == 0)
            gameCycle++;

        if(prev_word.back() != words[i].front()){
            answer[0] = cur_people;
            answer[1] = gameCycle;
            break;
        }
        if(sBag.count(words[i])){
            answer[0] = cur_people;
            answer[1] = gameCycle;
            break;
        }
        sBag.insert(words[i]);
        prev_word = words[i];
    }

    return answer;
}

int main(){
    vector<int> ret = solution(3, {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
    for (const auto &item: ret) {
        cout << item << " ";
    }
    cout <<"\n";
}