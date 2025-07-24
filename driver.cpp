#include "number.h"
#include "driver.h"
#include <iostream>
#include <vector>


Driver::Driver(){}

void Driver::addNumber(int val){
    Number num(val);
    if (list1.size() >= 10){
        throw std::invalid_argument("Too many numbers.");
    }
    else{
        list1.push_back(num);
    }
}

void Driver::removeNumber(int idx){
    if (idx < 0 || idx >= list1.size()){
        throw std::invalid_argument("Cannot remove out of bounds element");
    }
    list1.erase(list1.begin() + idx);
}

