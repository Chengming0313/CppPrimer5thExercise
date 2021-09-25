//
//  test.cpp
//
//  Created by Tang Chengming on 2021/9/11.
//
//  @Brief  
//

class A {
public:
    int data1 = 0;
protected:
    int data2 = 1;
private:
    int data3 = 2;
};

class PubA : public A{
    void f() {

    }
};

class ProtA : protected A {
    void f() {

    }
};

class from_ProtA : public ProtA {

};

int main() {
    PubA pubA;
    ProtA protA;
    from_ProtA fromProtA;
    fromProtA.data1;
    int i = pubA.data2;
    return 0;
}