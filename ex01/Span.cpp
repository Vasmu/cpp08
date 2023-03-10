#include "Span.hpp"
#include <cstddef>

/***********            CONSTRUCTOR & DESTRUCTOR            ************/

Span::Span(void) : _N(0), _tab(), _added(0) { }

Span::Span(unsigned int N) : _N(N), _tab(), _added(0){ 
}

Span::Span(Span const & ref) : _N(ref._N), _tab(ref._tab), _added(ref._added) {
    for (unsigned int i = 0; i < ref._added; i++)
        this->_tab[i] = ref._tab[i];
}

Span::~Span(void) { }

/***********                 OPERATOR                 ************/

Span    &Span::operator=(Span const & ref) {
    if (this == &ref)
        return (*this);
    this->_N = ref._N;
    this->_tab = ref._tab;
    this->_added = ref._added;
    for (unsigned int i = 0; i < ref._added; i++)
    {
        this->_tab[i] = ref._tab[i];
    }
    return (*this);
}

/***********                    METHODES                  ************/

void    Span::addNumber(int value) {

    if ( this->_added >= this->_N )
        throw Span::NoSpaceAvailable();
    else
    {
        this->_tab.push_back(value);
        this->_added++;
    }
}

void    Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {

    for (std::vector<int>::iterator it = begin ; it != end; it++)
    {
        if (this->_added >= this->_N)
            throw Span::NoSpaceAvailable();
        else
        {
            this->_tab.push_back(*it);
            this->_added++;
        }
    }
}

unsigned int     Span::shortestSpan() {

    unsigned int    shortest = 4294967295; //UINT_MAX dans <climits>

    if (this->_added == 0 || this->_added == 1)
        throw NotEnoughValuesForSpan();
    else
    {
        std::vector<int> sortedtab = this->_tab;
        for ( std::vector<int>::iterator it = this->_tab.begin(); it != this->_tab.end() ; it++)
            sortedtab.push_back(*it);
        std::sort(sortedtab.begin(), sortedtab.begin() + this->_added);
        for ( std::vector<int>::iterator it = sortedtab.begin(); it != (sortedtab.end() - 1) ; it++)
        {
            if (static_cast<unsigned int>(*(it + 1) - *it) < shortest)
                shortest = (*(it + 1) - *it);
            if (shortest == 0)
                break;
        }

        return(shortest);
    }

}

unsigned int     Span::longestSpan() {

    unsigned int longuest;

    if (this->_added == 0 || this->_added == 1)
        throw NotEnoughValuesForSpan();

    int min = *std::min_element(this->_tab.begin(), this->_tab.end());
    int max = *std::max_element(this->_tab.begin(), this->_tab.end());

    longuest = max - min;
    return (longuest);

}

void        Span::printTab() {
    std::cout << "printTab : [ ";
    for (unsigned int i = 0 ; i < this->_added - 1; i++)
        std::cout << this->_tab[i] << ", ";
    std::cout << this->_tab[this->_added - 1] <<" ]\n";
}

/***********                 EXCEPTION                 ************/

const char *Span::NoSpaceAvailable::what( void ) const throw() {
    return ("No space to add new number !");
}
const char *Span::NotEnoughValuesForSpan::what( void ) const throw() {
    return ("There isn't enough values to calculate span !");
}