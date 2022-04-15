//
// Created by 김남협 on 2022/03/23.
//

#include<bits/stdc++.h>

using namespace std;

int n;

struct info{
    string name;
    string extension;

    bool operator < (const info other) const{
        if(extension != other.extension)
            return extension < other.extension;
        return name < other.name;
    }
};

vector<info> arrInfo;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        arrInfo.push_back({tmp.substr(0,tmp.find('.')), tmp.substr(tmp.find('.') + 1)});
    }

    sort(arrInfo.begin(), arrInfo.end());
    string curExtension = arrInfo[0].extension;
    int count = 1;
    for(int i = 1; i < arrInfo.size(); i++){
        string nextExtension = arrInfo[i].extension;
        if(curExtension == nextExtension){
            count++;
        }
        else{
            cout << curExtension << " " << count <<"\n";
            curExtension = nextExtension;
            count = 1;
        }
    }
    cout << curExtension << " " << count <<"\n";
}