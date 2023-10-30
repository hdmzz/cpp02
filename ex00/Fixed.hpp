/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:13:59 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/10/30 23:07:42 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);//constructor de recopie
	~Fixed();

	Fixed &operator=(Fixed const &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int					_raw;
	static const int	_fractionnal = 8;
};

#endif
