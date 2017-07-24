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
    /*
    initializes all space in array to be null pointer
    */
    HashWithQuadratic<K,V>(std::function<int(K)> hc)
      : hashcode(hc), size(0),key_examined(0) {
        for(int i=0;i<capacity;i++)         //  initializes all space in array to be null pointer
        data[i]=nullptr;
       }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      if(size>capacity)     //chech if the array is full by comparing size with capacity
      return false;          // insert failed
    int index=hashcode(key)%capacity;    // get the index from hash function
      if(data[index]==nullptr){          // this space has not been occupied
      data[index]=new HTEntry(key, value);  // insert information at this location
      size++;                               // increment size
      key_examined++;                       // examined one key!
      return true;                          // success
    }
      else{                                 // space at "index" has been taken
  bool found_parking=false;                 // bool value to indicate avalibility of empty space
for(int step=1, reverse=-1, i=0;
  i<=capacity&&found_parking==false;){     // array traversal
key_examined++;                            // examined one key
  int pos;                                // position being checked
if(index+step<0)                          // if negative index
  pos=capacity+index+step;                // then count from the end of the array
  else if(index+step>capacity)            // exceed array capacity
  pos=index+step-capacity;
  else
  pos=index+step;                         // legal "pos" value
if(data[pos]==nullptr){                   //space has not been taken
  found_parking=true;                     // found empty space
  data[pos]=new HTEntry(key, value);      // insert data
  size++;                                 // increment size
}
i++;                                      //update loop indecies
if(step>0)                                // update probe
  step=step*reverse;
else
   step=i*i;
}
if(found_parking)                     //insert successful
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
      int index=hashcode(key)%capacity;   // hash function to generate index
      if(data[index]->key==key)           // check if data at this location is the right one
      return &data[index]->value;
      else
      for(int step=1,reverse=-1,i=0,pos=0;i<=capacity;){  // same logic as insert
    if(index+step<0)                                 // same logic as insert function
      pos=capacity+index+step;                      // same logic as insert function
      else if(index+step>capacity)                  // same logic as insert function
      pos=index+step-capacity;                     // same logic as insert function
      else                                        // same logic as insert function
      pos=index+step;
      if(data[pos]!=nullptr)
      if(data[pos]->key==key)           // compare key
        return &data[pos]->value;      // return address of value
      i++;
      if(step>0)                     // update probe
        step=step*reverse;
      else
         step=i*i;
      }
    }
      return nullptr;             // not found
    }

    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      cout<<"size: "<<size<<endl;
      cout<<"capacity"<<capacity<<endl;
      float a=size;           // convert int to float for calculation
      float b=capacity;
      return a/b;   // calculation of loadfactor
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      return key_examined;  // from private memeber
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
  for(int i=0;i<capacity;i++)    //traverse array
    if(data[i]!=nullptr)         // make sure it is not empty
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
    int key_examined;  // how many key has the program accessed so far
};

#endif
