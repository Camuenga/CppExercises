#include <iostream>

using namespace std;

class test{
public:
    test(float value) : value(value){}
    float value;
    float set(float value){
        test::value += value;
        return value;
    }
    float get(float value){
        return test::value + value;
    }
};


int main()
{
    test obj,obj2(1.0);// return error: no matching function for call to ‘test::test()’ because was not found a standard constructor whitout parameter
    std::cout << obj.get(1.5);
    return 0;
}
