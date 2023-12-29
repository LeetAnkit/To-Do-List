#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int ID;


struct todolist {
    int id;
    string task;
};


void addtodo() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl << endl << endl;

    todolist todo;
    cout << "\n\tEnter new task: ";
    cin.get();
    getline(cin, todo.task); 
    ID++; 

   
    ofstream write;
    write.open("todo.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << todo.task ;
    write.close();

   
    write.open("id.txt");
    write << ID;
    write.close();

    char ch;
    cout << "Do you want to add more task? y/n" << endl;
    cin >> ch;

    
    if(ch == 'y') {
        addtodo();
    } else {
        cout << "\n\tTask has been added successfully";
        return;
    }
}


void print(todolist s) {
    cout << "\n\tID is : " << s.id;
    cout << "\n\tTask is : " << s.task;
}


void readData() {
    system("cls");
    cout << "\t\t\t***********************************************************************" << endl;
    cout << "\t\t\t                       WELCOME TO Your ToDo List                       " << endl;
    cout << "\t\t\t***********************************************************************" << endl;

    ifstream read;
    read.open("todo.txt");

    todolist todo;
    while(read >> todo.id) {
        getline(read, todo.task);
        print(todo);
    }

    read.close();
}

int main() {
    readData();
    addtodo();
    return 0;
}
