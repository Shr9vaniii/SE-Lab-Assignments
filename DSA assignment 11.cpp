#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name, address;

    int roll, divi;

    Student() {
        name = address = "";
        roll = divi = 0;
    }

    void getdata() {
        cin.ignore(); // Only once before first getline
        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter the roll no.: ";
        cin >> roll;
        cout << "Enter the division: ";
        cin >> divi;
        cin.ignore(); // To flush newline from buffer
        cout << "Enter the address: ";
        getline(cin, address);
    }

    void showdata() const {
        cout << "Roll No.: " << roll << ", Name: " << name 
             << ", Division: " << divi << ", Address: " << address << endl;
    }

    int getroll() const {
        return roll;
    }
};

class File {
    string filename = "student.txt";
    Student s;

public:
    void addStudent() {
        ofstream file(filename, ios::app);
        if (!file) {
            cout << "Error opening file for writing.\n";
            return;
        }
        s.getdata();
        file << s.roll << '\n' << s.name << '\n' << s.divi << '\n' << s.address << '\n';
        file.close();
    }

    void displaybyroll(int r) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        bool found = false;
        Student temp;
        while (file >> temp.roll) {
            file.ignore();
            getline(file, temp.name);
            file >> temp.divi;
            file.ignore();
            getline(file, temp.address);
            if (temp.roll == r) {
                cout << "Record found:\n";
                temp.showdata();
                found = true;
                break;
            }
        }
        file.close();
        if (!found) {
            cout << "Record with roll number " << r << " not found.\n";
        }
    }

    void deletere(int r) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        ofstream temp("temp.txt");
        bool found = false;
        Student tempStudent;

        while (file >> tempStudent.roll) {
            file.ignore();
            getline(file, tempStudent.name);
            file >> tempStudent.divi;
            file.ignore();
            getline(file, tempStudent.address);

            if (tempStudent.roll == r) {
                cout << "Deleting record:\n";
                tempStudent.showdata();
                found = true;
            } else {
                temp << tempStudent.roll << '\n'
                     << tempStudent.name << '\n'
                     << tempStudent.divi << '\n'
                     << tempStudent.address << '\n';
            }
        }

        file.close();
        temp.close();

        remove("student.txt");
        rename("temp.txt", "student.txt");

        if (!found) {
            cout << "Record not found.\n";
        }
    }

    void display() {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        Student temp;
        bool found = false;
        cout << "\nAll student records:\n";
        while (file >> temp.roll) {
            file.ignore();
            getline(file, temp.name);
            file >> temp.divi;
            file.ignore();
            getline(file, temp.address);
            temp.showdata();
            found = true;
        }

        if (!found) {
            cout << "No records to display.\n";
        }

        file.close();
    }
};

int main() {
    File f;
    int choice, roll;

    do {
        cout << "\n1. Add Student\n2. Display All\n3. Search by Roll\n4. Delete by Roll\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                f.addStudent();
                break;
            case 2:
                f.display();
                break;
            case 3:
                cout << "Enter roll number to search: ";
                cin >> roll;
                f.displaybyroll(roll);
                break;
            case 4:
                cout << "Enter roll number to delete: ";
                cin >> roll;
                f.deletere(roll);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
