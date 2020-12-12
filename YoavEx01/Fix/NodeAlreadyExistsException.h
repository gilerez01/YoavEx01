//
// Created by Frankel on 29/11/2020.
//

#ifndef DATA_STRUCTURS_WET1_NODEALREADYEXISTSEXCEPTION_H
#define DATA_STRUCTURS_WET1_NODEALREADYEXISTSEXCEPTION_H
#include <exception>
using namespace std;

class NodeAlreadyExistsException : public exception {
public:
    virtual char const * what();
};


#endif //DATA_STRUCTURS_WET1_NODEALREADYEXISTSEXCEPTION_H
