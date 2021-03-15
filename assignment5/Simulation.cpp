#include "Simulation.h"
#include <iostream>
#include <fstream>

using namespace std;

//default constructor
Simulation::Simulation(){
  masterFaculty = new BST<Faculty>();
  masterStudent = new BST<Student>();
  rollBackStudent = new GenStack<Student>();
  rollBackFaculty = new GenStack<Faculty>();
  rollBackNum = new GenStack<int>();

  choice = 0;
  studentID = 0;
  facultyID = 0;
  stud = true;
  undo = 0;
}

//overload constructor
Simulation::Simulation(string file, string file2){

  //making the BST
  masterFaculty = new BST<Faculty>();
  masterStudent = new BST<Student>();

  int count = 0;
  string line = "";

  //reading into the file
  ifstream infile(file);

  //member variables
  int id = 0;
  string name = "";
  string level = "";
  string major = "";
  double gpa = 0.0;
  int advisor = 0;

  string department = "";
  int advisee = 0;

  //reading into the studentTable file to add pre-existing nodes to student BST
  while(getline(infile, line)){

    if(count == 0){
      id = stoi(line);
      count++;
      continue;
    }

    if(count == 1){
      name = line;
      count++;
      continue;
    }

    if(count == 2){
      level = line;
      count++;
      continue;
    }

    if(count == 3){
      major = line;
      count++;
      continue;
    }

    if(count == 4){
      gpa = stoi(line);
      count++;
      continue;
    }

    if(count == 5){
      advisor = stoi(line);
      count++;
    }

    if(count == 6){
      Student *s = new Student(id, name, level, major, gpa, advisor);
      masterStudent->insert(id, s);
      count = 0;
    }
  }

  //reading into facultyTable file to add pre-existing faculty nodes to BST
  ifstream infile2(file2);

  while(getline(infile2, line)){


    if(count == 0){
      id = stoi(line);
      count++;
      continue;
    }

    if(count == 1){
      name = line;
      count++;
      continue;
    }

    if(count == 2){
      level = line;
      count++;
      continue;
    }

    if(count == 3){
      department = line;
      count++;
      continue;
    }

    if(count == 4){
      Faculty *f = NULL;
      string s;
      int count2 = 0;

      //case for accounting for multiple advisees
      for(char c : line){
        if(c != ' '){
          s += c;
        }else if(c == ' '){
          advisee = stoi(s);
          if(count2 == 0){
            f = new Faculty(id, name, level, department, advisee);
            masterFaculty->insert(id, f);
            count2++;
            s = "";
            continue;
          }else{
            f->addAdvisee(advisee);
            s = "";
            continue;
          }
        }
      }
      advisee = stoi(s);
      if(count2 != 0){
        f->addAdvisee(advisee);
      }

      if(count2 == 0){
        f = new Faculty(id, name, level, department, advisee);
        masterFaculty->insert(id, f);
      }
      count = 0;
    }
  }

  //rollback stacks
  rollBackStudent = new GenStack<Student>();
  rollBackFaculty = new GenStack<Faculty>();
  rollBackNum = new GenStack<int>();

  choice = 0;
  studentID = 0;
  facultyID = 0;
  stud = true;
  undo = 0;
}

//destructor
Simulation::~Simulation(){
  delete masterFaculty;
  delete masterStudent;
  delete rollBackFaculty;
  delete rollBackStudent;
}


