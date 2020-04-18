#ifndef QUEUE_H
#define QUEUE_H

template<typename TheType>
class Queue {
private:
	int front;
	int rear;
	static const int SIZE = 50;
	TheType ary[SIZE];

public:
	void push(TheType);
	TheType pop();
	TheType peek() const;
	bool isEmpty() const;
	bool isFull() const;
	Queue();

};

template<typename TheType>
void Queue<TheType>::push(TheType val)
{
	ary[rear + 1] = val;
	rear++;
}

template<typename TheType>
TheType Queue<TheType>::pop()
{

	TheType temp;

	temp = ary[front];

	for (int i = 0; i < rear; i++) {
		ary[i] = ary[i + 1];
	}

	rear--;

	return temp;

}

template<typename TheType>
TheType Queue<TheType>::peek() const
{
	return ary[front];
}

template<typename TheType>
bool Queue<TheType>::isFull() const
{
	if (rear == SIZE - 1)
		return true;
	else
		return false;
}

template<typename TheType>
bool Queue<TheType>::isEmpty() const
{
	if (rear == -1)
		return true;
	else
		return false;
}

template<typename TheType>
Queue<TheType>::Queue()
{
	front = 0;
	rear = -1;
}

#endif

