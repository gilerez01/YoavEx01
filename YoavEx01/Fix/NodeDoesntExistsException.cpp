//
// Created by Frankel on 01/12/2020.
//

#include "NodeDoesntExistsException.h"

char const *NodeDoesntExistsException::what() {
    return "The given node cannot be removed, since it doesnt exists in the tree.";
}
