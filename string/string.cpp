//
// Created by cody on 2020-02-18.
//
#include "string.h"
#include <vector>

std::string getString(const std::string &str, int begin, int end);

// 将数字转为字符串
// 13443转为字符串
// num % 10 得到最后一位数
// num / 10 得到减去了之后的数
void convertNumToStr(int num) {
    std::vector<char> v;
    while (num != 0) {
        int tmp = num % 10;
        v.push_back(tmp + '0');
        num = num / 10;
    }

    for (auto c: v) {
        std::cout << c << std::endl;
    }

}

// 字符串逆序
void reverseStr(std::string str) {
    int i = 0, j = str.size() - 1;

    while (i < j) {
        std::swap(str[i], str[j]);
        i++;
        j--;
    }

    for (auto c : str) {
        std::cout << c << "\t";
    }
    std::cout << std::endl;
}

// 翻转字符串，但是单词顺序不变
void reverseWords(std::string str) {
    int begin = 0; // 每个单词的起始位置
    int end = 0; // 每个单词的尾位置
    while (end < str.size()) {
        begin = end;
        while (end < str.size() && str[end] != ' ') {
            end++;
        }
        std::string word = getString(str, begin, end);
        reverseStr(word);
        end++;
    }
}

std::string getString(const std::string &str, int begin, int end) {// 获取单词
    std::string word = "";
    for (int i = begin; i < end; i++) {
        word += str[i];
    }
    return word;
}

void stringCopy(std::string str) {

}

/**
 * 两个字符串的最长公共子串：动态规划
 * dp[i][j] 表示必须把s1[i]和s2[j]当做公共子串最后一个字符的情况下，公共子串最长的长度
 */
int LongestCommonStr(std::string s1, std::string s2) {
    // 求解dp
    std::vector<std::vector<int>> dp(s1.size());
    for (int i = 0; i < dp.size(); i++) {
        dp[i].resize(s2.size());
    }

    int length1 = s1.size();
    int length2 = s2.size();

    for (int i = 0; i < length1; i++) {
        for (int j = 0; j < length2; j++) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0) { // 第一行和第一列单独处理
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // 输出dp
    // 遍历dp找到最大值
    int max = 0;
    for (auto i: dp) {
        for (auto j : i) {
            if (j > max) {
                max = j;
            }
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }

    return max;
}

int longestCommonSubstr(std::string s1, std::string s2) {
    // 定义dp数组
    std::vector<std::vector<int>> dp(s1.size());
    for (int i = 0; i < dp.size(); i++) {
        dp[i].resize(s2.size());
    }
    // 求解dp数组
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            } else {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {

                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    for (auto i:dp) {
        for (auto j : i) {
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }

    // 最大值出现在最后一个格子中
    return dp[s1.size() - 1][s2.size() - 1];

}