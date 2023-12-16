#include <iostream>
#include <exception>

using namespace std;

class MathException : public std::exception 
{
public:
    virtual const char* what() const throw() 
    {
        return "Math error occurred";
    }
};

class DivisionByZeroException : public MathException 
{
public:
    const char* what() const throw()
    {
        return "Division by zero";
    }
};

class OverflowException : public MathException 
{
public:
    const char* what() const throw()
    {
        return "Overflow error";
    }
};

class FileException : public exception 
{
public:
    virtual const char* what() const throw()
    {
        return "File error occurred";
    }
};

class MemoryException : public exception 
{
public:
    const char* what() const throw() 
    {
        return "Memory allocation error";
    }
};

int main() 
{
    try 
    {
        throw DivisionByZeroException();
    }
    catch (const exception& x)
    {
        cout << x.what() << endl;
    }

    try
    {
        throw MemoryException();
    }
    catch (const exception& x) 
    {
        cout << x.what() << endl;
    }

    return 0;
}