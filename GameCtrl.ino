#include "Arduino.h"
#include "RaceCar.h"
#include "math.h"

GameCtrl::GameCtrl(float _speed)
{
	speed = _speed;
}

void		GameCtrl::start_formula_one(float _speed)
{
	speed = _speed;
	for (int i = 2500; i >= 500; i /= 2)
	{
		lcd.clear();
		delay(500);
		lcd.setCursor(4, 0);
		lcd.print("FORMULA");
		lcd.setCursor(6, 1);
		lcd.print("ONE");
		delay(i);
	}
	lcd.clear();
	lcd.setCursor(4, 0);
	lcd.print("START !!!");
	delay(750);
	lcd.clear();
	game_ctrl.setup();
}

void		GameCtrl::setup()
{
	player.car.place(0, random(2));
	player.points = 0;
	game_ctrl.update_disp_score();
	for (int i = 0; i < NR_ENEMIES; i++)
		enemies[i].place(-1, -1);
}

void		GameCtrl::spawn_enemy()
{
	RaceCar*	new_car;

	if ((new_car = _get_free_car()) == NULL)
		return;
	new_car->place(X_MAX, (int)random(2));
}

void		GameCtrl::move_enemies()
{
	for (int i = 0; i < NR_ENEMIES; i++)
	{
		if (enemies[i].is_on_board())
			enemies[i].move(-1, 0);
	}
}

int			GameCtrl::get_delay()
{
	return (int)(delay_time * 1 / _get_speed());
}

RaceCar*	GameCtrl::_get_free_car()
{
	for (int i = 0; i < NR_ENEMIES; i++)
	{
		if (!enemies[i].is_on_board())
			return &enemies[i];
	}
	return NULL;
}

/*
** There's a rate at which enemies move, but it may be too high, which
** can make the user input slow
*/

void		GameCtrl::custom_delay()
{
	int		i;
	float	_delay_time;

	_delay_time = get_delay();
	for (i = 0; i < _delay_time; i += input_rate)
	{
		player.input_movement();
		check_player();
		delay(input_rate);
	}
}


/*
** return true if player's still alive.
*/

bool		GameCtrl::check_player()
{
	if (game_ctrl.player.collides())
	{
		game_ctrl.player.die();
		start_formula_one(1);
		return false;
	}
	else
		return true;
}

float		GameCtrl::_get_chance_spawn()
{
	const float	points_when_100_perc = 200;
	const float	normal_chance = 40;

	return normal_chance + 40 * player.points / points_when_100_perc;
}

/*
** Distance from the top to the first enemy car on board.
*/

int			GameCtrl::_dist_to_firt_car()
{
	int		min;

	min = X_MAX;
	for (int i = 0; i < NR_ENEMIES; i++)
		if (enemies[i].is_on_board() && X_MAX - (int)enemies[i].x < min)
			min = X_MAX - (int)enemies[i].x;
	return min;
}

float		GameCtrl::_get_speed()
{
	const float	max_speed = 8;
	const float	acceleration = 0.001;

	return 2 + (float)max_speed * player.points /
		((float)player.points + 1 / acceleration);
}

void		GameCtrl::random_enemy_spawn()
{
	if (_dist_to_firt_car() >= 3 + 4 && random(100) < _get_chance_spawn())
		spawn_enemy();
}

void		GameCtrl::update_disp_score()
{
	int		a, b, ab;

	ab = player.points / 50;
	a = ab / 10;
	b = ab % 10;
	lcd.setCursor(15, 0);
	lcd.print(a);
	lcd.setCursor(15, 1);
	lcd.print(b);
}