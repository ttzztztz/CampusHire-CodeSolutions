#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> ips[35];

pair<uint32_t, uint32_t> parseip(const string& ip) {
    uint32_t answer = 0, seg = 31;
    uint32_t cur_ips[4] = {0};
    string tmp;
    int ids = 0, have_seg = 0;

    for (int i = 0; i < ip.size(); i++) {
        if (ip[i] >= '0' && ip[i] <= '9') {
            tmp += ip[i];
        } else if (ip[i] == '.') {
            cur_ips[ids++] = stoi(tmp);
            tmp.clear();
        } else if (ip[i] == '/') {
            cur_ips[ids++] = stoi(tmp);
            tmp.clear();
            have_seg = true;
        }
    }

    if (!tmp.empty()) {
        if (have_seg) {
            seg = stoi(tmp);
        } else {
            cur_ips[ids] = stoi(tmp);
        }
    }

    answer |= cur_ips[3];
    answer |= cur_ips[2] << 8u;
    answer |= cur_ips[1] << 16u;
    answer |= cur_ips[0] << 24u;

    return {answer, seg};
}

uint32_t make_mask(int seg) {
    uint32_t answer = 0;
    for (int i = 31, j = 0; i >= 0 && j < seg; i--, j++) {
        answer |= 1u << i;
    }
    return answer;
}

int query(const string& _ip) {
    uint32_t ip, seg;
    tie(ip, seg) = parseip(_ip);

    for (int i = 31; i >= 0; i--) {
        const uint32_t mask = make_mask(i + 1);
        if (ips[i].count(ip & mask)) {
            return ips[i][ip & mask];
        }
    }

    return -1;
}

void inc(const string& _ip, int id) {
    uint32_t ip, seg, mask;
    tie(ip, seg) = parseip(_ip);

    mask = make_mask(seg);
    ip &= mask;
    ips[seg - 1][ip] = id;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int id;
        string _ip;
        cin >> id >> _ip;
        inc(_ip, id);
    }

    for (int i = 0; i < m; i++) {
        string _ip;
        cin >> _ip;
        cout << query(_ip) << endl;
    }
    return 0;
}