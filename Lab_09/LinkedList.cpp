#include <iostream>
#include "LinkedList.h"

using namespace std;

//Exercise1
LinkedList::LinkedList(){
    this->first = NULL;
    this->last = NULL;
}

LinkedList::~LinkedList(){
    while (!isEmpty()) removeFromBack();
}

void LinkedList::insertAtBack(int valueToInsert){
    Node* temp = new Node();
    temp->val = valueToInsert;
    temp->next = NULL; 
    
    Node* end = this->first;

    if(end == NULL){ 
        end = temp;
        this->first = temp;
        this->last = temp;
    }else{
        while(end->next != NULL){
            end = end->next; 
        }
        end->next = temp;
        this->last = temp;
    }
}

bool LinkedList::removeFromBack(){
    try{
        if(!this->isEmpty()){
            Node* old;
            Node* end = this->first;
            
            if(end->next == NULL){ 
                old = end;
                this->first = NULL;
                this->last = NULL;
                delete old;
                return 1;
            }else{
                while(end->next != last){
                    end = end->next;
                }
                old = end->next;
                end->next = NULL;
                this->last = end;
                delete old;
                return 1;
            }
        }else{
            return 0;
        }
    }catch(const exception e){
        return 0;
    }
}

void LinkedList::print(){
    Node* v = this->first;
    if(!isEmpty()){
        cout << v->val;
        while (v->next != NULL){
            v = v->next;
            cout << ", " << v->val;
        }
    }
}

bool LinkedList::isEmpty(){
    return (this->first == NULL);
}

int LinkedList::size(){
    if(this->isEmpty())
        return 0;
    else{
        int counter = 1;
        Node* v = this->first;
        while (v->next != NULL){
            counter++;
            v = v->next;
        }
        return counter;
    }
    return -1;
}

void LinkedList::clear(){
    while (!this->isEmpty()) removeFromBack();
}

//Exercise2
void LinkedList::insertAtFront(int valueToInsert){
    Node* v =  new Node; // create new node
    v->val = valueToInsert; // store data
    v->next = first; // head now follows v
    this->first = v;
    if(this->first->next == NULL){
        this->last = first;
    }
}

bool LinkedList::removeFromFront(){
    if(!this->isEmpty()){
        Node* old = this->first; // save current head
        first = old->next; // skip over old head
        delete old; // delete the old head
        return 1;
    }else
        return 0;
}


int LinkedList::getFront(){
    return this->first->val;
}