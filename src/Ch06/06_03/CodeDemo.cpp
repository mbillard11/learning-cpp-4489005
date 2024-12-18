// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <fstream>
#include "records.h"

void initialize(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    SR.write_report_card();
    
    std::cout << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& srec){
    std::ifstream inFile;
    std::string str;
    int sid;
    std::string sname;
    int cid;
    std::string cname;
    int credits;
    char grade;

    inFile.open("students.txt");
    if (inFile.fail())
        std::cout << std::endl << "File not found!" << std::endl;
    else{
        while (!inFile.eof()){
            getline(inFile, str);
            sid = stoi(str);
            getline(inFile, str);
            sname = str;
            srec.add_student(sid, sname);
        }
        inFile.close();
    }

    inFile.open("courses.txt");
    if (inFile.fail())
        std::cout << std::endl << "File not found!" << std::endl;
    else{
        while (!inFile.eof()){
            getline(inFile, str);
            cid = stoi(str);
            getline(inFile, str);
            cname = str;
            getline(inFile, str);
            credits = stoi(str);
            srec.add_course(cid, cname, credits);
        }
        inFile.close();
    }

    inFile.open("grades.txt");
    if (inFile.fail())
        std::cout << std::endl << "File not found!" << std::endl;
    else{
        while (!inFile.eof()){
            getline(inFile, str);
            sid = stoi(str);
            getline(inFile, str);
            cid = stoi(str);
            getline(inFile, str);
            grade = str[0];
            srec.add_grade(sid, cid, grade);
        }
        inFile.close();
    }
}
