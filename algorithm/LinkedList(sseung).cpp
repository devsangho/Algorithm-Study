//
//  LinkedList(sseung).cpp
//  algorithm
//
//  Created by 홍승의 on 2020/04/11.
//  Copyright © 2020 홍승의. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};


struct LinkedList{
    Node * head = NULL;
    void insert(int idx, Node *node){
        if(head == NULL){
            head = node;
        } else if(idx == 0){
            Node * tmp = head;
            head = node;
            node -> next = tmp;
        } else {
            Node * current = head;
            for(int i = 0; i < idx - 1; ++i){
                current = current -> next;
            }
            Node *tmp = current -> next;
            current -> next = node;
            node -> next = tmp;
        }
    }
    void orderlyInsert(Node *node){
        if(head == NULL){
            head = node;
        } else {
            Node * current = head;
            Node * before = head;
            
            while(current != NULL && current->data <= node->data){
                before = current;
                current = current->next;
            }
            
            Node *tmp = before -> next;
            before -> next = node;
            node -> next = tmp;
            
        }
    }
    void remove(int idx){
        //예외처리 해주세요 size가 idx 보다 작을 때
        if(idx == 0){
            Node * tmp = head -> next;
            delete head;
            head = tmp;
        }
        else{
            Node * before = head;
            for(int i = 0; i < idx - 1; ++i){
                before = before -> next;
            }
            
            Node *tmp = before -> next -> next;
            delete before -> next;
            before -> next = tmp;
        }
    }
    int searchByData(int data){
        int idx = 0;
        Node * current = head;
        while(current != NULL && current->data != data){
            idx += 1;
            current = current->next;
        }
        return idx;
    }
    int searchByIdx(int idx){
        int cnt = 0;
        Node *current = head;
        while (current != NULL && cnt != idx) {
            cnt ++;
            current = current -> next;
        }
        
        return current -> data;
    }
    
};

int main() {
    
    LinkedList l;
    Node * node = new Node();
    Node * node2 = new Node();
    Node * node3 = new Node();
    
    node->data = 1;
    node2->data = 4;
    node3->data = 2;
    
    l.insert(0,node);
    l.insert(1,node2);
    l.orderlyInsert(node3);
    printf("%d", l.searchByIdx(1));
    printf("%d", l.searchByData(2));
    
    delete node;
    delete node2;
    
    
    
    return 0;
}
