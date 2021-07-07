
#include <iostream>
#include<string>
using namespace std;

int TryDiv(int a, int b)
{
    if (b == 0)
    {
        throw exception("Div by zero!");

    }
    return a / b;
}

int Perev(const char* a)
{
    int b;
    b = atoi(a);
    return b;
}

int Perev2(string a)
{
    
        string value;
        int res = stoi(a);
    
    return res;
}


int main()
{
   /* try
    {
        cout << 1 << endl;
        throw "test exp";
    }
    catch (int exp)
    {
        cout << "Exception " << exp << endl;
    }
    catch (const char* exp)
    {
        cout << "Exception 2" << exp << endl;
    }
    catch (...)
    {
        cout << "all exp";
    }
    cout << 2 << endl;*/

    try
    {
        int c = Perev2("123");
        cout << c<< endl;

        if (c<-2000000000|| c > 2000000000)
        {
            throw exception("ljkhiluh");

        }
        
    }
    catch (exception exp)
    {
        cout << "exp : " << exp.what() << endl;
    }
    catch (const char* exp)
    {
        cout << "exp no: "  << endl;
    }
}


