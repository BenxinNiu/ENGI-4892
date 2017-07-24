#include "HeapPriorityQueue.hxx"
#include <iostream>
#include <fstream>
#include <string>

int main(){

HeapPriorityQueue<int, std::string> queue;

std::ifstream infor;
infor.open("tickets.txt");
if(infor.is_open()){  // file opened successfully
int num;
std::string ticket;
while(!infor.eof()){  // not end of file
infor>>num;
infor>>ticket;
std::cout<<std::endl<<"inserting a ticket"<<std::endl;
queue.enqueue(num,ticket);   // insert a ticket
queue.print();              // print the content of queue after each insertion
}
std::cout<<std::endl<<"insert complete!"<<std::endl;
}

for(int i=0;i<7;i++){   // dequeue 7 times (last time should fail because there will be nothing in the queue)
std::cout<<std::endl;
std::cout<<"removed "<<queue.dequeue()<<std::endl; // perform dequeue
std::cout<<"what's left"<<std::endl;
queue.print(); // print heap after each
std::cout<<std::endl;
}
  return 0;
}
