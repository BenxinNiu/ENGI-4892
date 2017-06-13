
#include <iostream>
using namespace std;

template<class T>
class item{  //node
public:
  int occurrence;
  int infor;
  item *next;
  item(const T& id, item *ptr=0);  //
};

template<class T>
class shoppingBag{ //list
public:
  shoppingBag(){head=0; end=0;}//
  void addItem(const T elements[],int size);//
  void removeOne(const T& id);//
  void removeAll(const T& id);
  int size(); //
  void sort_update();
  int countItem(const T& id);//
  bool isEmpty();  //
  bool find(const T& id);//
  void display();
private:
  item<T> *head, *end;
};

class ErrorMsg{
public:
string msg;
ErrorMsg(string inMsg){
msg=inMsg;
}
};



template<class T>
item<T>::item(const T& id, item *ptr){
infor=id;
next=ptr;
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
int count=0;
item<T> *temp;
for (temp=head;temp!=0;temp=temp->next)
  if(temp->infor==id)
  count++;
  delete temp;
return count;
}

template<class T>
bool shoppingBag<T>::find(const T& id){
  item<T> *temp;
  for (temp=head; temp!=0 && (temp->infor!=id);temp=temp->next);
  if(temp!=0){
  delete temp;
  return true;
}
  else{
  delete temp;
  return false;
}
}

template<class T>
void shoppingBag<T>::addItem(const T elements[],int size){
  for (int i=0;i<size;i++){
    head=new item<T>(elements[i],head);
    if(end==0) end=head;
  }
  sort_update();
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
  int a=countItem(id);
 for (int i=0;i<a;i++)
  removeOne(id);
}

template<class T>
void shoppingBag<T>::display(){
item<T>* temp;

for(temp=head;temp!=0;temp=temp->next){
  cout<<"The item is "<<temp->infor<<endl;
  cout<<"The occurrence is "<<temp->occurrence<<endl;
  cout<<endl;
}
delete temp;
}

template<class T>
void shoppingBag<T>::sort_update(){
item<T> *temp;
int o;
for(temp=head;temp!=0;temp=temp->next)
temp->occurrence=countItem(temp->infor);
delete temp;
}
