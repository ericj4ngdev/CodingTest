#include <iostream>
#include <vector>
using namespace std;

int one[41], zero[41];

int main()
{
    int testcase = 0;
    cin>> testcase;

    int n = 40;
    zero[0] = 1;
    one[0] = 0;
    zero[1] = 0;
    one[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        zero[i] = zero[i - 1] + zero[i-2];
        one[i] = one[i - 1] + one[i-2];        
    }

    // 초기값
    // zero[2] = 1;
    // one[2] = 1;


    // 호출된 횟수를 DP로 저장
    // zero[3] = 1;
    // one[3] = 2;

    // fibo[4] = (fibo[2] + fibo[1]) + (fibo[1] + fibo[0])
    // zero[4] = 1;
    // one[4] = 2;

    // fibo[5] = fibo[4] + fibo[3]
    //         = (fibo[3] + fibo[2]) + (fibo[2] + fibo[1])
    //         = (fibo[2] + fibo[1]) + (fibo[1] + fibo[0]) + (fibo[1] + fibo[0]) + fibo[1]
    // zero[5] = 2 = zero[4] + zero[3]
    // one[5] = 4 = one[4] + one[3]


    while (testcase--)
    {
        cin >> n;        
        cout << zero[n] << " " << one[n] << '\n';
    }
    


    return 0;
}