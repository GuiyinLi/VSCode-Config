/*
 * @Author: Ken Kaneki
 * @Date: 2020-04-08 13:28:49
 * @LastEditTime: 2020-04-08 13:29:44
 * @Description: README
 * @FilePath: \C-C++_SimpleFile_Example\cpptest.c++
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
