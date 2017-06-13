#include <iostream>
#include "QueueStack.h"
using namespace std;

QueueStack::QueueStack(LLqueue *p_top,LLqueue *p_bot){  // contrctor for stack
  top=p_top;
  bot=p_bot;
}
void QueueStack::push(int e){  // push an item to the top of the stack
  if(top!=0)
    top->enqueue(e);
}
int QueueStack::pop(){  // remove from the top of stack
int num;
  if(top!=0)
num=top->dequeue();
else throw ErrorMsg("The stack is empty");
return num;
}
bool QueueStack::isEmpty() const{  // return true if the stack if empty
  return top==0;
}
void QueueStack::print()const {  // print the content of stack
  top->print();
  bot->print();
}

task::task(int num, task *p_next, task *p_prev){
  infor=num;
  next=p_next;
  prev=p_prev;
}
LLqueue::LLqueue(task *p_head, task *p_end){
head=p_head;
end=p_end;
}
void LLqueue::enqueue(int e){
if(end!=0){
  end=new task(e,0,end);
  end->prev->next=end;
}
else head=end=new task(e);
}

int LLqueue::dequeue(){
  int dequeued;
  if(head==0) throw ErrorMsg("You can not delete empty listtttttttt");
  if(head==end){
dequeued=head->infor;
delete head;
head=end=0;
  }
  else{
    dequeued=head->infor;
    head=head->next;
    delete head->prev;
    head->prev=0;
  }
  return dequeued;
}

bool LLqueue::isEmpty()const{
  return head==0;
}
void LLqueue::print() const{
  task* temp;
  for(temp=head;temp!=0;temp=temp->next){
    cout<<"The item is "<<temp->infor<<endl;
    cout<<endl;
  }
  delete temp;
}
