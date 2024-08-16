#include<bits/stdc++.h>
using namespace std;

int num[10];
int main()
{
    string number;
    cin >> number;

    // 문자열 말고 %10하여 자리수로 받는 방법도 있다. 
    // 그런데 n의 범위가 백만까지라 괜찮은듯
    for(auto c : number)
    {
        // 6에 몰아넣기
        if(c == '9')
        {
            num[6]++;
        }
        else
        {
            num[(int)c - 48]++;
        }
    }

    if(num[6] % 2 == 0)
    {
        num[6] /= 2;
    }
    else
    {
        num[6] = num[6] / 2 + 1;
    }

    // for(int i = 0; i < 10; i++)
    // {
    //     cout << num[i] << " ";
    // }
    // cout << endl;
    // 배열 중 가장 숫자가 높은 것
    int ret = *max_element(num,num+9);

    cout << ret;
    return 0;
}