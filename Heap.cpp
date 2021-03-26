#include <iostream>
#include <cmath>
using namespace std;

class Heap
{
private:
    int size;
    int capacity;
    int *element;

public:
    Heap(int maxsize);
    Heap(int source[],int length);
    void Insert(int item);
    bool IsFull();
    bool IsEmpty();
    void print();
    int DeleteMax();
    ~Heap();
};

Heap::Heap(int maxsize)
{
    element = new int[maxsize+1];
    size = 0;
    capacity = maxsize;
    element[0] = INT32_MAX;
}

Heap::~Heap()
{
    delete[] element;
}

void Heap::print(){
    for (int i = 1; i < size+1; i++)
    {
        cout<<element[i]<<" ";
    }
    cout <<endl;
    
}

bool Heap::IsFull(){
    return size<capacity; 
}

bool Heap::IsEmpty(){
    return size==0;
}

void Heap::Insert(int item)
{
    if (IsFull()){
        cout<<"full!"<<endl;
        return;
    }
    int i = ++size;
    while (element[i/2]<item)
    {
        element[i] = element[i/2];
        i/=2;
    }
    element[i] = item;
}

int Heap::DeleteMax(){
    if (IsEmpty()){
        cout<<"empty"<<endl;
        return;
    }
    int maxitem = element[1];
    int tmp = element[size--];
    int parent,child;
    for(parent=1;parent*2<=size;parent = child){
        child = parent*2;
        // if parent has right son
        if ((child!=size)&&(element[child]<element[child+1]){}){
            child++;
        }
        if (tmp>=element[child]) break;
        else
            element[parent] = element[child];
    }

    element[parent] = tmp;
    return maxitem;
}

Heap::Heap(int source[],int length){
   element = new int[1+length*2];
   size = length;
   capacity = length*2;
   element[0] = INT32_MAX; 
   // copying
   for (int i = 0; i < length; i++)
   {
       element[i+1] = source[i];
   }
   // sorting
   for (int parent = size/2 ; parent>=1; parent++)
   {
       int tmp = parent;
       while (tmp*2<=size)
       {
           int child = tmp*2;
           if ((child!=size)&&(element[child]<element[child+1])){
                child++;
           }
           if(tmp>=element[child]) break;
           else{
               swap(element[tmp],element[child]);
               tmp = child;
           }
       }
   }
}