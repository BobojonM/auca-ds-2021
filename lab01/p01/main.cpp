#include <iostream>

//entry point 
int main()
{
#ifdef AUCA_DEBUG
    std::cout << "Author: Bobojon Abdulloev" << std::endl;
#endif
    std::cout << "Hello C++ " << __cplusplus << "!!!\n";
}