//
// Created by Frankel on 29/11/2020.
//

#include "NodeAlreadyExistsException.h"

char const *NodeAlreadyExistsException::what() {
    return "A node with given data already exists in the tree.";
}
