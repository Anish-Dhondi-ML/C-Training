// the header file for the program 10_point.cpp
// Try to make our own smart pointer

template <typename T> class Playptr
{

    public:
        Playptr(T *ptr):_ptr(ptr){};
        ~Playptr(){
            delete _ptr;
            _ptr=nullptr;
        }
        T& operator *(){ return *_ptr;}
        T* operator ->(){ return _ptr;}
    private:
        T *_ptr;
};