---
title: "[0085] Maximal Rectangle"
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
date: 2020-01-01 00:01:25
---

## 题目描述

> 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。 
> 
> 示例: 
> 
> 输入:
> [
> ["1","0","1","0","0"],
> ["1","0","1","1","1"],
> ["1","1","1","1","1"],
> ["1","0","0","1","0"]
> ]
> 输出: 6 
> Related Topics 栈 数组 哈希表 动态规划

## 题目代码

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
    }
};
```

## 解析

### 方法一

此题是之前那道的 Largest Rectangle in Histogram 的扩展，这道题的二维矩阵每一层向上都可以看做一个直方图，输入矩阵有多少行，就可以形成多少个直方图，对每个直方图都调用 Largest Rectangle in Histogram 中的方法，就可以得到最大的矩形面积。那么这道题唯一要做的就是将每一层都当作直方图的底层，并向上构造整个直方图，由于题目限定了输入矩阵的字符只有 '0' 和 '1' 两种，所以处理起来也相对简单。方法是，对于每一个点，如果是 ‘0’，则赋0，如果是 ‘1’，就赋之前的 height 值加上1。具体参见代码如下：



```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        vector<int> height;
        for (int i = 0; i < matrix.size(); ++i) {
            height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    int largestRectangleArea(vector<int>& height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (s.empty() || height[s.top()] <= height[i]) s.push(i);
            else {
                int tmp = s.top(); s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                --i;
            }
        }
        return res;
    }
};
```

### 方法二

我们也可以在一个函数内完成，这样代码看起来更加简洁一些，注意这里的 height 初始化的大小为 n+1，为什么要多一个呢？这是因为我们只有在当前位置小于等于前一个位置的高度的时候，才会去计算矩形的面积，假如最后一个位置的高度是最高的，那么我们就没法去计算并更新结果 res 了，所以要在最后再加一个高度0，这样就一定可以计算前面的矩形面积了，这跟上面解法子函数中给 height 末尾加一个0是一样的效果，参见代码如下：



```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n + 1);
        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for (int j = 0; j < n + 1; ++j) {
                if (j < n) {
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
                }
                while (!s.empty() && height[s.top()] >= height[j]) {
                    int cur = s.top(); s.pop();
                    res = max(res, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
                }
                s.push(j);
            }
        }
        return res;
    }
}; 	
```

### 方法三

下面这种方法的思路很巧妙，height 数组和上面一样，这里的 left 数组表示若当前位置是1且与其相连都是1的左边界的位置（若当前 height 是0，则当前 left 一定是0），right 数组表示若当前位置是1且与其相连都是1的右边界的位置再加1（加1是为了计算长度方便，直接减去左边界位置就是长度），初始化为n（若当前 height 是0，则当前 right 一定是n），那么对于任意一行的第j个位置，矩形为 (right[j] - left[j]) * height[j]，我们举个例子来说明，比如给定矩阵为：

[
  [1, 1, 0, 0, 1],
  [0, 1, 0, 0, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 0, 0, 1]
]
第0行：

h: 1 1 0 0 1
l: 0 0 0 0 4
r: 2 2 5 5 5 
 

第1行：

h: 0 2 0 0 2
l: 0 1 0 0 4
r: 5 2 5 5 5 
 

第2行：

h: 0 0 1 1 3
l: 0 0 2 2 4
r: 5 5 5 5 5
 

第3行：

h: 0 0 2 2 4
l: 0 0 2 2 4
r: 5 5 5 5 5
 

第4行：

h: 0 0 0 0 5
l: 0 0 0 0 4
r: 5 5 5 5 5 
 

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), left(n, 0), right(n, n);
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                    left[j] = max(left[j], cur_left);
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], cur_right);
                } else {
                    right[j] = n;
                    cur_right = j;
                }
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        return res;
    }
}; 	
```

### 方法四

再来看一种解法，这里我们统计每一行的连续1的个数，使用一个数组 h_max, 其中 h_max[i][j] 表示第i行，第j个位置水平方向连续1的个数，若 matrix[i][j] 为0，那对应的 h_max[i][j] 也一定为0。统计的过程跟建立累加和数组很类似，唯一不同的是遇到0了要将 h_max 置0。这个统计好了之后，只需要再次遍历每个位置，首先每个位置的 h_max 值都先用来更新结果 res，因为高度为1也可以看作是矩形，然后我们向上方遍历，上方 (i, j-1) 位置也会有 h_max 值，但是用二者之间的较小值才能构成矩形，用新的矩形面积来更新结果 res，这样一直向上遍历，直到遇到0，或者是越界的时候停止，这样就可以找出所有的矩形了，参见代码如下：



```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> h_max(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                if (j > 0) h_max[i][j] = h_max[i][j - 1] + 1;
                else h_max[i][0] = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (h_max[i][j] == 0) continue;
                int mn = h_max[i][j];
                res = max(res, mn);
                for (int k = i - 1; k >= 0 && h_max[k][j] != 0; --k) {
                    mn = min(mn, h_max[k][j]);
                    res = max(res, mn * (i - k + 1));
                }
            }
        }
        return res;
    }
};
```

类似题目：

Maximal Square

Largest Rectangle in Histogram