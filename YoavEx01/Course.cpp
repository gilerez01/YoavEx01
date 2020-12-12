#include "Course.h"

Course::Course(const int course_id, const int num_of_lectures) : course_id(course_id), num_of_lectures(num_of_lectures), lectures_array(NULL)
{
    lectures_array = new TreeNode<Lecture> *[num_of_lectures];
    for (int i = 0; i < num_of_lectures; i++)
    {
        lectures_array[i] = NULL;
    }
}

Course::Course(const Course &course) : course_id(course.course_id), num_of_lectures(course.num_of_lectures), lectures_array(NULL)
{
    lectures_array = new TreeNode<Lecture> *[num_of_lectures];
    for (int i = 0; i < num_of_lectures; i++)
    {
        lectures_array[i] = course.lectures_array[i];
    }
}

Course::~Course()
{
    delete[] lectures_array;
}

const int Course::getCourseId() const
{
    return course_id;
}

const int Course::getNumOfLectures() const
{
    return num_of_lectures;
}

TreeNode<Lecture> *const Course::getLecture(const int lecture_id)
{
    return lectures_array[lecture_id];
}

void Course::setLecture(const int lecture_id, TreeNode<Lecture> *lecture_ptr)
{
    lectures_array[lecture_id] = lecture_ptr;
}

bool operator<(const Course &course1, const Course &course2)
{
    return (course1.getCourseId() < course2.getCourseId());
}

bool operator==(const Course &course1, const Course &course2)
{
    return (course1.getCourseId() == course2.getCourseId());
}

bool operator!=(const Course &course1, const Course &course2)
{
    return !(course1 == course2);
}

bool operator>(const Course &course1, const Course &course2)
{
    return (course2 < course1);
}

bool operator<=(const Course &course1, const Course &course2)
{
    return !(course1 > course2);
}

bool operator>=(const Course &course1, const Course &course2)
{
    return !(course1 < course2);
}
