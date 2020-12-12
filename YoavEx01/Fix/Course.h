#ifndef _COURSE_
#define _COURSE_
#include "TreeNode.h"
#include "Lecture.h"

/**
* Course class
*
* The following methods are available:
*   constructor          - Creates new Course.
*   copy constructor     - Create a copy of a given Course.
*   getCourseId          - Return the course id.
*   getNumOfLectures     - Return the number of lectures ins the Course.
*   getLecture           - Return a pointer to TreeNode with a value of the given lecture id. 
*   setLecture           - Set the above pointer to the given TreeNode.            
*/

/**
 * Another Course related functions (not methods)
 * 
 *  operator<   - Check if course 1 id is smaller than course 2 id.    
 *  operator<=  - Check if course 1 id is smaller or equal to course 2 id.
 *  operator>   - Check if course 1 id is bigger than course 2 id.
 *  operator>=  - Check if course 1 id is bigger or equal to course 2 id.
 *  operator==  - Check if course 1 id is identical to course 2 id.
 *  operator!=  - Check if course 1 id is not identical to course 2 id.
 */

class Course
{
private:
    const int course_id;
    const int num_of_lectures;
    TreeNode<Lecture> **lectures_array;

public:
    /**
     * constructor: Create new Course with the given parameters.
     * 
     * @param
     *  course id, number of lectures.
     * 
     * @return
     *  A new Course with the given course id and number of classes.
     */
    Course(const int course_id, const int num_of_lectures);
    
    ~Course();
    
    /**
     * copy constructor: Create copy of the given course.
     * 
     * @param
     *  Course course.
     * 
     * @return
     *  A new Course which is a copy of the given course.
     */
    Course(const Course &course);
    
    Course operator=(const Course &course) = delete;

    /**
     * getCourseId: Return the course id.
     */
    const int getCourseId() const;
    
    /**
     * getNumOfLectures: Return the number of lectures ins the Course.
     */
    const int getNumOfLectures() const;
    
    /**
     * getLecture: Return a pointer to TreeNode with a value of the given lecture id.
     * 
     * @param
     *  The wanted lecture id.
     */
    TreeNode<Lecture> *const getLecture(const int lecture_id);
    
    /**
     * setLecture: Set the lecture TreeNode pointer to the given TreeNode.
     * 
     * @param
     *  The wanted lecture id and the new pointer to the new TreeNode.
     */
    void setLecture(const int class_id, TreeNode<Lecture> *lectures_ptr);
};

/**
 * operator<: Check if course 1 id is smaller than course 2 id.
 * 
 * @param
 *  course 1,course 2
 * 
 * @return
 *  True if course 1 id is smaller than course 2 id.
 *  Otherwise false.
 */
bool operator<(const Course &course1, const Course &course2);

/**
 * operator==: Check if course 1 id is identical to course 2 id.
 * 
 * @param
 *  course 1,course 2
 * 
 * @return
 *  True if course 1 id is identical to course 2 id.
 *  Otherwise false.
 */
bool operator==(const Course &course1, const Course &course2);

/**
 * operator!=: Check if course 1 id is not identical to course 2 id.
 * 
 * @param
 *  course 1,course 2
 * 
 * @return
 *  True if course 1 id is not identical to course 2 id.
 *  Otherwise false.
 */
bool operator!=(const Course &course1, const Course &course2);

/**
 * operator>: Check if course 1 id is bigger than course 2 id.
 * 
 * @param
 *  course 1,course 2
 * 
 * @return
 *  True if course 1 id is bigger than course 2 id.
 *  Otherwise false.
 */
bool operator>(const Course &course1, const Course &course2);

/**
 * operator<=: Check if course 1 id is smaller or equal to course 2 id.
 * 
 * @param
 *  course 1,course 2
 * 
 * @return
 *  True if course 1 id is smaller or equal to course 2 id.
 *  Otherwise false.
 */
bool operator<=(const Course &course1, const Course &course2);

/**
 * operator>=: Check if course 1 id is bigger or equal to course 2 id.
 * 
 * @param
 *  course 1,course 2
 * 
 * @return
 *  True if course 1 id is bigger or equal to course 2 id.
 *  Otherwise false.
 */
bool operator>=(const Course &course1, const Course &course2);

#endif