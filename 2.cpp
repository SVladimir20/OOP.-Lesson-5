#include <iostream>
using namespace std;
template <class T1, class T2>
class Pair
{
public:
    Pair(T1 num1, T2 num2) : P_num1(num1), P_num2(num2) {}
    T1 first() const
    {
        return P_num1;
    }
    T2 second() const
    {
        return P_num2;
    }

private:
    T1 P_num1;
    T2 P_num2;
};

int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    return 0;
}