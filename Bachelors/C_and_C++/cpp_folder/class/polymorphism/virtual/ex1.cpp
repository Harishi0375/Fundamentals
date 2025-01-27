class Base {
public:
    virtual void myFunction() {
        // Base class implementation
    }
};

class Derived : public Base {
public:
    void myFunction() override {
        // Derived class implementation, overrides the base class implementation
    }
};
