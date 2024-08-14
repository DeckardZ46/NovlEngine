#include <Example/test.h>

int main(){
#ifdef NOVL_PLAT_WINDOWS
    FreeConsole();
#endif
    Test myTest;
    myTest.testJolt();
    myTest.testLibs();
}