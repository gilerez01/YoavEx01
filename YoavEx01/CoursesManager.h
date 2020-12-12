//
// Created by Frankel on 29/11/2020.
//

#ifndef DATA_STRUCTURS_WET1_COURSESMANAGER_H
#define DATA_STRUCTURS_WET1_COURSESMANAGER_H

#include "AVL_Tree.h"
#include "Lecture.h"
#include "library.h"
#include "Course.h"

class CoursesManager
{

private:
    void ReversedBottomInOrder(TreeNode<Lecture> *vertex, int *counter, int numOfClasses, int *courses, int *classes);
    void leftSubTreeSearch(TreeNode<Lecture> *vertex, int *counter, int numOfClasses, int *courses, int *classes);

public:
    AVL_Tree<Lecture> *lectures;
    AVL_Tree<Course> *courses;

    CoursesManager();
    ~CoursesManager();
    StatusType AddCourse(int courseID, int numOfClasses);
    StatusType RemoveCourse(int courseID);
    StatusType WatchClass(int courseID, int classID, int time);
    StatusType TimeViewed(int courseID, int classID, int *timeViewed);
    StatusType GetMostViewedClasses(int numOfClasses, int *courses, int *classes);
    void Quit();

    void bottomInOrder(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes);

    void addLectureTime(TreeNode<Lecture> *vertex, int *counter, int *courses, int *classes);
    void rightSubTreeSearch(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes);

    void addCourseTime(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes);
};

#endif //DATA_STRUCTURS_WET1_COURSESMANAGER_H
