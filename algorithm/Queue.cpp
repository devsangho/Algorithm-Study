//
//  Queue.cpp
//  algorithm
//
//  Created by 윤상호 on 2020/04/04.
//  Copyright © 2020 윤상호. All rights reserved.
//

#include <stdio.h>

using namespace std;

struct Queue {
private:
    int array[30] = { 0, };
    int head = 0;
    int rear = 0;
    
public:
    
    void EnQueue(int input) {
        if (size() >= 30) {
            printf("-1\n");
        } else {
            array[rear] = input;
            rear++;
        }
    }
    
    int DeQueue() {
        if (size() == 0) {
            printf("-1");
            return -1;
        } else {
            int tmp = array[head];
            array[head] = NULL;
            head ++;
            return tmp;
        }
    }
    
    int getHead() {
        return array[head];
    }
    
    int getRear() {
        return array[rear];
    }
    
    int size() {
        return (rear - head);
    }
    
    bool isEmpty() {
        if (size() == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    
    Queue q;
    
    
    for (int i=0; i<32; i++) {
        q.EnQueue(i);
        printf("head: %d\n", q.getHead());
        printf("rear: %d\n", q.getRear());
    }
    
    printf("kkkkkkkkkkkkkkkkkk\n");
    for (int i=0; i<30; i++) {
        q.DeQueue();
        printf("head: %d\n", q.getHead());
        printf("size: %d\n", q.size());
    }
    
    q.EnQueue(50);
    printf("head: %d\n", q.getHead());
    
    return 0;
}
