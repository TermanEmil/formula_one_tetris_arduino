/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RaceCar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:28:55 by eterman           #+#    #+#             */
/*   Updated: 2017/05/23 13:54:41 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RACE_CAR_H
# define RACE_CAR_H

# include "tetris.h"

class	RaceCar
{
	public:
		float	x;
		float	y;

		RaceCar(float new_x, float new_y);
		void	place(float _x, float _y);
		void	move(float delta_x, float delta_y);
		void	safe_move(float delta_x, float delta_y);
		void	print_me(int bakc_part = RACE_CAR_BK, int front_part = RACE_CAR_FR);
		bool	is_on_board();
		bool	collides(RaceCar *_car);
		void	play_dead_anim(int _time);
		
	private:
		void	_set_pos(float new_x, float new_y);
};

#endif
