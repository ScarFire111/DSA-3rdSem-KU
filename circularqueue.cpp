
#include<iostream>
#include<string>
#define MAXSIZE 6
using namespace std;

class CircularQueue{
    int queue[MAXSIZE];
    int front,rear;
    string yesorno;
    public:
    CircularQueue(){
        front=0;rear=0;
    }
    bool isFull(){
        return (front==(rear+1)%MAXSIZE);
    }
    bool isEmpty(){
        return rear==front;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"The queue is full "<<endl;
        }
        else{
            rear=(rear+1)%MAXSIZE;
            queue[rear]=data;
        }    
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Its empty, nothing left to dequeue"<<endl;
            return -1;
        }
        else {
            front=(front+1)%MAXSIZE;
            int dequeued=queue[front];
            return dequeued;
        }
    }
    void display(){
        cout<<"Your circular queue is "<<endl;
        for(int i=(front + 1) % MAXSIZE;i!=(rear+1)%MAXSIZE;i=(i+1)%MAXSIZE){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
        cout<<"You wish to dequeue?"<<endl;
        cin>>yesorno;
        while(yesorno!="No"&&yesorno!="no"){
            int popped=dequeue();
            if(popped==-1){
            	break;
			}
			cout<<"You dequeued this: "<<popped<<endl;
            cout<<"Press 'Yes' to continue dequeing"<<endl;
            cin>>yesorno;
        }
    }
};

int main(){
    int data;
    CircularQueue c;
    cout<<"For a queue of size "<<MAXSIZE-1<<" enter the values below "<<endl;
    for(int i=0;i<MAXSIZE-1;i++){
        cin>>data;
        c.enqueue(data);
    }
    c.display();
    return 0;
}
