
#include "mylist.h"
#include <iostream>
namespace Neeraj
{




        
//remove data from the list

void ForwardList::remove(const int& item_)
{
    if(!empty())
    {
        for(iterator it = begin(); it != end(); ++it)
        {
            if(item_ == ((it._node)->_data))
            {
                Node *front = it._node;
                Node *temporary = front->_next;
                delete front->_next;
                front->_next = temporary;
            }
        }
    }
                
}


}









