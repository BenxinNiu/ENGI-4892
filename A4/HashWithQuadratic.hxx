#ifndef __HASH_WITH_QUADRATIC_
#define __HASH_WITH_QUADRATIC_

#include "HashTable.hxx"

/**
 * This class uses open-addressing, specifically quadratic probing to
 * resolve collisions.
 */

template<class K, class V>
class HashWithQuadratic : public HashTable<K,V>
{
  public:
    HashWithQuadratic<K,V>(std::function<int(K)> hc)
      : hashcode(hc), size(0) { }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      // FIXME
      return false;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      // FIXME
      return nullptr;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      // FIXME
      return 0;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      // FIXME
      return 0;
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
      // FIXME
    }

  private:
    static constexpr int capacity = 211;
    std::function<int(K)> hashcode;

    // Contains key/value pairs for the hashtable
    struct HTEntry {
      K key;
      V value;

      HTEntry(const K& k = K(), const V& v = V()) : key(k), value(v) { }
    };

    // An array of type 'HTEntry' pointers (nullptr indicates that the
    // position is empty)
    HTEntry* data[capacity];
    int size;
};

#endif
