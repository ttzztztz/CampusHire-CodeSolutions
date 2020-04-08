class Solution {
public:
    /**
     * 实现方案
     * @param m int整型 最少m个键
     * @param n int整型 最多n个键
     * @return int整型
     */
    int m, n;
    vector<vector<bool>> visited;
    int solution(int m, int n) {
        this->m = m, this->n = n;
        visited = vector<vector<bool>>(3, vector<bool>(3, false));
         
        int answer = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                visited[i][j] = true;
                answer += dfs(i, j, 1);
                visited[i][j] = false;
            }
        }
        return answer;
    }
private:
    bool pointValid(int i, int j) {
        return i >= 0 && j >= 0 && i < 3 && j < 3;
    }
    int dfs(int i, int j, int k) {
        if (k > n) return 0;
        int answer = 0;
        if (k >= m && k <= n) answer ++;
         
         
        for (int nx = 0; nx < 3; nx++) {
            for (int ny = 0; ny < 3; ny++) {
                if (nx == i && ny == j) continue;
                if (visited[nx][ny]) continue;
                 
                if (nx == i && ny == j + 2 && !visited[nx][j + 1]) continue;
                if (nx == i && ny == j - 2 && !visited[nx][j - 1]) continue;
                if (nx == i + 2 && ny == j && !visited[i + 1][j]) continue;
                if (nx == i - 2 && ny == j && !visited[i - 1][j]) continue;
                if (nx == i + 2 && ny == j + 2 && !visited[i + 1][j + 1]) continue;
                if (nx == i - 2 && ny == j - 2 && !visited[i - 1][j - 1]) continue;
                if (nx == i + 2 && ny == j - 2 && !visited[i + 1][j - 1]) continue;
                if (nx == i - 2 && ny == j + 2 && !visited[i - 1][j + 1]) continue;
                 
                visited[nx][ny] = true;
                answer += dfs(nx, ny, k + 1);
                visited[nx][ny] = false;
            }
        }
        return answer;
    }
};