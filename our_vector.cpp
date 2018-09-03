#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class vector
{   public:
    int * arr;
    int sizet;
    int capacity;
    float load_factor = 0.5;
    vector()
    {
        capacity = 2;
        arr = (int*) malloc(capacity*sizeof(int));
        sizet = 0;
    }
    vector(int n, int intializing_element)
    {
        capacity = n;
        sizet = n;
        arr = (int*)malloc(capacity*sizeof(int));
        for(int i = 0 ; i<capacity ; i++)
        {
            *(arr + i) = intializing_element;
        }

    }
    void push_back(int element_to_pushed)
    {   
        // cout<<"before"<<endl;
        // cout<<sizet<<endl;
        // cout<<capacity<<endl;
        // cout<<element_to_pushed<<endl;
        // if(sizet+1 > capacity)
        // {
        //     cout<<"overflow: Segmentation fault";
        //     return;
        // }
        
        
            sizet = sizet+ 1;
            if(sizet >= load_factor*capacity)
            {   
                
                capacity = capacity/load_factor;
                arr = (int *)realloc(arr, sizeof(int)*capacity);
   
            }
            arr[sizet -1] = element_to_pushed;
        
        // cout<<"after"<<endl;
        // cout<<sizet<<endl;
        // cout<<capacity<<endl;
        // cout<<arr[sizet -1]<<"element"<<endl;
    }
    void pop_back()
    {
        cout<<"before"<<endl;
        cout<<sizet<<endl;
        cout<<capacity<<endl;

        if(sizet <= 0)
        {
            cout<<"Underflow: Segmentation fault";
            return;
        }
        else
        {
            sizet = sizet - 1;
            if(sizet <= load_factor*capacity)
            {
                capacity = capacity*load_factor;
                arr = (int *)realloc(arr, sizeof(int)*capacity);
            }
        }
        cout<<"after"<<endl;
        cout<<sizet<<endl;
        cout<<capacity<<endl;

    }
    int operator [](int i) const
    {
        if(i<0 || i>= sizet) 
        {
            cout<<"Segmentation fault";
            return -1;
        }
        return arr[i];
    }
    int& operator [](int i)
    {
        if(i<0 || i>= sizet) 
        {   
            int a  = -1;
            cout<<"Segmentation fault";
            return a;
        }
        return arr[i];
    } 
    void insert(int pos, int value_to_be_inserted)
    {
        if(pos < 0)
        {
            cout<<"index out of bound"<<endl;
            return;
        }
        if(pos > sizet)
        {   
            cout<<"Segmentation Fault";
            return;
        }
        else
        {   
            sizet = sizet + 1;
            if(sizet >= load_factor*capacity)
            {   
                
                capacity = capacity/load_factor;
                arr = (int *)realloc(arr, sizeof(int)*capacity);
   
            }
            cout<<"before"<<endl;
            for(int i = sizet-1 ; i>pos ; i--)
            {
                *(arr + i) = *(arr+i-1);
            }
            cout<<"before2"<<endl;
            arr[pos] = value_to_be_inserted;

        }
    }

    void erase(int pos)
    {
        if(pos < 0 || sizet == 0)
        {
            cout<<"index out of bound"<<endl;
            return;
        }
        if(pos > sizet - 1)
        {   
            cout<<"Segmentation Fault";
            return;
        }
        else
        {   
            cout<<"before"<<endl;
            for(int i = pos ; i<sizet-1 ; i++)
            {
                arr[i] = arr[i+1];
            }
            cout<<"before2"<<endl;
            sizet = sizet - 1;
            if(sizet <= load_factor*capacity)
            {
                capacity = capacity*load_factor;
                arr = (int *)realloc(arr, sizeof(int)*capacity);
            }

        }
    }
    int front()
    {   
        if(sizet == 0) 
        {
            cout<<"Segmentation fault";
            return -1;
        }
        return arr[0];
    }

    int back()
    {   
        if(sizet == 0) 
        {
            cout<<"Segmentation fault";
            return -1;
        }
        return arr[sizet - 1];
    }
    
    int size()
    {
        return sizet;
    }
};
int main()
{
vector vishal;
cout<<*(vishal.arr);
cout<<vishal.front()<<endl;
cout<<vishal.back()<<endl;
vishal.push_back(14);
cout<<vishal.front()<<endl;
cout<<vishal.back()<<endl;
vishal.push_back(50);
cout<<vishal.front()<<endl;
cout<<vishal.back()<<endl;
vishal[0] = 67;
cout<<vishal[0]<<"this";

// vishal.push_back(90);
// vishal.push_back(14);
// vishal.push_back(50);
// vishal.push_back(90);
// vishal.insert(2,99);
// vishal.insert(0,1234);
// vishal.insert(9,1299);
//vishal.erase(6);
//vishal.erase(2);
// vishal.pop_back();
// vishal.pop_back();
// vishal.pop_back();
// vishal.pop_back();
cout<<vishal.size()<<endl;
for(int i = 0; i<vishal.size() ; i++)
{
int a = *(vishal.arr + i);
cout<<a<<endl;
}

}