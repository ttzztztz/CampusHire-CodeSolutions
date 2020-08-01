#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;
string input;

bool validNumber(const string& str, int i, int j) {
    for (int k = i; k <= j; k++) {
        if (!(str[k] >= '0' && str[k] <= '9')) return false;
    }
    return true;
}

bool validDate(int y, int m, int d) {
    const bool isRunnian = (y == 2004 || y == 2008 || y == 2012 || y == 2016 || y == 2020);
    int months[] = {0, 31, isRunnian?29:28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return d >= 1 && d <= months[m];
}

int main() {
    cin >> input;
    unordered_map<string, int> validmap;
    for (int l = 0, r = 9; r < input.size(); l++, r++) {
        string cur = input.substr(l, 10);

        if (cur[2] == cur[5] && cur[2] == '-' &&
        validNumber(cur, 0, 1) && validNumber(cur, 3, 4) && validNumber(cur, 6, 9)) {
            int d = stoi(cur.substr(0, 2));
            int m = stoi(cur.substr(3, 2));
            int y = stoi(cur.substr(6, 4));

            if (y < 2001 || y > 2020) continue;
            if (m <= 0 || m >= 13) continue;
            if (!validDate(y, m, d)) continue;

            validmap[cur]++;
        }
    }

    string answer;
    int mx = 0;
    for (auto& p : validmap) {
        if (p.second > mx) {
            mx = p.second;
            answer = p.first;
        }
    }

    cout << answer << endl;
    return 0;
}