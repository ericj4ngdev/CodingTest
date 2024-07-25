#include<bits/stdc++.h>
using namespace std;

int n;
string str;
string temp;
vector<string> v;

bool compare(string a, string b)
{
    // 자리수 비교    
    if(a.size() < b.size())
    {
        return true;
    }
    else if(a.size() == b.size())
    {
        // 자리수 같은 경우 각 자리 숫자 비교
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] < b[i]) return true;        
            else if(a[i] > b[i]) return false;
        }
    }

    // a자리수가 더 많으면 false
    return false;    
}

int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> str;
        temp = "";
        // 글자 분해하고 숫자 뽑아서 배열에 넣기
        for(char c : str)
        {
            // 숫자 -> temp에 저장
            if(c >= 49 && c <= 57)
            {
                temp.push_back(c);
            }
            else if(temp.size())
            {
                v.push_back(temp);
                temp.clear();
            }
        }
        if(temp.size())
        {
            v.push_back(temp);
            temp.clear();
        }
    }

    sort(v.begin(), v.end(), compare);

    for(string s : v)
    {
        cout << s << '\n';
    }
        
    return 0;
}