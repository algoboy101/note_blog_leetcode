---
title: "[0903] Valid Permutations for DI Sequence"
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
date: 2020-01-01 00:15:03
---

## 题目描述

> 我们给出 S，一个源于 {'D', 'I'} 的长度为 n 的字符串 。（这些字母代表 “减少” 和 “增加”。） 
> 有效排列 是对整数 {0, 1, ..., n} 的一个排列 P[0], P[1], ..., P[n]，使得对所有的 i： 
> 
> 
> 如果 S[i] == 'D'，那么 P[i] > P[i+1]，以及； 
> 如果 S[i] == 'I'，那么 P[i] < P[i+1]。 
> 
> 
> 有多少个有效排列？因为答案可能很大，所以请返回你的答案模 10^9 + 7. 
> 
> 
> 
> 示例： 
> 
> 输入："DID"
> 输出：5
> 解释：
> (0, 1, 2, 3) 的五个有效排列是：
> (1, 0, 3, 2)
> (2, 0, 3, 1)
> (2, 1, 3, 0)
> (3, 0, 2, 1)
> (3, 1, 2, 0)
> 
> 
> 
> 
> 提示： 
> 
> 
> 1 <= S.length <= 200 
> S 仅由集合 {'D', 'I'} 中的字符组成。 
> 
> 
> 
> Related Topics 分治算法 动态规划

## 题目代码

```cpp
class Solution {
public:
    int numPermsDISequence(string S) {
        
    }
};
```

## 解析

### 方法一

```cpp

```

### 方法二

```cpp

```

### 方法三

```cpp

```

