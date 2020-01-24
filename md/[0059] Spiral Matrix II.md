---
title: "[0059] Spiral Matrix II"
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
date: 2020-01-01 00:00:59
---

## 题目描述

> 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。 
> 
> 示例: 
> 
> 输入: 3
> 输出:
> [
> [ 1, 2, 3 ],
> [ 8, 9, 4 ],
> [ 7, 6, 5 ]
> ] 
> Related Topics 数组

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
    }
};
```

## 解析

### 方法一

此题跟之前那道 Spiral Matrix 本质上没什么区别，就相当于个类似逆运算的过程，这道题是要按螺旋的顺序来填数，由于给定矩形是个正方形，我们计算环数时用 n / 2 来计算，若n为奇数时，此时最中间的那个点没有被算在环数里，所以最后需要单独赋值，还是下标转换问题是难点，参考之前 Spiral Matrix 的讲解来转换下标吧，参见代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int val = 1, p = n;
        for (int i = 0; i < n / 2; ++i, p -= 2) {
            for (int col = i; col < i + p; ++col)
                res[i][col] = val++;
            for (int row = i + 1; row < i + p; ++row)
                res[row][i + p - 1] = val++;
            for (int col = i + p - 2; col >= i; --col)
                res[i + p - 1][col] = val++;
            for (int row = i + p - 2; row > i; --row)    
                res[row][i] = val++;
        }
        if (n % 2 != 0) res[n / 2][n / 2] = val;
        return res;
    }
};
```

### 方法二

当然我们也可以使用下面这种简化了坐标转换的方法，博主个人还是比较推崇下面这种解法，不容易出错，而且好理解，参见代码如下：

 

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;
        while (true) {
            for (int j = left; j <= right; ++j) res[up][j] = val++;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res[i][right] = val++;
            if (--right < left) break;
            for (int j = right; j >= left; --j) res[down][j] = val++;
            if (--down < up) break;
            for (int i = down; i >= up; --i) res[i][left] = val++;
            if (++left > right) break;
        }
        return res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/59

 

类似题目：

Spiral Matrix

