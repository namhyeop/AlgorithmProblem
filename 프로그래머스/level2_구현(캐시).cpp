#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int MAX = 31;
vector<string> cache;
int cacheScore[MAX];

void minus_cacheValue(){
    for(int i = 0; i < cache.size(); i++){
        cacheScore[i]--;
    }
}

void debuging_image_print(int &cacheSize, int &i, int &answer){
    cout <<"i: " << i << " " << answer <<"\n";
    for(int i = 0; i < cacheSize; i++){
        cout << cache[i] <<" ";
    }
    cout <<"\n";
    for(int i = 0; i < cacheSize; i++){
        cout << cacheScore[i] <<" ";
    }
    cout <<"\n";
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0) {
        answer = cities.size() * 5;
        return answer;
    }

    for (auto &item: cities) {
        for (int i = 0; i < item.size(); i++) {
            item[i] = toupper(item[i]);
        }
    }

    for (int i = 0; i < cities.size(); i++) {
        auto it = find(cache.begin(), cache.end(), cities[i]);
        if (it != cache.end()) {
            answer += 1;
            minus_cacheValue();
            cacheScore[it - cache.begin()] = 0;
        } else {
            answer += 5;
            if(cache.size() < cacheSize){
                minus_cacheValue();
                cache.push_back(cities[i]);
                cacheScore[cache.size() - 1] = 0;
            }else {
                int pos = min_element(cacheScore, cacheScore + cacheSize) - cacheScore;
                minus_cacheValue();
                cache[pos] = cities[i];
                cacheScore[pos] = 0;
            }
        }
//        debuging_image_print(cacheSize, i, answer);
    }
    return answer;
}

int main() {
//    cout << solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) <<"\n";
    cout << solution(2, {"Jeju", "Pangyo", "NewYork", "newyork"}) << "\n";
//    cout << solution(0, {"Jeju", "Pangyo", "NewYork", "newyork"}) <<"\n";
}