#include <iostream>

class Parent {
private:
    int privateData;
public:
    void setPrivateData(int data) {
        privateData = data;
    }
    void accessPrivateData() {
        std::cout << "Accessing private data: " << privateData << std::endl;
    }
};

class Child : public Parent {
public:
    void setPrivateDataFromChild(int data) {
        // Can access the protected member function of the base class
        setPrivateData(data);
    }
// void accessPrivateData() {
//         std::cout << "Accessing private data: " << privateData << std::endl;
//     }
};

int main() {
    Child childObject;

    // childObject.setPrivateData(42);  // Error: Cannot access private member directly
    childObject.setPrivateDataFromChild(42); // OK: Access through a protected member function
    childObject.accessPrivateData(); // OK: Access through a public member function

    return 0;
}
