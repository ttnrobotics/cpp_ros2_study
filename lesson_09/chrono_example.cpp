#include <chrono>
#include <iostream>
#include <thread>

int main()
{
    std::cout << "Starting control loop..." << std::endl;

    for (int step = 0; step < 5; step++)
    {
        std::cout << "Control step: " << step << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

    }
    std::cout << "Finished." << std::endl;
    return 0;
}