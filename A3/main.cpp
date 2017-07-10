#include<string>
#include<iostream>
#include "Map.h"
using namespace std;

int main(){

  // forward insert   name as key  cell number as value
  BSTMap<std::string,int>*tree= new BSTMap<std::string,int>();
  bool empty=tree->isEmpty();  // test isEmpty() method
  if(empty)
  cout<<"tree is empty!"<<endl;
  cout<<"begin insert"<<endl;
  cout<<endl;
  cout<<endl;
  std::ifstream information;
  information.open("test.txt");
  if(information.is_open()){
    int num;
    std::string name;
    while(!information.eof()){
    information>>name;
    information>>num;
    tree->insert(name,num);  // forward insert
  }
    information.close();
  }
  cout<<"insert from test.txt completed"<<endl;
  cout<<endl;
   empty=tree->isEmpty();  // test isEmpty() method
  if(!empty)
  cout<<"tree is not empty!"<<endl;


// test forward insert
tree->print();
tree->remove("_MixALot");
tree->remove("Mr_Prince");
cout<<endl;
cout<<endl;
cout<< "removed _MixAlot"<<endl<<endl;
cout<< "removed Mr_Prince"<<endl<<endl;
tree->print();

cout<<endl;
cout<<endl;
// perform search
cout<<"search _MixAlot"<<endl;
cout<<endl;
const int *result=tree->search("_MixALot");
if(result==0)
cout<<"not in the tree"<<endl;
else
cout<<"result: "<<*result<<endl;

cout<<endl;
cout<<endl;

cout<<"search donald_trump_SB"<<endl;
cout<<endl;
 result=tree->search("donald_trump_SB");
if(result==0)
cout<<"not in the tree"<<endl;
else
cout<<"result: "<<*result<<endl;

cout<<endl;
cout<<endl;
cout<<endl;


cout<<"reverse insert test"<<endl<<endl<<endl;
// reverse insert cell number as key name as value
BSTMap<int,std::string>*tre= new BSTMap<int,std::string>();
bool e=tre->isEmpty();  // test isEmpty() method
if(e)
cout<<"tree is empty!"<<endl;
cout<<"begin insert"<<endl;
cout<<endl;
cout<<endl;
std::ifstream infor;
infor.open("test.txt");
if(infor.is_open()){
  int number;
  std::string Fullname;
  while(!infor.eof()){
  infor>>Fullname;
  infor>>number;
  tre->insert(number,Fullname);  // reverse insert
}
  infor.close();
}
cout<<"insert from test.txt completed"<<endl;
cout<<endl;
 e=tre->isEmpty();  // test isEmpty() method
if(!e)
cout<<"tree is not empty!"<<endl;

// test reverse insert
tre->print();
tre->remove(7777777);
tre->remove(6666666);
cout<<endl;
cout<<endl;
cout<< "removed 7777777"<<endl<<endl;
cout<< "removed 6666666"<<endl<<endl;
tre->print();

cout<<endl;
cout<<endl;
// perform search
cout<<"search 7777777"<<endl;
cout<<endl;
const string *re=tre->search(7777777);
if(re==0)
cout<<"not in the tree"<<endl;
else
cout<<"result: "<<*result<<endl;

cout<<endl;
cout<<endl;

cout<<"search 7779311"<<endl;
cout<<endl;
 re=tre->search(7779311);
if(re==0)
cout<<"not in the tree"<<endl;
else
cout<<"result: "<<*result<<endl;

cout<<endl;
cout<<endl;

  return 0;
}
