#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int>& arr, int l1, int r1, int l2, int r2) {
    vector<int> t;
    for (int i = l2; i <= r2; i++) t.push_back(arr[i]);
    for (int i = l1; i <= r1; i++) t.push_back(arr[i]);

    for (int i = 1; i < t.size(); i++) {
        if (t[i - 1] < t[i]) return false;
    }
    return true;
}

int main() {
    freopen("./case.txt", "r", stdin);

    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;
        vector<int> data(n);
        for (int i = 0; i < n; i++) cin >> data[i];

        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (check(data, 0, i, i + 1, n - 1)) {
                ok = true;
                break;
            }
        }

        if (ok) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}