#ifndef __PRIORITYQUEUE_HXX_
#define __PRIORITYQUEUE_HXX_

#include <vector>

#include "PriorityQueue.hxx"

template<class K, class V>
class HeapPriorityQueue : public PriorityQueue<K,V>
{
  public:
    HeapPriorityQueue()  = default;
    ~HeapPriorityQueue() = default;

    // Adds the key/value pair to the internal heap
    void enqueue(const K& key, const V& value) override;

    // Removes the best key from the heap and returns associated value
    V dequeue() override;

    // Test for empty
    bool isEmpty() const override;

    // Prints contents of queue (key/value pairs) using level-order traversal
    void print() const override;

  private:
    // Auxiliary methods to re-heapify the heap
    void trickleUp(int idx);
    void trickleDown(int idx);

    // The contents of the priority queue (a key/value pair)
    // 'key' is used for priority, 'value' is the relevant data
    struct PQEntry
    {
      K key;
      V value;

      PQEntry(const K& k, const V& v) : key(k), value(v) { }
    };

    // We use a vector so we don't have to worry about running
    // out of space
    std::vector<PQEntry> heap;
};

#endif
