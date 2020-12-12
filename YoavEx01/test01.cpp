// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#include "CoursesManager.h"
#include <assert.h>
#include <cstdlib>
#include <time.h>
using std::cout;
using std::endl;

int arr1[1104][3];
int arr2[1104][2];
void testInit();
void testWatchclass();
void testRemoveCourses();
void testQuit();
void problem();
void problem2();
void leakTest();

void testInit(){
    CoursesManager *a = (CoursesManager *)Init();
    CoursesManager *b = (CoursesManager *)Init();
    Quit((void**)&a);
    Quit((void**)&b);

}

void testWatchclass(){
    CoursesManager *DS = (CoursesManager *)Init();
    StatusType status = AddCourse(DS,84,4);
    assert(status == SUCCESS);
    status = WatchClass(DS,84,3,60);
    assert(status == SUCCESS);
    status = WatchClass(DS,84,2,60);
    assert(status == SUCCESS);
    status = WatchClass(DS,84,3,60);
    assert(status == SUCCESS);
    status = WatchClass(DS,84,2,60);
    assert(status == SUCCESS);
    status = WatchClass(DS,-3,2,60);
    assert(status == INVALID_INPUT);
    status = WatchClass(DS,84,2,0);
    assert(status == INVALID_INPUT);
    status = WatchClass(DS,84,4,1);
    assert(status == INVALID_INPUT);
    status = WatchClass(DS,50,2,1);
    assert(status == FAILURE);
    int num_of_invalid = 0;
    int num_of_fails = 0;
    int num_of_success = 0;
    for(int i = 0 ; i < 100 ; i++){
        int course_id = rand() % 100 + 1;
        int num_of_lectures = rand() % 100 +1;
        status = AddCourse(DS,course_id,num_of_lectures);
        if(status != SUCCESS){
            continue;
        }
    }
    for(int i = 0 ; i < 1104 ; i++){
        Course * co = DS->courses->arr[i]->getValue();
        if(co != NULL){
            arr2[i][0] = co->getCourseId();
            arr2[i][1] = co->getNumOfLectures();
            cout<<"{ "<<arr2[i][0]<<", "<<arr2[i][1] <<" },"<<endl;
        }
    }
    cout<<"###############################"<<endl;
    for(int i = 0 ; i < 1100 ; i++){
        int course_id = rand() % 100 + -5;
        int lecture_id = rand() % 100 -5;
        int time = rand() %30 - 15;
        TreeNode<Course> *temp = DS->courses->find(Course(course_id,1));
        status = WatchClass(DS,course_id,lecture_id,time);
        //cout <<course_id << ", "<<lecture_id<<", "<<time<<endl;
        //TreeNode<Course> *temp = DS->courses->find(Course(course_id,1));
        if(course_id <= 0 || lecture_id < 0 || time <= 0){
            assert(status == INVALID_INPUT);
            num_of_invalid++;
            continue;
        }
        if(temp == NULL){
            assert(status == FAILURE);
            num_of_fails++;
            continue;
        }
        if(lecture_id +1 > temp->getValue()->getNumOfLectures()){
            assert(status == INVALID_INPUT);
            num_of_invalid++;
            continue;
        }
        assert(status == SUCCESS);
        num_of_success++;
    }
    cout<<"num of successes: "<<num_of_success<<endl;
    cout<<"num of invalid input: "<<num_of_invalid<<endl;
    cout<<"num of failures: "<<num_of_fails<<endl;
    cout<<"num of lectures: "<<DS->lectures->number_of_nodes<<endl;
    for(int i = 0 ; i < 1104 ; i++){
        if(DS->lectures->arr[i] != NULL){
            Lecture * lec = DS->lectures->arr[i]->getValue();
            arr1[i][0] = lec->getCourseId();
            arr1[i][1] = lec->getId();
            arr1[i][2] = lec->getTimeViewed();
            cout<<"{ "<<arr1[i][0]<<", "<<arr1[i][1] << ", "<<arr1[i][2]<<" },"<<endl;
        }
    }
    Quit((void**)&DS);

}

