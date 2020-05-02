#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
unordered_set<unsigned int> allow[35], deny[35];

pair<unsigned int, unsigned int> convertToIp(const string& str) {
    unsigned int ip = 0, cidr = 32;

    vector<unsigned int> allSeg(4);
    auto split = str.find('/');
    if (split != string::npos) {
        sscanf(str.c_str(), "%d.%d.%d.%d/%d", &allSeg[0], &allSeg[1],
               &allSeg[2], &allSeg[3], &cidr);
    } else {
        sscanf(str.c_str(), "%d.%d.%d.%d", &allSeg[0], &allSeg[1],
               &allSeg[2], &allSeg[3]);
    }

    ip |= (allSeg[0] & (unsigned) 0xffff) << 24u;
    ip |= (allSeg[1] & (unsigned) 0xffff) << 16u;
    ip |= (allSeg[2] & (unsigned) 0xffff) << 8u;
    ip |= allSeg[3] & (unsigned) 0xffff;

    return {ip, cidr};
}

unsigned int cidrToMask(unsigned int cidr) {
    unsigned int answer = 0;
    for (int i = 0; i < cidr; i++) {
        const unsigned int front = 31 - i;
        answer |= 1u << front;
    }
    return answer;
}

int main() {
    cin >> N >> M;
    for (int _ = 0; _ < N; _++) {
        string access, ip;
        cin >> access >> ip;

        auto converted = convertToIp(ip);
        const auto data = converted.first & cidrToMask(converted.second);
        if (access == "allow") {
            if (!deny[converted.second].count(data)) {
                allow[converted.second].insert(data);
            }
        } else {
            if (!allow[converted.second].count(data)) {
                deny[converted.second].insert(data);
            }
        }
    }

    for (int _ = 0; _ < M; _++) {
        string ip;
        cin >> ip;

        auto converted = convertToIp(ip);

        unsigned int mask = numeric_limits<unsigned int>::max();
        bool find = false;
        for (unsigned int i = 0; i <= 32; i++) {
            if (i != 0) {
                mask ^= 1u << (i - 1);
            }

            if (allow[32 - i].count(converted.first & mask)) {
                cout << "YES" << endl;
                find = true;
                break;
            } else if (deny[32 - i].count(converted.first & mask)) {
                cout << "NO" << endl;
                find = true;
                break;
            }
        }
        if (!find) cout << "YES" << endl;
    }
    return 0;
}