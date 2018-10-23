//
//  main.cpp
//  PROJECT3
//
//  Created by Maria Teleki on 10/22/18.
//  Copyright © 2018 Maria Teleki. All rights reserved.
//

#include <iostream>
#include <exception>

using namespace std;



/** Note: in order to try to make things easier, the queue below will only have a single type of value in it instead of a (key, value) pair.  You could still store a (key, value) pair, but you would make a priority queue that stored an object with both the key/value in it and a comparison operator that only compared the keys.
 */

template <class Type>
struct Node{ //using a struct bc a struct has default public data, so it's really good to use with pointers and associated data (like an optional in swift)
    Type data;
    Node* next;
    Node* previous;
    
    Node(Type data){
        this->data = data;
        next = nullptr;
        previous = nullptr;
    }
    
};

template <class Type>
class DoublyLinkedList{
private:
    Node<Type>* head;
    Node<Type>* tail;
    int sizeCounter;
    
public:
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        sizeCounter = 0;
    }
    
    ~DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    
    bool isEmpty(void){return ((head == nullptr) && (tail == nullptr));}
    
    int size(void){return sizeCounter;}
    
    Type first(void) throw(exception) {
        if(isEmpty()){
            throw exception();
        }
        return head->data;
    }
    
    Type last(void) throw(exception) {
        if(isEmpty()){
            throw exception();
        }
        return tail->data;
    }
    
    //have to deal with 4 pointers here
    void insertFirst(Type e){
        Node<Type>* n = new Node<Type>(e);
        
        if (isEmpty()) {
            head = n;
            tail = n;
            head->next = tail;
            tail->previous = head;
        }
        else {
            n->next = head;
            head->previous = n;
            head = n;
        }
        sizeCounter++;
    }
    
    void insertLast(Type e){
        Node<Type>* n = new Node<Type>(e);
        
        if (isEmpty()) {
            head = n;
            tail = n;
            head->next = tail;
            tail->previous = head;
        }
        else {
            tail->next = n;
            n->previous = tail;
            tail = n;
        }
        sizeCounter++;
    }
    
    Type removeFirst(void) throw(exception){
        Type data;
        
        if(isEmpty()){
            throw exception();
        }
        
        if (head->next == nullptr) {
            data = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            
        } else {
            Node<Type>* theOneAfterTheFirstOne = head->next;
            
            data = head->data;
            delete head;
            theOneAfterTheFirstOne->previous= nullptr;
            
        }
        sizeCounter--;
        return data;
    }
    
    //FIXME need to mess with this function because the tail delete thing isn't working
    Type removeLast(void) throw(exception){
        Type data;
        
        if(isEmpty()){
            throw exception();
        }
        
        if (head->next == nullptr) {
            data = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            
        } else {
            Node<Type>* end = tail;
            
            data = end->data;
            
            
            tail = end->previous;
            end->previous = nullptr;
            delete end;
            tail->next = nullptr;
            
        }
        sizeCounter--;
        return data;
    }
    
};



template <class Type>
class Deque{
private:
    DoublyLinkedList<Type>* d; //point to linked list
    int sizeCounter;
    
public:
    Deque(){
        d = new DoublyLinkedList<Type>();
    }
    
    ~Deque(){delete d;}
    
    bool isEmpty(){return (d->size()==0);}
    
    int size(){return d->size();}
    
    Type first(){return d->first();}
    
    Type last(){return d->last();}
    
    void insertFirst(Type e){d->insertFirst(e);}
    
    void insertLast(Type e){d->insertLast(e);}
    
    Type removeFirst(){return d->removeFirst();}
    
    Type removeLast(){return d->removeLast();}
    
};


template <class Type>
class PriorityQueue
{
private:
    // data here
    
public:
    PriorityQueue(void);
    
    ~PriorityQueue(void);
    
    bool isEmpty(void);
    
    int size(void);
    
    // inserts a piece of data into the priority queue
    void insertItem ( Type data );
    
    // removes and returns the minimum value in the queue
    // throws an exception if the queue is empty
    Type removeMin ( void );
    
    // return the minimum value in the queue without removing it
    // throws an exception if the queue is empty
    Type minValue ( void );
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
