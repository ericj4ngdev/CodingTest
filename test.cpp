#include<bits/stdc++.h>
using namespace std;

int num_jewels, weight, value, num_bags, capacity;
vector<pair<int,int>> v_jewels;
vector<int> v_capacity;

int main()
{
    cin >> num_jewels >> num_bags;
    for(int i = 0; i < num_jewels; i++)
    {
        cin >> weight >> value;
        v_jewels.push_back({value, weight});
    }

    for(int i = 0; i < num_bags; i++)
    {
        cin >> capacity;
        v_capacity.push_back(capacity);
    }

    sort(v_jewels.begin(), v_jewels.end());
    sort(v_capacity.begin(), v_capacity.end());

    for(int i = 0; i < num_jewels; i++)
    {
        cout << v_jewels[i].first << " " << v_jewels[i].second << "\n";
    }

    for(int i = 0; i < num_bags; i++)
    {
        cout << v_capacity[i] << " ";
    }

    return 0;
}

