---
title: "[0064] Minimum Path Sum"
tags:
  - leetcode
categories:
  - leetcode
author: 张学志
comments: true
updated: false
permalink:
mathjax: false
top: false
description: ...
date: 2020-01-01 00:01:04
---

## 题目描述

> 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
> 
> 说明：每次只能向下或者向右移动一步。 
> 
> 示例: 
> 
> 输入:
> [
>   [1,3,1],
> [1,5,1],
> [4,2,1]
> ]
> 输出: 7
> 解释: 因为路径 1→3→1→1→1 的总和最小。
> 
> Related Topics 数组 动态规划

## 题目代码

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
    }
};
```

## 解析

### 方法一

这道题给了我们一个只有非负数的二维数组，让找一条从左上到右下的路径，使得路径和最小，限定了每次只能向下或者向右移动。一个常见的错误解法就是每次走右边或下边数字中较小的那个，这样的贪婪算法获得的局部最优解不一定是全局最优解，因此是不行的。实际上这道题跟之前那道 Dungeon Game 没有什么太大的区别，都需要用动态规划 Dynamic Programming 来做，这应该算是 DP 问题中比较简单的一类，我们维护一个二维的 dp 数组，其中 dp[i][j] 表示到达当前位置的最小路径和。接下来找状态转移方程，因为到达当前位置 (i, j)  只有两种情况，要么从上方 (i-1, j) 过来，要么从左边 (i, j-1) 过来，我们选择 dp 值较小的那个路径，即比较 dp[i-1][j] 和 dp[i][j-1]，将其中的较小值加上当前的数字 grid[i][j]，就是当前位置的 dp 值了。但是有些特殊情况要提前赋值，比如起点位置，直接赋值为 grid[0][0]，还有就是第一行和第一列，其中第一行的位置只能从左边过来，第一列的位置从能从上面过来，所以这两行要提前初始化好，然后再从 (1, 1) 的位置开始更新到右下角即可，反正难度不算大，代码如下：



```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int j = 1; j < n; ++j) dp[0][j] = grid[0][j] + dp[0][j - 1];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

### 方法二

我们可以优化空间复杂度，可以使用一个一维的 dp 数组就可以了，初始化为整型最大值，但是 dp[0][0] 要初始化为0。之所以可以用一维数组代替之前的二维数组，是因为当前的 dp 值只跟左边和上面的 dp 值有关。这里我们并不提前更新第一行或是第一列，而是在遍历的时候判断，若j等于0时，说明是第一列，我们直接加上当前的数字，否则就要比较是左边的 dp[j-1] 小还是上面的 dp[j]  小，当是第一行的时候，dp[j] 是整型最大值，所以肯定会取到 dp[j-1] 的值，然后再加上当前位置的数字即可，参见代码如下：


```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) dp[j] += grid[i][j];
                else dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        return dp[n - 1];
    }
};
```

### 方法三

我们还可以进一步的优化空间，连一维数组都不用新建，而是直接使用原数组 grid 进行累加，这里的累加方式跟解法一稍有不同，没有提前对第一行和第一列进行赋值，而是放在一起判断了，当i和j同时为0时，直接跳过。否则当i等于0时，只加上左边的值，当j等于0时，只加上面的值，否则就比较左边和上面的值，加上较小的那个即可，参见代码如下：


```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) grid[0][j] += grid[0][j - 1];
                else if (j == 0) grid[i][0] += grid[i - 1][0];
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid.back().back();
    }
};
```


### 方法四

下面这种写法跟上面的基本相同，只不过用了 up 和 left 两个变量来计算上面和左边的值，看起来稍稍简洁一点，参见代码如下：

```cpp

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i == 0 && j == 0) continue;
                int up = (i == 0) ? INT_MAX : grid[i - 1][j];
                int left = (j == 0) ? INT_MAX : grid[i][j - 1];
                grid[i][j] += min(up, left);
            }
        }
        return grid.back().back();
    }
};
```
Github 同步地址：

https://github.com/grandyang/leetcode/issues/64

 

类似题目：

Unique Paths

Dungeon Game

Cherry Pickup