/*
Author :- Mohit Bansal
Program :- Queue implementation [List]
Date :- 10th September 2014
*/

#include <iostream>
#include <cstring>

using namespace std;

struct node
{
    int data;
    node *next;
};

class nodelist
{
private:
    node *head;
    node *tail;

public:
    nodelist()
    {
        head = NULL;
        tail = NULL;
    }
    void enque(int d)
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
            cout << "The result after En-Queue is :-" << endl;
            display();
        }


    void display()
        {

            node *current = head;
            while(current != NULL)
            {
                cout << current -> data;
                current = current -> next;
                if (current != NULL)
                {
                    cout << "<-";
                }
            }
            cout << endl;

        }
    void deque()
        {
          if (head == NULL)
          {
              cout<< "Error :- Queue is empty, Please Insert a number"<< endl;
              return;
          }
          else
          {
              head = head -> next;

              if (head == NULL)
                {
                    tail = NULL;
                }
          }
          cout << "The result after De-Queue is :-" << endl;
          display();
        }
};
int main()
{
    nodelist m;
    m.enque(25);
    m.deque();
    m.deque();
    m.enque(30);
    m.enque(90);
    m.enque(50);
    m.enque(60);
    m.deque();
    m.deque();
    return 0;
}
