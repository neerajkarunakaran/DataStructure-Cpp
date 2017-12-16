



#include <iostream> 
#include "mylist.h"

int main()
{
    Neeraj::List<std::string> list;
    Neeraj::List<std::string>::iterator it = list.begin();
    std::string s;
    std::cin>> s;
    it = list.insert(it, s);
    std::cin >> s;
    it = list.insert(it, s);
    std::cin >> s;
    it = list.insert(it, s);
    it = list.begin();
    for(it; it != list.end(); ++it)
        std::cout << *it << std::endl;
    it = list.begin();
    ++it;
    list.erase(it);
    for(it = list.begin(); it != list.end(); ++it)
        std::cout << *it << std::endl;


    return 0;
}
