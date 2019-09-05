#pragma once
#include <array>
#include <iostream>

using namespace std;

template <class ClassType>
class TemplatedQueue {
private:

	//Fields
	int arraySize;
	int capacity;
	ClassType* data;

	//Helper function to double the bounds of the containing array when full
	void expandArrayBounds() 
	{
		capacity *= 2;
		ClassType* tempData = new ClassType[capacity];

		copy(data, data + capacity, tempData);

		delete[] data; 
		data = tempData;
	}


public:
	//Returns the number of entries in the queue
	int GetSize() 
	{
		return arraySize;
	}
	
	//Returns true if there are no entries in the queue, and false if entries are in the queue
	bool isEmpty() 
	{
		if (arraySize == 0) 
		{
			return true;
		}
		return false;
	}

	//Prints the contents of the queue to the console in order
	void Print() 
	{
		for (int i = 0; i < arraySize; i++) 
		{

			cout << "[" << data[i] << "]";
		}
	}

	//Default Constructor
	TemplatedQueue() 
	{
		capacity = 1;
		arraySize = 0;
		data = new ClassType[capacity];
	}

	//Pushes a new value onto the back of the queue
	void Push(ClassType newData) 
	{
		if (arraySize == capacity) 
		{
			expandArrayBounds();
		}

		data[arraySize] = newData;
		arraySize++;
	}
	
	//Removes a value from the front of the queue
	void Pop() 
	{
		if (arraySize == 0) 
		{
			return;
		}
		
		data[0] = NULL;
		arraySize--;

		for (int i = 0; i < arraySize; i++) 
		{
			data[i] = data[i + 1];
		}
	}

	/* REQUIREMENTS FOR RULE OF THREE*/
	//Destructor
	~TemplatedQueue() 
	{
		delete[] data;
		data = nullptr;
	}

	//Copy Constructor
	TemplatedQueue(const TemplatedQueue& other) 
	{
		arraySize = other.arraySize;
		capacity = other.capacity;

		data = new ClassType[capacity];
		copy(other.data, other.data + other.capacity, data);
	}

	//Copy Assignment Operator
	TemplatedQueue& operator= (const TemplatedQueue& other) 
	{
		if (this != &other) 
		{
			arraySize = other.arraySize;
			capacity = other.capacity;
			copy(other.data, other.data + other.capacity, data);
		}
	}
};