/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:13:59 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/31 13:26:28 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const &src );
	~Fixed();

	Fixed	&operator=( Fixed const &rhs ); 
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat(void ) const;
	int		toInt( void ) const;

	//surcharge des operateurs de comparaison
	int	operator>( Fixed const &rhv ) const;
	int	operator<( Fixed const &rhv ) const;
	int	operator>=( Fixed const &rhv ) const;
	int	operator<=( Fixed const &rhv ) const;
	int	operator==( Fixed const &rhv ) const;
	int	operator!=( Fixed const &rhv ) const;

	//operateur arithmettique renverroon une instance de la classe 
	Fixed	operator+( Fixed const &rhv ) const;
	Fixed	operator-( Fixed const &rhv ) const;
	Fixed	operator*( Fixed const &rhv ) const;
	Fixed	operator/( Fixed const &rhv ) const;

	//operateur d'incrementation et de decrementation
	//ne prenne pas dargument vu que l'on agit directement sur l'instance
	Fixed &	operator++( void );//++i
	Fixed	operator++( int );//++i
	Fixed & operator--( void );//--i
	Fixed	operator--( int );//i--

//fonction statique signigie que on peut les appler de nimporte ou comma ac => Fixed::max( a, b );
	static Fixed&		min(Fixed& nb1, Fixed& nb2);
	static Fixed const&	min( Fixed const & nb1, Fixed const & nb2 );
	static Fixed&		max(Fixed& nb1, Fixed& nb2);
	static Fixed const&	max( Fixed const & nb1, Fixed const & nb2 );

private:
	int					_raw;
	static const int	_fractionnal = 8;
};

//il faut une surcharge d'operateur pour << lorsque on lui passe un objet Fixed
//renverra une reference sur output stream
//prend en paramaetre une reference sur ostream et un reference sur instance de la classe Fixed
//nb appellera sa fonction membre to float 
std::ostream& operator<<( std::ostream& os, const Fixed& nb );

#endif
