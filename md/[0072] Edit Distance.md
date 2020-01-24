---
title: "[0072] Edit Distance"
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
date: 2020-01-01 00:01:12
---

## 题目描述

> 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。 
> 
> 你可以对一个单词进行如下三种操作： 
> 
> 
> 插入一个字符 
> 删除一个字符 
> 替换一个字符 
> 
> 
> 示例 1: 
> 
> 输入: word1 = "horse", word2 = "ros"
> 输出: 3
> 解释: 
> horse -> rorse (将 'h' 替换为 'r')
> rorse -> rose (删除 'r')
> rose -> ros (删除 'e')
> 
> 
> 示例 2: 
> 
> 输入: word1 = "intention", word2 = "execution"
> 输出: 5
> 解释: 
> intention -> inention (删除 't')
> inention -> enention (将 'i' 替换为 'e')
> enention -> exention (将 'n' 替换为 'x')
> exention -> exection (将 'n' 替换为 'c')
> exection -> execution (插入 'u')
> 
> Related Topics 字符串 动态规划

## 题目代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        
    }
};
```

## 解析

### 方法一

这道题让求从一个字符串转变到另一个字符串需要的变换步骤，共有三种变换方式，插入一个字符，删除一个字符，和替换一个字符。题目乍眼一看并不难，但是实际上却暗藏玄机，对于两个字符串的比较，一般都会考虑一下用 HashMap 统计字符出现的频率，但是在这道题却不可以这么做，因为字符串的顺序很重要。还有一种比较常见的错误，就是想当然的认为对于长度不同的两个字符串，长度的差值都是要用插入操作，然后再对应每位字符，不同的地方用修改操作，但是其实这样可能会多用操作，因为删除操作有时同时可以达到修改的效果。比如题目中的例子1，当把 horse 变为 rorse 之后，之后只要删除第二个r，跟最后一个e，就可以变为 ros。实际上只要三步就完成了，因为删除了某个字母后，原来左右不相连的字母现在就连一起了，有可能刚好组成了需要的字符串。所以在比较的时候，要尝试三种操作，因为谁也不知道当前的操作会对后面产生什么样的影响。对于当前比较的两个字符 word1[i] 和 word2[j]，若二者相同，一切好说，直接跳到下一个位置。若不相同，有三种处理方法，首先是直接插入一个 word2[j]，那么 word2[j] 位置的字符就跳过了，接着比较 word1[i] 和 word2[j+1] 即可。第二个种方法是删除，即将 word1[i] 字符直接删掉，接着比较 word1[i+1] 和 word2[j] 即可。第三种则是将 word1[i] 修改为 word2[j]，接着比较 word1[i+1] 和 word[j+1] 即可。分析到这里，就可以直接写出递归的代码，但是很可惜会 Time Limited Exceed，所以必须要优化时间复杂度，需要去掉大量的重复计算，这里使用记忆数组 memo 来保存计算过的状态，从而可以通过 OJ，注意这里的 insertCnt，deleteCnt，replaceCnt 仅仅是表示当前对应的位置分别采用了插入，删除，和替换操作，整体返回的最小距离，后面位置的还是会调用递归返回最小的，参见代码如下：


```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n));
        return helper(word1, 0, word2, 0, memo);
    }
    int helper(string& word1, int i, string& word2, int j, vector<vector<int>>& memo) {
        if (i == word1.size()) return (int)word2.size() - j;
        if (j == word2.size()) return (int)word1.size() - i;
        if (memo[i][j] > 0) return memo[i][j];
        int res = 0;
        if (word1[i] == word2[j]) {
            return helper(word1, i + 1, word2, j + 1, memo);
        } else {
            int insertCnt = helper(word1, i, word2, j + 1, memo);
            int deleteCnt = helper(word1, i + 1, word2, j, memo);
            int replaceCnt = helper(word1, i + 1, word2, j + 1, memo);
            res = min(insertCnt, min(deleteCnt, replaceCnt)) + 1;
        }
        return memo[i][j] = res;
    }
};
```

### 方法二

根据以往的经验，对于字符串相关的题目且求极值的问题，十有八九都是用动态规划 Dynamic Programming 来解，这道题也不例外。其实解法一的递归加记忆数组的方法也可以看作是 DP 的递归写法。这里需要维护一个二维的数组 dp，其大小为 mxn，m和n分别为 word1 和 word2 的长度。dp[i][j] 表示从 word1 的前i个字符转换到 word2 的前j个字符所需要的步骤。先给这个二维数组 dp 的第一行第一列赋值，这个很简单，因为第一行和第一列对应的总有一个字符串是空串，于是转换步骤完全是另一个字符串的长度。跟以往的 DP 题目类似，难点还是在于找出状态转移方程，可以举个例子来看，比如 word1 是 "bbc"，word2 是 "abcd"，可以得到 dp 数组如下：

 

  Ø a b c d
Ø 0 1 2 3 4
b 1 1 1 2 3
b 2 2 1 2 3
c 3 3 2 1 2
 

通过观察可以发现，当 word1[i] == word2[j] 时，dp[i][j] = dp[i - 1][j - 1]，其他情况时，dp[i][j] 是其左，左上，上的三个值中的最小值加1，其实这里的左，上，和左上，分别对应的增加，删除，修改操作，具体可以参见解法一种的讲解部分，那么可以得到状态转移方程为：

dp[i][j] =      /    dp[i - 1][j - 1]                                                                   if word1[i - 1] == word2[j - 1]

                  \    min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1            else

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
```

ithub 同步地址：

https://github.com/grandyang/leetcode/issues/72

 

类似题目：

One Edit Distance

Delete Operation for Two Strings

Minimum ASCII Delete Sum for Two Strings