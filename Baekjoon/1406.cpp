#include<bits/stdc++.h>
using namespace std;

string input;
int location;
struct Command
{
    char cmd;
    char c;
};

void execute(Command command)
{
    if(command.cmd == 'L')
    {
        if(location == 0) return;
        location--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m = 0;
    cin >> input;
    cin >> m;
    location = input.size();
    cout << location;

    Command command;
    for(int i = 0; i < m; i++)
    {
        cin >> command.cmd;
        if(command.cmd == 'P')
        {
            cin >> command.c;
        }
        execute(command);
    }
    





    return 0;
}