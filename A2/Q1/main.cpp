#include "A2.hxx"
#include <iostream>
#include <typeinfo>
using namespace std;

void instruction();

int main(){
int length;
cout<<"Enter the total number of item you wish to add to the bag"<<endl;
cin>>length;
int a;
int e[length];
cout<<"Enter the number one at a time"<<endl;
for(int i=0;i<length;i++){
cin>>a;
e[i]=a;
}
shoppingBag<int>* bag=new shoppingBag<int>();
bag->addItem(e,length);
cout<<"The content of bag:"<<endl;
bag->display();
instruction();
while(1>0){
char input;
cin>>input;
if(input=='G'){
  int x;
  cout<<"Enter the total number of item you wish to add to the bag"<<endl;
  cin>>x;
  int y;
  int z[x];
  cout<<"Enter the number one at a time"<<endl;
  for(int i=0;i<x;i++){
  cin>>y;
  z[i]=y;
  }
  bag->addItem(z,x);
  if(bag->size()>x)
  cout<<"Added"<<endl;
  else
  cout<<"failed press ctrl + C"<<endl;
}
if(input=='H'){
bag->display();
cout<<endl;
instruction();
}
if(input=='A'){
cout<<"Length is "<<bag->size()<<endl;
instruction();
}
if(input=='B'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
if(bag->find(number)) cout<<" exists in the bag"<<endl;
else cout<<"it does not exist"<<endl;
instruction();
}
if(input=='C'){
  if(bag->isEmpty()) cout<<"It is empty"<<endl;
  else cout<<"It is not empty"<<endl;
  instruction();
}
if(input=='D'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
 cout<<bag->countItem(number)<<" item(s) exists in the bag"<<endl;
 instruction();
}
if(input=='E'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
bag->removeOne(number);
 cout<<"removed"<<endl;
 instruction();
}
if(input=='F'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
bag->removeAll(number);
 cout<<"removed"<<endl;
 instruction();
}
}
return 0;
}

void instruction(){
  cout<<endl;
  cout<<"Select what you wish to do"<<endl;
  cout<<"A : check length of the bag"<<endl;
  cout<<"B : Find an item"<<endl;
  cout<<"C : Is bag Empty"<<endl;
  cout<<"D : count an item"<<endl;
  cout<<"E : Remove one item"<<endl;
  cout<<"F : Remove all duplicated item"<<endl;
  cout<<"G : add new items to bag"<<endl;
  cout<<"H : Print"<<endl;
  cout<<"ctrl + C to exit"<<endl;
}
