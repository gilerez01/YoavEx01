//
// Created by Frankel on 29/11/2020.
//

#ifndef DATA_STRUCTURS_WET1_COURSESMANAGER_H
#define DATA_STRUCTURS_WET1_COURSESMANAGER_H

#include "AVL_Tree.h"
#include "Lecture.h"
#include "library.h"
#include "Course.h"

/**
* CoursesManager class
*
* The following methods are available:
*   constructor          - Creates new empty CoursesManager.
*   AddCourse            - Add a given course to the CoursesManager.
*   RemoveCourse         - Remove a given course from the CoursesManager.
*   WatchClass           - Update the given class in the CoursesManager views by a given time.
*   TimeViewed           - Return the view time of a given class in the CoursesManager.
*   GetMostViewedClass   - Put the most viewed classes into a given array.
*   Quit                 - Deallocate all the allocated memory of the CoursesManager.           
*/

class CoursesManager
{

private:
    AVL_Tree<Lecture> *lectures;
    AVL_Tree<Course> *courses;

    ////////////////////////////
    // Auxiliary functions
    ////////////////////////////
    void ReversedBottomInOrder(TreeNode<Lecture> *vertex, int *counter, int numOfClasses, int *courses, int *classes);
    
    void leftSubTreeSearch(TreeNode<Lecture> *vertex, int *counter, int numOfClasses, int *courses, int *classes);
    
    void bottomInOrder(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes);

    void addLectureTime(TreeNode<Lecture> *vertex, int *counter, int *courses, int *classes);
    
    void rightSubTreeSearch(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes);

    void addCourseTime(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes);

public:

    /**
     * constructor: Create new empty CoursesManager.
     * 
     * @return 
     *  A new empty CoursesManager.
     */
    CoursesManager();

    ~CoursesManager();

    /**
     * AddCourse: Add a given course to the CoursesManager.
     * 
     * @param
     *  course id and number of classes in the course.
     * 
     * @return
     *  Invalid input if the course id is illegal or if the number of class is illegal.
     *  Failure if the course is allready in the CoursesManager.
     *  Allocation error if there were an error in the allocation of the new course.
     *  Otherwise Success.
     */
    StatusType AddCourse(int courseID, int numOfClasses);

    /**
     * RemoveCourse: Remove a given course from the CoursesManager.
     * 
     * @param
     *  course id.
     * 
     * @return
     *  Invalid input if the course id is illegal.
     *  Failure if the wanted course does not exists in the CoursesManager.
     *  Otherwise Success.
     */
    StatusType RemoveCourse(int courseID);
    
    /**
     * WatchClass: Update the given class in the CoursesManager views by a given time.
     * 
     * @param
     *  course id, class id and time.
     * 
     * @return
     *  Invalid input if the course id or the class id or the time are illegal.
     *  Failure if the wanted course does not exists in the CoursesManager.
     *  Allocation error if there were some kind of error in some allocation.
     *  Otherwise Success.
     */
    StatusType WatchClass(int courseID, int classID, int time);

    /**
     * TimeViewed: Return the view time of a given class in the CoursesManager.
     * 
     * @param
     *  course id, class id and a pointer to the return value: time viewed.
     * 
     * @return
     *  Invalid input if the course id or the class id are illegal.
     *  Failure if the wanted course does not exists in the CoursesManager.
     *  Otherwise Success. Put the return value in the parameter timeViewed. 
     */
    StatusType TimeViewed(int courseID, int classID, int *timeViewed);

    /**
     * GetMostViewedClasses: Put the most viewed classes into a given array.
     * 
     * @param
     *  nubmer of classes which is the size of the other parameters courses array and classes array.
     * 
     * @return
     *  Invalid input if num of classes is illegal.
     *  Failure if there are less classes in the CoursesManager than in the num of classes parameter.
     *  Allocation error if there were some kind of error in some allocation.
     *  Otherwise Success. Put the return values in the parameters courses and classes. 
     */
    StatusType GetMostViewedClasses(int numOfClasses, int *courses, int *classes);
    
    /**
     * Quit: Deallocate all the allocated memory of the CoursesManager. 
     */
    void Quit();
};

#endif //DATA_STRUCTURES_WET1_COURSESMANAGER_H
