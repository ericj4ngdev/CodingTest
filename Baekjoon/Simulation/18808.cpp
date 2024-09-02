#include<bits/stdc++.h>
using namespace std;

int width, height;
int stickerCnt;
int row, col, ret;
int sticker[12][12];
int notebook[44][44];

void InputSticker()
{
    memset(sticker, 0, sizeof(sticker));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> sticker[i][j];
        }
    }
}

void RotateSticker()
{
    int tmp[12][12];
    memcpy(tmp, sticker, sizeof(sticker));
    memset(sticker, 0, sizeof(sticker));
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            sticker[i][j] = tmp[row - 1 - j][i];
        }
    }
    swap(row, col);
}

// 왼쪽 위 지점 
void Attach(int h, int w)
{
    // 스티커 부착
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {            
            if (sticker[i][j] == 1 && notebook[h + i][w + j] == 0)
            {
                notebook[h+i][w+j] = sticker[i][j];
            }
        }
    }
}

bool CanAttach(int h, int w)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // 하나라도 겹치면 실패
            if (sticker[i][j] == 1 && notebook[h + i][w + j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

void CheckSize()
{
    // 1. 왼쪽 위 모서리를 왼쪽 위 -> 오른쪽 위-> 왼쪽 아래 -> 오른쪽 아래
    // 2. cw 90도 회전 후 1번 진행
    // 3. cw 180도 회전 후 1번 진행
    // 4. cw 270도 회전 후 1번 진행
    // 5. 없으면 다음 타일

    // 회전
    for (int k = 0; k <= 3; k++)
    {
        // 이동
        // 왼쪽 위 지점 (j,i)    
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // i <= height - row
                // i + row <= height
                // 스티커가 노트북 밖으로 나가면 다음 위치
                if (j + col > width || i + row > height) continue;

                // 붙히려는 곳에 1이 있다면 다음 위치
                if (CanAttach(i, j) == false) continue;

                Attach(i, j);
                return;
            }
        }
        RotateSticker();
    }
}

void PrintNote()
{
    cout << "NoteBook \n";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << notebook[i][j] << " ";
        }
        cout << '\n';
    }
}

void PrintCount()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (notebook[i][j] == 1)
            {
                ret++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> height >> width >> stickerCnt;
    for (int i = 0; i < stickerCnt; i++)
    {
        cin >> row >> col;
        InputSticker();
        // 붙힐 수 있는지 판단
        CheckSize();
        // PrintNote();
    }

    PrintCount();
    cout << ret;

    return 0;
}