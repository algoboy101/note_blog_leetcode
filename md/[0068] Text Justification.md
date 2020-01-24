---
title: "[0068] Text Justification"
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
date: 2020-01-01 00:01:08
---

## 题目描述

> 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。 
> 
> 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。 
> 
> 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。 
> 
> 文本的最后一行应为左对齐，且单词之间不插入额外的空格。 
> 
> 说明: 
> 
> 
> 单词是指由非空格字符组成的字符序列。 
> 每个单词的长度大于 0，小于等于 maxWidth。 
> 输入单词数组 words 至少包含一个单词。 
> 
> 
> 示例: 
> 
> 输入:
> words = ["This", "is", "an", "example", "of", "text", "justification."]
> maxWidth = 16
> 输出:
> [
>    "This    is    an",
>    "example  of text",
>    "justification.  "
> ]
> 
> 
> 示例 2: 
> 
> 输入:
> words = ["What","must","be","acknowledgment","shall","be"]
> maxWidth = 16
> 输出:
> [
>   "What   must   be",
>   "acknowledgment  ",
>   "shall be        "
> ]
> 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
>      因为最后一行应为左对齐，而不是左右两端对齐。       
> 第二行同样为左对齐，这是因为这行只包含一个单词。
> 
> 
> 示例 3: 
> 
> 输入:
> words = ["Science","is","what","we","understand","well","enough","to","explain",
>          "to","a","computer.","Art","is","everything","else","we","do"]
> maxWidth = 20
> 输出:
> [
>   "Science  is  what we",
> "understand      well",
>   "enough to explain to",
>   "a  computer.  Art is",
>   "everything  else  we",
>   "do                  "
> ]
> 
> Related Topics 字符串

## 题目代码

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
    }
};
```

## 解析

### 方法一

我将这道题翻译为文本的左右对齐是因为这道题像极了word软件里面的文本左右对齐功能，这道题我前前后后折腾了快四个小时终于通过了OJ，完成了之后想着去网上搜搜看有没有更简单的方法，搜了一圈发现都差不多，都挺复杂的，于是乎就按自己的思路来说吧，由于返回的结果是多行的，所以我们在处理的时候也要一行一行的来处理，首先要做的就是确定每一行能放下的单词数，这个不难，就是比较n个单词的长度和加上n - 1个空格的长度跟给定的长度L来比较即可，找到了一行能放下的单词个数，然后计算出这一行存在的空格的个数，是用给定的长度L减去这一行所有单词的长度和。得到了空格的个数之后，就要在每个单词后面插入这些空格，这里有两种情况，比如某一行有两个单词"to" 和 "a"，给定长度L为6，如果这行不是最后一行，那么应该输出"to   a"，如果是最后一行，则应该输出 "to a  "，所以这里需要分情况讨论，最后一行的处理方法和其他行之间略有不同。最后一个难点就是，如果一行有三个单词，这时候中间有两个空，如果空格数不是2的倍数，那么左边的空间里要比右边的空间里多加入一个空格，那么我们只需要用总的空格数除以空间个数，能除尽最好，说明能平均分配，除不尽的话就多加个空格放在左边的空间里，以此类推，具体实现过程还是看代码吧：



```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            int j = i, len = 0;
            while (j < words.size() && len + words[j].size() + j - i <= L) {
                len += words[j++].size();
            }
            string out;
            int space = L - len;
            for (int k = i; k < j; ++k) {
                out += words[k];
                if (space > 0) {
                    int tmp;
                    if (j == words.size()) { 
                        if (j - k == 1) tmp = space;
                        else tmp = 1;
                    } else {
                        if (j - k - 1 > 0) {
                            if (space % (j - k - 1) == 0) tmp = space / (j - k - 1);
                            else tmp = space / (j - k - 1) + 1;
                        } else tmp = space;
                    }
                    out.append(tmp, ' ');
                    space -= tmp;
                }
            }
            res.push_back(out);
            i = j;
        }
        return res;
    }
};
```

### 方法二

```cpp

```

### 方法三

```cpp

```

