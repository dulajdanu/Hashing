#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node
{
    int val;
    int key;
    int isOccupied;
    node():val(0),key(0),isOccupied(0) {}
}HashNode;

HashNode* newHashMap;

int numberofElements;

int hashFun(int key)
{
    return (key%numberofElements);
}


void insertToTheHashMap(int key,int val)
{
    int i = 0;
    int location;
    while(i != (numberofElements-1))
    {
        location = hashFun(key) + i;
        if(newHashMap[location].isOccupied == 0) //checking whether the slot is occupied
        {
            newHashMap[location].val = val;
            newHashMap[location].isOccupied = 1 ;//change it to 1 now it is occupied
            newHashMap[location].key = key;
            return;
        }
        else
        {
            i = i +1;
        }   
    }

}

int searchVal(int keyF)
{
    int i = 0 ;
    int location = hashFun(keyF);
    while(newHashMap[location].isOccupied != 0 || i != (numberofElements-1) )
    {

        location = hashFun(keyF) + i;
        if(newHashMap[location].key == keyF)
            return location;
        else
            i+= 1;    
    }
}

int main()
{
    cout << "Enter the number of elements to be mapped: ";
    cin >> numberofElements;
    newHashMap = (HashNode*)malloc(sizeof(HashNode)*numberofElements);
    //cout << endl << newHashMap[0].isOccupied;
    //newHashMap = new HashNode*numberofElements;
    insertToTheHashMap(22,22);
    insertToTheHashMap(1,1);
    insertToTheHashMap(13,13);
    insertToTheHashMap(11,11);
    insertToTheHashMap(24,24);
    insertToTheHashMap(33,33);

    for(int i = 0 ; i <numberofElements ; i++)
    {
        cout << newHashMap[i].key << endl;
    }

    cout << "Enter the element to search:" ;
    int val;
    cin >> val;
    val =searchVal(val);
    cout << "\nthe location is : " << val;



}