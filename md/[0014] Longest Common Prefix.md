---
title: "[0014] Longest Common Prefix"
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
date: 2020-01-01 00:00:14
---

## 题目描述

> 编写一个函数来查找字符串数组中的最长公共前缀。 
> 
> 如果不存在公共前缀，返回空字符串 ""。 
> 
> 示例 1: 
> 
> 输入: ["flower","flow","flight"]
> 输出: "fl"
> 
> 
> 示例 2: 
> 
> 输入: ["dog","racecar","car"]
> 输出: ""
> 解释: 输入不存在公共前缀。
> 
> 
> 说明: 
> 
> 所有输入只包含小写字母 a-z 。 
> Related Topics 字符串

## 题目代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
    }
};
```

## 解析

这道题让我们求一系列字符串的共同前缀，没有什么特别的技巧，无脑查找即可，定义两个变量i和j，其中i是遍历搜索字符串中的字符，j是遍历字符串集中的每个字符串。这里将单词上下排好，则相当于一个各行长度有可能不相等的二维数组，遍历顺序和一般的横向逐行遍历不同，而是采用纵向逐列遍历，在遍历的过程中，如果某一行没有了，说明其为最短的单词，因为共同前缀的长度不能长于最短单词，所以此时返回已经找出的共同前缀。每次取出第一个字符串的某一个位置的单词，然后遍历其他所有字符串的对应位置看是否相等，如果有不满足的直接返回 res，如果都相同，则将当前字符存入结果，继续检查下一个位置的字符，参见代码如下：

### 方法一

```cpp

```

### 方法二

```cpp

```

### 方法三

```cpp

```

