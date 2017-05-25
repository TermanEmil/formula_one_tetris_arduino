/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameCtrl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 17:26:59 by eterman           #+#    #+#             */
/*   Updated: 2017/05/23 15:50:50 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CTRL_H
# define GAME_CTRL_H

# include "Arduino.h"
# include "RaceCar.h"
# include "Player.h"
# include "tetris.h"

# define NR_ENEMIES 4

class	GameCtrl
{
	public:
		int		input_rate = 50;
		float	speed = 1;
		float	delay_time = 400;
		Player	player = Player();

		RaceCar enemies[NR_ENEMIES] = {
			RaceCar(0, -1),
			RaceCar(0, -1),
			RaceCar(0, -1),
			RaceCar(0, -1)
		};

		GameCtrl(float _speed);
		void		setup();
		void		spawn_enemy();
		void		move_enemies();
		void		custom_delay();
		int			get_delay();
		bool		check_player();
		void		random_enemy_spawn();
		void		update_disp_score();
		void		start_formula_one(float _speed);
		
	private:
		RaceCar*	_get_free_car();
		int			_dist_to_firt_car();
		float		_get_chance_spawn();
		float		_get_speed();
		
};

#endif
