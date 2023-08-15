#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Enter number of Process : ";
    int n, i, j, k;
    cin >> n;
    int arrival[n + 5], burst[n + 5], l[n + 5], r[n + 5], vis[n + 5] = {0}, priority[n + 5];
    for (i = 1; i <= n; i++) {
        cin >> priority[i] >> arrival[i] >> burst[i];
    }
    int cur = 0;
    while (1) {
        int mn = 1000, val = 1000, p = -1, p1 = -1;
        map<int, int> mp;
        for (i = 1; i <= n; i++) {
            if (!vis[i] && arrival[i] <= cur) {
                if (priority[i] < mn) {
                    mn = priority[i];
                    p = i;
                    mp[mn]++;
                }
            }
        }
        if (mp[mn] >= 2) {
            for (i = 1; i <= n; i++) {
                if (!vis[i] && arrival[i] <= cur && priority[i] == mn) {
                    if (burst[i] < val) {
                        val = burst[i];
                        p = i;
                    }
                }
            }
        }
        if (p != -1) {
            vis[p] = 1;
            l[p] = cur;
            cur += burst[p];
            r[p] = cur;
        } else if (p1 != -1) {
            vis[p1] = 1;
            cur = arrival[p1];
            l[p1] = cur;
            cur += burst[p1];
            r[p1] = cur;
        } else {
            break;
        }
    }
    for (i = 1; i <= n; i++) {
        cout << "Execution time of process : " << i << " " << l[i] << " to " << r[i] << endl;
    }
}
