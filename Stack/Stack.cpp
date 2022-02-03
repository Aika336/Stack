#include <iostream>

template<typename T = int> class Stack {
	T* buffer;
	int size;
public:
	Stack();
	~Stack();

	void push(T value);
	void pop();
	T& top();

	bool empty();
	int GetSize() { return size; }
};

template<typename T>
inline Stack<T>::Stack() {
	size = 1;

	buffer = nullptr;
}

template<typename T>
Stack<T>::~Stack()
{
	if(buffer != nullptr)
		delete[] buffer;
}

template<typename T>
inline bool Stack<T>::empty() {
	if (size)
		return false;
	return true;
}

template<typename T>
inline void Stack<T>::push(T value) {
	if (buffer == nullptr) {
		buffer = new T[1];
		*buffer = value;
	}
	else {
		T* temp = new T[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			*(temp + i) = *(buffer + i);
		}
		*(temp + size) = value;
		size++;

		delete[] buffer;
		buffer = temp;
	}
}

template<typename T>
void Stack<T>::pop() {
	size--;
	T* temp = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		*(temp + i) = *(buffer + i);
	}
	delete[] buffer;

	buffer = temp;
}

template<typename T>
T& Stack<T>::top() {
	return *(buffer + size - 1);
}

int main() {

	Stack<int> stack;
	stack.push(21);
	stack.push(22);
	stack.push(24);
	stack.push(25);

	stack.pop();
	stack.pop();

	while (!stack.empty()) {
		std::cout << ' ' << stack.top();
		stack.pop();
	}

	return 0;
}