void testRemoveCourses(){
    CoursesManager *DS = (CoursesManager *)Init();
    StatusType status = AddCourse(DS,84,4);
    assert(status == SUCCESS);
    status = AddCourse(DS,158,8);
    assert(status == SUCCESS);
    status = RemoveCourse(DS,83);
    assert(status == FAILURE);
    status = RemoveCourse(DS,84);
    assert(status == SUCCESS);
    status = RemoveCourse(DS,84);
    assert(status == FAILURE);
    Quit((void **)&DS);
}

void testQuit(){
    CoursesManager *DS = (CoursesManager *)Init();
    StatusType status = AddCourse(DS,84,4);
    assert(status == SUCCESS);
    status = AddCourse(DS,158,8);
    assert(status == SUCCESS);
    Quit((void**)&DS);
    DS = (CoursesManager *)Init();
    for(int i = 0 ; i < 100 ; i++){
        int course_id = rand() % 100 + 1;
        int num_of_lectures = rand() % 100 +1;
        status = AddCourse(DS,course_id,num_of_lectures);
        if(status != SUCCESS){
            continue;
        }
    }
    
    for(int i = 0 ; i < 1000 ; i++){
        int course_id = rand() % 100 + 1;
        int lecture_id = rand() % 100 + 1;
        int time = rand() %100 + 1;
        TreeNode<Course> *temp = DS->courses->find(Course(course_id,1));
        status = WatchClass(DS,course_id,lecture_id,time);
        if(temp == NULL){
            assert(status == FAILURE);
        }else if(temp->getValue()->getNumOfLectures() < lecture_id +1){
            assert(status == INVALID_INPUT);
        }else{
            assert(status == SUCCESS);
        }
    }
    Quit((void**)&DS);
}

void testLecturesTree(){
    AVL_Tree<Lecture> lecture = AVL_Tree<Lecture>();
    int random = 100000;
    lecture.insert(Lecture(1,1,4));
    lecture.insert(Lecture(1,5,2));
    lecture.insert(Lecture(2,5,2));
    lecture.insert(Lecture(1,8,100));
    for(int i = 0 ; i < random ; i++){
        int course_id = rand() % 100 + 1;
        int lecture_id = rand() % 100 + 1;
        int time = rand() %100 + 1;
        try{
            lecture.insert(Lecture(course_id,lecture_id,time));
        }catch(NodeAlreadyExistsException &e){
        }
    }
    cout<<lecture.number_of_nodes<<endl;
    lecture.deleteTree(lecture.getRoot());
    cout<<lecture.number_of_nodes<<endl;
}

int main(){
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    srand (time(NULL));
    //testInit();
    //cout<<"testInit: success"<<endl;
    //testWatchclass();
    //cout<<"testWatchclass: success"<<endl;
    //testRemoveCourses();
    //cout<<"testRemoveCourses: success"<<endl;
    //testQuit();
    //cout<<"testQuit: success"<<endl;
    //testLecturesTree();
    
    leakTest();
    problem();
    
    //problem2();

    //_CrtDumpMemoryLeaks();

    return 0;
}

void leakTest()
{
    char* str = new char[17];
}

