#ifndef _SPAN_
# define _SPAN_
# include <iostream>
# include <ctime>
# include <algorithm>
# include <vector>

# define SIZE (10)

class Span {
    private :
        unsigned int    _N;
        std::vector<int> _tab;
        unsigned int    _added;
        int *           _sortedtab;

    public :
        Span(void);
        Span(unsigned int N);
        Span(Span const & ref);
        ~Span(void);
        Span    &operator=(Span const & ref);

        void    addNumber(int value);
        void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        unsigned int     shortestSpan();
        unsigned int     longestSpan();
        void             printTab();
        class NoSpaceAvailable : public std::exception
        {
            public :
                virtual const char *what( void ) const throw();
        };
        class NotEnoughValuesForSpan : public std::exception
        {
            public :
                virtual const char *what( void ) const throw();
        };

};

#endif