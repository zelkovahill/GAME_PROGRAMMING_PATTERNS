#include <iostream>

using namespace std;

template <typename T>

class Singleton
{
    private:
        Singleton(const Singleton&) =delete;
        Singleton& operator = (const Singleton &) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator = (Singleton&&) = delete;

    protected:
        Singleton() = default;
        virtual ~Singleton() = default;

    public:
        static T& getInstance()
        {
            static T instance;
            return instance;
        }  
};

class Cursor : public Singleton<Cursor>
{
   friend class Singleton<Cursor>;

   private:
        Cursor() = default;
    
    public:
        virtual ~Cursor() = default;
};

int main()
{
    Cursor& cursor = Cursor::getInstance();
    Cursor& cursor2 = Cursor::getInstance();

    cout << &cursor << endl;
    cout << &cursor2 << endl;

}