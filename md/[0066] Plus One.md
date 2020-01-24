---
title: "[0066] Plus One"
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
date: 2020-01-01 00:01:06
---

## 题目描述

> 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。 
> 
> 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。 
> 
> 你可以假设除了整数 0 之外，这个整数不会以零开头。 
> 
> 示例 1: 
> 
> 输入: [1,2,3]
> 输出: [1,2,4]
> 解释: 输入数组表示数字 123。
> 
> 
> 示例 2: 
> 
> 输入: [4,3,2,1]
> 输出: [4,3,2,2]
> 解释: 输入数组表示数字 4321。
> 
> Related Topics 数组

## 题目代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
    }
};
```

## 解析

### 方法一

将一个数字的每个位上的数字分别存到一个一维向量中，最高位在最开头，我们需要给这个数字加一，即在末尾数字加一，如果末尾数字是9，那么则会有进位问题，而如果前面位上的数字仍为9，则需要继续向前进位。具体算法如下：首先判断最后一位是否为9，若不是，直接加一返回，若是，则该位赋0，再继续查前一位，同样的方法，知道查完第一位。如果第一位原本为9，加一后会产生新的一位，那么最后要做的是，查运算完的第一位是否为0，如果是，则在最前头加一个1。代码如下：



```cpp
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] == 9) digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

### 方法二

我们也可以使用跟之前那道Add Binary类似的做法，我们将carry初始化为1，然后相当于digits加了一个0，处理方法跟之前那道题一样，参见代码如下：


```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int carry = 1, n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            if (carry == 0) return digits;
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

类似题目：

Add Binary