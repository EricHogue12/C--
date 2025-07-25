// defines the driver class before implementation
#pragma once
#include "number.h"
#include <vector>

    class Driver {
        private:
            std::vector<Number> list1;

        public:
            Driver();
            void addNumber(int val);
            void removeNumber(int idx);
            void generateRandom();
            std::vector<Number> getNumbers();
            void printNumbers();
            double mean();
            double stdv();
            int range();
            int median();
            int mode();
    };
