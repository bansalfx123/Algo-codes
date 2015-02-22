#include <iostream>
#include <cstdlib>

using namespace std;

//defining structure of node of tree
struct leaf
{
    int key;
    leaf *left;
    leaf *right;
};
//defining structure of node of queue for Breadth First Search
struct node
{
    int data;
    node *next;
};
// Class for Tree
class bintree
{
    public:
    leaf *root;
    bintree()
    {
        root = NULL;
    }
    void addleaf(int key);
    void addleaf1(int key, leaf *ptr);
    void inorder();
    void inorder1(leaf *ptr);
    void preorder();
    void preorder1(leaf *ptr);
    void bft();
    void bft1(leaf *ptr);
    int smallest(leaf *ptr);
    void remmatch(leaf *parent,leaf *match,bool left);
    void remleaf(int key);
    void remleafprivate(int key,leaf *ptr);
};
// Class for queue for breadth first search
class nodelist
{
public:
    node *head;
    node *tail;

    nodelist()
    {
        head = NULL;
        tail = NULL;
    }
    void enque(int d){
        node *newnode = new node;
        newnode -> data = d;

            if (tail == NULL){
                    newnode -> next = NULL;
                    tail = newnode;
                    head = tail;}
            else{
                    tail -> next = newnode;
                    tail = tail -> next;
                    tail -> next = NULL;}
        }

    int deque(){
            int a;
            if (head == NULL){
              cout<< "Queue is empty, Please Insert a number"<< endl;
              return 0;}
          else{
              a = head->data;
              head = head -> next;

              if (head == NULL){
                    tail = NULL;}
               }
          return a;
        }
};

void bintree::addleaf(int key){
    addleaf1(key,root);
};

void bintree::addleaf1(int key, leaf *ptr){
    if (root == NULL){
        leaf *n = new leaf;
        n->key=key;
        n->left=NULL;
        n->right=NULL;
        root = n;
    }
    else if (key <= ptr->key){
        if (ptr->left ==NULL){
            leaf *n = new leaf;
            n->key=key;
            n->left=NULL;
            n->right=NULL;
            ptr->left = n;
        }
        else{
            addleaf1(key,ptr->left);
        }
    }
    else if (key > ptr->key)
        {
        if (ptr->right ==NULL){
            leaf *n = new leaf;
            n->key=key;
            n->left=NULL;
            n->right=NULL;
            ptr->right = n;
        }
        else{
            addleaf1(key,ptr->right);
        }
    }
};
//function for smallest
int bintree::smallest(leaf *ptr)
{
  if (ptr->left != NULL){
      smallest(ptr->left);
  }
  else{
      return ptr->key;
  }
};
//public function for printing indorder traversal
void bintree::inorder()
{
    inorder1(root);
};
//private function for printing indorder traversal
void bintree::inorder1(leaf *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
    }
    else
    {
        if (ptr->left != NULL)
        {
            inorder1(ptr->left);
        }
        cout << ptr->key << " ";
        if (ptr->right != NULL)
        {
            inorder1(ptr->right);
        }
    }
};
// removenode private
void bintree:: remleaf(int key)
{
    remleafprivate(key,root);
}
// removenode public
void bintree:: remleafprivate(int key,leaf *ptr)
{
    if (key < ptr->key && ptr->left != NULL)
    {
        if (ptr->left->key == key)
        {
            remmatch(ptr,ptr->left,true);
        }
        else
        {
            remleafprivate(key,ptr->left);
        }
    }
    if (key > ptr->key && ptr->right != NULL)
    {
        if (ptr->right->key == key)
        {
            remmatch(ptr,ptr->right,false);
        }
        else
        {
            remleafprivate(key,ptr->right);
        }
    }
};
//remove the matched leaf from the tree
void bintree:: remmatch(leaf *parent,leaf *match,bool left)
{
    int small;

    // case when matching node have zero children
    if (match->left == NULL && match->right == NULL)
    {
        left == true ? parent -> left = NULL : parent -> right = NULL;
    }
    // case when matching node have 1 child
    if (match->left != NULL && match->right == NULL)
    {
        left == true ? parent->left = match->left : parent->right = match->left;
    }
    else if (match->left == NULL && match->right != NULL)
    {
        left == true ? parent->left = match->right : parent->right = match->right;
    }
    else if (match->left != NULL && match->right != NULL)
    {
        small = smallest(match->right);
        remleafprivate(small,match);
        match -> key = small;
    }
};
//public function for printing predorder traversal
void bintree::preorder()
{
    preorder1(root);
};
//private function for printing indorder traversal
void bintree::preorder1(leaf *ptr)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
    }
    else
    {
        cout << ptr->key << " ";
        if (ptr->left != NULL)
        {
            preorder1(ptr->left);
        }
                if (ptr->right != NULL)
        {
            preorder1(ptr->right);
        }
    }
};

void bintree::bft()
{
    bft1(root);
}
void bintree::bft1(leaf *ptr)
{
    nodelist q;
    leaf *temp;
    int v = 1;
    q.enque((long)ptr);

    while (q.tail != NULL)
    {
            v = q.deque();
        temp = (leaf *)v;
        cout << temp->key << " ";
        if ( temp->left != NULL)
        {
            q.enque((long)temp->left);
        }
        if ( temp->right != NULL)
        {
            q.enque((long)temp->right);
        }
    }
};

int main()
{
    bintree m;
    m.addleaf(12);
    m.addleaf(54);
    m.addleaf(34);
    m.addleaf(76);
    m.addleaf(46);
    m.addleaf(2);
    m.addleaf(18);
    m.addleaf(38);
    m.addleaf(23);
    m.addleaf(11);
    m.addleaf(9);
    m.addleaf(87);
    m.addleaf(33);
    m.addleaf(65);
    cout << "Printing In-Order Traversal before deletion\n";
    m.inorder();
    cout << "\nPrinting Pre-Order Traversal before deletion\n";
    m.preorder();
    cout << "\nBreath First Search before deletion\n";
    m.bft();
    m.remleaf(54);
    cout << "\n\nAfter Removal of node\n";
    cout << "\nPrinting In-Order Traversal after deletion\n";
    m.inorder();
    cout << "\nPrinting Pre-Order Traversal after deletion\n";
    m.preorder();
    cout << "\nBreath First Search after deletion\n";
    m.bft();
    return 0;
}
