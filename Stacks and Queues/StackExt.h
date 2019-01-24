# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
private:
	stack<T> stlStack;
	stack<T> minValues;
public:
	StackExt() {};
	bool empty() const;
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

template <class T>
bool StackExt<T>::empty() const {
	return this->stlStack.empty();
}

template <class T>
T& StackExt<T>::top() {
	if (!this->stlStack.empty())
		return this->stlStack.top();
}

template <class T>
void StackExt<T>::pop() {
	if (!this->stlStack.empty())
	{
		if (!this->minValues.empty())
		{
		if (this->minValues.top() == this->stlStack.top())
			this->minValues.pop();
		}
		this->stlStack.pop();
	}
}

template <class T>
void StackExt<T>::push(const T& val) {
	this->stlStack.push(val);

	if (this->minValues.empty() || val < this->minValues.top())
		this->minValues.push(val);
}

template <class T>
T& StackExt<T>::findMin() {
	if (!minValues.empty())
		return this->minValues.top();
}
