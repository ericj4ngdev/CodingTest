#include<bits/stdc++.h>
using namespace std;

void printList(list<int>& l)
{
    for(int it : l)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    int k = 0;
    cin >> n >> k;

    list<int> L;
    for(int i = 1; i <= n; i++)
    {
        L.push_back(i);
    }
    printList(L);

    auto it = L.begin();
    while(L.size())
    {
        for(int i = 0; i < k - 1; i++)
        {
            cout << "before cur : " << *it << '\n';
            if(*it == L.back()) 
            {
                it = L.begin();
                cout << "after cur : " << *it << '\n';                
                continue;
            }
            it++;
            cout << "after cur : " << *it << '\n';
        }
        cout << "erase : " << *it << '\n';
        it = L.erase(it);
        cout << "cur after erase : " << *it << '\n';
        
        // it++;
        printList(L);
    }

    return 0;
}
