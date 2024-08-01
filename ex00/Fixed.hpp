#include <iostream>
#include <string>

class Fixed
{
    private:
        int                 _fixed;
        static const int    _fraction = 8;
    public:;
        Fixed();
        Fixed(const Fixed& copy);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits( int const raw);
};