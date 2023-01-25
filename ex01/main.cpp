#include "Span.hpp"
#include <ctime>
#include <iostream>
#include <algorithm>


int main()
{
    srand(time(NULL));

    {
        std::cout << "-------------TEST COPIE---------------" << std::endl;

        Span sp5(SIZE);

        for (unsigned int i = 0; i < (SIZE - 1) ; i++)
        {
            const int value = rand() % 10000;
            try
            {
                sp5.addNumber(value);
            }
            catch(Span::NoSpaceAvailable & e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        Span sp6(sp5);
        sp6.addNumber(3);
        sp5.printTab();
        sp6.printTab();

        sp6 = sp5;
        sp5.printTab();
        sp6.printTab();

        unsigned int shortest = sp5.shortestSpan();
        std::cout <<"shortest span : "<<  shortest << std::endl;
        unsigned int longest = sp5.longestSpan();
        std::cout <<"longest span : "<<  longest << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << "-------------TEST 10 000 valeur ---------------" << std::endl;

        Span sp2(SIZE);

        for (unsigned int i = 0; i < (SIZE + 4) ; i++)
        {
            const int value = rand() % 10000;
            try
            {
                sp2.addNumber(value);
            }
            catch(Span::NoSpaceAvailable & e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        sp2.printTab();

        unsigned int shortest = sp2.shortestSpan();
        std::cout <<"shortest span : "<<  shortest << std::endl;
        unsigned int longest = sp2.longestSpan();
        std::cout <<"longest span : "<<  longest << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << "-------------TEST SUJET + EXCEPTION---------------" << std::endl;
        Span sp = Span(5);
        try 
        {
            // sp.shortestSpan();
            sp.longestSpan();
        }
        catch (Span::NotEnoughValuesForSpan & e)
        {
            std::cout << e.what() << std::endl;
        }
        sp.addNumber(6);
        try 
        {
            // sp.shortestSpan();
            sp.longestSpan();
        }
        catch (Span::NotEnoughValuesForSpan & e)
        {
            std::cout << e.what() << std::endl;
        }
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.printTab();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << "-------------TEST ADD NUMBERSS---------------" << std::endl;

        Span sp3(10);

        std::vector<int> v;
        v.push_back(-103);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        try {
            sp3.addNumbers(v.begin(), v.end());
            sp3.addNumbers(v.begin(), v.end());
            sp3.addNumbers(v.begin(), v.end());
        }
        catch (Span::NoSpaceAvailable & e)
        {
            std::cout << e.what() << std::endl;
        }
        sp3.printTab();
    }
return 0;
}