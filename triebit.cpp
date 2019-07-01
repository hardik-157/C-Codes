#include<bits/stdc++.h> 
using namespace std; 

#define INT_SIZE 32 
 
struct node 
{ 
    int value;
    node *arr[2]; 
}; 


node *newNode() 
{ 
    node *temp = new node; 
    temp->value = 0; 
    temp->arr[0] = temp->arr[1] = NULL; 
    return temp; 
} 

void insert(node *root, int pre_xor) 
{ 
    node *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--) 
    {
        bool val = pre_xor & (1<<i);

        if (temp->arr[val] == NULL) 
            temp->arr[val] = newNode(); 

        temp = temp->arr[val]; 
    }
    temp->value = //your value; 
}
