//
//  10845.cpp
//  algorithm
//
//  Created by 윤상호 on 2020/04/04.
//  Copyright © 2020 윤상호. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

const int MAX_LENGTH = 100000;
const int MAX_ORDER_CNT = 10000;

struct Queue {
private:
    int array[MAX_LENGTH] = { 0, };
    int head = 0; // 처음에는 비어있는 값을 가르키는 head 인덱스
    int tail = 0; // 값이 들어갈 인덱스
    bool isHeadEmpty = true;
    int length = MAX_LENGTH;
    
public:
    
    void push(int X) {
        // 처음
        if (head == tail && isHeadEmpty == true) {
            array[tail] = X;
            isHeadEmpty = false;
            tail = (tail + 1) % length;
        
        // 예외pu
        } else if (head == tail && isHeadEmpty == false) {
            printf("overflow");
        } else {
            array[tail] = X;
            tail = (tail + 1) % length;
        }
    }
    
    void pop() {
        if(isEmpty()) {
            printf("-1");
        } else if (isHeadEmpty == true) {
            printf("-1");
        } else {
            printf("%d", array[head]);
            array[head] = 0;
            head = (head + 1) % length;
            
            if (head == tail) {
                isHeadEmpty = true;
            }
        }
    }
    
    int size() {
        if (head > tail) {
            return (head - tail);
        } else if (head < tail) {
            return (tail - head);
        } else {
            return 0;
        }
    }
    
    bool isEmpty() {
        if (size() == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    int front() {
        if (isHeadEmpty) {
            return -1;
        } else {
            return array[head];
        }
    }
    
    int back() {
        if (isHeadEmpty) {
            return -1;
        } else {
            return array[tail-1];
        }
    }
};

int main() {
    
    Queue q;
    int cnt; // 명령의 수
    char str[6];
    
    scanf("%d", &cnt);
    
    if (cnt > MAX_ORDER_CNT) {
        return 0;
    }
    
    for (int i=0; i<cnt; i++) {
        scanf("%s", str);
        if (strcmp(str, "push") == 0) {
            int x;
            scanf("%d", &x);
            q.push(x);
        } else if(strcmp(str, "pop") == 0) {
            q.pop();
        } else if(strcmp(str, "size") == 0) {
            printf("%d", q.size());
        } else if(strcmp(str, "front") == 0) {
            printf("%d", q.front());
        } else if(strcmp(str, "back") == 0) {
            printf("%d", q.back());
        } else if(strcmp(str, "empty") == 0) {
            if (q.isEmpty()) {
                printf("1");
            } else {
                printf("0");
            }
        } else {
            return 0;
        }
    }
    
    return 0;
}
