#include "Fixed.hpp"

int    Fixed::getRawBits() const
{
    return (this->_fixed);
}

void    Fixed::setRawBits(int const raw)
{
    this->_fixed = raw;
}

float   Fixed::toFloat() const
{
    return static_cast<float>(_fixed) / (1 <<_fraction);
}

int     Fixed::toInt(void) const
{
    return _fixed >> _fraction;
}

Fixed::Fixed(): _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int input)
{
    std::cout << "Int constructor called" << std::endl;
    _fixed = input << _fraction;
}

Fixed::Fixed(const float input)
{
    std::cout << "Float constructor called" << std::endl;
    _fixed = static_cast<int>(roundf(input * (1 << _fraction)));
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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}