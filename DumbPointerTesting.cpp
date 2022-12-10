#include <memory>
#include <vector>
#include <iostream>

int main()
{
    std::unique_ptr<int> p1(new int(5));

    std::reference_wrapper<int> p2 = std::ref(*p1);
    delete p2;
}