/*   Author :- Mohit Bansal [MMB140030]
     Program :- Traverse the Tree breadth-wise ( Breadth First Search) - ASSIGNMENT-2
     Date :- 18th September 2014                */

#include <iostream>
#include <cstdlib>

using namespace std;

struct leaf
{
    int key;
    leaf *left;
    leaf *right;
};
struct node
{
    int data;
    node *next;
};

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
    void bfs();
    void bfs1(leaf *ptr);
};

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
    void enque(int d)       //Enqueue the queue with the data of tree
        {
        node *newnode = new node;
        newnode -> data = d;

            if (tail == NULL)
                {
                    newnode -> next = NULL;
                    tail = newnode;
                    head = tail;
                }
            else
                {
                    tail -> next = newnode;
                    tail = tail -> next;
                    tail -> next = NULL;
                }
        }

    int deque()      // Dequeue the Queue
        {
          int a;
          if (head == NULL)
          { cout<< "Queue is empty, Please Insert a number"<< endl;
            return 0;}
          else
          {
              a = head->data;
              head = head -> next;
              if (head == NULL)
                {tail = NULL;}
          }
          return a;
        }
};

void bintree::addleaf(int key)  // Public Function to call addleaf
{
    addleaf1(key,root);
};

void bintree::addleaf1(int key, leaf *ptr)  // Private Function to call addleaf ( consists of leaf pointer)
{
    if (root == NULL)
    {
        leaf *n = new leaf;
        n->key=key;
        n->left=NULL;
        n->right=NULL;
        root = n;
    }
    else if (key <= ptr->key)
    {
        if (ptr->left ==NULL)
        {
            leaf *n = new leaf;
            n->key=key;
            n->left=NULL;
            n->right=NULL;
            ptr->left = n;
        }
        else
        {
            addleaf1(key,ptr->left);
        }
    }
    else if (key > ptr->key)
    {
        if (ptr->right ==NULL)
        {
            leaf *n = new leaf;
            n->key=key;
            n->left=NULL;
            n->right=NULL;
            ptr->right = n;
        }
        else
        {
            addleaf1(key,ptr->right);
        }
    }
};

void bintree::inorder()             //public function for printing indorder traversal
{
    inorder1(root);
};

void bintree::inorder1(leaf *ptr)   //private function for printing indorder traversal
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

void bintree::preorder()    //public function for printing predorder traversal
{
    preorder1(root);
};

void bintree::preorder1(leaf *ptr)  //private function for printing indorder traversal
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

void bintree::bfs()     // Breadth First Search Public Function
{
    bfs1(root);
}
void bintree::bfs1(leaf *ptr)   // Breadth First Search Private Function
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
    m.addleaf(70);
    m.addleaf(20);
    m.addleaf(90);
    m.addleaf(40);
    m.addleaf(100);
    m.addleaf(60);
    m.addleaf(6);
    m.addleaf(10);
    m.addleaf(1);
    m.addleaf(75);
    cout << "Printing In-Order Traversal\n";
    m.inorder();
    cout << "\nPrinting Pre-Order Traversal\n";
    m.preorder();
    cout << "\nBreath First Search\n";
    m.bfs();
    return 0;
}
