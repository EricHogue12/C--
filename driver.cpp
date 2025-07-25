// has most of the methods for adding numbers and determining the statistics
// interacts with the main method

#include "number.h"
#include "driver.h"
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>


Driver::Driver(){

}

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

void Driver::generateRandom(){
    for (int i = 0; i < 10; i++){
        std::random_device rd; 
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distr(-1000, 1000);
        list1.push_back(distr(gen));
    }
}

std::vector<Number> Driver::getNumbers(){
    return list1;
}

void Driver::printNumbers(){
    for (int i = 0; i < list1.size(); i++){
        std::cout << std::to_string(list1[i].getValue()) + " ";
    }
    std::cout << "" << std::endl;
}

double Driver::mean(){
    int sum = 0;
    for (int i = 0; i < list1.size(); i++){
        sum = sum + list1[i].getValue();
    }
    double ans = static_cast<double>(sum) / list1.size();
    return ans;
}

double Driver::stdv(){
    double mean = Driver::mean();
    double total = 0;
    for (int i = 0; i < list1.size(); i++){
        double diff = list1[i].getValue() - mean;
        double sq = diff * diff;
        total = total + sq;
    }
    double res = total / list1.size();
    double ans = std::sqrt(res);
    return ans;
}

int Driver::range(){
    int highest = list1[0].getValue();
    int lowest = list1[0].getValue();
    for (int i = 1; i < list1.size(); i++){
        if (list1[i].getValue() > highest){
            highest = list1[i].getValue();
        }
        if (list1[i].getValue() < lowest){
            lowest = list1[i].getValue();
        }
    }
    return highest - lowest;
}

int Driver::median(){
    for (int i = 0; i < list1.size() - 1; i++) {
		int minIndex = i;
		for (int j = i+1; j < list1.size(); j++) {
			if (list1[j].getValue() < list1[minIndex].getValue()) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			std::swap(list1[i], list1[minIndex]);
				
		}
	}

    int idx;
    int idx1;
    if (list1.size() % 2 == 1){
        idx = list1.size() / 2;
        return list1[idx].getValue();
    }
    else{
        idx1 = (list1.size() / 2) - 1;
        int val = (list1[idx1].getValue() + list1[idx1 + 1].getValue()) / 2;
        return val;
    }

}

int Driver::mode(){

    std::vector<int> replacement;
    for (int i = 0; i < list1.size(); i++){
        replacement.push_back(list1[i].getValue());
    }

    int currentFreq = 0;
    int currentVal;

    for (int i = 0; i < replacement.size(); i++){
        int count = std::count(replacement.begin(), replacement.end(), replacement[i]);
        if (count > currentFreq){
            currentFreq = count;
            currentVal = replacement[i];
        }
    }

    return currentVal;

}
