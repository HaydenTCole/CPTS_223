#include "testQueue.hpp"

void testbench_queue_enqueue_insert()
{
    cout << "We are testing the insert function to see if it outputs the correct response when the list is empty\n";
    queue test; cout << "A queue is initiated\n";
    test.enqueue(5);  cout << "The enqueue function is called with integer five as its input parameter\n";
    cout << "This means that the integer 5 should be the first and last elements in the queue. And the size of the queue should be 1.\n";

    if (test.getcount() == 1)
    {
        cout << "The queue isn't empty, test successful\n";
    }
    else
    {
        cout << "The queue is empty, test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_enqueue_overflow()
{
    cout << "We are testing the insert function to see if it outputs the correct reponse when the list is full\n";
    queue test; cout << "A queue is initiated\n";
    test.enqueue(1); test.enqueue(2); test.enqueue(3); test.enqueue(4); test.enqueue(5);
    test.enqueue(6); test.enqueue(7); test.enqueue(8); test.enqueue(9); test.enqueue(2);
    cout << "10 items are queued, exhibiting its maximum capacity\n";
    cout << "One more item is going to be queued.\n";
    cout << "The function should throw an error claiming the maximum capacity has been reached\n";
    cout << "\n";

    test.enqueue(2);

    if (test.getcount() == 10)
    {
        cout << "Queue is full, test successfull\n";
    }
    else
    {
        cout << "Queue did not register capacity, test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_dequeue_emptylist()
{
    cout << "We are testing the dequeue function on an empty list\n";
    queue test; cout << "A queue is initialized\n";
    cout << "This program will attempt to dequeue an empty list, which should lead to an underflow error\n";
    cout << "\n";

    test.dequeue(); cout << "\n";
    if (test.getrear() == -1 && test.getfront() == 0)
    {
        cout << "The queue is empty and an underflow error was thrown, test successful\n";
    }
    else
    {
        cout << "An underflow error was not thrown, test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_dequeue_delete()
{
    cout << "We are testing the dequeue function on a filled list\n";
    queue test; test.enqueue(1); cout << "A queue is initialized and an item is inserted\n";
    cout << "This program will attempt to dequeue the item\n";

    test.dequeue(); cout << "\n";
    if (test.getcount() == 0)
    {
        cout << "The list is now empty, test successful\n";
    }
    else
    {
        cout << "The list isn't empty, test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_peek_emptylist()
{
    cout << "We are testing the peek function on an empty list\n";
    queue test; cout << "A queue is initialized\n";

    if (test.peek() == 0)
    {
        cout << "The peek function returned the correct output, test successful\n";
    }
    else
    {
        cout << "The peek function did't return the correct output, test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_peek_poplist()
{
    cout << "We are testing the peek function on a filled list\n";
    queue test; test.enqueue(1); test.enqueue(2); test.enqueue(3); cout << "A queue is initialized, and three items are added\n";
    cout << "The first of these items is '1', which is the expected result from the peek function\n";
    cout << "\n";

    if (test.peek() == 1)
    {
        cout << "The function returned " << test.peek() << ", test successful\n";
    }
    else
    {
        cout << "The function returned " << test.peek() << ", test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_size()
{
    cout << "We are testing the size function\n";
    queue test; cout << "A queue is initialized\n";
    cout << "The size function is called to test how it behaves on an empty list\n";
    cout << "The expected output is 0\n" << endl;

    if (test.size() == 0)
    {
        cout << "The function returned 0, test successful\n" << endl;
    }
    else
    {
        cout << "The function returned " << test.size() << ", test unsuccessful\n" << endl;
        return;
    }

    cout << "An item is then inserted, from which the size function should read a value of 1\n" << endl;
    test.enqueue(2);

    if (test.size() == 1)
    {
        cout << "The function returned 1, test successful\n";
    }
    else
    {
        cout << "The function returned " << test.size() << ", test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_isEmpty()
{
    cout << "We are testing the isEmpty function\n";
    queue test; cout << "A queue is initialized\n";
    cout << "isEmpty() has a boolean output, meaning that an empty list should return a true output\n";
    cout << "\n";

    if (test.isEmpty())
    {
        cout << "isEmpty() returned true, test successful\n" << endl;
    }
    else
    {
        cout << "isEmpty() returned false, test unsuccessful\n" << endl;
        return;
    }

    test.enqueue(2); cout << "An item is inserted into the queue, meaning the list is no longer empty\n";
    cout << "\n";

    if (!test.isEmpty())
    {
        cout << "isEmpty() returned false, test successful\n";
    }
    else
    {
        cout << "isEmpty() returned true, test unsuccessful\n";
    }
    cout << "\n";
    return;
}

void testbench_queue_isFull()
{
    cout << "We are testing the isFull function\n";
    queue test; cout << "A queue is initialized\n";
    test.enqueue(1); test.enqueue(2); test.enqueue(3); test.enqueue(4); test.enqueue(5);
    test.enqueue(6); test.enqueue(7); test.enqueue(8); test.enqueue(9);
    cout << "8 items are queued into the list\n";
    cout << "isFull() has a boolean output, meaning that a list that isn't full should return a false output\n";
    cout << "\n";

    if (!test.isFull())
    {
        cout << "isFull() returned false, test successful\n" << endl;
    }
    else
    {
        cout << "isFull() returned true, test unsuccessful\n" << endl;
        return;
    }

    test.enqueue(9); cout << "One more item is queued in, filling the list to max capacity\n" << endl;

    if (test.isFull())
    {
        cout << "isFull() returned true, test successful\n" << endl;
    }
    else
    {
        cout << "isFull() returned false, test unsuccessful\n" << endl;
    }
    return;
}

