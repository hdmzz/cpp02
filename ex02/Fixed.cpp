/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:13:56 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/31 06:37:16 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*******************************************************************************
 * 						constructor/destructor
*******************************************************************************/
Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

//constructeur prenant un entier constant
Fixed::Fixed(int const n) : _raw(n << _fractionnal)
{
	std::cout << "Int construcor called" << std::endl;
	return ;
}

//constructeru prenant un float constant
Fixed::Fixed(float const f) : _raw( roundf(f * (1 << _fractionnal)))
{
	std::cout << "Float construcor called" << std::endl;
	return ;
}

//copy constructor recopie src qui est une reference sur l'instance this
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	//dereference this et lui assigner la va valeur src qui est une reference
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}


/*******************************************************************************
 * 						Operator
*******************************************************************************/
/* 
L'opérateur d'assignation (=) est une fonction membre qui permet d'assigner une
 instance de la classe à une autre instance de la même classe.
 cela permet d'evier par exemple l'auto-assignation

 typiquement ici on verifie que src (qui est un objet Fixed) n'est pas le meme que this
 et si on a bien 2objets differnts on assigne les valeurs de src a this mais on n'assigne pas 
 comme en c le pointeur de src a this mais les valeurs de src a this
 autrement dis cest une copie de src dans this
 */
Fixed &Fixed::operator=( Fixed const & src )
{
	std::cerr << "Copy assignment operator called." << std::endl;
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}
/* 
Par exemple:

Fixed a; 
Fixed b;

a = b; // appelle operator= 
Ici, l'objet a est assigné à l'objet b, en copiant les données membres de b vers a.

L'opérateur= est défini comme membre de la classe Fixed et prend comme paramètre une référence 
constante à un autre objet Fixed src.

Il doit typiquement:

Vérifier que src n'est pas le même objet que this pour éviter l'auto-assignation
Faire une copie des données membres de src vers this
Retourner une référence à l'objet courant this
Cette fonction opérateur= suit la convention de copie et est importante pour permettre
 l'assignation entre objets Fixed.
 */

/*******************************************************************************
 * 						getter setter
*******************************************************************************/
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}


float	Fixed::toFloat( void ) const
{
	float	ret;

	ret = (float)_raw / (1 << _fractionnal);
	return (ret);
}

int		Fixed::toInt( void ) const
{
	int	ret;

	ret = _raw >> _fractionnal;
	return (ret);
}


/*******************************************************************************
 * 						operator overload member function
*******************************************************************************/
//la valeur lefthand est forcement this on a plus qua comparer la valeur contenu
//par this au parametre qui sera donc right hand value
int	Fixed::operator>( Fixed const &rhv ) const
{
	if (this->toFloat() > rhv.toFloat())
		return (1);
	return (0);
}

int	Fixed::operator<( Fixed const &rhv ) const
{
	if (this->toFloat() < rhv.toFloat())
		return (1);
	return (0);
}

int	Fixed::operator>=( Fixed const &rhv ) const
{
	if (this->toFloat() >= rhv.toFloat())
		return (1);
	return (0);
}

int	Fixed::operator<=( Fixed const &rhv ) const
{
	if (this->toFloat() <= rhv.toFloat())
		return (1);
	return (0);
}

int	Fixed::operator==( Fixed const &rhv ) const
{
	if (this->toFloat() == rhv.toFloat())
		return (1);
	return (0);
}

int	Fixed::operator!=( Fixed const &rhv ) const
{
		if (this->toFloat() != rhv.toFloat())
		return (1);
	return (0);
}

/*******************************************************************************
 * 						arithmetique operator overload
*******************************************************************************/
Fixed	Fixed::operator+( Fixed const &rhv ) const
{
	return ( Fixed(this->toFloat() + rhv.toFloat()));
}

Fixed	Fixed::operator-( Fixed const &rhv ) const
{
	return ( Fixed(this->toFloat() - rhv.toFloat()));
}

Fixed	Fixed::operator*( Fixed const &rhv ) const
{
	return ( Fixed(this->toFloat() * rhv.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &rhv ) const
{
	return ( Fixed(this->toFloat() / rhv.toFloat()));
}

/*******************************************************************************
 * 					incrementation/decrementation operator overload
*******************************************************************************/
Fixed &	Fixed::operator++( void )//++i
{
	this->_raw += 1;
	return ( *this );
}

//l'idée ici est de faire une copie de this, ensuite d'incrementer this avec la 
//surcharge ci dessus et renvoyer la copie qui n'as pas été incrémentée
Fixed	Fixed::operator++( int )//i++
{
	Fixed	copy = Fixed( *this );

	++( *this );
	return ( copy );
}

Fixed & Fixed::operator--( void )//--i
{
	this->_raw -= 1;
	return ( *this );
}

Fixed	Fixed::operator--( int )
{
	Fixed copy = Fixed( *this );
	--( *this );
	return ( copy );
}

/*******************************************************************************
 * 									Min/Max
*******************************************************************************/

Fixed&			Fixed::min(Fixed& nb1, Fixed& nb2)
{
	if (nb1 <= nb2)
		return ( nb1 );
	return ( nb2 );
}

Fixed const &	Fixed::min( Fixed const & nb1, Fixed const & nb2 )
{
	if (nb1 <= nb2)
		return ( nb1 );
	return ( nb2 );
}

Fixed&			Fixed::max(Fixed& nb1, Fixed& nb2)
{
	if (nb1 >= nb2)
		return ( nb1 );
	return ( nb2 );
}

Fixed const &	Fixed::max( Fixed const & nb1, Fixed const & nb2 )
{
	if (nb1 >= nb2)
		return ( nb1 );
	return ( nb2 );
}

/*******************************************************************************
 * 						operator overload global function						
*******************************************************************************/

//appelle a la methode toFloat car elle englobe meme les entier qui peux le plus peux le moins
std::ostream& operator<<( std::ostream& os, const Fixed& nb )
{
	std::cout << nb.toFloat();
	return (os);
}
