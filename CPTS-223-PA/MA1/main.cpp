// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn
////////////////////////////////////////////////////////////////////////////////////////// Initial testing results
/*
	Enqueue function
	 - Insert successful
	 - Overflow detection successful
	Dequeue function
	 - Underflow detection unsuccessful
	 - Delete successful
	Peek function
	 - Empty list detection successful
	 - Rear detection successful
	Size function
	 - Capacity detection unsuccessful
	isEmpty function
	 - Empty list detection unsuccessful
	isFull function
	 - Full list detection successful
*/
///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////// Final Design Notes
/*
	1. There weren't functions to aquire or access the private values in the queue class
	2. There were no comments within the functions to describe the design choices being made
	3. The destructor exhibits a delete function, which may free the pointers and cause a segmentation error
	4. The enqueue and dequeue functions should return some variable to help check its results 
	5. There should only be one return statement in any given function
*/
///////////////////////////////////////////////////////////////////////////////////////////

#include "testQueue.hpp"	
#include "queue.hpp"

// Constructor to initialize queue
queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
    delete arr; // you are not required to test this function;
    // however, are there issues with it?
}

int queue::getcapacity()
{
	return this->capacity;
}

int queue::getfront()
{
	return this->front;
}

int queue::getrear()
{
	return this->rear;
}

int queue::getcount()
{
	return this->count;
}

// Utility function to remove front element from the queue
void queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return;
    }

    cout <<  arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
    return;
}

// Utility function to add an item to the queue
void queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        return;
    }

    cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
    return;
}

// Utility function to return front element in the queue
int queue::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
	return 0;
    }
    return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
    return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{		
   return (size() == capacity);
}

// main function
int main()
{
    // call your test functions here!
    testbench_queue_enqueue_insert();
    testbench_queue_enqueue_overflow();
    testbench_queue_dequeue_emptylist();
    testbench_queue_dequeue_delete();
    testbench_queue_peek_emptylist();
    testbench_queue_peek_poplist();
    testbench_queue_size();
    testbench_queue_isEmpty();
    testbench_queue_isFull();
    return 0;
}

