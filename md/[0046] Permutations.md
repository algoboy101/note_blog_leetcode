---
title: "[0046] Permutations"
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
date: 2020-01-01 00:00:46
---

## 题目描述

> 给定一个没有重复数字的序列，返回其所有可能的全排列。 
> 
> 示例: 
> 
> 输入: [1,2,3]
> 输出:
> [
> [1,2,3],
> [1,3,2],
> [2,1,3],
> [2,3,1],
> [3,1,2],
> [3,2,1]
> ] 
> Related Topics 回溯算法

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
    }
};
```

## 解析

这道题是求全排列问题，给的输入数组没有重复项，这跟之前的那道 Combinations 和类似，解法基本相同，但是不同点在于那道不同的数字顺序只算一种，是一道典型的组合题，而此题是求全排列问题，还是用递归 DFS 来求解。这里需要用到一个 visited 数组来标记某个数字是否访问过，然后在 DFS 递归函数从的循环应从头开始，而不是从 level 开始，这是和 Combinations 不同的地方，其余思路大体相同。这里再说下 level 吧，其本质是记录当前已经拼出的个数，一旦其达到了 nums 数组的长度，说明此时已经是一个全排列了，因为再加数字的话，就会超出。还有就是，为啥这里的 level 要从0开始遍历，因为这是求全排列，每个位置都可能放任意一个数字，这样会有个问题，数字有可能被重复使用，由于全排列是不能重复使用数字的，所以需要用一个 visited 数组来标记某个数字是否使用过，代码如下：



### 方法一

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level == num.size()) {res.push_back(out); return;}
        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(num[i]);
            permuteDFS(num, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
```

### 方法二

还有一种递归的写法，更简单一些，这里是每次交换 num 里面的两个数字，经过递归可以生成所有的排列情况。这里你可能注意到，为啥在递归函数中， push_back() 了之后没有返回呢，而解法一或者是 Combinations 的递归解法在更新结果 res 后都 return 了呢？其实如果你仔细看代码的话，此时 start 已经大于等于 num.size() 了，而下面的 for 循环的i是从 start 开始的，根本就不会执行 for 循环里的内容，就相当于 return 了，博主偷懒就没写了。但其实为了避免混淆，最好还是加上，免得和前面的搞混了，代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        permuteDFS(num, 0, res);
        return res;
    }
    void permuteDFS(vector<int>& num, int start, vector<vector<int>>& res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            permuteDFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};
```

### 方法三

上述解法的最终生成顺序为：[[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,2,1], [3,1,2]] 

最后再来看一种方法，这种方法是 CareerCup 书上的方法，也挺不错的，这道题是思想是这样的：

当 n=1 时，数组中只有一个数 a1，其全排列只有一种，即为 a1

当 n=2 时，数组中此时有 a1a2，其全排列有两种，a1a2 和 a2a1，那么此时考虑和上面那种情况的关系，可以发现，其实就是在 a1 的前后两个位置分别加入了 a2 

当 n=3 时，数组中有 a1a2a3，此时全排列有六种，分别为 a1a2a3, a1a3a2, a2a1a3, a2a3a1, a3a1a2, 和 a3a2a1。那么根据上面的结论，实际上是在 a1a2 和 a2a1 的基础上在不同的位置上加入 a3 而得到的。

_ a1 _ a2 _ : a3a1a2, a1a3a2, a1a2a3

_ a2 _ a1 _ : a3a2a1, a2a3a1, a2a1a3

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        if (num.empty()) return vector<vector<int>>(1, vector<int>());
        vector<vector<int>> res;
        int first = num[0];
        num.erase(num.begin());
        vector<vector<int>> words = permute(num);
        for (auto &a : words) {
            for (int i = 0; i <= a.size(); ++i) {
                a.insert(a.begin() + i, first);
                res.push_back(a);
                a.erase(a.begin() + i);
            }
        }   
        return res;
    }
};
```

### 方法四

上面的三种解法都是递归的，我们也可以使用迭代的方法来做。其实下面这个解法就上面解法的迭代写法，核心思路都是一样的，都是在现有的排列的基础上，每个空位插入一个数字，从而生成各种的全排列的情况，参见代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res{{}};
        for (int a : num) {
            for (int k = res.size(); k > 0; --k) {
                vector<int> t = res.front();
                res.erase(res.begin());
                for (int i = 0; i <= t.size(); ++i) {
                    vector<int> one = t;
                    one.insert(one.begin() + i, a);
                    res.push_back(one);
                }
            }
        }
        return res;
    }
};
```

### 方法五

下面这种解法就有些耍赖了，用了 STL 的内置函数 next_permutation()，专门就是用来返回下一个全排列，耳边又回响起了诸葛孔明的名言，我从未见过如此...投机取巧...的解法！



```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        res.push_back(num);
        while (next_permutation(num.begin(), num.end())) {
            res.push_back(num);
        }
        return res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/46

 

类似题目：

Next Permutation

Permutations II

Permutation Sequence

Combinations