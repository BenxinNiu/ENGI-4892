#include "A2.h"
#include <iostream>
#include <typeinfo>
using namespace std;


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
cout<<"Select what you wish to do"<<endl;
cout<<"A : check length of the bag"<<endl;
cout<<"B : Find an item"<<endl;
cout<<"C : Is bag Empty"<<endl;
cout<<"D : count an item"<<endl;
cout<<"E : Remove one item"<<endl;
cout<<"F : Remove all duplicated item"<<endl;
while(1>0){
char input;
cin>>input;
if(input=='A')
cout<<"Length is "<<bag->size()<<endl;
if(input=='B'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
if(bag->find(number)) cout<<"It exists in the bag"<<endl;
else cout<<"it does not exist"<<endl;
}
if(input=='C'){
  if(bag->isEmpty()) cout<<"It is empty"<<endl;
  else cout<<"It is not empty"<<endl;
}
if(input=='D'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
 cout<<bag->countItem(number)<<"exists in the bag"<<endl;
}
if(input=='E'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
bag->removeOne(number);
 cout<<"removed"<<endl;
}
if(input=='F'){
  int number;
cout<<"Enter a number "<<endl;
cin>>number;
bag->removeAll(number);
 cout<<"removed"<<endl;
}
}
return 0;
}
