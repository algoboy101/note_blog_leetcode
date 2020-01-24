---
title: "[0030] Substring with Concatenation of All Words"
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
date: 2020-01-01 00:00:30
---

## 题目描述

> 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。 
> 
> 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。 
> 
> 
> 
> 示例 1： 
> 
> 输入：
> s = "barfoothefoobarman",
> words = ["foo","bar"]
> 输出：[0,9]
> 解释：
> 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
> 输出的顺序不重要, [9,0] 也是有效答案。
> 
> 
> 示例 2： 
> 
> 输入：
> s = "wordgoodgoodgoodbestword",
> words = ["word","good","best","word"]
> 输出：[]
> 
> Related Topics 哈希表 双指针 字符串

## 题目代码

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
    }
};
```

## 解析

这道题让我们求串联所有单词的子串，就是说给定一个长字符串，再给定几个长度相同的单词，让找出串联给定所有单词的子串的起始位置，还是蛮有难度的一道题。假设 words 数组中有n个单词，每个单词的长度均为 len，那么实际上这道题就让我们出所有长度为 nxlen 的子串，使得其刚好是由 words 数组中的所有单词组成。那么就需要经常判断s串中长度为 len 的子串是否是 words 中的单词，为了快速的判断，可以使用 HashMap，同时由于 words 数组可能有重复单词，就要用 HashMap 来建立所有的单词和其出现次数之间的映射，即统计每个单词出现的次数。

遍历s中所有长度为 nxlen 的子串，当剩余子串的长度小于 nxlen 时，就不用再判断了。所以i从0开始，到 (int)s.size() - nxlen 结束就可以了，注意这里一定要将 s.size() 先转为整型数，再进行解法。一定要形成这样的习惯，一旦 size() 后面要减去数字时，先转为 int 型，因为 size() 的返回值是无符号型，一旦减去一个比自己大的数字，则会出错。对于每个遍历到的长度为 nxlen 的子串，需要验证其是否刚好由 words 中所有的单词构成，检查方法就是每次取长度为 len 的子串，看其是否是 words 中的单词。为了方便比较，建立另一个 HashMap，当取出的单词不在 words 中，直接 break 掉，否则就将其在新的 HashMap 中的映射值加1，还要检测若其映射值超过原 HashMap 中的映射值，也 break 掉，因为就算当前单词在 words 中，但若其出现的次数超过 words 中的次数，还是不合题意的。在 for 循环外面，若j正好等于n，说明检测的n个长度为 len 的子串都是 words 中的单词，并且刚好构成了 words，则将当前位置i加入结果 res 即可，具体参见代码如下：

### 方法一

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> wordCnt;
        for (auto &word : words) ++wordCnt[word];
        for (int i = 0; i <= (int)s.size() - n * len; ++i) {
            unordered_map<string, int> strCnt;
            int j = 0; 
            for (j = 0; j < n; ++j) {
                string t = s.substr(i + j * len, len);
                if (!wordCnt.count(t)) break;
                ++strCnt[t];
                if (strCnt[t] > wordCnt[t]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
```

### 方法二

这道题还有一种 O(n) 时间复杂度的解法，设计思路非常巧妙，但是感觉很难想出来，博主目测还未到达这种水平。这种方法不再是一个字符一个字符的遍历，而是一个词一个词的遍历，比如根据题目中的例子，字符串s的长度n为 18，words 数组中有两个单词 (cnt=2)，每个单词的长度 len 均为3，那么遍历的顺序为 0，3，6，8，12，15，然后偏移一个字符 1，4，7，9，13，16，然后再偏移一个字符 2，5，8，10，14，17，这样就可以把所有情况都遍历到，还是先用一个 HashMap m1 来记录 words 里的所有词，然后从0开始遍历，用 left 来记录左边界的位置，count 表示当前已经匹配的单词的个数。然后一个单词一个单词的遍历，如果当前遍历的到的单词t在 m1 中存在，那么将其加入另一个 HashMap m2 中，如果在 m2 中个数小于等于 m1 中的个数，那么 count 自增1，如果大于了，则需要做一些处理，比如下面这种情况：s = barfoofoo, words = {bar, foo, abc}，给 words 中新加了一个 abc ，目的是为了遍历到 barfoo 不会停止，当遍历到第二 foo 的时候,  m2[foo]=2, 而此时 m1[foo]=1，这时候已经不连续了，所以要移动左边界 left 的位置，先把第一个词 t1=bar 取出来，然后将 m2[t1] 自减1，如果此时 m2[t1]<m1[t1] 了，说明一个匹配没了，那么对应的 count 也要自减1，然后左边界加上个 len，这样就可以了。如果某个时刻 count 和 cnt 相等了，说明成功匹配了一个位置，将当前左边界 left 存入结果 res 中，此时去掉最左边的一个词，同时 count 自减1，左边界右移 len，继续匹配。如果匹配到一个不在 m1 中的词，说明跟前面已经断开了，重置 m2，count 为0，左边界 left 移到 j+len，参见代码如下：



```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        vector<int> res;
        int n = s.size(), cnt = words.size(), len = words[0].size();
        unordered_map<string, int> m1;
        for (string w : words) ++m1[w];
        for (int i = 0; i < len; ++i) {
            int left = i, count = 0;
            unordered_map<string, int> m2;
            for (int j = i; j <= n - len; j += len) {
                string t = s.substr(j, len);
                if (m1.count(t)) {
                    ++m2[t];
                    if (m2[t] <= m1[t]) {
                        ++count;
                    } else {
                        while (m2[t] > m1[t]) {
                            string t1 = s.substr(left, len);
                            --m2[t1];
                            if (m2[t1] < m1[t1]) --count;
                            left += len;
                        }
                    }
                    if (count == cnt) {
                        res.push_back(left);
                        --m2[s.substr(left, len)];
                        --count;
                        left += len;
                    }
                } else {
                    m2.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }
        return res;
    }
};
```

 
Github 同步地址：

https://github.com/grandyang/leetcode/issues/30

类似题目：

Minimum Window Substring


