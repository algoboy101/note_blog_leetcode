---
title: "[0037] Sudoku Solver"
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
date: 2020-01-01 00:00:37
---

## 题目描述

> 编写一个程序，通过已填充的空格来解决数独问题。 
> 
> 一个数独的解法需遵循如下规则： 
> 
> 
> 数字 1-9 在每一行只能出现一次。 
> 数字 1-9 在每一列只能出现一次。 
> 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 
> 
> 
> 空白格用 '.' 表示。 
> 
> 
> 
> 一个数独。 
> 
> 
> 
> 答案被标成红色。 
> 
> Note: 
> 
> 
> 给定的数独序列只包含数字 1-9 和字符 '.' 。 
> 你可以假设给定的数独只有唯一解。 
> 给定数独永远是 9x9 形式的。 
> 
> Related Topics 哈希表 回溯算法

## 题目代码

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
    }
};
```

## 解析

这道求解数独的题是在之前那道 Valid Sudoku 的基础上的延伸，之前那道题让我们验证给定的数组是否为数独数组，这道让求解数独数组，跟此题类似的有 Permutations，Combinations， N-Queens 等等，其中尤其是跟 N-Queens 的解题思路及其相似，对于每个需要填数字的格子带入1到9，每代入一个数字都判定其是否合法，如果合法就继续下一次递归，结束时把数字设回 '.'，判断新加入的数字是否合法时，只需要判定当前数字是否合法，不需要判定这个数组是否为数独数组，因为之前加进的数字都是合法的，这样可以使程序更加高效一些，整体思路是这样的，但是实现起来可以有不同的形式。一种实现形式是递归带上横纵坐标，由于是一行一行的填数字，且是从0行开始的，所以当i到达9的时候，说明所有的数字都成功的填入了，直接返回 ture。当j大于等于9时，当前行填完了，需要换到下一行继续填，则继续调用递归函数，横坐标带入 i+1。否则看若当前数字不为点，说明当前位置不需要填数字，则对右边的位置调用递归。若当前位置需要填数字，则应该尝试填入1到9内的所有数字，让c从1遍历到9，每当试着填入一个数字，都需要检验是否有冲突，使用另一个子函数 isValid 来检验是否合法，假如不合法，则跳过当前数字。若合法，则将当前位置赋值为这个数字，并对右边位置调用递归，若递归函数返回 true，则说明可以成功填充，直接返回 true。不行的话，需要重置状态，将当前位置恢复为点。若所有数字都尝试了，还是不行，则最终返回 false。检测当前数组是否合法的原理跟之前那道 Valid Sudoku 非常的相似，但更简单一些，因为这里只需要检测新加入的这个数字是否会跟其他位置引起冲突，分别检测新加入数字的行列和所在的小区间内是否有重复的数字即可，参见代码如下：



### 方法一

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
    bool helper(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j >= 9) return helper(board, i + 1, 0);
        if (board[i][j] != '.') return helper(board, i, j + 1);
        for (char c = '1'; c <= '9'; ++c) {
            if (!isValid(board, i , j, c)) continue;
            board[i][j] = c;
            if (helper(board, i, j + 1)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int i, int j, char val) {
        for (int x = 0; x < 9; ++x) {
            if (board[x][j] == val) return false;
        }
        for (int y = 0; y < 9; ++y) {
            if (board[i][y] == val) return false;
        }
        int row = i - i % 3, col = j - j % 3;
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (board[x + row][y + col] == val) return false;
            }
        }
        return true;
    }
};
```

### 方法二

还有另一种递归的写法，这里就不带横纵坐标参数进去，由于递归需要有 boolean 型的返回值，所以不能使用原函数。因为没有横纵坐标，所以每次遍历都需要从开头0的位置开始，这样无形中就有了大量的重复检测，导致这种解法虽然写法简洁一些，但击败率是没有上面的解法高的。这里的检测数组冲突的子函数写法也比上面简洁不少，只用了一个 for 循环，用来同时检测行列和小区间是否有冲突，注意正确的坐标转换即可，参见代码如下：



```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
    bool helper(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') continue;
                for (char c = '1'; c <= '9'; ++c) {
                    if (!isValid(board, i, j, c)) continue;
                    board[i][j] = c;
                    if (helper(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& board, int i, int j, char val) {
        for (int k = 0; k < 9; ++k) {
            if (board[k][j] != '.' && board[k][j] == val) return false;
            if (board[i][k] != '.' && board[i][k] == val) return false;
            int row = i / 3 * 3 + k / 3, col = j / 3 * 3 + k % 3;
            if (board[row][col] != '.' && board[row][col] == val) return false;
        }
        return true;
    }
};
```


Github 同步地址：

https://github.com/grandyang/leetcode/issues/37

类似题目：

Valid Sudoku

Unique Paths III

