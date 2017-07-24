#ifndef __PRIORITYQUEUE_HXX_
#define __PRIORITYQUEUE_HXX_

#include <vector>
#include<iostream>
#include "PriorityQueue.hxx"

template<class K, class V>
class HeapPriorityQueue : public PriorityQueue<K,V>
{
  public:
    HeapPriorityQueue()  = default;
    ~HeapPriorityQueue() = default;

    // Adds the key/value pair to the internal heap
    void enqueue(const K& key, const V& value) override{
      heap.push_back(PQEntry(key,value)); // add to the bottom of vector which is the right most location in the tree
      trickleUp(heap.size()-1);  // then sort the queue using trickleUp
    };

    // Removes the best key from the heap and returns associated value
    V dequeue() override{
      if(isEmpty())              // check if the queue is empty
      return "Nothing";         // return nothing if it is empty
      else{
      PQEntry t=heap[0];       // store the root data
      heap[0]=heap[heap.size()-1]; //put the data at tail to the root
      heap.pop_back();   // remove the tail from vector
      trickleDown(0);    // sort the queue using trickleDown
      return t.value;  // return root (removed) data
      }

    };

    // Test for empty
    bool isEmpty() const override{
      return heap.size()==0;  // chech the size of vector (queue)
    };

    // Prints contents of queue (key/value pairs) using level-order traversal
    void print() const override{
      for(int i=0; i<heap.size();i++)  // traverse vector using for loop
      std::cout<<"key: "<<heap[i].key<<" serial: "<<heap[i].value<<std::endl;
    };

  private:
    // Auxiliary methods to re-heapify the heap
    void trickleUp(int idx);
    void trickleDown(int idx);
    void swap(int jackMaFather, int fosterChild); // swap two location's data
    // The contents of the priority queue (a key/value pair)
    // 'key' is used for priority, 'value' is the relevant data
    struct PQEntry
    {
      K key;
      V value;

      bool operator > (PQEntry a){
        return this->key>a.key;   // custom operator for key comparision
      }
      bool operator < (PQEntry a){
        return this->key<a.key;    // custom operator for key comparision (improve tidyness of code)
      }
      PQEntry(const K& k, const V& v) : key(k), value(v) { }
    };
    // We use a vector so we don't have to worry about running
    // out of space
    std::vector<PQEntry> heap;
};
/*
@pre: parameters are valid location
@post: two data at these locations are exchanged
       && I will inherit Alibaba enterprise ......
*/
template<class K, class V>
void HeapPriorityQueue<K,V>::swap(int jackMaFather, int fosterChild){
  PQEntry foster= heap[fosterChild];    // store data in temporary varible
  heap[fosterChild]=heap[jackMaFather];  //exchange data
  heap[jackMaFather]=foster;  // exchange data
}

template<class K, class V>
void HeapPriorityQueue<K,V>::trickleDown(int idx){
int leftNode=idx*2+1, rightNode=idx*2+2, size=heap.size()-1;  /// get right child and left child of node at "idx" and size of the heap
if(leftNode<size&&rightNode<size)    // check if parents of left and right child are at the bottom of the heap
if(heap[leftNode]>heap[rightNode]&&heap[leftNode]>heap[idx]){  // left child is the biggest in this partial family( bigger than its parent and right child)
  swap(idx,leftNode);  // exchange data at left child and its parent
  trickleDown(leftNode); // sort heap
}
else if(heap[rightNode]>heap[leftNode]&&heap[rightNode]>heap[idx]){ // right child is the biggest in this partial family( bigger than its parent and left child)
  swap(idx,rightNode); // exchange data at right child and its parent
  trickleDown(rightNode);  // sort heap
}
else return;  // parent is the king!!(biggest value; no action need to be performed)
else return;
}

template<class K, class V>
void HeapPriorityQueue<K,V>::trickleUp(int idx){
  int father=(idx-1)/2;
  if(idx>=0 && heap[idx]>heap[father]){  // is the child bigger than its parent
  swap(father,idx);            // if yes exhange data at child and its parent
  trickleUp(father);      // recursive
}
}


#endif
