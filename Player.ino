#include "Player.h"
#include "tetris.h"

void	Player::input_movement()
{
	int		i;

	for (i = 0; i < NR_OF_BTNS; i++)
	{
		if (digitalRead(buttons[i]) == HIGH)
		{
			switch (buttons[i])
			{
				case left_btn_port:
					car.safe_move(0, -1);
					break;
				case right_btn_port:
					car.safe_move(0, 1);
					break;
			}
		}
	}
}

bool	Player::collides()
{
	int		i;

	for (i = 0; i < NR_ENEMIES; i++)
	{
		if (game_ctrl.enemies[i].collides(&car))
			return true;
		
	}
	return false;
}

void	Player::die()
{
	const int	dead_anim_time = 2500;

	car.play_dead_anim(dead_anim_time);
}