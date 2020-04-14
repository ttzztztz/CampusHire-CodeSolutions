#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int N, M, answer = 0;
vector<vector<char>> map;
 
bool pointValid(int i, int j) {
    return i >= 0 && j >= 0 && i < N && j < M;
}
 
void change_a(int i, int j) {
    answer++;
    int x = i, y = j;
 
    while (pointValid(x, y) && (map[x][y] == 'B' || map[x][y] == 'G')) {
        if (map[x][y] == 'B') map[x][y] = 'X';
        else map[x][y] = 'Y';
 
        x--, y++;
    }
 
    x = i + 1, y = j - 1;
    while (pointValid(x, y) && (map[x][y] == 'B' || map[x][y] == 'G')) {
        if (map[x][y] == 'B') map[x][y] = 'X';
        else map[x][y] = 'Y';
 
        x++, y--;
    }
}
 
void change_b(int i, int j) {
    answer++;
    int x = i, y = j;
 
    while (pointValid(x, y) && (map[x][y] == 'Y' || map[x][y] == 'G')) {
        if (map[x][y] == 'Y') map[x][y] = 'X';
        else map[x][y] = 'B';
 
        x--, y--;
    }
 
    x = i + 1, y = j + 1;
    while (pointValid(x, y) && (map[x][y] == 'Y' || map[x][y] == 'G')) {
        if (map[x][y] == 'Y') map[x][y] = 'X';
        else map[x][y] = 'B';
 
        x++, y++;
    }
}
 
int main() {
    cin >> N >> M;
    map = vector<vector<char>>(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'X') continue;
            else if (map[i][j] == 'B') change_a(i, j);
            else if (map[i][j] == 'Y') change_b(i, j);
            else {
                change_a(i, j);
                change_b(i, j);
            }
        }
    }
 
    cout << answer << endl;
    return 0;
}