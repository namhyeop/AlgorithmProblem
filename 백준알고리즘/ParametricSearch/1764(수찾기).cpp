#include<bits/stdc++.h>

using namespace std;

vector<string> a, b, ret;
int n , m;
int main(){
    cin >> n >> m;
    a.resize(n), b.resize(m);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());

    auto lower_bound =[&](string target){
        int left = -1;
        int right = n;

        while(left + 1 < right){
            int mid = (left + right) /2 ;

            if(!(a[mid] >= target)){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        if(a[right] == target){
            ret.push_back(target);
        }
    };

    for(int i = 0; i < m; i++){
        lower_bound(b[i]);
    }

    sort(ret.begin(), ret.end());
    cout << ret.size() <<"\n";
    for (const auto &item: ret) {
        cout << item << "\n";
    }
}