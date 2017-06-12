#include "A2.h"
#include <iostream>
using namespace std;


int main(){
int e[5]={3, 1, 5, 1, 4};
shoppingBag<int>* bag=new shoppingBag<int>();
bag->addItem(e);
return 0;
}
