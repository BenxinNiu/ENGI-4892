#ifndef __QUEUE_HXX_
#define __QUEUE_HXX_

template<class K, class V>
class PriorityQueue
{
  public:
    // pre-condition:  a valid priority queue
    // post-condition: key/value pair is added to the queue
    virtual void enqueue(const K& key, const V& value) = 0;

    // pre-condition:  a valid priority queue
    // post-condition: the value of the 'best' key is removed and
    //                 returned from the queue
    virtual V dequeue() = 0;

    // pre-condition:  a valid priority queue
    // post-condition: query if queue is empty; queue remains unchanged
    virtual bool isEmpty() const = 0;

    // pre-condition:  a valid priority queue
    // post-condition: print all key/value pairs in the queue,
    //                 using level-order traversal
    virtual void print() const = 0;
};

#endif
