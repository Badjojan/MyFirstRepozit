

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Firm {
    char name[255];
    int age = 0;

public:
    Firm(const string &_name= "No name", int _age=0) {
        set_name(_name);
        set_age(_age);
    }
    void clear() {
        name[0] = '\0';
        age = 0;
    }
    string get_name() const {
        return string(reinterpret_cast<const char *>(name));
    };

    void set_name(string _name) {
        std::strncpy(reinterpret_cast<char *>(name), _name.c_str(), 255);
        

    };
    int get_age() const {

        return age;
    };
    void set_age( int _age) {
       
        age = _age;

    };

    
};
 ostream& operator<<(ostream& os, const Firm& firm) {
    os << "Name: " << firm.get_name() << "Age :" << firm.get_age();
    return os;

}
 istream& operator>>(istream& is,  Firm& firm) {
     string _name;
     int _age;

     cout << "name:";
     is >> _name;
     cout << "age:";
     is >> _age;
     firm.set_age(_age);
     
     firm.set_name(_name);
     return is;
}
 
 ofstream& operator<<(ofstream& of,const  Firm& firm) {

     of.write(reinterpret_cast<const char*>(&firm),sizeof(firm));
     of.flush();
     return of;
 }
 ifstream& operator>>(ifstream& gg, Firm& firm) {
     gg.read(reinterpret_cast< char*>(&firm), sizeof(firm));
     return gg;
 }

int main()
{
#if 0
    Firm a;
    cin >> a;
    Firm b;
    cin >> b;
    /*cout << a;*/

    ofstream os("wb.dat",ios::binary);
    os << a;
    os << b;

#else
    Firm firm;
    ifstream is("wb.dat", ios::binary);
    while (is >> firm) {
        
        if (firm.get_name() == "")
            break;
        firm.clear();
    }
    cout << firm << endl;
#endif
    return 0;
    
}


