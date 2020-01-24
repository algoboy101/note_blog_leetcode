---
title: "[0026] Remove Duplicates from Sorted Array"
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
date: 2020-01-01 00:00:26
---

## 题目描述

> 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。 
> 
> 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。 
> 
> 示例 1: 
> 
> 给定数组 nums = [1,1,2], 
> 
> 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
> 
> 你不需要考虑数组中超出新长度后面的元素。 
> 
> 示例 2: 
> 
> 给定 nums = [0,0,1,1,1,2,2,3,3,4],
> 
> 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
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
> // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
> int len = removeDuplicates(nums);
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
    int removeDuplicates(vector<int>& nums) {
        
    }
};
```

## 解析

这道题要我们从有序数组中去除重复项，和之前那道 Remove Duplicates from Sorted List 的题很类似，但是要简单一些，因为毕竟数组的值可以通过下标直接访问，而链表不行。那么这道题的解题思路是使用快慢指针来记录遍历的坐标，最开始时两个指针都指向第一个数字，如果两个指针指的数字相同，则快指针向前走一步，如果不同，则两个指针都向前走一步，这样当快指针走完整个数组后，慢指针当前的坐标加1就是数组中不同数字的个数，代码如下：

### 方法一

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0, cur = 0, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur]) ++cur;
            else nums[++pre] = nums[cur++];
        }
        return nums.empty() ? 0 : (pre + 1);
    }
};
```

### 方法二

我们也可以用 for 循环来写，这里的j就是上面解法中的 pre，i就是 cur，所以本质上都是一样的，参见代码如下：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != nums[j]) nums[++j] = nums[i];
        }
        return nums.empty() ? 0 : (j + 1);
    }
};
```

### 方法三

这里也可以换一种写法，用变量i表示当前覆盖到到位置，由于不能有重复数字，则只需要用当前数字 num 跟上一个覆盖到到数字 nums[i-1] 做个比较，只要 num 大，则一定不会有重复（前提是数组必须有序），参见代码如下：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 1 || num > nums[i - 1]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/26

 类似题目：

Remove Duplicates from Sorted List

Remove Duplicates from Sorted List II

Remove Duplicates from Sorted Array II

Remove Element

