#include<bits/stdc++.h>
using namespace std;

string func, inputArr;
int n;
bool flag = false;

void Reverse(deque<int>& dq)
{
    reverse(dq.begin(), dq.end());
}

void PopFront(deque<int>& dq)
{    
    // RR false
    // true
    if (!flag)
    {
        dq.pop_front();
    }
    else
    {
        dq.pop_back();
    }
}

void printDQ(deque<int>& dq)
{
    cout << '[';
    for (int i = 0; i < dq.size(); i++)
    {
        if (i == dq.size() - 1)
        {
            cout << dq[i];
        }
        else
        {
            cout << dq[i] << ',';
        }
    }
    cout << ']' << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testcase = 0;
    cin >> testcase;
    while (testcase--)
    {
        
        deque<int> dq;
        cin >> func;    
        cin >> n;
        cin >> inputArr;
        string str;
        for (char c : inputArr)
        {
            if (c == '[') continue;
            if (c == ']')
            {
                if (str == "")
                {
                    break;
                }
                else
                {
                    dq.push_back(stoi(str));
                }
                break;
            }
            if (c == ',')
            {
                // 다음에 쉼표가 나올 때 추가
                dq.push_back(stoi(str));
                str = "";
                continue;
            }
            if (c >= '0' && c <= '9')
            {
                str += c;
            }
        }

        bool flag2 = false;

        flag = false;

        for (char c : func)
        {            
            if (c == 'R')
            {
                flag = !flag;
            }
            else if (c == 'D')
            {
                if (dq.size() == 0)
                {
                    flag2 = true;
                    cout << "error" << '\n';
                    break;
                }
                PopFront(dq);
            }
        }
        if (flag) Reverse(dq);
        if(!flag2) printDQ(dq);
    }
    return 0;
}