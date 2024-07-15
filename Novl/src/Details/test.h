#include <iostream>

#ifdef NOVL_PLAT_WINDOWS
    #ifdef NOVL_BUILD_DLL
        #define NOVL_API __declspec(dllexport)
    #else
        #define NOVL_API __declspec(dllimport)
    #endif
#else 
    #define NOVL_API
#endif

class NOVL_API Test
{
private:
    /* data */
public:
    Test(/* args */){};
    ~Test(){};

    void test1()
    {
        std::cout << "hello xmake" << std::endl;
    }

    void test2();
    
};
