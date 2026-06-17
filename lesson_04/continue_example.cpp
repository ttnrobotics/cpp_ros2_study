#include <iostream>

int main() {
    for (int step = 0; step < 10; ++step) 
    {
        bool sensor_valid = true;

        if (step == 3 || step == 7)
        {
            sensor_valid = false;
        }
        if (!sensor_valid)
        {
            std::cout << "Step " << step << ": sensor invalid, skipping this step." << std::endl;
            continue;
        }

        std::cout << "Step " << step << ": sensor valid, computing command." << std::endl;
    }

    return 0;
}