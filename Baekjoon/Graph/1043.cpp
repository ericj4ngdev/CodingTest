#include<bits/stdc++.h>
using namespace std;

int n, m;
int knowTruthNum;
// vector<int> knowTruth;
set<int> knowTruth;
vector<vector<int>> party;

bool HasNum(int index)
{
    for(int it : knowTruth)
    {
        if(it == index)
            return true;
    }
    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // n : 사람 수
    // m : 파티 수
    cin >> n >> m;
    // 진실을 아는 사람 수
    cin >> knowTruthNum;
    for(int i = 0; i < knowTruthNum; i++)
    {
        int temp;
        cin >> temp;
        cout << "temp : " << temp << '\n';

        // 진실을 아는 사람 번호 저장
        knowTruth.insert(temp);
    }

    int count = 0;
    for(int i = 0; i < m; i++)
    {
        bool flag = false;
        // 각 파티마다 오는 사람 수
        int partyCome;
        cin >> partyCome;

        for(int j = 0; j < partyCome; j++)        
        {
            // 각 파티마다 오는 사람 번호 저장
            int num;
            cin >> num;
            cout << "num : " << num << '\n';
            party[i].push_back(num);
            // 진실 아는 사람 있는가?
            if(HasNum(num))
            {
                flag = true;
            }
        }

        if(flag)
        {
            // 지금 들어오는 num들은 모두 knowTruth에 추가
            for(int it : party[i])
            {
                knowTruth.insert(it);
            }
        }
    }

    // 진실을 아는 사람이 적은 파티
    // 겹치지 않게 
    // 파티에 가면 해당 파티에 있는 사람들중 진실을 아는 사람이 있으면 진실
    // 모두 모르면 과장 -> 그냥 패스, count++

    // knowTruthNum = 0이면 진실을 아는 사람이 없으므로 무조건 과장해도 됨. 따라서 파티 개수가 답    
    // knowTruthNum >= 1이면 진실을 아는 사람이 있는 파티에 있는 사람들은 모두 진실을 알게 됨. 
    // 따라서 겹치지 않는 파티에만 과장 가능

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; i < m; i++)
        {
            for(int k : party[j])
            {
                if(HasNum(k)) 
                {
                    break;
                }
                else
                {
                    count++;
                    break;
                }
            }
        }
    
    }
    cout << count;



    return 0;
}