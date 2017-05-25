/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eterman <terman.emil@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:38:12 by eterman           #+#    #+#             */
/*   Updated: 2017/05/23 15:46:59 by eterman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H

# define RACE_CAR_BK 2
# define RACE_CAR_FR 1
# define EMPTY_BYTE 3
# define NR_OF_BTNS 2
# define X_MAX 15
enum	e_btn_port
{
	left_btn_port = 7, right_btn_port = 6
};

const int		buttons[2] = {left_btn_port, right_btn_port};

#endif
