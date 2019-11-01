/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

bool isValid(char * s){

    int orgin = 0;
    int len = strlen(s);
    if (len % 2 == 1) {
        return false;
    }
    char* stack=(char*)malloc(len / 2 + 1);
    memset(stack, 0, len / 2 + 1);

/* if 8ms 6.9MB 19/11/01 14:00
    for (int i = 0; i < len; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            *(stack + orgin) = s[i];
            orgin += 1;             
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (orgin == 0) {
                return false;
            } else if (*(stack + orgin - 1) == (s[i] - 1) || *(stack + orgin - 1) == (s[i] - 2)) {
                orgin -= 1;
            } else {
                return false;
            }            
        } else {
        }
    }
    if (orgin == 0) {
        return true;
    } else {
        return false;
    }
 */
// switch 4ms 6.8MB 19/11/01 14:00
    for (int i = 0; i < len; i++) {
        switch (s[i]) {
        case '(':
        case '[':
        case '{':
            *(stack + orgin) = s[i];
            orgin += 1;           
            break;
        case ')':
        case ']':
        case '}':
            if (orgin == 0) {
                return false;
            } else if (*(stack + orgin - 1) == s[i] - 1 || *(stack + orgin - 1) == s[i] - 2) {
                orgin -= 1;
            } else {
                return false;
            }
            break;              
        default:
            break;
        }
    }
    if (orgin == 0) {
        return true;
    } else {
        return false;
    }
}


// @lc code=end

