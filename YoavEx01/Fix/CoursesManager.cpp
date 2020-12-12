//
// Created by Frankel on 29/11/2020.
//

#include "CoursesManager.h"

CoursesManager::CoursesManager()
{
    lectures = new AVL_Tree<Lecture>();
    courses = new AVL_Tree<Course>();
}

CoursesManager::~CoursesManager()
{
    delete lectures;
    delete courses;
}

StatusType CoursesManager::GetMostViewedClasses(int numOfClasses, int *courses, int *classes)
{
    if (numOfClasses <= 0)
    {
        return INVALID_INPUT;
    }

    int counter = 0;
    ReversedBottomInOrder(lectures->getRightMostVertex(), &counter, numOfClasses, courses, classes);

    if (counter < numOfClasses)
    {
        bottomInOrder(this->courses->getLeftMostVertex(), &counter, numOfClasses, courses, classes);
    }

    if (counter != numOfClasses)
    {
        return FAILURE;
    }
    return SUCCESS;
}

void CoursesManager::ReversedBottomInOrder(TreeNode<Lecture> *vertex, int *counter, int numOfClasses, int *courses, int *classes)
{
    if (vertex == NULL || *counter == numOfClasses)
        return;

    addLectureTime(vertex, counter, courses, classes);

    leftSubTreeSearch(vertex->getLeft(), counter, numOfClasses, courses, classes);

    ReversedBottomInOrder(vertex->getFather(), counter, numOfClasses, courses, classes);
}

void CoursesManager::leftSubTreeSearch(TreeNode<Lecture> *vertex, int *counter, int numOfClasses, int *courses, int *classes)
{
    if (vertex == NULL || *counter == numOfClasses)
        return;
    leftSubTreeSearch(vertex->getRight(), counter, numOfClasses, courses, classes);

    if (*counter < numOfClasses)
    {
        addLectureTime(vertex, counter, courses, classes);
    }

    leftSubTreeSearch(vertex->getLeft(), counter, numOfClasses, courses, classes);
}

void CoursesManager::bottomInOrder(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes)
{
    if (vertex == NULL || *counter == numOfClasses)
        return;

    // add the current course lectures' time, in ascending order.
    addCourseTime(vertex, counter, numOfClasses, courses, classes);

    // search in the right subTree.
    rightSubTreeSearch(vertex->getRight(), counter, numOfClasses, courses, classes);

    // search in the left subtree.
    bottomInOrder(vertex->getFather(), counter, numOfClasses, courses, classes);
}

void CoursesManager::rightSubTreeSearch(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes)
{
    if (vertex == NULL || *counter == numOfClasses)
        return;

    rightSubTreeSearch(vertex->getLeft(), counter, numOfClasses, courses, classes);

    if (*counter < numOfClasses) {
        addCourseTime(vertex, counter, numOfClasses, courses, classes);
    }

    rightSubTreeSearch(vertex->getRight(), counter, numOfClasses, courses, classes);
}

void CoursesManager::addLectureTime(TreeNode<Lecture> *vertex, int *counter, int *courses, int *classes)
{
    *(courses + *counter) = (vertex->getValue())->getCourseId();
    *(classes + *counter) = (vertex->getValue())->getId();
    *counter += 1;
}

void CoursesManager::addCourseTime(TreeNode<Course> *vertex, int *counter, int numOfClasses, int *courses, int *classes)
{
    for (int i = 0; i < vertex->getValue()->getNumOfLectures(); i++)
    {
        if (*counter >= numOfClasses)
        {
            return;
        }
        TreeNode<Lecture> *lectureVertex = vertex->getValue()->getLecture(i);

        // if lecture is not null, than we have already added it.
        if (lectureVertex == NULL)
        {
            *(courses + *counter) = vertex->getValue()->getCourseId();
            *(classes + *counter) = i;
            *counter += 1;
        }
    }
}

StatusType CoursesManager::AddCourse(int courseID, int numOfClasses)
{
    if (numOfClasses <= 0 || courseID <= 0)
    {
        return INVALID_INPUT;
    }

    Course newCourse = Course(courseID, numOfClasses);
    try
    {
        courses->insert(newCourse);
    }
    catch (std::bad_alloc &e)
    {
        return ALLOCATION_ERROR;
    }
    catch (NodeAlreadyExistsException &e)
    {
        return FAILURE;
    }
    return SUCCESS;
}
StatusType CoursesManager::RemoveCourse(int courseID)
{
    if (courseID <= 0)
    {
        return INVALID_INPUT;
    }
    Course *wanted = (courses->find(Course(courseID, 1)))->getValue();
    if (wanted == NULL)
    {
        return FAILURE;
    }
    int num_of_lectures = wanted->getNumOfLectures();

    for (int i = 0; i < num_of_lectures; i++)
    {
        TreeNode<Lecture> *curr = wanted->getLecture(i);
        if (curr != NULL)
        {
            lectures->remove(*(curr->getValue()));
        }
    }
    courses->remove(*wanted);
    return SUCCESS;
}

StatusType CoursesManager::WatchClass(int courseID, int classID, int time)
{
    if (courseID <= 0 || classID < 0 || time <= 0){
        return INVALID_INPUT;
    }
    TreeNode<Course> *temp = courses->find(Course(courseID, 1));
    if (temp == NULL){
        return FAILURE;
    }
    Course *wanted = temp->getValue();
    if (wanted->getNumOfLectures() < classID + 1){
        return INVALID_INPUT;
    }
    TreeNode<Lecture> *curr = wanted->getLecture(classID);
    try{
        if (curr == NULL)
        {
            Lecture updated_lecture = Lecture(classID, courseID, time);
            lectures->insert(updated_lecture);
            curr = lectures->find(updated_lecture);
        }
        else
        {
            Lecture updated_lecture = Lecture(classID, courseID, curr->getValue()->getTimeViewed() + time);
            lectures->remove(*(curr->getValue()));
            wanted->setLecture(classID, NULL);
            lectures->insert(updated_lecture);
            curr = lectures->find(updated_lecture);
        }
        wanted->setLecture(classID, curr);
    }catch(std::bad_alloc &e){
        return ALLOCATION_ERROR;
    }
    return SUCCESS;
}

void CoursesManager::Quit()
{
    TreeNode<Lecture> *lectures_root = lectures->getRoot();
    TreeNode<Course> *courses_root = courses->getRoot();
    lectures->deleteTree(lectures_root);
    courses->deleteTree(courses_root);
    delete lectures;
    lectures = NULL;
    delete courses;
    courses = NULL;
}

StatusType CoursesManager::TimeViewed(int courseID, int classID, int *timeViewed)
{
    if (courseID <= 0 || classID < 0)
    {
        return INVALID_INPUT;
    }
    TreeNode<Course> *c = courses->find(Course(courseID, 0));
    if (c == NULL)
    {
        return FAILURE;
    }
    else if (c->getValue()->getNumOfLectures() < classID + 1)
    {
        return INVALID_INPUT;
    }

    TreeNode<Lecture> *l = c->getValue()->getLecture(classID);
    *timeViewed = (l == NULL) ? 0 : l->getValue()->getTimeViewed();
    return SUCCESS;
}
