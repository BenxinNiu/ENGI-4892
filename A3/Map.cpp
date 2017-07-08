#include<string>
#include<iostream>
#include<fstream>
#include "Map.hxx"
using namespace std;


bool operator> (std::string a,std::string b){
  return a.length()>b.length();
}

void forward_insert(){
ifstream information;
information.open("infor.txt");
if(information.is_open()){
  //do{
    int num;
    string name;
    information>>name;
    information>>num;
    cout<<name<<" "<<num<<endl;
    node<string,int>* n= new node<string,int>(name,num);
//  }while(!information.eof());
}
}
