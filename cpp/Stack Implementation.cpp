#include<iostream>
#include<stdlib.h>
#define SIZE 4
using namespace std;
void push();
void pop();
void display();
int top=-1;
int array[SIZE];

int main(){
    int choice;
    
    while(1)
    {
        cout<<"\n1. push \n2. pop \n3. display \n4 exit"<<endl;
        cout<<"enter choice"<<endl;
        cin>>choice;
        switch(choice){
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            break;
            default: cout<<"invalid case";
            break;
        }
    }
}
void push(){
    int x;
    if(top == SIZE -1){
        cout<<"overflow"<<endl;
    }
    else{
        cout<<"enter element u want to add:";
        cin>>x;
        top = top+1;
        array[top] = x;
        
    }
}
void pop(){
    if(top ==-1){
        cout<<"Underflow";
    }
    else{
        cout<<"deletd element"<<array[top]<<endl;
        top = top -1;
    }
}
void display(){
    cout<<"elements are in stack are:";
    for(int i=top; i>=0;--i){
        cout<<array[i]<<endl;
    }
    cout<<endl;
}