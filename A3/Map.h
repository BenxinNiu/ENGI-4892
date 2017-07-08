
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

void forward_insert();
bool operator < (string a ,string b);
bool operator > (string a ,string b);


template<class K, class V>
class node{
public:
node(){left=right=0;}; //
node(const K& data,const V& v, node*l=0, node*r=0){
right=r;
left=l;
key=data;
value=v;
}; //
void print_node() const{
  cout<<key<<" "<<value<<endl;
}
  node<K,V>* left, *right;
  K key;
  V value;
};

template<class K, class V>
class BSTMap : public Map<K,V>{
public:
BSTMap(){root=0;};
virtual bool insert(const K& key, const V& value) override;
virtual  bool remove(const K& key) override;
virtual  const V* search(const K& key) const override;
virtual  bool isEmpty() const override;
virtual  void print() const override{ print(root);};
void print(node<K,V>* n) const;
void deleteTarget(node<K,V>*& n);
bool in(node<K,V>*& n,const K& key, const V& value);
protected:
  node<K,V>* root;
};

template<class K, class V>
void BSTMap<K,V>:: deleteTarget(node<K,V>*& n){
node<K,V>* temp=n;
if(n!=0){
  if(n->right==0) // there is no right child
  n= n->left;
  else if(n->left==0) // there is no left child
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


template<class K, class V>
bool BSTMap<K,V>::remove(const K& key){
node<K,V>* n=root;
node<K,V>* previous=0;
while(n!=0){
  if(n->key==key)
  break;
  previous = n;
  if(key> n->key)
  n=n->right;
  else n=n->left;
}
if (n!=0&&n->key==key){
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



template<class K, class V>
void BSTMap<K,V>::print(node<K,V>* n) const{
if(n!=0){
  print(n->left);
  n->print_node();
  print(n->right);
}
}

template<class K, class V>
bool BSTMap<K,V>::isEmpty() const{
  return root==0;
}

template<class K, class V>
const V* BSTMap<K,V>::search(const K& key) const{
  if (!isEmpty()){
    node<K,V>* temp=root;
      while(temp!=0){
        if(temp->key==key){
        return &(temp->value);
      cout<<temp->value<<endl;
      }
        else if(key>temp->key)
        temp=temp->right;
        else
        temp=temp->left;
    }
return nullptr;
}
}


template<class K, class V>
bool BSTMap<K,V>::in(node<K,V>*& n,const K& key, const V& value){
  if (n==nullptr){
  n=new node<K,V>(key,value);
  return true;
}
  else if(key>n->key)
  in(n->right,key,value);
  else if(key<n->key)
  in(n->left,key,value);
  else
  return false;
}

template<class K, class V>
bool BSTMap<K,V>::insert(const K& key, const V& value){
return in(root,key,value);
}



void forward_insert(){
BSTMap<std::string,int>*tree= new BSTMap<std::string,int>();
std::ifstream information;
information.open("test.txt");
if(information.is_open()){
  int num;
  std::string name;
  while(!information.eof()){
  information>>name;
  information>>num;
  tree->insert(name,num);
}
//tree->remove("John_Diary");
tree->print();
  information.close();
}
}

bool operator > (string a ,string b){
  return a.length()>b.length();
}

bool operator < (string a ,string b){
  return a.length()<b.length();
}
