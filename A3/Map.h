

#include<string>
#include<iostream>
#include<fstream>
using namespace std;
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

// node in the tree
template<class K, class V>
class node{
public:
node(){left=right=0;}; // default constructor
node(const K& data,const V& v, node*l=0, node*r=0){ // constructor
right=r;
left=l;
key=data;
value=v;
}; //
void print_node() const{    // print node content  const method
  cout<<key<<" "<<value<<endl;
}
  node<K,V>* left, *right;
  K key;
  V value;
};

//tree inhreit from Map class
template<class K, class V>
class BSTMap : public Map<K,V>{
public:
BSTMap(){root=0;};
virtual bool insert(const K& key, const V& value) override;
virtual  bool remove(const K& key) override;
virtual  const V* search(const K& key) const override;
virtual  bool isEmpty() const override;
virtual  void print() const override{ print(root);};
void print(node<K,V>* n) const;  // const method for print tree content by using recursion
void deleteTarget(node<K,V>*& n); // delete a specific node  which is passed as argument by reference
bool in(node<K,V>*& n,const K& key, const V& value); // insert a node using recursion
protected:
  node<K,V>* root;
};

bool operator < (string a ,string b);  // operator to compare string (length and alphabetical)
bool operator > (string a ,string b);  // operator to compare string (length and alphabetical)


// target passed by reference in this method
template<class K, class V>
void BSTMap<K,V>:: deleteTarget(node<K,V>*& n){
node<K,V>* temp=n;   //pointer to the target
if(n!=0){  // target is not a null pointer
  if(n->right==0) // target has no right child
  n= n->left;
  else if(n->left==0) // target has no left child
  n= n->right;
  else{
    temp=n->left;
    while(temp->right != 0)
    temp= temp->right;
    temp->right=n->right;
    temp=n;
    n=n->left;
  }
  delete temp;
}
}

// locate the node by search key and pass to deleteTarget
template<class K, class V>
bool BSTMap<K,V>::remove(const K& key){
node<K,V>* n=root;
node<K,V>* previous=0;
while(n!=0){
  if(n->key==key)
  break;  // found the node  breka loop
  previous = n;
  if(key> n->key)    // keep searching  update n
  n=n->right;
  else n=n->left;
}
if (n!=0&&n->key==key){   // if the n is present in the tree
if(n==root)
deleteTarget(root);
else if(previous->left==n)
  deleteTarget(previous->left);
  else deleteTarget(previous->right);
return true;
}
else if(!isEmpty()){
  cout<<"dose not exist in the tree"<<endl;
  return false;
}
else return false;
}


// print tree content by using recursion (inorder)
template<class K, class V>
void BSTMap<K,V>::print(node<K,V>* n) const{
if(n!=0){
  print(n->left);  // go to the left most bottom
  n->print_node(); // print that node
  print(n->right);
}
}

// see if a tree is empty
template<class K, class V>
bool BSTMap<K,V>::isEmpty() const{
  return root==0; // if root is null then it is empty
}

// search a specific node by using key
template<class K, class V>
const V* BSTMap<K,V>::search(const K& key) const{
  if (!isEmpty()){
    node<K,V>* temp=root;
      while(temp!=0){       // loop
        if(temp->key==key){ //compare key
        return &(temp->value); //return the address of value
      }
        else if(key>temp->key)  // update temp pointer for next loop
        temp=temp->right;
        else
        temp=temp->left;
    }
return nullptr; // it is not in the tree
}
}

// recursion insert
template<class K, class V>
bool BSTMap<K,V>::in(node<K,V>*& n,const K& key, const V& value){
  if (n==nullptr){      // check if it is the right location to insert(nullptr would be the right location)
  n=new node<K,V>(key,value); // insert the new node
  return true;    // insert successful
}
  else if(key>n->key)     // keep traversing the tree  got to rigth side
  in(n->right,key,value); // recursion
  else if(key<n->key)     // keep traversing the tree go to left side
  in(n->left,key,value);  // recursion
  else
  return false;          // unlikely to happen
}

// call in method to insert a pair of key and value
template<class K, class V>
bool BSTMap<K,V>::insert(const K& key, const V& value){
return in(root,key,value);  // begin with the root of tree
}

// custome operator for string comparsion
bool operator > (string a ,string b){
  if (a.length()==b.length())
  return a>b;
  else return a.length()>b.length();
}

// custome operator for string comparsion
bool operator < (string a ,string b){
  if (a.length()==b.length())
  return a<b;
  else return a.length()<b.length();
}
