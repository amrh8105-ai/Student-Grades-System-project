#include <iostream>
#include<string>
#include<vector>
#include<limits>
#include<algorithm>
using namespace std;

struct student {
    string name;
    int id;
    double grade;

};

vector<student> students;

void linearsearch (vector<student>& students , int n , string x  ) {
    for (int i=0 ; i<n ; i++) {
        if (students[i].name == x) {
            cout << "student found " << endl;
            cout <<"the student id is : " << students[i].id << " and the grade of this student is : " << students[i].grade << endl;
            return ;
        }
        cout << "student doesn't exist" << endl ;



    }
}
void binarysearch (vector<student>& students , int n  , int y) {
    int s =0 ;
    int e=n-1 ;
    int m;
    sort(students.begin(), students.end(),
         [](student a, student b) {
             return a.id < b.id;
         });
    while (s<=e) {
        m = (s+e)/2;
        if (students[m].id == y) {
            cout << "student found " << endl;
            cout << "the student name is : " << students[m].name  << " " << " and the grade of this student is : " << students[m].grade << endl;
            return ;
        }
        else if (students[m].id > y) {
            s=m+1 ;
        }
        else {
            e=m-1;
        }

    }
    cout << "student doesn't exist" << endl ;
}

void bubbleSort(vector<student>& students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

double sumGrades(vector<student>& students, int i=0) {
    if (i == students.size()) {
        return 0;
    }

    return students[i].grade + sumGrades(students, i + 1);
}

double averageGrade(vector<student>& students) {
    if (students.empty()) {
        cout << "no students found" << endl;
    }

    return sumGrades(students, 0) / students.size();
}

void mainmenu () {
    cout << "=====system grades system=====" << endl;
    cout <<"please enter your choice" << endl;
    cout << "1- add a student" << endl;
    cout << "2- display all students " << endl;
    cout <<"3- sort all students " << endl;
    cout << "4- search for a student " << endl;
    cout << "5- class average" << endl;
    cout <<"6- the best and the worst students " << endl;
    cout <<"7- exit" << endl;
}


int main () {
    int choice ;
    string name;
    int id ;
    double grade;
    while (choice != 7) {
        mainmenu();
        cin >> choice ;

        if (choice == 1) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "please enter the student name" << endl;
            getline(cin,name);
            cout<< "please enter the student id" << endl;
            cin >> id;
            cout << "please enter the student grade" << endl;
            cin >> grade;
            students.push_back(student(name,id,grade));
            cout << "student successfully added" << endl;

        }
        else if (choice == 2) {
            for (int i=0 ; i<students.size(); i++) {
                cout << "Name : " << students[i].name << " " << "||" << "Id : " <<  students[i].id << " " << "||" << "Grade : " << students[i].grade << endl;


            }
        }
        else if (choice == 3) {
            bubbleSort(students, students.size());
            for (int i=0 ; i<students.size(); i++) {
                cout << i+1 <<") " << "Name : " << students[i].name << " " << "ID : " << students[i].id << " " << "Grade : " << students[i].grade << endl;
            }


        }
        else if (choice == 4) {
            int c=0 ;

            while (c!=3) {
                cout <<"enter your choice" << endl;
                cout << "1- search by id" << endl;
                cout << "2- search by name" << endl;
                cout <<"3- exit this choice" << endl;
                cin >> c;
                if (c ==1) {
                    cout << "please enter the student id" << endl;
                    cin >> id ;
                    binarysearch(students, students.size(), id) ;


                }
                else if (c == 2) {
                    cout << "please enter the student name" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin,name);
                    linearsearch(students, students.size(), name);


                }
                else if (c == 3) {
                    cout << "exiting this choice" << endl;
                    break ;
                }
                else {
                    cout <<"invalid choice try again" << endl;
                }


            }

        }
        else if (choice == 5) {
            cout << "the class average is: " << averageGrade(students) << endl;
        }
        else if (choice == 6) {
            bubbleSort(students, students.size());
            int n = students.size();
            cout <<"the best student is : " << students[0].name << " " << "||||" << "and the worst is : " << students[n-1].name << endl;

        }
        else if (choice == 7) {
            cout <<"thank you" << endl;
            break ;

        }
        else {
            cout <<"invalid choice try again" << endl;
        }
    }
    return 0;
}









