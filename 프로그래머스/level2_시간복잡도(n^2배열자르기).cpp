#include<bits/stdc++.h>

#define ll long long
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(ll i = left; i <= right; i++){
        answer.push_back(max(i / n, i % n) + 1);
    }
    return answer;
}

int main(){
    vector<int> ret = solution(3, 2, 5);
    for (const auto &item: ret) {
        cout << item <<" ";
    }
}