---
title: "[0040] Combination Sum II"
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
date: 2020-01-01 00:00:40
---

## 题目描述

> 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
> 
> candidates 中的每个数字在每个组合中只能使用一次。 
> 
> 说明： 
> 
> 
> 所有数字（包括目标数）都是正整数。 
> 解集不能包含重复的组合。 
> 
> 
> 示例 1: 
> 
> 输入: candidates = [10,1,2,7,6,1,5], target = 8,
> 所求解集为:
> [
> [1, 7],
> [1, 2, 5],
> [2, 6],
> [1, 1, 6]
> ]
> 
> 
> 示例 2: 
> 
> 输入: candidates = [2,5,2,1,2], target = 5,
> 所求解集为:
> [
>   [1,2,2],
>   [5]
> ] 
> Related Topics 数组 回溯算法

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    }
};
```

## 解析

这道题跟之前那道 Combination Sum 本质没有区别，只需要改动一点点即可，之前那道题给定数组中的数字可以重复使用，而这道题不能重复使用，只需要在之前的基础上修改两个地方即可，首先在递归的 for 循环里加上 if (i > start && num[i] == num[i - 1]) continue; 这样可以防止 res 中出现重复项，然后就在递归调用 helper 里面的参数换成 i+1，这样就不会重复使用数组中的数字了，代码如下：

### 方法一

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& num, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(num.begin(), num.end());
        helper(num, target, 0, out, res);
        return res;
    }
    void helper(vector<int>& num, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(out); return; }
        for (int i = start; i < num.size(); ++i) {
            if (i > start && num[i] == num[i - 1]) continue;
            out.push_back(num[i]);
            helper(num, target - num[i], i + 1, out, res);
            out.pop_back();
        }
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/40

类似题目：

Combination Sum III

Combination Sum