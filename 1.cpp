#include <iostream>
using namespace std;
template <class T>
class Pair1
{
public:
    Pair1(T num1, T num2) : P_num1(num1), P_num2(num2) {}
	T first() const
    {
        return P_num1;
    }
    T second() const
    {
        return P_num2;
    }

private:
    T P_num1;
    T P_num2;
};

int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    return 0;
}