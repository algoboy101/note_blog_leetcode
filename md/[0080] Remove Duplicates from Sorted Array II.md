---
title: "[0080] Remove Duplicates from Sorted Array II"
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
date: 2020-01-01 00:01:20
---

## 题目描述

> 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。 
> 
> 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。 
> 
> 示例 1: 
> 
> 给定 nums = [1,1,1,2,2,3],
> 
> 函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。
> 
> 你不需要考虑数组中超出新长度后面的元素。 
> 
> 示例 2: 
> 
> 给定 nums = [0,0,1,1,1,1,2,3,3],
> 
> 函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。
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

### 方法一

这道题是之前那道 Remove Duplicates from Sorted Array 的拓展，这里允许最多重复的次数是两次，那么可以用一个变量 cnt 来记录还允许有几次重复，cnt 初始化为1，如果出现过一次重复，则 cnt 递减1，那么下次再出现重复，快指针直接前进一步，如果这时候不是重复的，则 cnt 恢复1，由于整个数组是有序的，所以一旦出现不重复的数，则一定比这个数大，此数之后不会再有重复项。理清了上面的思路，则代码很好写了：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre = 0, cur = 1, cnt = 1, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur] && cnt == 0) ++cur;
            else {
                if (nums[pre] == nums[cur]) --cnt;
                else cnt = 1;
                nums[++pre] = nums[cur++];
            }
        }
        return nums.empty() ? 0 : pre + 1;
    }
};
```

### 方法二

这里其实也可以用类似于 Remove Duplicates from Sorted Array 中的解法三的模版，由于这里最多允许两次重复，那么当前的数字 num 只要跟上上个覆盖位置的数字 nusm[i-2] 比较，若 num 较大，则绝不会出现第三个重复数字（前提是数组是有序的），这样的话根本不需要管 nums[i-1] 是否重复，只要将重复个数控制在2个以内就可以了，参见代码如下：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 2 || num > nums[i - 2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/80

 

类似题目：

Remove Duplicates from Sorted Array

