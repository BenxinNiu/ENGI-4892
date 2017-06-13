#include <iostream>
#include "QueueStack.h"
using namespace std;

int main(){
LLqueue *P_top=new LLqueue();
LLqueue *P_bot=new LLqueue();
QueueStack *p_stack=new QueueStack(P_top,P_bot);
p_stack->push(2);
p_stack->push(2);
p_stack->print();
if(p_stack->isEmpty())
cout<<"stack is empty"<<endl;
else cout<<"Stack is not empty"<<endl;
int popped;
try{
  popped=p_stack->pop();
}
catch(ErrorMsg &msg){
cerr<<msg.msg<<endl;
}
p_stack->print();
  return 0;
}
