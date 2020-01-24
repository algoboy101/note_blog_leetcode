---
title: "[0041] First Missing Positive"
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
date: 2020-01-01 00:00:41
---

## 题目描述

> 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。 
> 
> 示例 1: 
> 
> 输入: [1,2,0]
> 输出: 3
> 
> 
> 示例 2: 
> 
> 输入: [3,4,-1,1]
> 输出: 2
> 
> 
> 示例 3: 
> 
> 输入: [7,8,9,11,12]
> 输出: 1
> 
> 
> 说明: 
> 
> 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。 
> Related Topics 数组

## 题目代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
    }
};
```

## 解析

这道题让我们找缺失的首个正数，由于限定了 O(n) 的时间，所以一般的排序方法都不能用，最开始博主没有看到还限制了空间复杂度，所以想到了用 HashSet 来解，这个思路很简单，把所有的数都存入 HashSet 中，然后循环从1开始递增找数字，哪个数字找不到就返回哪个数字，如果一直找到了最大的数字（这里是 nums 数组的长度），则加1后返回结果 res，参见代码如下：

### 方法一

```cpp
// NOT constant space
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 1, n = nums.size();
        while (res <= n) {
            if (!st.count(res)) return res;
            ++res;
        }
        return res;
    }
};
```

### 方法二

但是上面的解法不是 O(1) 的空间复杂度，所以需要另想一种解法，既然不能建立新的数组，那么只能覆盖原有数组，思路是把1放在数组第一个位置 nums[0]，2放在第二个位置 nums[1]，即需要把 nums[i] 放在 nums[nums[i] - 1]上，遍历整个数组，如果 nums[i] != i + 1, 而 nums[i] 为整数且不大于n，另外 nums[i] 不等于 nums[nums[i] - 1] 的话，将两者位置调换，如果不满足上述条件直接跳过，最后再遍历一遍数组，如果对应位置上的数不正确则返回正确的数，参见代码如下：

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/41

 

类似题目：

Missing Number

Find the Duplicate Number

Find All Numbers Disappeared in an Array

Couples Holding Hands