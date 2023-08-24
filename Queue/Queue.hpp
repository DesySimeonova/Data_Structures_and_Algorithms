#pragma once
#include <iostream>

template <typename T>
class MyQueue
{
	T* data;
	size_t size;
	size_t capacity;

	size_t get;
	size_t put;

	void copyFrom(const MyQueue& other);
	void free();
	void resize();

public:
	MyQueue();
	MyQueue(const MyQueue& other);
	MyQueue& operator=(const MyQueue& other);
	MyQueue& operator=(MyQueue&& other);
	void push(const T& el);
	void push(T&& el);
	void pop();

	const T& peek()const;
	bool isEmpty()const;

	~MyQueue();
};

template <typename T>
void MyQueue<T>::copyFrom(const MyQueue<T>& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
	get = other.get;
	put = other.put;
}

template <typename T>
void MyQueue<T>::resize()
{
	capacity *= 2;
	T* newData = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		newData[i] = data[i];
		(++get) %= capacity;
	}
	delete[] data;
	data = newData;
	put = size;
	get = 0;
	
}

template <typename T>
void MyQueue<T>::free()
{
	delete[] data;
}

template <typename T>
MyQueue<T>::MyQueue()
{
	size = 0;
	capacity = 4;
	data = new T[capacity];
	get = 0;
	put = 0;
}

template <typename T>
MyQueue<T>::MyQueue(const MyQueue& other)
{
	copyFrom(other);
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue&& other)
{
	if (this != &other)
	{
		free();
		data = other;
		other = nullptr;
		size = other.size;
		capacity = other.capacity;
		put = other.put;
		get = other.get;
	}
	return *this;
}

template <typename T>
void MyQueue<T>::push(const T& el)
{
	if (size == capacity)
		resize();
	data[put] = el;
	(++put) %= capacity;
	size++;

}

template <typename T>
void MyQueue<T>::push(T&& el)
{
	if (size == capacity)
		resize();
	data[put] = MyQueue::operator=(el);
	(++put) %= capacity;
	size++;
}

template <typename T>
void MyQueue<T>::pop()
{
	if (isEmpty)
		throw std::logic_error("Empty queue!");
	size--;
	(++get) %= capacity;
	
}

template <typename T>
const T& MyQueue<T>::peek()const
{
	if (isEmpty())
		throw std::logic_error("Empty queue!");
	return data[get];
}

template <typename T>
bool MyQueue<T>::isEmpty()const
{
	return size == 0;
}

template <typename T>
MyQueue<T>::~MyQueue()
{
	free();
}