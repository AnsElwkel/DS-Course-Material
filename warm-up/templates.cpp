#include <iostream>
using namespace std;


// templates are not compiled until you make an instance from them, or call them, to determine what type they should have
// we can use "class" keyword instead of "typename"

// template function
template<typename type>
type add (type a, type b){
    return  a + b;
}

// template class
template<typename T>
class Box{
private:
    T box_item;

public:
    Box(T box_item){
        this->box_item = box_item;
    }
    void show_item(){
        cout << "item in the box [ " << this->box_item << " ]" << endl;
    }
};

// specialized template
// excludes specific type from the general template
template<>
class Box<string>{
private:
    string box_item;

public:
    Box(string box_item){
        this->box_item = box_item;
    }
    void show_item(){
        cout << "string in the box [ " << this->box_item<< " ]" << endl;
    }
};

int main() {
    Box<int> box1(5);
    Box<string> box2("hello");
    box1.show_item();
    box2.show_item();

    return 0;
}
