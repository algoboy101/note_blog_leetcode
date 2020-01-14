---
title: "[0005] Longest Palindromic Substring"
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
date: 2020-01-01 00:00:05
---

## 题目描述

> 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
> 
> 示例 1： 
> 
> 输入: "babad"
> 输出: "bab"
> 注意: "aba" 也是一个有效答案。
> 
> 
> 示例 2： 
> 
> 输入: "cbbd"
> 输出: "bb"
> 
> Related Topics 字符串 动态规划

## 题目代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        
    }
};
```

## 解析

### 方法一

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        int start = 0;
        int len = 0;
        for(int i=0; i<s.size(); i++){
            int tmp = max(getsub(s, i, i), getsub(s,i,i+1));
            if(tmp > len){
                len = tmp;
                start = i - (len-1)/2;
            }
        }
        return s.substr(start, len);
    }

    int getsub(string s, int i, int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return j - i - 1;
    }
};
```

### 方法二

```cpp

```

### 方法三

```cpp

```

