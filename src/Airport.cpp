#include "Airport.h"

Airport::Airport() {

}

Airport::Airport(const string& name){
    this->name = name;
}

string Airport::getName(){
    return name;
}

void Airport::setName(const string &name) {
    this->name = name;
}