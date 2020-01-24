---
title: "[0047] Permutations II"
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
date: 2020-01-01 00:00:47
---

## 题目描述

> 给定一个可包含重复数字的序列，返回所有不重复的全排列。 
> 
> 示例: 
> 
> 输入: [1,1,2]
> 输出:
> [
> [1,1,2],
> [1,2,1],
> [2,1,1]
> ] 
> Related Topics 回溯算法

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
    }
};
```

## 解析

### 方法一

这道题是之前那道 Permutations 的延伸，由于输入数组有可能出现重复数字，如果按照之前的算法运算，会有重复排列产生，我们要避免重复的产生，在递归函数中要判断前面一个数和当前的数是否相等，如果相等，且其对应的 visited 中的值为1，当前的数字才能使用（下文中会解释这样做的原因），否则需要跳过，这样就不会产生重复排列了，代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out, visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        permuteUniqueDFS(nums, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        if (level >= nums.size()) {res.push_back(out); return;}
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == 1) continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            permuteUniqueDFS(nums, level + 1, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
```

### 方法二

在使用上面的方法的时候，一定要能弄清楚递归函数的 for 循环中两个 if 的剪枝的意思。在此之前，要弄清楚 level 的含义，这里用数组 out 来拼排列结果，level就是当前已经拼成的个数，其实就是 out 数组的长度。我们看到，for 循环的起始是从0开始的，而本题的解法二，三，四都是用了一个 start 变量，从而 for 循环都是从 start 开始，一定要分清楚 start 和本解法中的 level 的区别。由于递归的 for 都是从0开始，难免会重复遍历到数字，而全排列不能重复使用数字，意思是每个 nums 中的数字在全排列中只能使用一次（当然这并不妨碍 nums 中存在重复数字）。不能重复使用数字就靠 visited 数组来保证，这就是第一个 if 剪枝的意义所在。关键来看第二个 if 剪枝的意义，这里说当前数字和前一个数字相同，且前一个数字的 visited 值为0的时候，必须跳过。这里的前一个数 visited 值为0，并不代表前一个数字没有被处理过，也可能是递归结束后恢复状态时将 visited 值重置为0了，实际上就是这种情况，下面打印了一些中间过程的变量值，如下所示：

```
level = 0, i = 0 => out: {}
level = 1, i = 0 => out: {1 } skipped 1
level = 1, i = 1 => out: {1 }
level = 2, i = 0 => out: {1 2 } skipped 1
level = 2, i = 1 => out: {1 2 } skipped 1
level = 2, i = 2 => out: {1 2 }
level = 3 => saved  {1 2 2}
level = 3, i = 0 => out: {1 2 2 } skipped 1
level = 3, i = 1 => out: {1 2 2 } skipped 1
level = 3, i = 2 => out: {1 2 2 } skipped 1
level = 2, i = 2 => out: {1 2 2 } -> {1 2 } recovered
level = 1, i = 1 => out: {1 2 } -> {1 } recovered
level = 1, i = 2 => out: {1 } skipped 2
level = 0, i = 0 => out: {1 } -> {} recovered
level = 0, i = 1 => out: {}
level = 1, i = 0 => out: {2 }
level = 2, i = 0 => out: {2 1 } skipped 1
level = 2, i = 1 => out: {2 1 } skipped 1
level = 2, i = 2 => out: {2 1 }
level = 3 => saved  {1 2 2}
level = 3, i = 0 => out: {2 1 2 } skipped 1
level = 3, i = 1 => out: {2 1 2 } skipped 1
level = 3, i = 2 => out: {2 1 2 } skipped 1
level = 2, i = 2 => out: {2 1 2 } -> {2 1 } recovered
level = 1, i = 0 => out: {2 1 } -> {2 } recovered
level = 1, i = 1 => out: {2 } skipped 1
level = 1, i = 2 => out: {2 }
level = 2, i = 0 => out: {2 2 }
level = 3 => saved  {1 2 2}
level = 3, i = 0 => out: {2 2 1 } skipped 1
level = 3, i = 1 => out: {2 2 1 } skipped 1
level = 3, i = 2 => out: {2 2 1 } skipped 1
level = 2, i = 0 => out: {2 2 1 } -> {2 2 } recovered
level = 2, i = 1 => out: {2 2 } skipped 1
level = 2, i = 2 => out: {2 2 } skipped 1
level = 1, i = 2 => out: {2 2 } -> {2 } recovered
level = 0, i = 1 => out: {2 } -> {} recovered
level = 0, i = 2 => out: {} skipped 2
```

注意看这里面的 skipped 1 表示的是第一个 if 剪枝起作用的地方，skipped 2 表示的是第二个 if 剪枝起作用的地方。我们主要关心的是第二个 if 剪枝，看上方第一个蓝色标记的那行，再上面的红色一行表示在 level = 1, i = 1 时递归调用结束后，恢复到起始状态，那么此时 out 数组中只有一个1，后面的2已经被 pop_back() 了，当然对应的 visited 值也重置为0了，这种情况下需要剪枝，当然不能再一次把2往里加，因为这种情况在递归中已经加入到结果 res 中了，所以到了 level = 1, i = 2 的状态时，nums[i] == nums[i-1] && visited[i-1] == 0 的条件满足了，剪枝就起作用了，这种重复的情况就被剪掉了。

还有一种比较简便的方法，在 Permutations 的基础上稍加修改，用 TreeSet 来保存结果，利用其不会有重复项的特点，然后在递归函数中 swap 的地方，判断如果i和 start 不相同，但是 nums[i] 和 nums[start] 相同的情况下跳过，继续下一个循环，参见代码如下：



```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        permute(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    void permute(vector<int>& nums, int start, set<vector<int>>& res) {
        if (start >= nums.size()) res.insert(nums);
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/47

 

类似题目：

Permutations

Next Permutation

Palindrome Permutation II 