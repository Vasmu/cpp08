#ifndef _EASYFIND_
# define _EASYFIND_

# include <iostream>
# include <vector>
# include <algorithm>


template <typename T>
typename T::iterator easyfind(T container, int key) {

    typename T::iterator it;
    it = std::find(container.begin(), container.end(), key);
    if (it == container.end())
        throw std::exception();
    return (it);
}



#endif