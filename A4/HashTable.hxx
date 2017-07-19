#ifndef __HASH_TABLE_HXX_
#define __HASH_TABLE_HXX_

#include <functional>
#include <iostream>
using namespace std;

template<class K, class V>
class HashTable
{
  public:
    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    virtual bool insert(const K& key, const V& value) = 0;

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    virtual const V* find(const K& key) = 0;

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    virtual float loadFactor() const = 0;

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    virtual int totalKeysExamined() const = 0;

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    virtual void print() const = 0;
};

#endif
