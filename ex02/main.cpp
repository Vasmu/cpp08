#include "MutantStack.hpp"
#include <list>

int main()
{
    srand(time(NULL));
    {
        std::cout << "--------------------TEST SUJET MUTANT--------------------" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << "--------------------TEST SUJET STD::LIST--------------------" << std::endl;
        std::list<int> lis;
        lis.push_back(5);
        lis.push_back(17);
        std::cout << lis.back() << std::endl;
        lis.pop_back();
        std::cout << lis.size() << std::endl;
        lis.push_back(3);
        lis.push_back(5);
        lis.push_back(737);
        //[...]
        lis.push_back(0);
        std::list<int>::iterator it = lis.begin();
        std::list<int>::iterator ite = lis.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::list<int> s(lis);
    }

    std::cout << std::endl << std::endl;
    {
        std::cout << "--------------------TEST SUPPLEMENTAIRES--------------------" << std::endl;
        MutantStack<int> lis;

        for (int i = 0; i < 301; i++)
        {
            int const value = rand() % 300;
            lis.push(value);
        }
        std::cout <<"top de mutant : " << lis.top() << std::endl;

        MutantStack<int> liscp(lis);
        std::cout << "top de mutant copie : " << liscp.top() << std::endl;

        lis.pop();
        std::cout << "size de mutant : " <<  lis.size() << std::endl;
        std::cout << "size de mutant copie : " << liscp.size() << std::endl;

        liscp = lis;
        std::cout << "size de mutant copie : " <<  lis.size() << std::endl;


        MutantStack<int>::iterator it = lis.begin();
        MutantStack<int>::iterator ite = lis.end();

        std::cout << "[ ";
        while (it != ite)
        {
            std::cout << *it << ", ";
            ++it;
        }
        std::cout << "]" << std::endl;
        MutantStack<int> s(lis);
    }
    return 0;
}