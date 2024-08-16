#include <bits/stdc++.h> 
int n, a[1004], cnt[1004], ret = 1, idx;
int prev_list[1004];
using namespace std;  


void go(int idx) {
    if (idx == -1) return;
    go(prev_list[idx]);
    printf("%d ", a[idx]);
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }

    fill(prev_list, prev_list + 1004, -1);
    fill(cnt, cnt + 1004, 1);

    for (int k = 0; k < n; k++) {
        // k보다 왼쪽에 있는 arr값 순회
        for (int i = 0; i < k; i++) {
            // 자기보다 작으면
            if (a[i] < a[k]) {
                // cnt값 갱신(이전 lis + 1)
                if (cnt[k] < cnt[i] + 1) {
                    cnt[k] = cnt[i] + 1;
                    prev_list[k] = i; 
                }
            }
        }
        if (ret < cnt[k]) {
            ret = cnt[k];
            idx = k;
        }
    }

    cout << ret << '\n';
    go(idx);

    return 0;
}