
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
            int mean();
            int stdv();
            int range();
    };
