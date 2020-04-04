//
//  CircularQueue.cpp
//  algorithm
//
//  Created by 윤상호 on 2020/04/04.
//  Copyright © 2020 윤상호. All rights reserved.
//

#include <stdio.h>
#include <math.h>

using namespace std;

const int LENGTH = 4;

struct Queue {
private:
    int array[LENGTH] = { 0, };
    int head = 0;
    int rear = 0;
    
public:
    void EnQueue(int input) {
        if (head == (rear + 1) % LENGTH) { // 오버플로우의 경우
            printf("-1\n");
        } else {
            rear ++;
            rear = rear % LENGTH;
            array[(rear)] = input;
        }
    }
    
    int DeQueue() {
        if (size() == 0) { // 언더플로우의 경우
            printf("-1");
            return -1;
        } else {
            int tmp = array[head];
            head ++;
            head = head % LENGTH;
            array[head] = NULL;
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
        if (head > rear) {
            return (LENGTH-head) + rear;
        } else if (head < rear) {
            return (LENGTH-rear) + head;
        } else { // head == rear
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
};

int main() {
    
    Queue q;
    q.DeQueue();
    q.EnQueue(0);
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    
    q.DeQueue();
    q.EnQueue(4);
    q.EnQueue(5);
    
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    
    return 0;
}
