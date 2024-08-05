#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int alpha[26] = { 0 };
    string name;
    vector<char> pel;
    int cnt = 0;

    cin >> name;

    for (char c : name)
    {
        alpha[c - 65]++;
    }

    // 홀수인 알파벳 개수 
    for (int i = 0; i < 26; i++)
    {
        // cout << alpha[i] << " ";
        if (alpha[i] % 2 == 1)
        {
            cnt++;
        }
    }
    // cout << "\n";

    // 팰린들롬 가능성 테스트
    if (cnt > 1)
    {
        cout << "I'm Sorry Hansoo" << "\n";
        return 0;
    }

    // 팰린들롬 만들기
    char temp = 'a';
    int size = 0;

    for (int j = 0; j < 26; j++)
    {
        // 홀수 개인데 2개 이상이면 알파벳순으로 추가
        // 홀짝 상관없이 알파벳 순으로 추가
        // 개수가 0이 될때까지 추가
        while (alpha[j] > 1)
        {
            pel.push_back((char)(j + 65));
            alpha[j] -= 2;
            size = pel.size();
        }
        if (alpha[j] == 1)
        {
            temp = (char)(j + 65);
        }
    }
    // 1개짜리가 있다면 추가
    if (temp != 'a') pel.push_back(temp);
    for (int i = size - 1; i >= 0; i--)
    {
        pel.push_back(pel[i]);
    }

    for (char c : pel)
    {
        cout << c;
    }

    return 0;
}