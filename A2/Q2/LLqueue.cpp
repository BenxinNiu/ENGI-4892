#include <iostream>
#include "LLqueue.h"
using namespace std;


task::task(int num, task *p_next, task *p_prev){ // task in the queue.
  infor=num;                                      // constructor
  next=p_next;
  prev=p_prev;
}
LLqueue::LLqueue(task *p_head, task *p_end){ // contructor for queue
head=p_head;
end=p_end;
}
void LLqueue::enqueue(int e){   // add item to the queue
if(end!=0){
  end=new task(e,0,end);
  end->prev->next=end;
}
else head=end=new task(e);
}

int LLqueue::dequeue(){  // remove item from the queue
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

bool LLqueue::isEmpty()const{  // check if the queue if empry
  return head==0; // return true if it is empty
}
void LLqueue::print() const{  // print the content of queue
  task* temp;
  for(temp=head;temp!=0;temp=temp->next){
    cout<<"The item is "<<temp->infor<<endl;
    cout<<endl;
  }
  delete temp;
}
