#include <iostream>
using namespace std;
template<typename S, typename T> class Pair {};
template<typename U> class Pair<string, U>
{
public:
    Pair(string str, U rand) : P_str(str), P_rand(rand) {}
    Pair() {}
    string first() const    
    {
        return P_str;
    }
    U second() const
    {
        return P_rand;
    }

protected:
    string P_str;
    U P_rand;
};

template<typename U> class StringValuePair : public Pair<string, U>
{
public:
    StringValuePair(string str, U rand) : Pair<string, U>(str, rand) {}
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
