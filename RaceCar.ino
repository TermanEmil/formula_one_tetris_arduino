#include "RaceCar.h"
#include "Arduino.h"
#include "tetris.h"

RaceCar::RaceCar(float new_x, float new_y)
{
	place(new_x, new_y);
}

void	RaceCar::place(float _x, float _y)
{
	_set_pos(_x, _y);
	print_me();
}

void	RaceCar::move(float delta_x, float delta_y)
{
	write_cond((int)x, (int)y, EMPTY_BYTE);
	write_cond((int)x + 1, (int)y, EMPTY_BYTE);
	_set_pos(x + delta_x, y + delta_y);
	print_me();
}

void	RaceCar::safe_move(float delta_x, float delta_y)
{
	if (x + delta_x < 0 || x + delta_x > X_MAX - 1)
		delta_x = 0;
	if (y + delta_y < 0 || y + delta_y > 1)
		delta_y = 0;
	move(delta_x, delta_y);
}

void	RaceCar::print_me(int bakc_part, int front_part)
{
	write_cond(x, y, bakc_part);
	write_cond(x + 1, y, front_part);
}

void	RaceCar::_set_pos(float new_x, float new_y)
{
	x = new_x;
	y = new_y;
}

bool	RaceCar::is_on_board()
{
	return x >= -1 && x <= X_MAX && y >= 0 && y < 2;
}

bool	RaceCar::collides(RaceCar *_car)
{
	return (int)_car->y == (int)y &&
		(int)_car->x >= (int)x - 1 && (int)_car->x <= (int)x + 1;
}

void	RaceCar::play_dead_anim(int _time)
{
	const int	blink_rate = 250;

	while (_time > 0)
	{
		print_me(EMPTY_BYTE, EMPTY_BYTE);
		delay(blink_rate);
		print_me();
		delay(blink_rate);
		_time -= blink_rate * 2;
	}	
}
