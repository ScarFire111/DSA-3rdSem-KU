#include<iostream>
#include<string>
#define MAXSIZE 5
using namespace std;

class Stack{
    protected:
    int stacksize[MAXSIZE];
    int top;
    virtual void push(int data){}
    virtual int pop(){return -1;}
    virtual bool isEmpty(){return -1;}
    virtual bool isFull(){return -1;}

};

class StackOverflow:public Stack{
    public:
    //void isEmpty() override {
        //if (top==-1){
           // cout<<"The stack is empty"<<endl;
        //dont do this shit, we are big boys now, we use bools
    
   bool isFull() override{
    return top==MAXSIZE-1;
   }
   bool isEmpty() override{
    return top==-1;
   }
    void push(int data) override{
        if (isFull()){
            cout<<"Sorry can not take "<<data<<" Stack is full"<<endl;
        }
        else {
            top++;
            stacksize[top]=data;
        }
    }
    int pop() override{
        if(isEmpty()){
            cout<<"Sorry cant pop, stack is empty"<<endl;
            return -1;
        }
        else{
            int popped=stacksize[top];
            top--;
            return popped;
        }
    }
};

int main()
{
    StackOverflow s;
    int data,noofpops;
    string yesorno;
    cout<<"Enter your stack"<<endl;
    
    for(int i=0;i<MAXSIZE;i++)
    {
        cin>>data;
        s.push(data);
        
    }


    cout<<"You wish to pop?"<<endl;
    cin>>yesorno;
    if(yesorno=="YES"|| yesorno=="Yes"||yesorno=="yes")
    {
        cout<<"Number of pops?"<<endl;
        cin>>noofpops;
        for(int i=0;i<noofpops;i++){
         int popped=s.pop();
         cout<<"The popped value is "<<popped<<endl; 
        }
    }

return 0;
}