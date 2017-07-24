#ifndef __HASH_WITH_CHAINING_
#define __HASH_WITH_CHAINING_

#include <vector>
#include "HashTable.hxx"

/**
 * This class uses separate chaining as described in class, but instead
 * of using linked lists, it uses vectors.
 * The idea and complexity is the same, but you're probably more accustomed
 * to using vectors vs. linked lists.
 */

template<class K, class V>
class HashWithChaining : public HashTable<K,V>
{
  public:
    // c'tor (initializes hashcode lambda function and size)
    HashWithChaining(std::function<int(K)> hc) : hashcode(hc), size(0),items(0),key_examined(0){
    }

    // Add key/value pair to the hashtable by using 'key' to determine
    // the index for initial placement.
    // pre-condition:  a valid hashtable
    // post-condition: 'value' is added at position determined by 'key'
    bool insert(const K& key, const V& value) override
    {
      int index=hashcode(key)%10;    // hash function to generate index
      if(data[index].size()==0){    // if there is no existing bucket at this location
      key_examined++;               // examined one key
      size++;                       // increment the size(how many space taken in the array)
      bucket_location.push_back(index); // record the location of new bucket for later access
      }
      if(index<capacity){
      key_examined++;              // examined one key
      data[index].push_back(HTEntry(key,value)); // insert data
      items++;                     // number of items in the table
      }
      else
      return false;
    }

    // pre-condition:  a valid hashtable
    // post-condition: the value associated with 'key', else nullptr
    const V* find(const K& key) override
    {
      int index=hashcode(key)%10;  // hash function to generate index
      if(index<capacity)
      for(int i=0; i<data[index].size();i++){  // traverse the bucket at this location
        key_examined++;                        // examined one key
        if((data[index][i]).key==key)         //compare key
        return &(data[index][i]).value;      // return address of value is keys are matched
}
        return nullptr;  // not found

}
    // pre-condition:  a valid hashtable
    // post-condition: return the load factor; hashtable is not modified
    float loadFactor() const override
    {
      cout<<"item: "<<items<<endl;
      cout<<"size: "<<size<<endl;
      float a=items; // number of items in the table&& convet to float
      float b=capacity;
      return a/b;   // calculate load factor
    }

    // pre-condition:  a valid hashtable
    // post-condition: return total keys examined so far;
    //                 hashtable is not modified
    int totalKeysExamined() const override
    {
      return key_examined; // how many times the program has accessed a key in table
    }

    // pre-condition:  a valid hashtable
    // post-condition: hashtable is not modified
    void print() const override
    {
      int location;
     for(int i=0;i<bucket_location.size();i++)  //print data stored in each non-empty bucket
      print_bucket(bucket_location[i]);    // the function to print data in a bucket
cout<<"total "<<items<<" students which are stored in "<<size<<" different location of hashtable"<<endl;
    }

    void print_bucket(int pos) const{
cout<<"Data in bucket which is at "<<pos<<"th location of table"<<endl;
      for(int i=0; i<data[pos].size();i++)  // traverse the bucket
        cout<<data[pos][i].key<<" "<<data[pos][i].value<<endl;  // print information
        cout<<endl<<endl;
    }

  private:
    static constexpr int capacity = 211;
    std::function<int(K)> hashcode;
    struct HTEntry {
      K key;
      V value;
      HTEntry(const K& k = K(), const V& v = V()) : key(k), value(v) { }
    };
    // A bucket array of vectors (each vector contains type 'HTEntry')
    vector<HTEntry> data[capacity];
    int size;   // how many nonempty bucket in the table
    int items;  // how many items are in the table
    int key_examined; // how many times the program has accessed a key in table
    vector <int> bucket_location;  // a vector to store the location of each non-empty bucket
};


#endif
