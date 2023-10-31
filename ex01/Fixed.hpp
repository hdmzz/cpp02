/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:13:59 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/31 02:18:37 by hdamitzi         ###   ########.fr       */
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
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const &src);
	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt( void ) const;

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
