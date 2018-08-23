#coding:utf-8

'''
实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

示例 1：
输入: "Hello"
输出: "hello"

示例 2：
输入: "here"
输出: "here"

示例 3：
输入: "LOVELY"
输出: "lovely"
'''


def toLowerCase(str):
    """
    :type str: str
    :rtype: str
    """
    res = ''
    for i in str:
        if ord(i) >= 65 and ord(i) <= 90:
            res += chr(ord(i) + 32)
        else:
            res += i
    return res

if __name__ == '__main__':
    print toLowerCase('al&phaBET')