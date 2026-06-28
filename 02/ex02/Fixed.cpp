# include "Fixed.hpp"


Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	this->_value = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if(this != &other)
		this->_value = other.getRawBits();
	return(*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return(this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return(static_cast<float>(this->_value) / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return(this->_value >> this->_fractionalBits);
}

bool Fixed::operator > (const Fixed &other) const
{
	return(this->_value > other._value);
}

bool Fixed::operator < (const Fixed &other) const
{
	return(this->_value < other._value);
}

bool Fixed::operator >= (const Fixed &other) const
{
	return(this->_value >= other._value);
}

bool Fixed::operator <= (const Fixed &other) const
{
	return(this->_value <= other._value);
}

bool Fixed::operator == (const Fixed &other) const
{
	return(this->_value == other._value);
}

bool Fixed::operator != (const Fixed &other) const
{
	return(this->_value != other._value);
}

Fixed Fixed::operator + (const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator - (const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator * (const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator / (const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

//++a
Fixed& Fixed::operator ++ (void)
{
	this->_value++;
	return (*this);
}

//a++
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);

	this->_value++;
	return (tmp);
}

//--a
Fixed& Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

//a--
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);

	this->_value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}


std::ostream &operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
