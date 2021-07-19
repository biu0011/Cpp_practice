#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Sreen
{
public:
    typedef string::size_type pos;
    Sreen() = default;
    Sreen(pos p1, pos p2, char c) : width(p1), height(p2), contents(p1 * p2, c) {}
    char get() const { return contents[cursor]; }
    char get(pos p1, pos p2) const;
    Sreen &move(pos p1, pos p2);
    Sreen &set(pos wd, pos ht, char c);
    Sreen &set(char c);
    const Sreen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    };
    Sreen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }

private:
    pos width = 0, height = 0;
    pos cursor = 0;
    string contents = "";
    void do_display(ostream &os) const
    {
        os << contents;
    }
};

inline char Sreen::get(pos p1, pos p2) const
{
    return contents[width * p1 + p2];
}

inline Sreen &Sreen::move(pos p1, pos p2)
{
    cursor = width * p1 + p2;
    return *this;
}

inline Sreen &Sreen::set(pos wd, pos ht, char c)
{
    contents[width * wd + ht] = c;
    return *this;
}

inline Sreen &Sreen::set(char c)
{
    contents[cursor] = c;
    return *this;
}