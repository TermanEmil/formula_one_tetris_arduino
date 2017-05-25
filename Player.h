/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:41:50 by eterman           #+#    #+#             */
/*   Updated: 2017/05/23 14:40:23 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "GameCtrl.h"
# include "RaceCar.h"

class	Player
{
	public:
		int		points = 0;
		RaceCar car = RaceCar(0, 0);
		
		void	input_movement();
		bool	collides();
		void	die();
};

#endif
