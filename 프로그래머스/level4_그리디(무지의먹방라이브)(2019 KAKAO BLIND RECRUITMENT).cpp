#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> food_times, long long k) {
    long long sum = 0, before = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pfood_times;
    for (int i = 0; i < food_times.size(); i++) {
        sum += food_times[i];
        pfood_times.push(make_pair(food_times[i], (i + 1)));
    }
    //if sum Value is less then or equal to k. it is mean search is impossible
    if (sum <= k)    return -1;
    while ((pfood_times.top().first - before) * pfood_times.size() <= k) {
        k -= (pfood_times.top().first - before) * pfood_times.size();
        //Update the time of the previous food to the time of the current food.
        before = pfood_times.top().first;
        pfood_times.pop();
    }
    vector<pair<int, int>> ftimes;
    while (!pfood_times.empty()) {
        ftimes.push_back(make_pair(pfood_times.top().second, pfood_times.top().first));
        pfood_times.pop();
    }
    //Arrange the food in the order of beginning
    sort(ftimes.begin(), ftimes.end());
    return ftimes[k % ftimes.size()].first;
}

int main(){
    vector<int> food_times = {3,1,2};
    int k = 5;
    cout << solution(food_times, k) <<"\n";
}