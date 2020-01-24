---
title: "[0028] Implement strStr()"
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
date: 2020-01-01 00:00:28
---

## 题目描述

> 实现 strStr() 函数。 
> 
> 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回 -1。 
> 
> 示例 1: 
> 
> 输入: haystack = "hello", needle = "ll"
> 输出: 2
> 
> 
> 示例 2: 
> 
> 输入: haystack = "aaaaa", needle = "bba"
> 输出: -1
> 
> 
> 说明: 
> 
> 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
> 
> 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 
> Related Topics 双指针 字符串

## 题目代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        
    }
};
```

## 解析

这道题让我们在一个字符串中找另一个字符串第一次出现的位置，那首先要做一些判断，如果子字符串为空，则返回0，如果子字符串长度大于母字符串长度，则返回 -1。然后开始遍历母字符串，这里并不需要遍历整个母字符串，而是遍历到剩下的长度和子字符串相等的位置即可，这样可以提高运算效率。然后对于每一个字符，都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，如果一直都没有跳出循环，则说明子字符串出现了，则返回起始位置即可，代码如下：



### 方法一

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};
```

### 方法二

我们也可以写的更加简洁一些，开头直接套两个 for 循环，不写终止条件，然后判断假如j到达 needle 的末尾了，此时返回i；若此时 i+j 到达 haystack 的长度了，返回 -1；否则若当前对应的字符不匹配，直接跳出当前循环，参见代码如下：



```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; ; ++i) {
            for (int j = 0; ; ++j) {
                if (j == needle.size()) return i;
                if (i + j == haystack.size()) return -1;
                if (needle[j] != haystack[i + j]) break;
            }
        }
        return -1;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/28

 

类似题目：

Shortest Palindrome

Repeated Substring Pattern

