#ifndef _COURSE_
#define _COURSE_
#include "TreeNode.h"
#include "Lecture.h"

class Course
{
private:
    const int course_id;
    const int num_of_lectures;
    TreeNode<Lecture> **lectures_array;

public:
    Course(const int course_id, const int num_of_lectures);
    ~Course();
    Course(const Course &course);
    Course operator=(const Course &course) = delete;

    const int getCourseId() const;
    const int getNumOfLectures() const;
    TreeNode<Lecture> *const getLecture(const int lecture_id);
    void setLecture(const int class_id, TreeNode<Lecture> *lectures_ptr);
};

bool operator<(const Course &course1, const Course &course2);
bool operator==(const Course &course1, const Course &course2);
bool operator!=(const Course &course1, const Course &course2);
bool operator>(const Course &course1, const Course &course2);
bool operator<=(const Course &course1, const Course &course2);
bool operator>=(const Course &course1, const Course &course2);

#endif