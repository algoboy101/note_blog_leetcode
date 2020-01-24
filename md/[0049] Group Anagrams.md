---
title: "[0049] Group Anagrams"
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
date: 2020-01-01 00:00:49
---

## 题目描述

> 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
> 
> 示例: 
> 
> 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
> 输出:
> [
> ["ate","eat","tea"],
> ["nat","tan"],
> ["bat"]
> ] 
> 
> 说明： 
> 
> 
> 所有输入均为小写字母。 
> 不考虑答案输出的顺序。 
> 
> Related Topics 哈希表 字符串

## 题目代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    }
};
```

## 解析

### 方法一

这道题让我们群组给定字符串集中所有的错位词，所谓的错位词就是两个字符串中字母出现的次数都一样，只是位置不同，比如 abc，bac, cba 等它们就互为错位词，那么如何判断两者是否是错位词呢，可以发现如果把错位词的字符顺序重新排列，那么会得到相同的结果，所以重新排序是判断是否互为错位词的方法，由于错位词重新排序后都会得到相同的字符串，以此作为 key，将所有错位词都保存到字符串数组中，建立 key 和当前的不同的错位词集合个数之间的映射，这里之所以没有建立 key 和其隶属的错位词集合之间的映射，是用了一个小 trick，从而避免了最后再将 HashMap 中的集合拷贝到结果 res 中。当检测到当前的单词不在 HashMap 中，此时知道这个单词将属于一个新的错位词集合，所以将其映射为当前的错位词集合的个数，然后在 res 中新增一个空集合，这样就可以通过其映射值，直接找到新的错位词集合的位置，从而将新的单词存入结果 res 中，参见代码如下：



```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            if (!m.count(t)) {
                m[t] = res.size();
                res.push_back({});
            }
            res[m[t]].push_back(str);
        }
        return res;
    }
};
```

### 方法二

下面这种解法没有用到排序，用一个大小为 26 的 int 数组来统计每个单词中字符出现的次数，然后将 int 数组转为一个唯一的字符串，跟字符串数组进行映射，这样就不用给字符串排序了，参见代码如下：



```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26);
            string t;
            for (char c : str) ++cnt[c - 'a'];
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] == 0) continue;
                t += string(1, i + 'a') + to_string(cnt[i]);
            }
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};
```


类似题目：

https://github.com/grandyang/leetcode/issues/49

 

类似题目：

Valid Anagram

Group Shifted Strings 