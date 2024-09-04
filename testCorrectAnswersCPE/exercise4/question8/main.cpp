#include <iostream>

using namespace std;

class test{
public:
    test(test &Tvalue) : value(Tvalue.get(0.0)){}
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
    test *obj = new test(1.0),*obj2 = new test(*obj);// return error: no matching function for call to ‘test::test()’ because was not found a standard constructor whitout parameter
    std::cout << obj->get(obj2->set(obj->value));
    delete obj,obj2;
    return 0;
}
