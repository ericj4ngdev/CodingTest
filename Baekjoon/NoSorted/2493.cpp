#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
    stack<pair<int,int>> st;
    vector<int> vec;
    int TowerCount;
    cin >> TowerCount;
    for(int i = 1; i <= TowerCount; i++)
    {
        int height;
        cin >> height;
        if(i == 1)
        {
            st.push({i,height});
            vec.push_back(0);
            continue;
        }

        // 본인 인덱스 앞에 있는 타워 ~ Max 타워 사이 부딪히는 타워 찾기
        // 하지만 이것도 비효율적이다.     
        // 스택을 쓰면 검사할 타워 수가 줄어든다. 
        while(true)
        {
            if(st.size())
            {
                if(st.top().second < height)
                {
                    // 직전 타워가 (자기보다) 작다
                    st.pop();
                    // 아직 수신 못찾음. 찾을 때까지 while 반복
                }
                else
                {
                    // 직전 타워가 (자기보다) 크거나 같으면 직전 타워 수신
                    vec.push_back(st.top().first);
                    // 넣긴 넣는다. 왜냐면 다음 타워가 더 작을 수도 있기 때문
                    st.push({i,height});
                    break;
                }
            }
            else
            {
                // 가장 큰 타워라 스택에 없으면
                st.push({i,height});
                vec.push_back(0);
                break;
            }            
        }
    }

    for(int i : vec)
    {
        cout << i << " ";
    }    
    return 0;
}

