// A1_TemplatedQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "queue.h"
using namespace std;

/* 
	Brody Davison
	IGME 309 Section 4
	Instructor: Stephen Maier
	9/4/2019
*/

int main()
{
	//Using a queue of integers as an example
	TemplatedQueue<int> q;

	//Check the starting size and check whether its empty or not
	cout << q.GetSize() << endl;
	if (q.isEmpty()) 
	{
		cout << "Queue is Empty" << endl;
	}
	else 
	{
		cout << "Queue contains data" << endl;
	}

	//Push some data into the queue
	q.Push(16);
	q.Push(25);
	q.Push(872);
	q.Push(57);
	q.Push(423);

	//Print out the array size
	cout << "Array Size: " << q.GetSize() << endl << endl;
	
	//Print out the queue's data
	q.Print();

	//Pop some elements from the queue
	q.Pop();
	q.Pop();
	cout << endl << "Popped 2 entries from the queue" << endl;

	//Print queue data after the pops
	q.Print();
	//Check array size after pops
	cout << endl << "New Array Size: " << q.GetSize() << endl;

}

