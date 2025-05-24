#include<iostream>
#include<string>
#define MAXSIZE 5
using namespace std;

class Stack{
    int top,noofpops;
    int stack[MAXSIZE];
    string yesorno,eventlistener;
    public:
    Stack(){
        top=-1;
    }
    bool isEmpty()
    {
        return top==-1;
    }

    bool isFull(){
        return top==MAXSIZE-1;
    }

    void push(int data)
    {
        if(isFull()){
            cout<<"Its full bruv"<<endl;
            return;
        }
        else if(isEmpty())
        {
            top=0;
        }
        else 
        {
            top++;
        }
        stack[top]=data;
    }

    int pop()
    {
        int popped;
        if (isEmpty()){
            cout<<"Its empty bruv"<<endl;
            return -1;
        }
        else if(top==0){
            popped=stack[top];
            top=-1;
            return popped;
        }
        else
        {
            popped=stack[top];
            top--;
            return popped;
        }
    } 
    
    void display(){
        cout<<"Your stack is "<<endl;
        for(int i=0;i<MAXSIZE;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
        cout<<"You wish to pop?"<<endl;
        cin>>yesorno;
        if(yesorno=="Yes"||yesorno=="yes"||yesorno=="YES")
        {
            cout<<"Enter the no of pops you want"<<endl;
            cin>>noofpops;
            for(int i=0;i<noofpops;i++){
            cout<<"Press \"GO\" for every pop"<<endl;
            cin>>eventlistener;
            if(eventlistener=="GO"){
                int poppp=pop();
                cout<<"The popped value is "<<poppp<<endl;
            }
        }
        }
    }
};

int main(){
    int stack;
    Stack s;
    cout<<"We have made a stack, enter values for it"<<endl;
    for(int i=0;i<MAXSIZE;i++){
     cin>>stack;
     s.push(stack);
    }
    s.display();
    return 0;
}