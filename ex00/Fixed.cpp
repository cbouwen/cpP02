#include "Fixed.hpp"

int    Fixed::getRawBits() const
{


}

void    Fixed::setRawBits(int const raw)
{


}

Fixed::Fixed(): _fixed(0)
{
}

Fixed::Fixed(const Fixed& copy): _fixed(copy._fixed)
{

}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_fixed = copy._fixed;
    }
}

Fixed::~Fixed()
{
}