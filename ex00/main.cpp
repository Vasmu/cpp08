#include "easyfind.hpp"
#include <vector>
#include <deque>
// #include <random>
#include <ctime>

int main()
{
        srand(time(NULL));
    {

        std::cout << "-------------------TEST Vector-------------------" << std::endl;
        std::vector<int> v;

        std::cout << "On ajoute 4, 1, 2 au vector initailise" << std::endl;
        v.push_back(4);
        v.push_back(1);
        v.push_back(2);

    try {
        std::cout << std::endl <<  (*easyfind(v, 4)); 
        std::cout << "4 was found in vector v" << std::endl;
        std::cout << std::endl << (*easyfind(v, 918263));
    }
    catch (...)
    {
        std::cout << "Value was not found in container... Try again :)" << std::endl;
    }

    std::cout << "On ajoute 297 valeurs aleatoires (entre 0 et 300) au vector initailise" << std::endl;

    for (int i = 0; i < 297; i++)
    {
        int const value = rand() % 300;
        v.push_back(value);
    }

        std::vector<int>::iterator i;
        for (i = v.begin(); i !=v.end(); ++i)
        {
            std::cout  << *i << " ";
        }

     try {
        std::cout << std::endl << (*easyfind(v, 10)) << std::endl; 
        std::cout << "10 was found in vector v" << std::endl;
        std::cout << (*easyfind(v, 20)) << std::endl;
        std::cout << "20 was found in vector v" << std::endl;
        std::cout << (*easyfind(v, 30)) << std::endl;
        std::cout << "30 was found in vector v" << std::endl;
        std::cout << (*easyfind(v, 40)) << std::endl;
        std::cout << "40 was found in vector v" << std::endl;
        std::cout << (*easyfind(v, 40)) << std::endl;
        std::cout << "40 was found in vector v" << std::endl;
    }
    catch (...)
    {
        std::cout << "Value was not found in container... Try again :)" << std::endl;
    }
    }

    std::cout << std::endl << std::endl;

    {
        std::cout << "-------------------TEST Deque-------------------" << std::endl;
        
        std::deque<int> d;
        d.push_back(32);
        d.push_back(31);
        d.push_back(30);
        d.push_back(29);
    
        try {
            std::cout << std::endl << (*easyfind(d, 29)) << std::endl;
            std::cout << "29 was found in deque d" << std::endl;

        }
        catch (...)
        {
            std::cout << "Value was not found in container... Try again :)" << std::endl;
        }

        for (int i = 0; i < 297; i++)
        {
            int const value = rand() % 300;
            d.push_back(value);
        }

        std::deque<int>::iterator i;
        for (i = d.begin(); i != d.end(); ++i)
        {
            std::cout  << *i << " ";
        }

        try {
            std::cout << std::endl << (*easyfind(d, 10)) << std::endl; 
            std::cout << "10 was found in vector d" << std::endl;
            std::cout << (*easyfind(d, 20)) << std::endl;
            std::cout << "20 was found in vector d" << std::endl;
            std::cout << (*easyfind(d, 30)) << std::endl;
            std::cout << "30 was found in vector d" << std::endl;
            std::cout << (*easyfind(d, 40)) << std::endl;
            std::cout << "40 was found in vector d" << std::endl;
            std::cout << (*easyfind(d, 40)) << std::endl;
            std::cout << "40 was found in vector d" << std::endl;
        }
        catch (...)
        {
            std::cout << "Value was not found in container... Try again :)" << std::endl;
        }
    }

}