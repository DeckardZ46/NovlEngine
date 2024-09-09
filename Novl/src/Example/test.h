/**
 * < Novl Engine > test.h
 * Author: DeckardZ46
 * Date: 2024/07/10
 * Note: This is a demo program to test third party libs, use it after linking Novl.dll and add include path properly
 * --- Example usage: --------------
 *      #include <Example/test.h>
 *      int main(){
 *          Test myTest;
 *          myTest.testLibs();
 *      }
 * ---------------------------------
 * Codebase: https://github.com/DeckardZ46/NovlEngine
 */

#include <RuntimeCommon.h>
#include <iostream>

namespace Novl{
    class NOVL_API Test
    {
    private:
        /* data */
        static int privateInt;
    public:
        Test(/* args */){};
        ~Test(){};

        void testLibs();
        // void testJolt();
    };
}