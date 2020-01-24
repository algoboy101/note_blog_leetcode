---
title: "[0054] Spiral Matrix"
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
date: 2020-01-01 00:00:54
---

## 题目描述

> 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。 
> 
> 示例 1: 
> 
> 输入:
> [
> [ 1, 2, 3 ],
> [ 4, 5, 6 ],
> [ 7, 8, 9 ]
> ]
> 输出: [1,2,3,6,9,8,7,4,5]
> 
> 
> 示例 2: 
> 
> 输入:
> [
> [1, 2, 3, 4],
> [5, 6, 7, 8],
> [9,10,11,12]
> ]
> 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
> 
> Related Topics 数组

## 题目代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
    }
};
```

## 解析

### 方法一

这道题让我们搓一个螺旋丸，将一个矩阵按照螺旋顺序打印出来，只能一条边一条边的打印，首先要从给定的 mxn 的矩阵中算出按螺旋顺序有几个环，注意最中间的环可以是一个数字，也可以是一行或者一列。环数的计算公式是 min(m, n) / 2，知道了环数，就可以对每个环的边按顺序打印，比如对于题目中给的那个例子，个边生成的顺序是(用颜色标记了数字，Github 上可能无法显示颜色，请参见博客园上的帖子) Red -> Green -> Blue -> Yellow -> Black 

 

1　2　3

4　5　6

7　8　9

 

定义 p，q 为当前环的高度和宽度，当p或者q为1时，表示最后一个环只有一行或者一列，可以跳出循环。此题的难点在于下标的转换，如何正确的转换下标是解此题的关键，可以对照着上面的 3x3 的例子来完成下标的填写，代码如下：

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int c = m > n ? (n + 1) / 2 : (m + 1) / 2;
        int p = m, q = n;
        for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
            for (int col = i; col < i + q; ++col) 
                res.push_back(matrix[i][col]);
            for (int row = i + 1; row < i + p; ++row)
                res.push_back(matrix[row][i + q - 1]);
            if (p == 1 || q == 1) break;
            for (int col = i + q - 2; col >= i; --col)
                res.push_back(matrix[i + p - 1][col]);
            for (int row = i + p - 2; row > i; --row) 
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};
```

### 方法二

如果觉得上面解法中的下标的转换比较难弄的话，也可以使用下面这种坐标稍稍简洁一些的方法。对于这种螺旋遍历的方法，重要的是要确定上下左右四条边的位置，那么初始化的时候，上边 up 就是0，下边 down 就是 m-1，左边 left 是0，右边 right 是 n-1。然后进行 while 循环，先遍历上边，将所有元素加入结果 res，然后上边下移一位，如果此时上边大于下边，说明此时已经遍历完成了，直接 break。同理对于下边，左边，右边，依次进行相对应的操作，这样就会使得坐标很有规律，并且不易出错，参见代码如下：



```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (true) {
            for (int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            if (--right < left) break;
            for (int j = right; j >= left; --j) res.push_back(matrix[down][j]);
            if (--down < up) break;
            for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};
```

### 方法三

若对上面解法中的多个变量还是晕的话，也可以使用类似迷宫遍历的方法，这里只要设定正确的遍历策略，还是可以按螺旋的方式走完整个矩阵的，起点就是（0，0）位置，但是方向数组一定要注意，不能随便写，开始时是要往右走，到了边界或者访问过的位置后，就往下，然后往左，再往上，所以 dirs 数组的顺序是 右->下->左->上，由于原数组中不会有0，所以就可以将访问过的位置标记为0，这样再判断新位置的时候，只要其越界了，或者是遇到0了，就表明此时需要转弯了，到 dirs 数组中去取转向的 offset，得到新位置，注意这里的 dirs 数组中取是按循环数组的方式来操作，加1然后对4取余，按照这种类似迷宫遍历的方法也可以螺旋遍历矩阵，参见代码如下：



```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size(), idx = 0, i = 0, j = 0;
        vector<int> res;
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int k = 0; k < m * n; ++k) {
            res.push_back(matrix[i][j]);
            matrix[i][j] = 0;
            int x = i + dirs[idx][0], y = j + dirs[idx][1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 0) {
                idx = (idx + 1) % 4;
                x = i + dirs[idx][0];
                y = j + dirs[idx][1];
            }
            i = x;
            j = y;
        }
        return res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/54

 

类似题目：

Spiral Matrix II

