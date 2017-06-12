#include <iostream>
#include "A2.h"
using namespace std;

template<class T>
item<T>::item(const T& id, int o, item *ptr){
infor=id;
next=ptr;
occurrence=o;
}

template<class T>
int shoppingBag<T>::size(){
int count=0;
item<T> *temp;
for(temp=head;temp!=0;temp=temp->next)
count++;
delete temp;
return count;
}

template<class T>
bool shoppingBag<T>::isEmpty(){
  return head==0;
}

//determine the number of occurrences of a specified item in a bag
template<class T>
int shoppingBag<T>::countItem(const T& id){
int count;
item<T> *temp;
for (temp=head;temp!=0&&temp->infor!=id;temp=temp->next);
if(temp->infor==id)
return temp->occurrence;
else throw ErrorMsg ("This item is not found in the bag!!!");
}

template<class T>
bool shoppingBag<T>::find(const T& id){
  item<T> *temp;
  for (temp=head;temp!=0&&temp->infor!=id;temp=temp->next);
  if(temp->infor==id){
  delete temp;
  return true;
}
  else{
  delete temp;
  return false;
}

}

template<class T>
void shoppingBag<T>::addItem(const T& elements){
  for (int i=0;i<sizeof(elements)/sizeof(elements[0]);i++){
    int occur=count_occurence(elements[i],elements);
    head=new item<T>(elements[i],occur,head);
    if(end==0) end=head;
  }
}

template<class T>
void shoppingBag<T>::removeOne(const T& id){
if(head!=0)
if(head==end&&id==head->infor){
  delete head;
  head=0;
  end=0;
}
else if(id==head->infor){
  item<T> *temp=head;
  head=head->next;
  delete temp;
}
else{
  item<T> *prev, *temp;
  for(prev=head,temp=head->next;temp!=0&&temp->infor!=id;prev=prev->next,temp=temp->next);
  if(temp!=0){
    prev->next=temp->next;
    if(temp==end)
    end=prev;
    delete temp;
      delete prev;
  }
}
}

template<class T>
void shoppingBag<T>::removeAll(const T& id){
  item<T> *temp;
  for (temp=head;temp!=0&&temp->infor!=id;temp=temp->next);
  int num=temp->occurrence;
  for(int i=0;i<num;i++)
  removeOne(id);
  delete temp;
}

template<class T>
void shoppingBag<T>::print(){
  item<T> *temp;
  for(temp=head;temp!=0;temp=temp->next){
    cout<<"The item is"<<temp->infor<<endl;
  }
  delete temp;
}
