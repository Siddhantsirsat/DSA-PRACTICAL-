#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    int rollno;
    string name, Div, address;

public:
    int add()
    {
        fstream f;
        f.open("test.txt", ios::in);
        cout << "Enter roll no:";
        cin >> rollno;
        int roll;
 while (!f.eof())
        {
            f >> roll >> name >> Div >> address;
            if (rollno == roll)
            {
                cout<<"Roll already exist";
                return -1;
            }
        }     
        f.close();
                f.open("test.txt", ios::app);
        cout << "Enter name:";
        cin >> name;
        cout << "Enter div:";
        cin >> Div;
        cout << "Enter address";
        cin >> address;
        f << rollno<<" "<< name<<" " << Div<<" " << address<<endl;
        f.close();
        return 0;
    }
    void Remove()
    {

        fstream f, f1;

        f.open("test.txt", ios::in);
        f1.open("temp.txt", ios::app);
        int roll;
        cout << "Enter rollno:";
        cin >> roll;
        while (!f.eof())
        {
            f >> rollno >> name >> Div >> address;
            if (rollno != roll)
            {
                f1 << rollno << name << Div << address;
            }
        }
        remove("test.txt");
        rename("temp.txt", "test.txt");
        f1.close();
        f.close();
    }
    void display()
    {
        fstream f;

        f.open("test.txt", ios::in);
        while (!f.eof())
        {
            f >> rollno >> name >> Div >> address;
            cout << "Roll no:" << rollno<<endl;
            cout << "Name:" << name<<endl;
            cout << "Div:" << Div<<endl;
            cout << "Address:" << address<<endl;
        }
        f.close();
    }
     void displayBinary()
    {
        ifstream f("test.txt", ios::binary);
        char buffer[1024];
        while (f.read(buffer, 1024))
        {
            cout<<buffer;
        }
        f.close();
    }
};


int main()
{

    Student s;
    int ch;
    while (true)
    {
        cout << "1.Add\n2.Remove\n3.Display\n4.display in binarty \n any other key for exit";
        cout << "\nEnter your choice";
        cin >> ch;
        if (ch == 1)
        {
            s.add();
        }
        else if (ch == 2)
        {
            s.Remove();
        }
        else if (ch == 3)
        {
            s.display();
        }
        else if (ch == 4)
        {
            s.displayBinary();
        }
        else
        {
            break;
        }
    }

    return 0;
}
