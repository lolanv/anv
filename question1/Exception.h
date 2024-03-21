#ifndef EXCEPTION_H
#define EXCEPTION_H


#include<stdexcept>
#include<cstring>

class Exception : public std::exception
{
private:
    /* data */
    char* _msg;
public:
    /*  */
    Exception() = delete;
    Exception(const Exception&) = delete;
    Exception(Exception&&) = default;
    Exception& operator=(const Exception&) = delete;
    Exception&& operator=(Exception&&) = delete;

    Exception(const char* msg) {
        // strlen();
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    ~Exception() {
        delete _msg;
    }

    //overriding what function
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return _msg;
    }
};
#endif // EXCEPTION_H
