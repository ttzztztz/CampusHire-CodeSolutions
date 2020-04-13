#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
vector<int> finalState;
 
bool dfs(vector<int>& all) {
    if (all == finalState) {
        return true;
    }
    bool flag = false;
 
    for (int i = 1; i <= 9; i++) {
        if (all[i] >= 3) {
            all[i] -= 3;
            if (dfs(all)) flag = true;
            all[i] += 3;
        }
    }
 
    for (int left = 1, right = 3; right <= 9; left++, right++) {
        if (all[left] >= 1 && all[left + 1] >= 1 && all[left + 2] >= 1) {
            all[left]--;
            all[left + 1]--;
            all[left + 2]--;
            if (dfs(all)) flag = true;
            all[left]++;
            all[left + 1]++;
            all[left + 2]++;
        }
    }
 
    return flag;
}
 
int main() {
    vector<int> all(10, 0);
    finalState = vector<int>(10, 0);
 
    for (int i = 0; i < 13; i++) {
        int tmp;
        cin >> tmp;
        all[tmp]++;
    }
 
    bool have = false;
    for (int i = 1; i <= 9; i++) {
        if (all[i] >= 4) continue;
        all[i] += 1;
        bool current = false;
 
        for (int j = 1; j <= 9; j++) {
            if (all[j] >= 2) {
                all[j] -= 2;
                if (dfs(all)) {
                    have = true;
                    current = true;
                }
                all[j] += 2;
            }
        }
 
        if (current) cout << i << " ";
        all[i] -= 1;
    }
 
    if (!have) cout << 0;
    cout << endl;
    return 0;
}