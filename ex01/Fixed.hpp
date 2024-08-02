#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int                 _fixed;
        static const int    _fraction = 8;
    public:;
        //Constructors
        Fixed();
        Fixed(const int input);
        Fixed(const float input);
        Fixed(const Fixed& copy);

        //Overloaded operators
        Fixed& operator=(const Fixed& copy) ;

        //Destructors
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits( int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif