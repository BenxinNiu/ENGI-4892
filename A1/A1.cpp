#include "A1.h"
#include<iostream>
#include<fstream>

//extrac information from the input file
void extract(){
  std::ifstream ragged;
  std::cout<<"Please enter the file name you wish to open"<<std::endl;
  std::cout<<"Be sure to add file format. Press Enter to continue "<<std::endl;
  char name[20];
  std::cin>>name; // require file name
  ragged.open(name);
  if(ragged.is_open()){ // check if the file is successfully opened
  int num;
  ragged>>num;
  if(num!=0){
  infor new_array[num]; // create an array of struct with specified size in the file
  for (int i=0;i<num;i++){ // start reading the file
  int size;
  ragged>>size;  // The size of Internal array
  new_array[i].pointer_array=new int[size]; //point to the internal array
  new_array[i].size=size;   // store size in the struct
  for (int j=0;j<size;j++)  // putting value in the array(struct)
  ragged>>(new_array[i].pointer_array)[j];
new_array[i].max=maximum(new_array[i].pointer_array,size); // claculate max value
new_array[i].avg=average(new_array[i].pointer_array,size);// claculate average value
new_array[i].min=minimun(new_array[i].pointer_array,size);// claculate min value
}
for(int k=0;k<num;k++)   // display information of array of struct in console
display_infor(new_array[k]);
  }
  else{  // The file contains wrong structure   restart the programm
    std::cout<<"Something wrong with the file Please try again!"<<std::endl;
    extract();
  }}}

// display the array of struct
void display_infor(infor a){
  std::cout<<"The size of the interal array is "<<a.size<<std::endl;
 std::cout<<"The maximum value in the interal array is "<<a.max<<std::endl;
 std::cout<<"The minimum value in the interal array is "<<a.min<<std::endl;
 std::cout<<"The Average value of the interal array is "<<a.avg<<std::endl;
 std::cout<<"The interal array is [ ";
 for(int i=0;i<a.size;i++)
std::cout<<a.pointer_array[i]<<" ";
std::cout<<"]"<<std::endl;
std::cout<<std::endl;
std::cout<<std::endl;
}

// calculate min value in the array
int minimun(int *arr,int size){
int min=arr[0];
for(int i=1;i<size;i++)
if(min>arr[i])//compare with the next one
min=arr[i]; //update value of min if it is less the original value
return min;
}
// calculate max value in the array
int maximum(int *arr,int size){
  int max=arr[0];
  for(int i=1;i<size;i++)
  if(max<arr[i]) //compare with the next one
  max=arr[i]; //update value of max if it is larger the original value
  return max;
}
// calculate aveage value in the array
double average(int *arr,int size){
  double sum=0;
  for (int i=0;i<size;i++)
   sum+=arr[i];
   return sum/size;
}
