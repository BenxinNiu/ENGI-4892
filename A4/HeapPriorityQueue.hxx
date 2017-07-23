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
      heap.push_back(PQEntry(key,value));
      trickleUp(heap.size()-1);
    };

    // Removes the best key from the heap and returns associated value
    V dequeue() override{
      if(isEmpty())
      return "Nothing";
      else{
      PQEntry t=heap[0];
      heap[0]=heap[heap.size()-1];
      heap.pop_back();
      trickleDown(0);
      return t.value;
      }

    };

    // Test for empty
    bool isEmpty() const override{
      return heap.size()==0;
    };

    // Prints contents of queue (key/value pairs) using level-order traversal
    void print() const override{
      for(int i=0; i<heap.size();i++)
      std::cout<<"key: "<<heap[i].key<<" serial: "<<heap[i].value<<std::endl;
    };

  private:
    // Auxiliary methods to re-heapify the heap
    void trickleUp(int idx);
    void trickleDown(int idx);
    void swap(int jackMaFather, int fosterChild);
    // The contents of the priority queue (a key/value pair)
    // 'key' is used for priority, 'value' is the relevant data
    struct PQEntry
    {
      K key;
      V value;

      bool operator > (PQEntry a){
        return this->key>a.key;
      }
      bool operator < (PQEntry a){
        return this->key<a.key;
      }
      PQEntry(const K& k, const V& v) : key(k), value(v) { }
    };
    // We use a vector so we don't have to worry about running
    // out of space
    std::vector<PQEntry> heap;
};

template<class K, class V>
void HeapPriorityQueue<K,V>::swap(int jackMaFather, int fosterChild){
  PQEntry foster= heap[fosterChild];
  heap[fosterChild]=heap[jackMaFather];
  heap[jackMaFather]=foster;
}

template<class K, class V>
void HeapPriorityQueue<K,V>::trickleDown(int idx){
int leftNode=idx*2+1, rightNode=idx*2+2, size=heap.size()-1;
if(leftNode<size&&rightNode<size)
if(heap[leftNode]>heap[rightNode]&&heap[leftNode]>heap[idx]){
  swap(idx,leftNode);
  trickleDown(leftNode);
}
else if(heap[rightNode]>heap[leftNode]&&heap[rightNode]>heap[idx]){
  swap(idx,rightNode);
  trickleDown(rightNode);
}
else return;
else return;
}

template<class K, class V>
void HeapPriorityQueue<K,V>::trickleUp(int idx){
  int father=(idx-1)/2;
  if(idx>=0 && heap[idx]>heap[father]){
  swap(father,idx);
  trickleUp(father);
}
}


#endif
