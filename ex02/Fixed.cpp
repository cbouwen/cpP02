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

// Overload comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return _fixed > other._fixed;
}

bool Fixed::operator<(const Fixed& other) const {
    return _fixed < other._fixed;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _fixed >= other._fixed;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _fixed <= other._fixed;
}

bool Fixed::operator==(const Fixed& other) const {
    return _fixed == other._fixed;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _fixed != other._fixed;
}

// Overload arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._fixed = _fixed + other._fixed;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._fixed = _fixed - other._fixed;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result._fixed = static_cast<int>((static_cast<long long>(_fixed) * other._fixed) >> _fraction);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._fixed == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result._fixed = static_cast<int>((static_cast<long long>(_fixed) << _fraction) / other._fixed);
    return result;
}

// Pre-increment
Fixed& Fixed::operator++() {
    _fixed++;
    return *this;
}

// Post-increment
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _fixed++;
    return temp;
}

// Pre-decrement
Fixed& Fixed::operator--() {
    _fixed--;
    return *this;
}

// Post-decrement
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _fixed--;
    return temp;
}

// Static member functions for min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
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