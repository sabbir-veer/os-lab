#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << "Enter number of Process : ";
    int n, i, j, k;
    cin >> n;
    int arrival[n + 5], burst[n + 5], leftExecution[n + 5], rightExecution[n + 5], vis[n + 5] = {0};
    for (i = 1; i <= n; i++) {
        cin >> arrival[i] >> burst[i];
    }
    int cur = 0;
    while (1) {
        int mn = 1000, val = 1000, p = -1, p1 = -1;
        for (i = 1; i <= n; i++) {
            if (!vis[i] && arrival[i] <= cur) {
                if (arrival[i] < mn) {
                    mn = arrival[i];
                    p = i;
                }
            } else if (!vis[i]) {
                if (arrival[i] < val) {
                    val = arrival[i];
                    p1 = i;
                }
            }
        }
        if (p != -1) {
            vis[p] = 1;
            leftExecution[p] = cur;
            cur += burst[p];
            rightExecution[p] = cur;
        } else if (p1 != -1) {
            vis[p1] = 1;
            cur = arrival[p1];
            leftExecution[p1] = cur;
            cur += burst[p1];
            rightExecution[p1] = cur;
        } else {
            break;
        }
    }
    for (i = 1; i <= n; i++) {
        cout << "Execution time of process : " << i << "> " << leftExecution[i] << " to " << rightExecution[i] << endl;
    }
}
