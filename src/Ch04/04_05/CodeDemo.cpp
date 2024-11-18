// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // GPA = total points / total credits
    std::string name;
    float points = 0.0f;
    float total_points = 0.0f;
    float total_credits = 0.0f;

    for (auto student : students){
        if (student.get_id() == id){
            name = student.get_name();
        }
    }

    for (auto grade : grades){
        if(grade.get_student_id() == id){
            switch (grade.get_grade()){
                case 'A':
                    points = 4.0;
                    break;
                case 'B':
                    points = 3.0;
                    break;
                case 'C':
                    points = 2.0;
                    break;
                case 'D':
                    points = 1.0;
                    break;
                case 'F':
                    points = 0.0;
                    break;
                default:
                    points = 0.0;
                    break;
            }
            for (auto course : courses){
                if (course.get_id() == grade.get_course_id()){
                    total_points += points * course.get_credits();
                    total_credits += course.get_credits();
                }
            }
        }
    }

    GPA = total_points / total_credits;

    std::string student_str;
    student_str = name; // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
