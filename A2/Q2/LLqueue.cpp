#include <iostream>
#include "LLqueue.h"
using namespace std;


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
  if(head=0) throw ErrorMsg("You can not delete empty listtttttttt");
  if(head==end){
dequeued=head->infor;
delete head;
head=end=0;
  }
  else{
    head=head->next;
    delete head;
  }
}
