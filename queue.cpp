#include<iostream>
#include<string>
#define MAXSIZE 5
using namespace std;

class QueueOverflow{
	int stack[MAXSIZE];
	int rear,front,noofpops;
	string yesorno,eventlistener;
	public:
		QueueOverflow(){
			front=-1;
			rear=-1;
		}
		bool isFull(){
			return rear==MAXSIZE-1;
		}
		bool isEmpty(){
			if (front==-1 && rear==-1){
				return true;
			}
			else
			{return false;
			}
			
		}
		void enqueue(int data)
		{
			if(isFull()){
				cout<<"The queue is full"<<endl;
			}
			else if(isEmpty()){
				front=rear=0;
			}
			else{
				rear++;
			}
			stack[rear]=data;
			
		}
		int dequeue(){
			int dequeued=0;
		    if(isEmpty()){
		    	cout<<"Queue is empty, there is nothing left to dequeue"<<endl;
			}	
			else if(front==rear){
				dequeued=stack[front];
				front=rear=-1;
				return -1;
			}
			else{
			 dequeued=stack[front];
			 front++;
			}
			return dequeued;
		}
		
		void display()
		{
			cout<<"Your queue is "<<endl;
			for(int i=0;i<MAXSIZE;i++)
			{
				cout<<stack[i]<<" ";
			}
			cout<<endl;
			cout<<"You wish to dequeue?"<<endl;
			cin>>yesorno;
			if(yesorno=="Yes"||yesorno=="YES"||yesorno=="yes"){
				cout<<"Alright press 'go',first enter how many pops"<<endl;
				cin>>noofpops;
				for(int i=0;i<noofpops;i++)
				{
					if(isEmpty())
					{
						cout<<"Thats all of them mate"<<endl;
						break;
					}
					cout<<"Waiting for the go"<<endl;
					cin>>eventlistener;
					if(eventlistener=="go"){
					  int popped=dequeue();
					  cout<<"The popped file is "<<popped<<endl;
					}
					else{
						cout<<"Invalid command"<<endl;
					}
				}
				
			}
			
		}
};

int main()
{
	QueueOverflow q;
	int data;
	cout<<"we have made a queue, enter data into it mate"<<endl;
	for(int i=0;i<MAXSIZE+1;i++){
		cin>>data;
		q.enqueue(data);
	}
	q.display();
	return 0;
}
