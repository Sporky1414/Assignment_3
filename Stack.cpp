#include <iostream>

using namespace std;

template <class T>

//header file
class GenStack {
  public:
    GenStack();
    ~GenStack();

    void push(T data);
    T pop();
    T peek();

    bool isEmpty();
    int getSize();

  private:
    bool isFull();
    void resize();

    T *stackArray;
    int top; //top element of stack
    int currArraySize;
};

//implementation file

template <class T>
GenStack<T>::GenStack() {
  stackArray = new T[10];
  currArraySize = 10;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack() {
  delete stackArray;
}

template <class T>
void GenStack<T>::push(T data) {
  stackArray[++top] = data;
  if(isFull()) {
    resize();
  }
}

template <class T>
T GenStack<T>::pop() {
  try {
    if(isEmpty()) {
      throw 20;
    } else {
      return stackArray[top--];
    }
  } catch (int e) {
    cout << "EXCEPTION: Stack is Empty. Please input data before pop!" << endl;
    abort();
  }
}

template <class T>
T GenStack<T>::peek() {
  try {
    if(isEmpty()) {
      throw 20;
    } else {
      return stackArray[top];
    }
  } catch(int e) {
    cout << "EXCEPTION: Stack is Empty. Please input data before peek!" << endl;
    abort();
  }
}

template <class T>
bool GenStack<T>::isEmpty() {
  return (top == -1);
}

template <class T>
int GenStack<T>::getSize() {
  return (top + 1);
}

template <class T>
bool GenStack<T>::isFull() {
  return (top == currArraySize - 1);
}

template <class T>
void GenStack<T>::resize() {
  int tempSize = currArraySize * 2;
  T *tempArray = new T[tempSize];
  for(int i = 0; i < currArraySize; ++i) {
    tempArray[i] = stackArray[i];
  }
  stackArray = tempArray;
  currArraySize = tempSize;
}
