# 字节跳动2018校招后端方向（第二批）

## T1 Medium

直接二分搜索即可

## T2 Easy

直接哈希、遍历即可

## T3 Hard

对于每个字母，使用哈希维护出现的位置，然后`f[i][j]`表示 pos 的 index 为`[i, j]` 合并所需的最小代价

1. len = 1：`f[i][i] = 0`
2. len = 2：`f[i][i + 1] = pos[i + 1] - pos[i] - 1`
3. len >= 3： `f[i][j] = f[i + 1][j - 1] + pos[j] - pos[i] - (j - i)`