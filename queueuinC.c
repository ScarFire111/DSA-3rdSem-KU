#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 5
int front = -1;
int rear = -1;
int stack[SIZE];
bool isEmpty(){
    return (front == -1 && rear == -1);
}
bool isFull(){
  return rear==SIZE-1;
}

void enqueue(int data){
    if(isEmpty()){
        front=rear=0;
    }
    else if(isFull()){
        printf("There is nothing left to enqueue, the queue is full \n");
    }
    else{
        rear++;
    }
    stack[rear]=data;    
}

int dequeue(){
    int dequeued=0;
   if(isEmpty()){
    printf("The stack is empty, you cant pop \n");
    return -1;
   }
   else if(front==rear){
    dequeued=stack[front];
    return front;
   }
   else {
    dequeued=stack[front];
    front++;
    return front;
   }
}

void display(){
    printf("The stack is \n");
    for(int i=0;i<SIZE;i++){
        printf("%d \t",stack[i]);
    }
    printf("\n");
    for(int i=0;i<2;i++){
    int popped=dequeue();
    printf("You dequeued: %d \n", popped );}
}

int main()
{
    enqueue(5);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    enqueue(11);
    display();
}