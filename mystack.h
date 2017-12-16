
#ifndef MYLIST_H
#define MYLIST_H
#endif
#ifndef MYSTACK_H
#define MYSTACK_H

namespace Neeraj
{

class Stack
{

    public:
        
        void pushBack(int newItem_)      // insert item into Stack
        {
            _forwardList.pushFront(newItem_);
        };
        void popBack()                  // delete item from Stack
        {
              _forwardList.popFront();
        };
        bool empty()                  // check for Stack empty
        {
            return _forwardList.empty();
        };
        const int& top()             // return reference of top element from Stack
        {
             return _forwardList.front();
        };

        void display()const              // print Stack items
        {
            _forwardList.display();
        };
    private:
        ForwardList _forwardList;
};

}

#endif
