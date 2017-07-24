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
  str<<x;            // read number to string
  std::string st=str.str();// read number to string
  int hc=0;  // the concated value
  int divisor=10000;
  std::string new_str;
  for(int i=0; i<st.length();i=i+2){ // extract even position
    new_str=st[i];
    hc +=divisor*(std::stoi (new_str,nullptr,10)); // convert that letter to number
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
    for(int i=1; i<st.length();i=i+2){  // same logic as above
      new_str=st[i];                    // but use different initial value of i for odd use 1 for even use 0
      hc+=divisor*(std::stoi (new_str,nullptr,10));
      divisor=divisor/10;
    }
  return hc;
};
  // concat even digits, chaining
  HashWithChaining<int,string> h1(concatEven);

  // concat even digits, quadratic probing
  HashWithQuadratic<int,string> h2(concatEven);

  // concat odd digits, chaining
  HashWithChaining<int,string> h3(concatOdd);

  // concat odd digits, quadratic probing
  HashWithQuadratic<int,string> h4(concatOdd);

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
student>>stu_num;   // read from txt
student>>name;      // read from txt
h1.insert(stu_num,name);   // insert  information to each table
h2.insert(stu_num,name); // insert  information to each table
h4.insert(stu_num,name); // insert  information to each table
h3.insert(stu_num,name); // insert  information to each table
}
student.close();
cout<<"insert complete!"<<endl;
}

while(1>0){
  cout<<endl<<endl;
  cout<<"press 1 for h1 hashtable information"<<endl;
  cout<<"press 2 for h1 hashtable information"<<endl;
  cout<<"press 3 for h1 hashtable information"<<endl;
  cout<<"press 4 for h1 hashtable information"<<endl;
int input;
cin>>input;
switch(input){
  case 1: h1.print();
          cout<<endl<<endl;
          cout<<"search 201796620"<<endl;
          cout<<"search 201447153"<<endl;
          cout<<"search 201447"<<endl;
          cout<<endl;
          cout<<"result: "<<endl;
          if(h1.find(201796620)!=nullptr)  // perform search
          cout<<*h1.find(201796620)<<endl; // display result
          else cout<<"not found"<<endl;
          if(h1.find(201447153)!=nullptr)
          cout<<*h1.find(201447153)<<endl;
          else cout<<"not found"<<endl;
          if(h1.find(201447)!=nullptr)
          cout<<*h1.find(201447)<<endl;
          else cout<<"not found"<<endl;
          cout<<endl;
          cout<<"The load factor is"<<h1.loadFactor()<<endl;  // perform load factor calculation
          cout<<"The totalKeysExamined is"<<h1.totalKeysExamined()<<endl;
          break;
          case 4: h4.print();    // same testing method as above
                  cout<<endl<<endl;
                  cout<<"search 201796620"<<endl;
                  cout<<"search 201447153"<<endl;
                  cout<<"search 201447"<<endl;
                  cout<<endl;
                  cout<<"result: "<<endl;
                  if(h4.find(201796620)!=nullptr)     // perform search
                  cout<<*h4.find(201796620)<<endl;
                  else cout<<"not found"<<endl;
                  if(h4.find(201447153)!=nullptr)
                  cout<<*h4.find(201447153)<<endl;
                  else cout<<"not found"<<endl;
                  cout<<endl;
                  cout<<"The load factor is "<<h4.loadFactor()<<endl;
                  cout<<"The totalKeysExamined is "<<h4.totalKeysExamined()<<endl;
                  break;
                  case 2: h2.print();
                          cout<<endl<<endl;
                          cout<<"search 201796620"<<endl;
                          cout<<"search 201447153"<<endl;
                          cout<<"search 201447"<<endl;
                          cout<<endl;
                          cout<<"result: "<<endl;
                          if(h2.find(201796620)!=nullptr)
                          cout<<*h2.find(201796620)<<endl;
                          else cout<<"not found"<<endl;
                          if(h2.find(201447153)!=nullptr)
                          cout<<*h2.find(201447153)<<endl;
                          else cout<<"not found"<<endl;
                          cout<<endl;
                          cout<<"The load factor is"<<h2.loadFactor()<<endl;
                          cout<<"The totalKeysExamined is"<<h2.totalKeysExamined()<<endl;
                          break;
                          case 3: h3.print();
                                  cout<<endl<<endl;
                                  cout<<"search 201796620"<<endl;
                                  cout<<"search 201447153"<<endl;
                                  cout<<"search 201447"<<endl;
                                  cout<<endl;
                                  cout<<"result: "<<endl;
                                  if(h3.find(201796620)!=nullptr)
                                  cout<<*h3.find(201796620)<<endl;
                                  else cout<<"not found"<<endl;
                                  if(h3.find(201447153)!=nullptr)
                                  cout<<*h3.find(201447153)<<endl;
                                  else cout<<"not found"<<endl;
                                  cout<<endl;
                                  cout<<"The load factor is"<<h3.loadFactor()<<endl;
                                  cout<<"The totalKeysExamined is"<<h3.totalKeysExamined()<<endl;
                                  break;
}
}


}// main
