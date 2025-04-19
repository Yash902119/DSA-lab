#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Emp {
    int empid;
    char name[20];
    char design[20];
    float salary;

public:
    Emp() {
        empid = 0;
        strcpy(name, "");
        strcpy(design, "");
        salary = 0.0;
    }

    int acceptempid() {
        return empid;
    }

    void getdata() {
        cout << "\nEnter Emp details:";
        cout << "\nEnter emp id: ";
        cin >> empid;
        cout << "Enter emp name: ";
        cin >> name;
        cout << "Enter Designation: ";
        cin >> design;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void display() {
        cout << "\nEmp Details";
        cout << "\nEmp id = " << empid;
        cout << "\nEmp Name = " << name;
        cout << "\nDesignation = " << design;
        cout << "\nSalary = " << salary;
    }
};

class fileop {
    ifstream fin;
    ofstream fout;
    fstream fs;

public:
    void insert();
    void show();
    void search(int);
    int deleterecord(int);
    int append(int);
};

void fileop::insert() {
    Emp obj;
    obj.getdata();
    fout.open("data.txt", ios::binary | ios::app);
    fout.write((char*)&obj, sizeof(obj));
    fout.close();
}

void fileop::show() {
    Emp obj;
    fin.open("data.txt", ios::binary);
    fin.seekg(0, ios::beg);
    while (fin.read((char*)&obj, sizeof(obj))) {
        obj.display();
    }
    fin.close();
}

void fileop::search(int rno) {
    Emp obj;
    int flag = 0;
    fin.open("data.txt", ios::binary);
    fin.seekg(0, ios::beg);
    while (fin.read((char*)&obj, sizeof(obj))) {
        if (obj.acceptempid() == rno) {
            flag = 1;
            break;
        }
    }
    fin.close();
    if (flag == 1) {
        cout << "\nEmp found";
        obj.display();
    } else {
        cout << "\nEmp not found";
    }
}

int fileop::deleterecord(int rno) {
    Emp obj;
    int flag = 0;
    fin.open("data.txt", ios::binary);
    ofstream fout_temp("temp.txt", ios::binary);

    while (fin.read((char*)&obj, sizeof(obj))) {
        if (obj.acceptempid() == rno) {
            flag = 1;
        } else {
            fout_temp.write((char*)&obj, sizeof(obj));
        }
    }

    fin.close();
    fout_temp.close();

    remove("data.txt");
    rename("temp.txt", "data.txt");

    return flag;
}

int fileop::append(int rno) {
    Emp obj;
    int flag = 0;
    fs.open("data.txt", ios::in | ios::out | ios::binary);
    fs.seekg(0, ios::beg);

    while (fs.read((char*)&obj, sizeof(obj))) {
        if (obj.acceptempid() == rno) {
            flag = 1;
            cout << "\nEnter new details: ";
            obj.getdata();
            fs.seekp((int)fs.tellg() - sizeof(obj), ios::beg);
            fs.write((char*)&obj, sizeof(obj));
            break;
        }
    }

    fs.close();
    return flag;
}

int main() {
    fileop fobj;
    char ch = 'y';
    int choice, n;

    do {
        cout << "\nMain Menu";
        cout << "\n1. Create";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Append";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: fobj.insert(); break;
            case 2: fobj.show(); break;
            case 3:
                cout << "\nEnter emp id to search: ";
                cin >> n;
                fobj.search(n);
                break;
            case 4:
                cout << "\nEnter emp id to delete: ";
                cin >> n;
                fobj.deleterecord(n);
                break;
            case 5:
                cout << "\nEnter emp id to edit: ";
                cin >> n;
                fobj.append(n);
                break;
            case 6:
                exit(0);
        }

        cout << "\nDo you want to continue (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    return 0;
}
