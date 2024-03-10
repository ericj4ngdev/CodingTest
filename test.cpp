#include <bits/stdc++.h>
using namespace std;

string a, b;

string Add(string a, string b)
{
    int sum = 0;
    string ret;
    while(a.size()||b.size()||sum){
        if(a.size()){
            sum += a.back() - '0';            
            a.pop_back();
        }
        if(b.size()){
            sum += b.back() - '0';
            b.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;        
    }
    reverse(ret.begin(), ret.end());      // 이거 까먹지 않기
    return ret;
}

int main(){
    cin >> a >> b;
    cout << Add(a, b);
}