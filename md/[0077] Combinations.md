---
title: "[0077] Combinations"
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
date: 2020-01-01 00:01:17
---

## 题目描述

> 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
> 
> 示例: 
> 
> 输入: n = 4, k = 2
> 输出:
> [
> [2,4],
> [3,4],
> [2,3],
> [1,2],
> [1,3],
> [1,4],
> ] 
> Related Topics 回溯算法

## 题目代码

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
    }
};
```

## 解析

### 方法一

这道题让求1到n共n个数字里k个数的组合数的所有情况，还是要用深度优先搜索DFS来解，根据以往的经验，像这种要求出所有结果的集合，一般都是用DFS调用递归来解。那么我们建立一个保存最终结果的大集合res，还要定义一个保存每一个组合的小集合out，每次放一个数到out里，如果out里数个数到了k个，则把out保存到最终结果中，否则在下一层中继续调用递归。网友u010500263的博客里有一张图很好的说明了递归调用的顺序，请点击这里。根据上面分析，可写出代码如下：

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out;
        helper(n, k, 1, out, res);
        return res;
    }
    void helper(int n, int k, int level, vector<int>& out, vector<vector<int>>& res) {
        if (out.size() == k) {res.push_back(out); return;}
        for (int i = level; i <= n; ++i) {
            out.push_back(i);
            helper(n, k, i + 1, out, res);
            out.pop_back();
        }
    }
};
```

### 方法二

对于n = 5, k = 3, 处理的结果如下：

1 2 3
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5

 

我们再来看一种递归的写法，此解法没用helper当递归函数，而是把本身就当作了递归函数，写起来十分的简洁，也是非常有趣的一种解法。这个解法用到了一个重要的性质 C(n, k) = C(n-1, k-1) + C(n-1, k)，这应该在我们高中时候学排列组合的时候学过吧，博主也记不清了。总之，翻译一下就是，在n个数中取k个数的组合项个数，等于在n-1个数中取k-1个数的组合项个数再加上在n-1个数中取k个数的组合项个数之和。这里博主就不证明了，因为我也不会，就直接举题目中的例子来说明吧：

C(4, 2) = C(3, 1) + C(3, 2)

我们不难写出 C(3, 1) 的所有情况：[1], [2], [3]，还有 C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]。我们发现二者加起来为6，正好是 C(4, 2) 的个数之和。但是我们仔细看会发现，C(3, 2)的所有情况包含在 C(4, 2) 之中，但是 C(3, 1) 的每种情况只有一个数字，而我们需要的结果k=2，其实很好办，每种情况后面都加上4，于是变成了：[1, 4], [2, 4], [3, 4]，加上C(3, 2) 的所有情况：[1, 2], [1, 3], [2, 3]，正好就得到了 n=4, k=2 的所有情况了。参见代码如下：

 
```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n || k < 0) return {};
        if (k == 0) return {{}};
        vector<vector<int>> res = combine(n - 1, k - 1);
        for (auto &a : res) a.push_back(n);
        for (auto &a : combine(n - 1, k)) res.push_back(a);
        return res;
    }
};
```

### 方法三

我们再来看一种迭代的写法，也是一种比较巧妙的方法。这里每次先递增最右边的数字，存入结果res中，当右边的数字超过了n，则增加其左边的数字，然后将当前数组赋值为左边的数字，再逐个递增，直到最左边的数字也超过了n，停止循环。对于n=4, k=2时，遍历的顺序如下所示：

0 0 #initialization
1 0
1 1 
1 2 #push_back
1 3 #push_back
1 4 #push_back
1 5
2 5
2 2 
2 3 #push_back
2 4 #push_back
...
3 4 #push_back
3 5
4 5
4 4
4 5
5 5 #stop 

```cpp
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out(k, 0);
        int i = 0;
        while (i >= 0) {
            ++out[i];
            if (out[i] > n) --i;
            else if (i == k - 1) res.push_back(out);
            else {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
};
```

类似题目：

Combination Sum

Permutations

 