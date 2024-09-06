#include "singleton.hpp"

#include <vector>
template <class T, class U>
T* Singleton<T, U>::_instance = 0;

template <class T, class U>
T* Singleton<T, U>::getInstance()
{
    if (_instance == 0) {
        _instance = new T();
    }
    return _instance;
}
template <class T, class U>
std::vector<U *> Singleton<T, U>::getList()
{
    return this->_List;
}
template <class T, class U>
U* Singleton<T, U>::getObject(U *p_var)
{
    for (size_t i = 0; i < _List.size(); i++)
    {
        if (_List[i] == p_var)
        {
            return _List[i];
        }
    }
    std::cout << " Object Not Found " << std::endl;
    return NULL;
}
template <class T, class U>
int Singleton<T, U>::addObject(U *p_var)
{
    for (size_t i = 0 ; i < _List.size(); i++)
    {
        if (_List[i] == p_var)
        {
            std::cout << " Object Already Exists " << std::endl;
            return 1;
        }
    }
    this->_List.push_back(p_var);
    return 0;
}
template <class T, class U>
int Singleton<T, U>::removeObject(U *p_var)
{
    for (size_t i = 0 ; i < _List.size(); i++)
    {
        if (_List[i] == p_var)
        {
            _List.erase(_List.begin() + i);
            return 0;
        }
    }
    std::cout << " Object Not Found " << std::endl;
    return 1;
}
template <class T, class U>
Singleton<T, U>::~Singleton()
{
    this->_List.clear();
}

template class Singleton<RoomList, Room>;
template class Singleton<CourseList, Room>;
template class Singleton<StaffList, Person>;
template class Singleton<StudentList, Person>;