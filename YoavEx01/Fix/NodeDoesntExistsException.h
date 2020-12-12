//
// Created by Frankel on 01/12/2020.
//

#ifndef DATA_STRUCTURS_WET1_NODEDOESNTEXISTSEXCEPTION_H
#define DATA_STRUCTURS_WET1_NODEDOESNTEXISTSEXCEPTION_H
#include <exception>

class NodeDoesntExistsException : public std::exception {
    virtual char const * what();

};


#endif //DATA_STRUCTURS_WET1_NODEDOESNTEXISTSEXCEPTION_H
