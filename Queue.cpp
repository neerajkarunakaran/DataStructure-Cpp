#include<iostream>


class Queue
{
        public:
                Queue()
                        :_front(-1)
                         ,_rear(-1)
        {}


                bool enqueue(int data)
                {
                        if(isFull())
                        {
                                return false;
                        }
                        else if(isEmpty())
                        {
                                _front = _rear = 0;
                        }
                        else
                        {
                                _rear = (_rear + 1) % 5;
                        }
                        _circularArray[_rear] = data;
                        return true;

                }

                void dequeue()
                {
                        if(isEmpty())
                        {
                                return;
                        }
                        else if(_rear == _front)
                        {
                                _rear = _front = -1;
                        }
                        else
                        {
                                _front = (_front + 1) % 5;
                        }
                }

                int front()
                {
                        _circularArray[_front];
                }

                bool isEmpty()
                {
                        return (-1 ==_front && -1 == _rear);
                }

                bool isFull()
                {
                        return (_rear + 1) % 5 == _front;
                }

                void print()
                {
                        if(!isEmpty())
                        {
                                int i = _front;
                                do
                                {
                                        std::cout << _circularArray[i] << "  ";
                                        i = ++i % 5;
                                }while(i != _rear);
                                std::cout << _circularArray[_rear] << std::endl;
                        }
                }
        private:

                int _circularArray[5];

                int   _front;
                int   _rear;
};