//simulation method that performs the commands of the program
void Simulation::simulation(){

  //members variables
  int id = 0;
  int facultyID = 0;
  int studentID = 0;
  string name = "";
  string level = "";
  string major = "";
  double gpa = 0.0;
  int advisor = 0;
  int ad = 0;

  string department = "";
  int advisee = 0;

  bool loop = true;

  //printing the avaliable choices to the user
  while(loop){
    cout << "-------------------------------------------"<< endl;
    cout << "1. Print all students and their information (sorted by ascending id #" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id" << endl;
    cout << "11. Add a new student and its new faculty advisor" << endl;
    cout << "12. Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "13. Remove an advisee from a faculty member given the ids" << endl;
    cout << "14. Rollback" << endl;
    cout << "15. Exit" << endl;
    cout << endl;

    cout << "Enter number of choice: ";
    cin >> choice;

    //printing student tree
    if(choice == 1){
      masterStudent->printTree();
    }

    //printing faculty tree
    if(choice == 2){
      masterFaculty->printTree();
    }

    //printing information of one student
    if(choice == 3){

      cout << "Enter Student ID to display info: ";
      cin >> studentID;

      //if the ID doesnt exist
      if(masterStudent->search(studentID) == NULL){
        cout << "Invalid Student ID, try again" << endl;
        continue;
      }

      masterStudent->search(studentID)->getInfo();
      cout << endl;
    }

    //printing info of one faculty
    if(choice == 4){

      cout << "Enter Faculty ID to display info: ";
      cin >> facultyID;

      //if the ID doesnt exist
      if(masterFaculty->search(facultyID) == NULL){
        cout << "Invalid Faculty ID, try again" << endl;
        continue;
      }

      masterFaculty->search(facultyID)->getInfo();
    }

    //printing name and info of faculty advisor
    if(choice == 5){

      cout << "Enter Student ID to show advisor: ";
      cin >> studentID;

      //if the ID doesnt exist
      if(masterStudent->search(studentID) == NULL){
        cout << "Invalid Student ID, try again" << endl;
        continue;
      }

      Student *temp = masterStudent->search(studentID);
      facultyID = temp->getID();

      masterFaculty->search(facultyID)->getInfo();

    }

    ///printing name and info and faculty advisees
    if(choice == 6){
      cout << "Enter Faculty ID to show advisees: ";
      cin >> facultyID;

      //if the ID doesnt exist
      if(masterFaculty->search(facultyID) == NULL){
        cout << "Invalid Faculty ID, try again" << endl;
        continue;
      }

      Faculty *temp = masterFaculty->search(facultyID);
      GenDoublyLinkedList<int> *list = temp->getAdvisees();

      int size = list->getSize();

      for(int i = 0; i < size; i++){
        int studentID = list->removeFront();
        masterStudent->search(studentID)->getInfo();
        temp->addAdvisee(studentID);
      }
    }

    //adding a student
    if(choice == 7){


      cout << "Enter ID: ";
      cin >> id;

      //if the ID is already in the tree
      if(masterStudent->search(id) != NULL){
        cout <<  "ID already in use, please try again";
        continue;
      }

      cout << "Enter name: ";
      cin >> name;
      cout << "Enter level: ";
      cin >> level;
      cout << "Enter major: ";
      cin >> major;
      cout << "Enter GPA: ";
      cin >> gpa;
      cout << "Enter faculty advisor ID: ";
      cin >> facultyID;
      cout << endl;

      Student *s = new Student(id, name, level, major, gpa, facultyID);
      masterStudent->insert(id, s);

      if(masterFaculty->search(facultyID) == NULL){
        cout << "Faculty Advisor does not exist in tree" << endl;
        cout << "Please enter information of the Faculty Advisor" << endl;
        cout << endl;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter department: ";
        cin >> department;
        cout << endl;

        Faculty *f = new Faculty(facultyID, name, level, department, id);
        masterFaculty->insert(facultyID, f);
      }else{
        masterFaculty->search(facultyID)->addAdvisee(id);
      }

      rollBackNum->push(7);
      rollBackStudent->push2(s);

    }

    //deleting the student
    if(choice == 8){
      cout << "Enter student ID: ";
      cin >> studentID;

      //if the ID doesnt exist
      if(masterStudent->search(studentID) == NULL){
        cout << "Invalid Student ID, try again" << endl;
        continue;
      }

      rollBackNum->push(8);
      rollBackStudent->push2(masterStudent->search(studentID));

      facultyID = masterStudent->search(studentID)->getID();
      masterFaculty->search(facultyID)->setAdvisees(studentID);
      masterStudent->deleteNode(studentID);
    }

    //add a new faculty member
    if(choice == 9){

      int num = 0;
      char a = ' ';
      bool loop2 = true;


      cout << "Enter ID: ";
      cin >> id;

      //if the ID is already in the tree
      if(masterFaculty->search(id) != NULL){
        cout <<  "ID already in use, please try again"  << endl;
        continue;
      }

      cout << "Enter name: ";
      cin >> name;
      cout << "Enter level: ";
      cin >> level;
      cout << "Enter department: ";
      cin >> department;
      cout << "Enter ID number of one advisees: ";
      cin >> ad;

      Faculty *f = new Faculty(id, name, level, department, ad);
      masterFaculty->insert(id, f);

      //if the student doesnt exist
      if(masterStudent->search(ad) == NULL){
        cout << "Student does not exist in tree" << endl;
        cout << "Please enter information of the Student" << endl;
        cout << endl;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter major: ";
        cin >> major;
        cout << "Enter gpa: ";
        cin >> gpa;
        cout << endl;

        Student *s = new Student(ad, name, level, major, gpa, id);
        masterStudent->insert(ad, s);
      }

      //checking if there's more advisees
      while(loop2){

        cout << "Does the faculty member have another advisee(y/n): ";
        cin >> a;

        if(a == 'y'){

          while(loop2){
            cout << "ID number for advisee: ";
            cin >> ad;
            cout << endl;
            f->addAdvisee(ad);

            if(masterStudent->search(ad) == NULL){
              cout << "Student does not exist in tree" << endl;
              cout << "Please enter information of the Student" << endl;
              cout << endl;

              cout << "Enter name: ";
              cin >> name;
              cout << "Enter level: ";
              cin >> level;
              cout << "Enter major: ";
              cin >> major;
              cout << "Enter gpa: ";
              cin >> gpa;
              cout << endl;

              Student *s = new Student(ad, name, level, major, gpa, id);
              masterStudent->insert(ad, s);
            }
            break;
          }
        }else{
          loop2 = false;
        }
      }
      rollBackFaculty->push2(f);
      rollBackNum->push(9);
    }

    //deleting the faculty
    if(choice == 10){
      cout << "Enter faculty ID: ";
      cin >> facultyID;

      //if the ID isnt in the tree
      if(masterFaculty->search(facultyID) == NULL){
        cout << "Invalid Faculty ID, try again" << endl;
        continue;
      }

      rollBackNum->push(10);
      rollBackFaculty->push2(masterFaculty->search(facultyID));

      cout << "The faculty has been deleted, please update the student advisors (choice 12) of the following students: " << endl;
      masterFaculty->search(facultyID)->printAdvisees();

      masterFaculty->deleteNode(facultyID);
    }

    //adding a new advisee and new faculty -> added change
    if(choice == 11){

      cout << "Enter student ID: ";
      cin >> id;

      //if the ID is already in the tree
      if(masterStudent->search(id) != NULL){
        cout <<  "ID already in use, please try again" << endl;
        continue;
      }

      cout << "Enter name: ";
      cin >> name;
      cout << "Enter level: ";
      cin >> level;
      cout << "Enter major: ";
      cin >> major;
      cout << "Enter GPA: ";
      cin >> gpa;
      cout << "Enter faculty advisor ID: ";
      cin >> facultyID;
      cout << endl;

      //if the ID is already in the tree
      if(masterFaculty->search(facultyID) != NULL){
        cout <<  "ID already in use, please try again" << endl;
        continue;
      }

      Student *s = new Student(id, name, level, major, gpa, facultyID);
      masterStudent->insert(id, s);

      cout << "Enter information of the Faculty Advisor" << endl;
      cout << endl;

      cout << "Enter name: ";
      cin >> name;
      cout << "Enter level: ";
      cin >> level;
      cout << "Enter department: ";
      cin >> department;
      cout << endl;

      Faculty *f = new Faculty(facultyID, name, level, department, id);
      masterFaculty->insert(facultyID, f);

      rollBackNum->push(11);
      rollBackStudent->push2(s);
      rollBackFaculty->push2(f);

    }

    //changing facultyAdvisor
    if(choice == 12){
      int ogFac = 0;
      cout << "Enter student ID: ";
      cin >> studentID;

      //if the student ID doesnt exist
      if(masterStudent->search(studentID) == NULL){
        cout << "Invalid Student ID, try again" << endl;
        continue;
      }

      cout << "Enter new advisor ID: ";
      cin >> facultyID;

      ogFac = masterStudent->search(studentID)->getID();


      masterStudent->search(studentID)->changeFacultyAdvisor(facultyID);


      ogFac = masterFaculty->search(ogFac)->setAdvisees(studentID);

      //if the facultyID doesnt exist - adds a new faculty advisor
      if(masterFaculty->search(facultyID) == NULL){
        cout << "Faculty Advisor does not exist in tree" << endl;
        cout << "Please enter information of the Faculty Advisor" << endl;
        cout << endl;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter department: ";
        cin >> department;
        cout << endl;

        Faculty *f = new Faculty(facultyID, name, level, department, studentID);
        masterFaculty->insert(facultyID, f);
      }else{
        masterFaculty->search(facultyID)->addAdvisee(studentID);
        masterFaculty->search(facultyID)->printAdvisees();

      }
    }

    //remove advisee from faculty advisors list
    if(choice == 13){
      cout << "Enter facultyID: ";
      cin >> facultyID;

      //if the ID doesnt exist
      if(masterFaculty->search(facultyID) == NULL){
        cout << "Invalid Faculty ID, try again" << endl;
        continue;
      }

      cout << "Enter studentID you want to remove: ";
      cin >> studentID;

      //if ID doesnt exist
      if(masterStudent->search(studentID) == NULL){
        cout << "Invalid Student ID, try again" << endl;
        continue;
      }

      studentID = masterFaculty->search(facultyID)->setAdvisees(studentID);
      cout << "Please update the advisee's faculty member of delete student (choice 12)" <<  endl;
    }

    //rollback
    if(choice == 14){

      int num = 0;

      //finding what command was just chosen
      num = rollBackNum->pop();

      int IDnum;

      //deleting inserted student node
      if(num == 7){
        Student *temp;
        temp = rollBackStudent->pop2();
        IDnum = temp->returnID();

        facultyID = temp->getID();

        masterStudent->deleteNode(IDnum);

        //deleting the student from the faculty advisee
        masterFaculty->search(facultyID)->setAdvisees(IDnum);
      }

      //inserting deleted student node
      if(num == 8){
        Student *temp;

        temp = rollBackStudent->pop2();
        IDnum = temp->returnID();

        masterStudent->insert(IDnum, temp);
        facultyID = masterStudent->search(studentID)->getID();

        //adding the student to the faculty node
        masterFaculty->search(facultyID)->addAdvisee(studentID);

      }

      //deleting inserted faculty node
      if(num == 9){

        Faculty *temp = rollBackFaculty->pop2();
        IDnum = temp->getID();

        masterFaculty->deleteNode(IDnum);

        cout << "Deleted faculty, please update the advisees" << endl;
      }

      //inserting deleted faculty node
      if(num == 10){

        Faculty *temp = rollBackFaculty->pop2();
        IDnum = temp->getID();

        masterFaculty->insert(IDnum, temp);

      }

      //accounting for newly inputted student and faculty
      if(num == 11){
        Student *temp;
        temp = rollBackStudent->pop2();
        IDnum = temp->returnID();

        masterStudent->deleteNode(IDnum);

        Faculty *temp2 = rollBackFaculty->pop2();
        IDnum = temp2->getID();

        masterFaculty->deleteNode(IDnum);

      }
    }

    //exit and serialization to the text file
    if(choice == 15){

      if(masterStudent->isEmpty() == false){
        masterStudent->serialization("studentTable");
      }

      if(masterFaculty->isEmpty() == false){
        masterFaculty->serialization("facultyTable");
      }

      loop = false;

    //accounting for an invalid input from user
    }if(choice > 15){
      cout << "Entered wrong number, please try again" << endl;
    }
  }
}
