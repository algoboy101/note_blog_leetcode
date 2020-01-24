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
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = "";
        for (int j = 0; j < strs[0].size(); ++j) {
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); ++i) {
                if (j >= strs[i].size() || strs[i][j] != c) {
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};
```

### 方法二

我们可以对上面的方法进行适当精简，如果发现当前某个字符和第一个字符串对应位置的字符不相等，说明不会再有更长的共同前缀了，直接通过用 substr 的方法直接取出共同前缀的子字符串。如果遍历结束前没有返回结果的话，说明第一个单词就是公共前缀，返回为结果即可。代码如下：

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int j = 0; j < strs[0].size(); ++j) {
            for (int i = 0; i < strs.size(); ++i) {
                if (j >= strs[i].size() || strs[i][j] != strs[0][j]) {
                    return strs[i].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};
```

### 方法三

我们再来看一种解法，这种方法给输入字符串数组排了个序，想想这样做有什么好处？既然是按字母顺序排序的话，那么有共同字母多的两个字符串会被排到一起，而跟大家相同的字母越少的字符串会被挤到首尾两端，那么如果有共同前缀的话，一定会出现在首尾两端的字符串中，所以只需要找首尾字母串的共同前缀即可。比如例子1排序后为 ["flight", "flow", "flower"]，例子2排序后为 ["cat", "dog", "racecar"]，虽然例子2没有共同前缀，但也可以认为共同前缀是空串，且出现在首尾两端的字符串中。由于是按字母顺序排的，而不是按长度，所以首尾字母的长度关系不知道，为了防止溢出错误，只遍历而这种较短的那个的长度，找出共同前缀返回即可，参见代码如下：

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while (i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/14