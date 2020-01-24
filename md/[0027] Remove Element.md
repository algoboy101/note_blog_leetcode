---
title: "[0027] Remove Element"
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
date: 2020-01-01 00:00:27
---

## 题目描述

> 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。 
> 
> 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。 
> 
> 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。 
> 
> 示例 1: 
> 
> 给定 nums = [3,2,2,3], val = 3,
> 
> 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
> 
> 你不需要考虑数组中超出新长度后面的元素。
> 
> 
> 示例 2: 
> 
> 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
> 
> 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
> 
> 注意这五个元素可为任意顺序。
> 
> 你不需要考虑数组中超出新长度后面的元素。
> 
> 
> 说明: 
> 
> 为什么返回数值是整数，但输出的答案是数组呢? 
> 
> 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。 
> 
> 你可以想象内部操作如下: 
> 
> // nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
> int len = removeElement(nums, val);
> 
> // 在函数里修改输入数组对于调用者是可见的。
> // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
> for (int i = 0; i < len; i++) {
>     print(nums[i]);
> }
> 
> Related Topics 数组 双指针

## 题目代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
    }
};
```

## 解析

这道题让我们移除一个数组中和给定值相同的数字，并返回新的数组的长度。是一道比较容易的题，只需要一个变量用来计数，然后遍历原数组，如果当前的值和给定值不同，就把当前值覆盖计数变量的位置，并将计数变量加1。代码如下：



### 方法一

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) nums[res++] = nums[i];
        }
        return res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/27

 

类似题目：

Remove Duplicates from Sorted Array

Remove Linked List Elements

Move Zeroes
