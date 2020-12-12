//
// Created by Frankel on 26/11/2020.
//

#include "Lecture.h"

Lecture::Lecture(const int Id, const int courseId, const int timeViewed = 0)
    : id(Id), courseId(courseId), timeViewed(timeViewed)
{
}

int Lecture::getTimeViewed() const
{
    return this->timeViewed;
}

int Lecture::getCourseId() const
{
    return this->courseId;
}

int Lecture::getId() const
{
    return this->id;
}

bool Lecture::operator==(const Lecture &lecture) const
{
    return this->timeViewed == lecture.timeViewed &&
           this->courseId == lecture.courseId &&
           this->id == lecture.id;
}

bool Lecture::operator!=(const Lecture &lecture) const
{
    return !(*this == lecture);
}

bool Lecture::operator<(const Lecture &lecture) const
{
    if (this->timeViewed != lecture.timeViewed)
        return this->timeViewed < lecture.timeViewed; // descending order
    else if (this->courseId != lecture.courseId)
        return this->courseId > lecture.courseId; // ascending order
    else if (this->id != lecture.id)
        return this->id > lecture.id; // ascending order
    return false;
}

bool Lecture::operator<=(const Lecture &lecture) const
{
    return *this == lecture || *this < lecture;
}

bool Lecture::operator>(const Lecture &lecture) const
{
    return *this != lecture && !(*this < lecture);
}

bool Lecture::operator>=(const Lecture &lecture) const
{
    return *this == lecture || *this > lecture;
}

std::ostream &operator<<(std::ostream &output, const Lecture &lecture)
{
    return output << lecture.courseId << "	|	 "<< lecture.timeViewed;
}
