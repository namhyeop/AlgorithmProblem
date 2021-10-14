#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long sum = 0, before = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pfood_times;
    for (int i = 0; i < food_times.size(); i++) {
        sum += food_times[i];
        pfood_times.push(make_pair(food_times[i], (i + 1)));
    }
    if (sum <= k)    return -1;
    while ((pfood_times.top().first - before) * pfood_times.size() <= k) {
        k -= (pfood_times.top().first - before) * pfood_times.size();
        before = pfood_times.top().first;
        pfood_times.pop();
    }
    vector<pair<int, int>> ftimes;
    while (!pfood_times.empty()) {
        ftimes.push_back(make_pair(pfood_times.top().second, pfood_times.top().first));
        pfood_times.pop();
    }
    sort(ftimes.begin(), ftimes.end());
    return ftimes[k % ftimes.size()].first;
}

int main(){
    vector<int> food_times = {3,1,2};
    int k = 5;
    cout << solution(food_times, k) <<"\n";
}