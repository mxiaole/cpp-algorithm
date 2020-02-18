//
// Created by cody on 2020-02-18.
//

#ifndef ALGORITHM_STRING_H
#define ALGORITHM_STRING_H

#include <string>
#include <iostream>

// 将数字转为字符串
void convertNumToStr(int num);

// 字符串逆序
void reverseStr(std::string str);

// 字符串逆序单词内部顺序不变
void reverseWords(std::string str);

// strcpy实现
void stringCopy(std::string str);
// strstr

// 两个字符串的最长公共子串
int LongestCommonStr(std::string s1, std::string s2);

// 两个字符串的最长公共子序列
int longestCommonSubstr(std::string s1, std::string s2);


#endif //ALGORITHM_STRING_H
