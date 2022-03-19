#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef struct Deque{
    int data;
    struct Deque* ptr;
}Deque;

int size = 0;


Deque* head = NULL;
Deque* tail = NULL;

Deque* createNode(int ele){
    Deque* newnode = (Deque*)malloc(sizeof(Deque));
    newnode->data = ele;
    newnode->ptr = NULL;
    return newnode;
}

Deque* XOR(Deque* a ,Deque* b){
    return (Deque*)((uintptr_t)(a)^(uintptr_t)(b));
}

int Empty(){
    if(head==NULL && tail==NULL){
        return 1;
    }
    return 0;
}

void push_Back(int ele){
    Deque* newnode = createNode(ele);
    if(tail==NULL){
        tail = newnode;
        head = newnode;
    }else{
        tail->ptr = XOR(newnode,tail->ptr);
        newnode->ptr = XOR(newnode->ptr,tail);
        tail = newnode;
    }
    size++;

}


void push_Front(int ele){
    Deque* newnode = createNode(ele);
    if(head==NULL){
        head = newnode;
        tail = newnode;
    }else{
        head->ptr = XOR(head->ptr,newnode);
        newnode->ptr = XOR(newnode->ptr,head);
        head = newnode;
    }
    size++;

}



void pop_Front(){
    if(size==0){
        printf("Deque is Empty\n");
    }
    else if(size==1){
        head = NULL;
        tail = NULL;
        size--;
    }else{
        Deque *temp;
        temp = head->ptr;
        temp->ptr = XOR(temp->ptr,head);
        free(head);
        head = temp;
        size--;

    }
}


void pop_Back(){
    if(size==0){
        printf("Deque is Empty\n");
    }
    else if(size==1){
        head = NULL;
        tail = NULL;
        size--;
    }else{
        Deque *temp;
        temp = tail->ptr;
        temp->ptr = XOR(temp->ptr,tail);
        free(tail);
        tail = temp;
        size--;
    }
}


void get_front(){
    if(!Empty()){
        printf("first element of deque is  %d\n",head->data);
    }else{
        printf("deque is empty\n");
    }
    return ;
}

void get_back(){
    if(!Empty()){
        printf("last element of deque is %d\n",tail->data);
    }else{
        printf("deque is empty\n");
    }
}


void get_sec_front(){
    if(size>=2){
        Deque *temp;
        temp = head->ptr;
        printf("second element of deque is %d\n",temp->data);
        temp = NULL;
    }else{
        printf("deque elements are less than 2\n");
    }
}

void get_sec_back(){
    if(size>=2){
        Deque *temp;
        temp = tail->ptr;
        printf("last second element of deque is %d\n",temp->data);
        temp = NULL;
    }else{
        printf("deque elements are less than 2\n");
    }
}

int Size(){
    return size;
}






int main()
{
	push_Back(10);
	push_Back(0);
	printf("size of Deque:%d\n",Size());
	pop_Back();
	pop_Front();
	pop_Front();
	pop_Front();
	pop_Back();
	printf("size of Deque:%d\n",Size());

	push_Back(10);
	push_Back(20);
	push_Front(100);
	push_Front(200);
	printf("size of Deque:%d\n",Size());
	pop_Back();
	pop_Front();
	pop_Front();
	pop_Front();
	pop_Back();
	pop_Front();
	push_Back(10);
	push_Back(20);
	push_Front(100);
	push_Front(200);
	get_front();
	get_back();
	get_sec_front();
	get_sec_back();
	printf("size of Deque:%d\n",Size());

}

