#include "HeapPriorityQueue.hxx"
#include <iostream>
#include <fstream>
#include <string>

int main(){

HeapPriorityQueue<int, std::string> queue;

std::ifstream infor;
infor.open("tickets.txt");
if(infor.is_open()){
int num;
std::string ticket;
while(!infor.eof()){
infor>>num;
infor>>ticket;
std::cout<<std::endl<<"inserting a ticket"<<std::endl;
queue.enqueue(num,ticket);
queue.print();
}
std::cout<<std::endl<<"insert complete!"<<std::endl;
}

for(int i=0;i<7;i++){
std::cout<<std::endl;
std::cout<<"removed "<<queue.dequeue()<<std::endl;
std::cout<<"what's left"<<std::endl;
queue.print();
std::cout<<std::endl;
}


  return 0;
}
