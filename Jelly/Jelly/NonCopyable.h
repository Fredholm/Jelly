#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

// Pretty straight-forward
// Extend class from this to make it not copyable with it-self

class NonCopyable
{
public:
    NonCopyable() { }
    NonCopyable(const NonCopyable& other) = delete;
    NonCopyable* operator=(const NonCopyable& other) = delete;
    virtual ~NonCopyable() { }
};

#endif // !NONCOPYABLE_H
