/* MyList header */
#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <exception>
namespace Neeraj
{

template<typename T>
class Node
{
    public:
        Node(T item_);
        Node();
        ~Node();
        T*               _data;
        Node<T> *       _next;
        Node<T> *       _previous;
};

template<class T>
class ListIterator
{
    public:

        ListIterator();
        ListIterator(Node<T> * other_);

        ListIterator &              operator =(const  ListIterator &other_);
        T                           operator *()const;
        ListIterator &              operator ++();
        ListIterator &              operator --();
        bool                        operator ==(const ListIterator<T> &other_)const;
        bool                        operator !=(const ListIterator<T> &other_)const;
        Node<T> *                   _node;
};

template <class T>
class List
{
    public:

        List();
        ~List();
        typedef ListIterator<T> iterator;
        iterator                   begin();
        iterator                   end();
        iterator                   erase(iterator &pos_);                            //erase element from forward list       
        iterator                   insert(iterator &pos_, T& newItem_);        // insert element into forward list
        bool                       empty()const;                                            //check for forward list empty   
        unsigned int               size();     

    private:   

        Node<T> *                  _head;
        Node<T> *                  _tail;
};

template <class T>
Node<T>::Node():_next(0), _previous(0), _data(0){}

template <class T>
Node<T>::Node(T item_) : _next(0), _previous(0) {_data = new T(); *_data = item_;}

template <class T>
Node<T>::~Node()
{
    if(NULL != _data) 
        delete _data;
}

template<class T>
ListIterator<T>::ListIterator(): _node(0){}

template<class T>
ListIterator<T>::ListIterator(Node<T> * other_): _node(other_){}

template<class T>
T ListIterator<T>::operator *()const
{
    return *(_node->_data);
}

template <class T>
ListIterator<T> & ListIterator<T>::operator =(const ListIterator &other_)
{
    _node = other_._node;
    return *this;
}


template<class T>
ListIterator<T>& ListIterator<T>::operator ++()
{
    _node = _node->_next;
    return *this;
}

template<class T>
ListIterator<T> & ListIterator<T>::operator --()
{
    _node = _node->_previous;
    return *this;
}

template <class T>
bool ListIterator<T>::operator ==(const ListIterator<T> &other_)const
{
    if(_node == other_._node)
        return true;
    return false;
}
    
template<class T>
bool ListIterator<T>::operator != (const ListIterator &other_)const
{
    if(_node != other_._node)
        return true;
    return false;
}

template<class T>
List<T>::List() 
{ 
    _head = new Node<T>();
    _tail = _head;
}

template<class T>
ListIterator<T> List<T>::begin()
{
    
    return iterator(_head);
}

template<class T>
ListIterator<T> List<T>::end()
{
    return iterator(_tail);
}

template<class T>
bool List<T>::empty()const            //check for forward list empty
{
    return _head == _tail ? true : false;
}
  
template<class T>
List<T>::~List()
{
    Node<T> *current = _head;

    while(current != NULL)
    {
        Node<T> *nextNode = current->_next;
        delete current;
        current = nextNode;
    }
}

template<class T>
ListIterator<T> List<T>::erase(iterator &pos_)
{
    if(empty() || pos_ == end())
    { 
        throw  std::runtime_error("List empty");
    }

    if(pos_ != begin())
    {
       (pos_._node)->_previous->_next = (pos_._node)->_next;
    }
    else
    {
        _head = pos_._node->_next;
    }
    (pos_._node)->_next->_previous = (pos_._node)->_previous;
    ListIterator<T> ret(pos_._node->_next);
    delete (pos_._node);
    return ret;
}
 
//insert node at any postion in list
template<class T>
ListIterator<T> List<T>::insert(iterator &pos_, T& newItem_)
{
    Node<T>* newNode = new Node<T>(newItem_);
    newNode->_previous = pos_._node->_previous;
    newNode->_next = pos_._node;

    if(pos_ != begin())
    {
       pos_._node->_previous->_next = newNode;
    }
    else
    {
       _head = newNode;
    }
    pos_._node->_previous = newNode;
    ListIterator<T> iterator(newNode);
    return iterator;

}
       
template <class T>
unsigned int List<T>::size()
{
    if(!empty())
    {
        iterator it = begin();
        unsigned int count;

        for(count = 0; it != end(); ++it, ++count);

        return count;
    }

    else
        return 0;
}

template <class T>        
void advance(ListIterator<T> &it, unsigned int pos_)
{
    for(unsigned int i = 1; i < pos_ && NULL != it._node; ++i, ++it)
    ;
}
       
}


#endif
