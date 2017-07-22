#include "HashWithChaining.hxx"
#include "HashWithQuadratic.hxx"
#include <string>
#include<sstream>
#include <fstream>

int main(int ac, char* av[])
{
  // Key is an integer for student ID
  // Value is a string representing the students' entire name

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 13579
  // FIXME
std::function<int(int x)> concatEven =[](int x){
  std::ostringstream str;
  str<<x;
  std::string st=str.str();
  int hc=0;
  int divisor=10000;
  std::string new_str;
  for(int i=0; i<st.length();i=i+2){
    new_str=st[i];
    hc +=divisor*(std::stoi (new_str,nullptr,10));
    divisor=divisor/10;
  }
return hc;
  };

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 2468
  // FIXME
  std::function<int(int x)> concatOdd =[](int x){
    std::ostringstream str;
    str<<x;
    std::string st=str.str();
    int hc=0;
    int divisor=1000;
    std::string new_str;
    for(int i=1; i<st.length();i=i+2){
      new_str=st[i];
      hc+=divisor*(std::stoi (new_str,nullptr,10));
      divisor=divisor/10;
    }
    cout<<hc<<endl;
  return hc;
};
  // concat even digits, chaining
  HashWithChaining<int,string> h1(concatEven);

  // concat even digits, quadratic probing
  //HashWithQuadratic<int,string> h2(concatEven);

  // concat odd digits, chaining
  HashWithChaining<int,string> h3(concatOdd);

  // concat odd digits, quadratic probing
  //HashWithQuadratic<int,string> h4(concatOdd);

  // Read data from input file, and do inserts's and find's,
  // and gather statistics ...
  // FIXME
  int n=0;
std::ifstream student;
student.open("students.txt");
if (student.is_open()){
  int stu_num;
  std::string name;
//cout<<"files opend successfully"<<endl;
while(!student.eof()){
student>>stu_num;
student>>name;
//cout<<stu_num<<" "<<name<<endl;
h1.insert(stu_num,name);
}
student.close();
}
h1.print();


}// main
