#ifndef __MAP_HXX__
#define __MAP_HXX__

template<class K, class V>
class Map
{
  public:
    // pre-condition:   a valid key/value pair
    // post-condition:  pair will be added to the BST, if not already present
    //                  Return true if insert succeeded, else false
    virtual bool insert(const K& key, const V& value) = 0;

    // pre-condition:   a valid key
    // post-condition:  if key was present, key/value pair is removed
    //                  Return true if remove succeeded, else false
    virtual bool remove(const K& key) = 0;

    // pre-condition:   a valid key
    // post-condition:  return the corresponding value for key, else nullptr
    //                  the BST is not changed
    virtual const V* search(const K& key) const = 0;

    // pre-condition:   a valid BST
    // post-condition:  return whether or not BST contains any items
    //                  the BST is not changed
    virtual bool isEmpty() const = 0;

    // pre-condition:   a valid BST
    // post-condition:  prints contents of BST in sorted order
    //                  the BST is not changed
    virtual void print() const = 0;
};

#endif
