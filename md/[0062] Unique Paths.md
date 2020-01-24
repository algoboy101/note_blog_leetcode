---
title: "[0062] Unique Paths"
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
date: 2020-01-01 00:01:02
---

## 题目描述

> 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。 
> 
> 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。 
> 
> 问总共有多少条不同的路径？ 
> 
> 
> 
> 例如，上图是一个7 x 3 的网格。有多少可能的路径？ 
> 
> 说明：m 和 n 的值均不超过 100。 
> 
> 示例 1: 
> 
> 输入: m = 3, n = 2
> 输出: 3
> 解释:
> 从左上角开始，总共有 3 条路径可以到达右下角。
> 1. 向右 -> 向右 -> 向下
> 2. 向右 -> 向下 -> 向右
> 3. 向下 -> 向右 -> 向右
> 
> 
> 示例 2: 
> 
> 输入: m = 7, n = 3
> 输出: 28 
> Related Topics 数组 动态规划

## 题目代码

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        
    }
};
```

## 解析

### 方法一

这道题让求所有不同的路径的个数，一开始还真把博主难住了，因为之前好像没有遇到过这类的问题，所以感觉好像有种无从下手的感觉。在网上找攻略之后才恍然大悟，原来这跟之前那道 Climbing Stairs 很类似，那道题是说可以每次能爬一格或两格，问到达顶部的所有不同爬法的个数。而这道题是每次可以向下走或者向右走，求到达最右下角的所有不同走法的个数。那么跟爬梯子问题一样，需要用动态规划 Dynamic Programming 来解，可以维护一个二维数组 dp，其中 dp[i][j] 表示到当前位置不同的走法的个数，然后可以得到状态转移方程为:  dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，这里为了节省空间，使用一维数组 dp，一行一行的刷新也可以，代码如下：


```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }
        }
        return dp[n - 1];
    }
};
```

### 方法二

这道题其实还有另一种很数学的解法，参见网友 Code Ganker 的博客，实际相当于机器人总共走了 m + n - 2步，其中 m - 1 步向右走，n - 1 步向下走，那么总共不同的方法个数就相当于在步数里面 m - 1 和 n - 1 中较小的那个数的取法，实际上是一道组合数的问题，写出代码如下:


```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        double num = 1, denom = 1;
        int small = m > n ? n : m;
        for (int i = 1; i <= small - 1; ++i) {
            num *= m + n - 1 - i;
            denom *= i;
        }
        return (int)(num / denom);
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/62

 

类似题目：

Unique Paths II

Minimum Path Sum
