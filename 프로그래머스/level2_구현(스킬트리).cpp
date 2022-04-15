//
// Created by 김남협 on 2022/03/06.
//

#include<bits/stdc++.h>

#define ll long long
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(int i = 0; i < skill_trees.size(); i++){
        bool flag = false;
        int now = 0;
        string cur = skill_trees[i];
        for(int j = 0; j < cur.size(); j++){
            if(flag)
                break;
            for(int k = 0; k < skill.size(); k++) {
                if(cur[j] == skill[k]){
                    if(k>now){
                        flag = true;
                    }
                    now++;
                    break;
                }
            }
        }
        if(!flag)
            answer++;
    }
//    cout << answer <<"\n";
    return answer;
}