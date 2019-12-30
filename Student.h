//
// Created by 廖石泉 on 2019/11/9.
//

#ifndef ALGORITHM_STUDENT_H
#define ALGORITHM_STUDENT_H

#include <string>

using namespace std;

struct Student {
    string name;
    int score;

    bool operator<(const Student &student) {
        return score != student.score ? score < student.score : name < student.name;
    }

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << "Student: " << student.name << " " << student.score << endl;
        return os;
    }

};

#endif //ALGORITHM_STUDENT_H
