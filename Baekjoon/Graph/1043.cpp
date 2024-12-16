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

    // n : ��� ��
    // m : ��Ƽ ��
    cin >> n >> m;
    // ������ �ƴ� ��� ��
    cin >> knowTruthNum;
    for(int i = 0; i < knowTruthNum; i++)
    {
        int temp;
        cin >> temp;
        cout << "temp : " << temp << '\n';

        // ������ �ƴ� ��� ��ȣ ����
        knowTruth.insert(temp);
    }

    int count = 0;
    for(int i = 0; i < m; i++)
    {
        bool flag = false;
        // �� ��Ƽ���� ���� ��� ��
        int partyCome;
        cin >> partyCome;

        for(int j = 0; j < partyCome; j++)        
        {
            // �� ��Ƽ���� ���� ��� ��ȣ ����
            int num;
            cin >> num;
            cout << "num : " << num << '\n';
            party[i].push_back(num);
            // ���� �ƴ� ��� �ִ°�?
            if(HasNum(num))
            {
                flag = true;
            }
        }

        if(flag)
        {
            // ���� ������ num���� ��� knowTruth�� �߰�
            for(int it : party[i])
            {
                knowTruth.insert(it);
            }
        }
    }

    // ������ �ƴ� ����� ���� ��Ƽ
    // ��ġ�� �ʰ� 
    // ��Ƽ�� ���� �ش� ��Ƽ�� �ִ� ������� ������ �ƴ� ����� ������ ����
    // ��� �𸣸� ���� -> �׳� �н�, count++

    // knowTruthNum = 0�̸� ������ �ƴ� ����� �����Ƿ� ������ �����ص� ��. ���� ��Ƽ ������ ��    
    // knowTruthNum >= 1�̸� ������ �ƴ� ����� �ִ� ��Ƽ�� �ִ� ������� ��� ������ �˰� ��. 
    // ���� ��ġ�� �ʴ� ��Ƽ���� ���� ����

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