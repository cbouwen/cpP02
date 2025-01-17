#include "Fixed.hpp"

int    Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" <<std::endl;
    return (this->_fixed);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout <<"setRawBits member function called" << std::endl;
    this->_fixed = raw;
}

Fixed::Fixed(): _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_fixed = copy.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}