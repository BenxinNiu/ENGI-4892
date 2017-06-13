#include <iostream>
#include "LLqueue.h"
using namespace std;

void instruction();

int main(){
  int num;
  char com;
  LLqueue *Q=new LLqueue();cout<<endl;
 instruction();
  while(1>0){
cin>>com;
  if(com=='A'){
    cout<<"Enter an integer"<<endl;
    cin>>num;
    Q->enqueue(num);
   instruction();
  }
  if(com=='B'){
    int removed;
    try{
        removed= Q->dequeue();
    }
    catch(ErrorMsg &msg){
      cerr<<msg.msg<<endl;
    }
    cout<<removed<<" has been removed!!!!"<<endl;
   instruction();
  }
  if(com=='C'){
   if (Q->isEmpty())
   cout<<"It is empty"<<endl;
   else
   cout<<"It is not empty"<<endl;
   instruction();
  }
  if(com=='P'){
   Q->print();
   instruction();
  }
  }
  return 0;
}

void instruction(){
  cout<<endl;
  cout<<"Press A to add to this lovely queue"<<endl;
  cout<<"Press B to remove from the head of queue"<<endl;
  cout<<"Press C to see if queue is empty"<<endl;
  cout<<"Press P to print the queue"<<endl;
  cout<<"ctrl + C to exit"<<endl;
}
