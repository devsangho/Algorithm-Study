//
//  main.cpp
//  algorithm
//
//  Created by 윤상호 on 2020/03/29.
//  Copyright © 2020 윤상호. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

struct Node {
public:
    int value;
    bool isNumber;
};

int main() {
    char str[31] = { 0, };
    stack<Node> stack;
    int i = 0;
    int sum = 0;
    Node tmp;
    
    scanf("%s", str);
    
    while (str[i]) {
        switch (str[i]) {
            case '(':
            case '[':
                sum=0;
                tmp.value = str[i];
                tmp.isNumber = false;
                stack.push(tmp);
                break;
            case ')':
                tmp = stack.top();
                if (tmp.isNumber) {
                    sum = 0;
                    while (!stack.empty() && stack.top().isNumber) {
                        sum += stack.top().value;
                        stack.pop();
                    }
                    stack.pop();
                    tmp.value = sum * 2;
                    tmp.isNumber = true;
                    stack.push(tmp);
                } else if(!tmp.isNumber && tmp.value == '(') {
                    sum = 2;
                    tmp.value = sum;
                    tmp.isNumber = true;
                    stack.pop();
                    stack.push(tmp);
                } else {
                    printf("0");
                    return 0;
                }
                
                break;
            case ']':
                tmp = stack.top();
                if (tmp.isNumber) {
                    sum = 0;
                    while (!stack.empty() && stack.top().isNumber) {
                        sum += stack.top().value;
                        stack.pop();
                    }
                    stack.pop();
                    tmp.value = sum * 3;
                    tmp.isNumber = true;
                    stack.push(tmp);
                } else if(!tmp.isNumber && tmp.value == '[') {
                    sum = 3;
                    tmp.value = sum;
                    tmp.isNumber = true;
                    stack.pop();
                    stack.push(tmp);
                } else {
                    printf("0");
                    return 0;
                }
                
                break;
                
            default:
                printf("0");
                return 0;
                break;
        }
        
        i++;
    }
    
    sum = 0;
    
    while (!stack.empty()) {
        if (stack.top().isNumber) {
            sum += stack.top().value;
            stack.pop();
        } else {
            printf("0");
            return 0;
        }
    }
    
    printf("%d\n", sum);
    
    return 0;
}
