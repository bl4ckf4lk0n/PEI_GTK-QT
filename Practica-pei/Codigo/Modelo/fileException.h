#ifndef FILE_EXCEPTION
#define FILE_EXCEPTION
#include <stdexcept>
using namespace std;

class fileException : public std::runtime_error
{
    public:
        fileException(string mess): runtime_error(mess){}
};
#endif