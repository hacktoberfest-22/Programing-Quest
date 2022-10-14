#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
public:
    Student(string s)
    {
        name = s;
    }
    Student()
    {
        name = "Unknown";
    }
    void print_name()
    {
        cout << name << endl;
    }
    ~Student()
	{
		cout<<"Object Destroyed"<<endl;
	}
};

int main()
{
    Student s1("Aaryan");
    Student s2;
    s1.print_name();
    s2.print_name();
    return 0;
}                        