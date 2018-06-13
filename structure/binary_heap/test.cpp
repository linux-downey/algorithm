#include <iostream>


template <class T>
class test
{   
    public:
    T func1(T data);
    T func2(T data);
};


template <typename T>
T test<T>::func1(T data)
{
    std::cout<<"hello1"<<std::endl;
}

template <typename T>
T test<T>::func2(T data)
{
    std::cout<<"hello2"<<std::endl;
}

int main()
{
    test<char> BB;
    BB.func1(1);
    BB.func2(2);
}