void problem(){
    const int len1 = 133; // 133;
    int lectures_arr[len1][3];
    const int len1Base = 133;
    int lectures_arrBase[len1Base][3] = {
{ 84, 2, 120 },
{ 25, 67, 2 },
{ 20, 28, 12 },
{ 2, 75, 3 },
{ 15, 58, 2 },
{ 66, 14, 11 },
{ 70, 5, 7 },
{ 57, 2, 5 },
{ 67, 42, 7 },
{ 70, 7, 13 },
{ 16, 74, 9 },
{ 5, 43, 13 },
{ 25, 17, 7 },
{ 25, 55, 14 },
{ 15, 52, 6 },
{ 25, 31, 2 },
{ 25, 64, 8 },
{ 36, 47, 8 },
{ 85, 49, 5 },
{ 21, 47, 14 },
{ 43, 44, 12 },
{ 56, 61, 12 },
{ 15, 67, 11 },
{ 87, 57, 10 },
{ 2, 50, 5 },
{ 34, 88, 5 },
{ 45, 36, 10 },
{ 30, 58, 1 },
{ 85, 2, 14 },
{ 87, 11, 3 },
{ 45, 30, 8 },
{ 15, 24, 5 },
{ 45, 57, 10 },
{ 16, 33, 9 },
{ 60, 53, 11 },
{ 50, 3, 6 },
{ 70, 48, 8 },
{ 81, 35, 1 },
{ 65, 0, 4 },
{ 81, 6, 5 },
{ 35, 56, 4 },
{ 2, 52, 11 },
{ 15, 11, 8 },
{ 50, 47, 1 },
{ 30, 46, 6 },
{ 44, 57, 2 },
{ 34, 27, 10 },
{ 57, 53, 7 },
{ 51, 55, 11 },
{ 30, 11, 14 },
{ 83, 70, 11 },
{ 45, 61, 11 },
{ 85, 25, 9 },
{ 30, 65, 8 },
{ 50, 7, 6 },
{ 20, 18, 3 },
{ 38, 8, 7 },
{ 4, 3, 2 },
{ 85, 91, 8 },
{ 83, 19, 9 },
{ 19, 40, 5 },
{ 5, 88, 1 },
{ 92, 22, 3 },
{ 70, 34, 3 },
{ 85, 80, 1 },
{ 35, 36, 3 },
{ 30, 41, 1 },
{ 57, 22, 10 },
{ 25, 69, 9 },
{ 76, 0, 4 },
{ 51, 83, 3 },
{ 35, 0, 12 },
{ 36, 46, 1 },
{ 56, 52, 7 },
{ 16, 55, 12 },
{ 43, 36, 2 },
{ 57, 5, 4 },
{ 2, 16, 13 },
{ 68, 5, 13 },
{ 11, 24, 9 },
{ 45, 59, 6 },
{ 85, 48, 2 },
{ 25, 82, 13 },
{ 50, 59, 1 },
{ 74, 32, 10 },
{ 35, 50, 10 },
{ 25, 44, 10 },
{ 89, 8, 8 },
{ 81, 21, 6 },
{ 50, 4, 1 },
{ 50, 57, 11 },
{ 50, 74, 11 },
{ 66, 29, 12 },
{ 21, 20, 9 },
{ 2, 37, 4 },
{ 34, 85, 6 },
{ 36, 42, 11 },
{ 89, 12, 1 },
{ 12, 2, 7 },
{ 34, 30, 16 },
{ 87, 18, 11 },
{ 86, 1, 4 },
{ 21, 12, 20 },
{ 17, 4, 8 },
{ 15, 78, 7 },
{ 51, 79, 5 },
{ 38, 19, 4 },
{ 70, 70, 23 },
{ 15, 22, 2 },
{ 51, 46, 24 },
{ 81, 16, 2 },
{ 34, 45, 2 },
{ 51, 31, 13 },
{ 34, 46, 1 },
{ 67, 30, 14 },
{ 85, 44, 2 },
{ 16, 1, 11 },
{ 94, 54, 6 },
{ 89, 46, 6 },
{ 25, 38, 6 },
{ 40, 28, 8 },
{ 44, 14, 11 },
{ 74, 59, 10 },
{ 9, 14, 14 },
{ 9, 3, 5 },
{ 5, 62, 5 },
{ 94, 33, 3 },
{ 87, 35, 1 },
{ 49, 12, 10 },
{ 50, 77, 7 },
{ 57, 61, 3 },
{ 35, 38, 8 },
{ 2, 27, 5 }};

const int len2 = 61; // 61;
int courses_arr[len2][2];
const int lenBase2 = 61;
int courses_arrBase[lenBase2][2] =
{
{ 84, 4 },
{ 4, 29 },
{ 11, 27 },
{ 38, 29 },
{ 9, 28 },
{ 49, 14 },
{ 81, 56 },
{ 48, 38 },
{ 45, 71 },
{ 68, 15 },
{ 7, 97 },
{ 34, 93 },
{ 51, 97 },
{ 28, 46 },
{ 24, 23 },
{ 89, 54 },
{ 25, 92 },
{ 70, 71 },
{ 16, 79 },
{ 44, 83 },
{ 20, 43 },
{ 65, 40 },
{ 30, 71 },
{ 36, 63 },
{ 15, 86 },
{ 12, 42 },
{ 83, 87 },
{ 40, 41 },
{ 96, 44 },
{ 67, 46 },
{ 60, 62 },
{ 5, 100 },
{ 94, 69 },
{ 39, 23 },
{ 92, 26 },
{ 100, 46 },
{ 35, 64 },
{ 17, 75 },
{ 56, 83 },
{ 19, 47 },
{ 79, 37 },
{ 99, 25 },
{ 23, 15 },
{ 87, 66 },
{ 72, 3 },
{ 86, 16 },
{ 33, 41 },
{ 50, 84 },
{ 76, 21 },
{ 57, 74 },
{ 43, 55 },
{ 74, 84 },
{ 42, 32 },
{ 18, 27 },
{ 85, 95 },
{ 21, 66 },
{ 66, 30 },
{ 75, 5 },
{ 95, 20 },
{ 2, 91 },
{ 77, 5 }
};

//int course_id_problem = 21;
//int lecture_id_problem = 20;
//int time_problem = 9;
for (int i = 0; i < len1; i++) {
    lectures_arr[i][0] = lectures_arrBase[i][0];
    lectures_arr[i][1] = lectures_arrBase[i][1];
    lectures_arr[i][2] = lectures_arrBase[i][2];
}

for (int i = 0; i < len2; i++) {
    courses_arr[i][0] = courses_arrBase[i][0];
    courses_arr[i][1] = courses_arrBase[i][1];
}

CoursesManager *DS = (CoursesManager *)Init();
StatusType status = AddCourse(DS,84,4);
    int num_of_invalid = 0;
    int num_of_fails = 0;
    int num_of_success = 0;
    for(int i = 0 ; i < len2 ; i++){
        int course_id = courses_arr[i][0];
        int num_of_lectures = courses_arr[i][1];
        status = AddCourse(DS,course_id,num_of_lectures);
        if(status != SUCCESS){
            continue;
        }
    }
    for(int i = 0 ; i < len1 ; i++){
        int course_id = lectures_arr[i][0];
        int lecture_id = lectures_arr[i][1];
        int time = lectures_arr[i][2];
        TreeNode<Course> *temp = DS->courses->find(Course(course_id,1));
        status = WatchClass(DS,course_id,lecture_id,time);
        //cout <<course_id << ", "<<lecture_id<<", "<<time<<endl;
        //TreeNode<Course> *temp = DS->courses->find(Course(course_id,1));
        if(course_id <= 0 || lecture_id < 0 || time <= 0){
            assert(status == INVALID_INPUT);
            num_of_invalid++;
            continue;
        }
        if(temp == NULL){
            assert(status == FAILURE);
            num_of_fails++;
            continue;
        }
        if(lecture_id +1 > temp->getValue()->getNumOfLectures()){
            assert(status == INVALID_INPUT);
            num_of_invalid++;
            continue;
        }
        assert(status == SUCCESS);
        num_of_success++;
    }
    /*
    cout<<"num of successes: "<<num_of_success<<endl;
    cout<<"num of invalid input: "<<num_of_invalid<<endl;
    cout<<"num of failures: "<<num_of_fails<<endl;
    cout<<"num of lectures: "<<DS->lectures->number_of_nodes<<endl;
    */
    Quit((void**)&DS);

}

void problem2() 
{
    CoursesManager* DS = (CoursesManager*)Init();
    //StatusType status = AddCourse(DS, 84, 4);

    Quit((void**)&DS);
}
