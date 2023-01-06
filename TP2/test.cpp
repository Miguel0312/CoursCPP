#include<vector>
#include<iostream>
using namespace std;

class foo{
    public:
    virtual void print(){
        cout<<"foo\n";
    }
};

class bar : public foo{
    public:
    void print(){
        cout<<"bar\n";
    }
};


int main(){
    vector<foo> v;
    foo f1;
    bar f2;
    v.push_back(f1);
    v.push_back(f2);
    v[0].print();
    v[1].print();
    f1.print();
    f2.print();
}