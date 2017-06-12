#include <iostream>
using namespace std;

template<class T>
class item{  //node
public:
  int occurrence;
  int infor;
  item *next;
  item(const T& id, int o, item *ptr=0);  //
};

template<class T>
class shoppingBag{ //list
public:
  shoppingBag(){head=0; end=0;}//
  void addItem(const T& elements);//
  void removeOne(const T& id);//
  void removeAll(const T& id);
  int size(); //
  int countItem(const T& id);//
  bool isEmpty();  //
  bool find(const T& id);//
  void print();
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
int count_occurence(const T num, const T elements);
