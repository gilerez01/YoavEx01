//
// Created by Frankel on 26/11/2020.
//

#ifndef DATA_STRUCTURS_WET1_LECTURE_H
#define DATA_STRUCTURS_WET1_LECTURE_H

#include <iostream>

            class Lecture {
            private:
                int id;
                int courseId;
                int timeViewed;
            public:

                Lecture(const int Id, const int courseId, const int timeViewed);

                int getTimeViewed() const;
                int getId() const;
                int getCourseId() const;

                /// Comparison operators for Leccures:
                /// 1. decending order of time.
                /// 2. ascending order of course's id.
                /// 3. ascending order of lecture's id.
                ///
                /// \param lecture - the lecture to compare to.
                bool operator==(const Lecture &lecture) const;
                bool operator!=(const Lecture& lecture) const;
                bool operator<(const Lecture& lecture) const;
                bool operator<=(const Lecture& lecture) const;
                bool operator>(const Lecture& lecture) const;
                bool operator>=(const Lecture& lecture) const;

                /// Prints the lecture's data in the following format:
                ///
                /// <courseId> | <timeViewed>
                /// \param output - the output stream to which the data is printed.
                /// \param lecture - the lecture which is printed.
                friend std::ostream& operator<<(std::ostream& output, const Lecture& lecture);

                ~Lecture() = default;
            };

            std::ostream& operator<<(std::ostream& output, const Lecture& lecture);



#endif //DATA_STRUCTURS_WET1_LECTURE_H
