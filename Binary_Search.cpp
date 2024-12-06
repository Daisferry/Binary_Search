#include <iostream>
using namespace std;

//prototype
int BinarySearch(int search[],int size, int to_find);

//function
int BinarySearch(int search[], int size, int to_find)
{
    //end of array
    int max = size;
    //start of array
    int min = 0;
    //their middle
    int pivot = (max+min)/2;

    while(search[pivot] != to_find)
    {
        if(max == min && search[pivot] != to_find)
        {
            return -1;
        }
        if(search[pivot] > to_find)
        {
            max = pivot-1;
            pivot = (max+min)/2;
        }
        else if(search[pivot] < to_find)
        {
            min = pivot+1;
            pivot = (max+min)/2;
        }
    }
    return pivot;
}

int main()
{
    int list[] = {1,3,5,6,8,10};
    int size = (sizeof(list)/4 - 1);

    int num_to_find;
    cin>>num_to_find;     

    //error handling
    try
    {
        if(num_to_find > list[size] || num_to_find < list[0])
        {
            throw(num_to_find);
        }
    }
    catch(int a)
    {
        cout<<"Number "<<a<<" isn't on the list.";
        return 0;
    }

    int location = BinarySearch(list,size,num_to_find);

    //error handling 2
    try
    {
        if(location == -1)
        {
            throw("error");
        }
    }
    catch(...)
    {
        cout<<"Number "<<num_to_find<<" isn't on the list.";
        return 0;
    }

    cout<<"on position: list["<<location<<"] - ("<<&list[location]<<") is the number: "<<list[location]<<"\nFound in O(log n) time complexity";

    return 0;
}