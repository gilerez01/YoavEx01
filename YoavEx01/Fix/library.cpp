//
// Created by Frankel on 29/11/2020.
//

#include "library.h"
#include "CoursesManager.h"

void *Init()
{
    CoursesManager *DS = new CoursesManager();
    return (void *)DS;
}

StatusType AddCourse(void *DS, int courseID, int numOfClasses)
{
    if (DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager *)DS)->AddCourse(courseID, numOfClasses);
}

StatusType TimeViewed(void *DS, int courseID, int classID, int *timeViewed)
{
    if (DS == NULL)
    {
        return INVALID_INPUT;
    }
    return ((CoursesManager *)DS)->TimeViewed(courseID, classID, timeViewed);
}

StatusType GetMostViewedClasses(void *DS, int numOfClasses, int *courses, int *classes)
{
    if (DS == NULL)
    {
        return INVALID_INPUT;
    }

    return ((CoursesManager *)DS)->GetMostViewedClasses(numOfClasses, courses, classes);
}

StatusType RemoveCourse(void *DS, int courseID){
    if(DS == NULL){
        return INVALID_INPUT;
    }
    StatusType result;
    try{
        result = ((CoursesManager *)DS)->RemoveCourse(courseID);
    } catch(std::bad_alloc &e){
        return ALLOCATION_ERROR;
    }
    return result;
}

StatusType WatchClass(void *DS, int courseID, int classID, int time){
    if(DS == NULL){
        return INVALID_INPUT;
    }
    return ((CoursesManager *)DS)->WatchClass(courseID,classID,time);
}

void Quit(void** DS){
    ((CoursesManager *)*DS)->Quit();
    delete ((CoursesManager *)*DS);
    *DS = NULL;
    DS = NULL;
}
