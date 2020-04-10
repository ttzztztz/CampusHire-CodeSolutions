#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    long long hp, normal, buffer;
    cin >> hp >> normal >> buffer;
 
    if (buffer <= 2 * normal) {
        long long cnt = hp / normal;
        if (hp % normal) cnt++;
        cout << cnt << endl;
    } else {
        long long cnt = hp / buffer;
        cnt *= 2;
        if (hp % buffer) {
            long long rest = hp - ((cnt / 2) * buffer);
            if (rest <= normal) cnt++;
            else cnt += 2;
        }
        cout << cnt << endl;
    }
 
    return 0;
}