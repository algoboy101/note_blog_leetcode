---
title: "[0017] Letter Combinations of a Phone Number"
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
date: 2020-01-01 00:00:17
---

## 题目描述

> 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。 
> 
> 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
> 
> 
> 
> 示例: 
> 
> 输入："23"
> 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
> 
> 
> 说明: 
> 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。 
> Related Topics 字符串 回溯算法

## 题目代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
    }
};
```

## 解析

这道题让我们求电话号码的字母组合，即数字2到9中每个数字可以代表若干个字母，然后给一串数字，求出所有可能的组合，相类似的题目有 Path Sum II，Subsets II，Permutations，Permutations II，Combinations，Combination Sum 和 Combination Sum II 等等。这里可以用递归 Recursion 来解，需要建立一个字典，用来保存每个数字所代表的字符串，然后还需要一个变量 level，记录当前生成的字符串的字符个数，实现套路和上述那些题十分类似。在递归函数中首先判断 level，如果跟 digits 中数字的个数相等了，将当前的组合加入结果 res 中，然后返回。我们通过 digits 中的数字到 dict 中取出字符串，然后遍历这个取出的字符串，将每个字符都加到当前的组合后面，并调用递归函数即可，参见代码如下：

### 方法一

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsDFS(digits, dict, 0, "", res);
        return res;
    }
    void letterCombinationsDFS(string& digits, vector<string>& dict, int level, string out, vector<string>& res) {
        if (level == digits.size()) {res.push_back(out); return;}
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); ++i) {
            letterCombinationsDFS(digits, dict, level + 1, out + str[i], res);
        }
    }
};
```

### 方法二

这道题也可以用迭代 Iterative 来解，在遍历 digits 中所有的数字时，先建立一个临时的字符串数组t，然后跟上面解法的操作一样，通过数字到 dict 中取出字符串 str，然后遍历取出字符串中的所有字符，再遍历当前结果 res 中的每一个字符串，将字符加到后面，并加入到临时字符串数组t中。取出的字符串 str 遍历完成后，将临时字符串数组赋值给结果 res，具体实现参见代码如下：

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res{""};
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> t;
            string str = dict[digits[i] - '0'];
            for (int j = 0; j < str.size(); ++j) {
                for (string s : res) t.push_back(s + str[j]);
            }
            res = t;
        }
        return res;
    }
};
```

Github 同步地址：

https://github.com/grandyang/leetcode/issues/17

 

类似题目：

Generate Parentheses

Combination Sum

