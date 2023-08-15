#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Enter number of Processes: ";
    int n, i, j, k;
    cin >> n;

    int arrival[n + 5], burst[n + 5], l[n + 5], r[n + 5], vis[n + 5] = {0};
    for (i = 1; i <= n; i++) {
        cin >> arrival[i] >> burst[i];
    }

    int cur = 0;
    while (1) {
        int mn = 1000, val = 1000, p = -1, p1 = -1;
        map<int, int> mp;

        // Find the process with the minimum burst time
        for (i = 1; i <= n; i++) {
            if (!vis[i] && arrival[i] <= cur) {
                if (burst[i] < mn) {
                    mn = burst[i];
                    p = i;
                    mp[mn]++;
                }
            }
        }

        // Handle multiple processes with the same burst time
        if (mp[mn] >= 2) {
            for (i = 1; i <= n; i++) {
                if (!vis[i] && arrival[i] <= cur && burst[i] == mn) {
                    if (arrival[i] < val) {
                        val = arrival[i];
                        p1 = i;
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
            cur = max(cur, arrival[p1]);
            l[p1] = cur;
            cur += burst[p1];
            r[p1] = cur;
        } else {
            break;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << "Execution time of process " << i << ": " << l[i] << " to " << r[i] << endl;
    }

    return 0;
}
