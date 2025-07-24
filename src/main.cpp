#include <src/matrix.h>
#include <iostream>

int main()
{
    try
    {
        math::Matrix A(2, 2);
        math::Matrix B(2, 2);

        std::cout << "Enter matrix A (2x2):\n";
        std::cin >> A;

        std::cout << "Enter matrix B (2x2):\n";
        std::cin >> B;

        std::cout << "\nA + B:\n"
                  << A + B;
        std::cout << "\nA - B:\n"
                  << A - B;
        std::cout << "\nA * B:\n"
                  << A * B;

        A += B;
        std::cout << "\nAfter A += B:\n"
                  << A;

        A *= 2.5;
        std::cout << "\nAfter A *= 2.5:\n"
                  << A;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}