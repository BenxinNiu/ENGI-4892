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
      : hashcode(hc), size(0) {
        for(int i=0;i<capacity;i++)
        data[i]=nullptr;
       }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      if(size>capacity)
      return false;
    int index=hashcode(key)%capacity;
      if(data[index]==nullptr){
      data[index]=new HTEntry(key, value);
      size++;
      return true;
    }
      else{
  bool found_parking=false;
for(int step=1, reverse=-1, i=0;
  i<=capacity&&found_parking==false;){
  int pos;
if(index+step<0)
  pos=capacity+index+step;
  else if(index+step>capacity)
  pos=index+step-capacity;
  else
  pos=index+step;
if(data[pos]==nullptr){
  found_parking=true;
  data[pos]=new HTEntry(key, value);
  size++;
}

i++;
if(step>0)
  step=step*reverse;
else
   step=i*i;
}
if(found_parking)
  return true;
  else
  return false;
}
return false;
}
    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      if(size==0)
      return nullptr;
      else{
      int index=hashcode(key)%capacity;
      if(data[index]->key==key)
      return &data[index]->value;
      else
      for(int step=1,reverse=-1,i=0,pos=0;i<=capacity;){
    if(index+step<0)
      pos=capacity+index+step;
      else if(index+step>capacity)
      pos=index+step-capacity;
      else
      pos=index+step;
      if(data[pos]!=nullptr)
      if(data[pos]->key==key)
        return &data[pos]->value;
      i++;
      if(step>0)
        step=step*reverse;
      else
         step=i*i;
      }
    }
      return nullptr;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      cout<<"size: "<<size<<endl;
      cout<<"capacity"<<capacity<<endl;
      float a=size;
      float b=capacity;
      return a/b;
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      return size;
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
  for(int i=0;i<capacity;i++)
    if(data[i]!=nullptr)
    cout<<data[i]->key<<" "<<data[i]->value<<endl;
    cout<<"total students: "<<size<<endl;
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
    int key_examined;
};

#endif
