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

        //Getters
        int     getRawBits(void) const;

        //Setters
        void    setRawBits( int const raw);


        float   toFloat(void) const;
        int     toInt(void) const;

        // Comparison Operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Arithmetic Operators
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Increment/Decrement Operators
        Fixed& operator++();    // Pre-increment
        Fixed operator++(int);  // Post-increment
        Fixed& operator--();    // Pre-decrement
        Fixed operator--(int);  // Post-decrement

        // Static Member Functions
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif