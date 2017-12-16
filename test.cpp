

#include <iostream>
#include <vector>
#include <list>
class na
{
    public:
    private:
        class name
        {
            ;
        };
        typedef name it;
};
    
template <class T>
T* val(T item)
{
    T* data = new T(item);
    return data;
}        
int main()
{
    int *p = val<int>(45);
    std::cout << *p ;   
    return 0;   
}

