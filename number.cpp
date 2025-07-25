// defines the number object and what is a valid number

#include "number.h"
#include <iostream>

Number::Number(int val){
    setValue(val);
}

void Number::setValue(int val) {
    if (val > 1000 || val < -1000){
        throw std::invalid_argument("Number is too much.");
    }
    else{
        value = val;
    }
}

int Number::getValue(){
    return value;
}

