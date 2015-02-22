/* Mohit Bansal [mmb140030]
Assingment - 4
Heap Sort */
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int heapsize = 0;

//defining the binary tree minimum heap
class minheap {
public:
    vector<int> data;

    minheap(int size){
        data.resize(size);
    }

    int getminimum(){
     return data[0];
    }

    int leftchild(int index);
    int rightchild(int index);
    int parent(int index);
    void insertc(int value);
    void percolateup(int index);
    void removemin();
    void percolatedown(int index);
    void display();
    void heapsort();
};
int minheap:: leftchild(int index)
{
        return index*2;
}

int minheap:: rightchild(int index)
{
        return (index*2 + 1);
}

int minheap:: parent(int index)
{
        return index/2 ;
}

void minheap:: insertc(int value)
{
    cout << value << "  ";
    heapsize = heapsize + 1;
    data[heapsize] = value;
    percolateup(heapsize);
}

void minheap:: percolateup(int index)
{
    int par,temp;
    if (index > 1)
    {
        par = parent(index);
        if (data[par] > data[index])
        {
            temp = data[index];
            data[index] = data[par];
            data[par] = temp;
            percolateup(par);
        }
    }
}

void minheap:: removemin()
{
        data[1] = data[heapsize];
        heapsize = heapsize - 1;
        percolatedown(1);
}

void minheap:: percolatedown(int index)
{
    int lc,rc,temp,min;
    rc = rightchild(index);
    lc = leftchild(index);

    if (lc >= heapsize){
        if (rc >= heapsize){
            return;
        }
        else{
            min=rc;
        }
    }
    else{
        if (data[lc] > data[rc]){
            min = rc;
        }
        else{
            min = lc;
        }
    }

    if (data[index] > data[min]){
        temp = data[min];
        data[min] = data[index];
        data[index] = temp;
        percolatedown(min);
    }
}

void minheap:: display(){
    for (int i=1;i<= heapsize;i++){
        cout<<data[i]<<"  ";
    }
}

void minheap:: heapsort()
{
    while(heapsize >= 1){
        cout << data[1] << "  ";
        removemin();
        heapsort();
    }
}


int main()
{
    cout << "Array of elements, before we make a heap.(Array of Numbers entered)\n";
    minheap a(12);
    a.insertc(12);
    a.insertc(5);
    a.insertc(11);
    a.insertc(3);
    a.insertc(10);
    a.insertc(6);
    a.insertc(9);
    a.insertc(4);
    a.insertc(8);
    a.insertc(1);
    a.insertc(7);
    a.insertc(2);
    cout << "\n\n Array of elements, after we make a heap.(Heap)\n";
    a.display();
    cout << "\n\n Array of heap elements in sorted order.(Heap sort)\n";
    a.heapsort();
    cout << endl;
    return 0;
}
