#include<iostream>

int main()
{
    auto print_message = []()
    {
        std::cout << "Hello from lambda function." << std::endl;
    };

    print_message();

    return 0;
}