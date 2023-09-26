#ifndef QUEUE_HPP
#define QUEUE_HPP

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of the queue
#define SIZE 10

// Class for queue
class queue
{
    int* arr;           // array to store queue elements
    int capacity;       // maximum capacity of the queue
    int front;          // front points to front element in the queue (if any)
    int rear;           // rear points to last element in the queue
    int count;          // current size of the queue

public:
    queue(int size = SIZE);     // constructor
    ~queue();                   // destructor
   
    int getcapacity();
    int getfront();
    int getrear();
    int getcount();

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#endif
