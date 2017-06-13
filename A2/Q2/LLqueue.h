#include <iostream>
using namespace std;

class ErrorMsg{
public:
string msg;
ErrorMsg(string inMsg){
msg=inMsg;
}
};


class Queue{
 public:
 // c'tor and d'tor
 Queue(){}//
 virtual ~Queue(){}
 // pre-condition: given an integer 'e'
 // post-condition: the queue will contain 'e' at one end of the data structure
virtual void enqueue(int e) = 0;
 // pre-condition: queue must not be empty
 // post-condition: the integer at the other end of the data structure is returned,
 // and also removed from the structure
 virtual int dequeue() = 0;
 virtual bool isEmpty() const = 0;
 virtual void print() const = 0;
};

class task{
public:
  task(){next=prev=0;}
  task(int num, task *p_next=0, task *p_prev=0);
  int infor;
  task *next, *prev;
};

class LLqueue : public Queue {
public:
  LLqueue(task *p_head=0, task *p_end=0);//
  virtual void enqueue(int e) override;//
  virtual int dequeue() override;
  virtual bool isEmpty() const override;
  virtual void print() const override;
protected:
task *head, *end;
};
