#include <LiquidCrystal.h>
#include "GameCtrl.h"
#include "RaceCar.h"
#include "Player.h"
#include "tetris.h"

byte race_car_back[8] =
{
	0b10000,
	0b11000,
	0b11000,
	0b00111,
	0b00111,
	0b11000,
	0b11000,
	0b10000
};

byte race_car_front[8] =
{
	0b00000,
	0b11000,
	0b11000,
	0b11111,	
	0b11111,
	0b11000,
	0b11000,
	0b00000
};

byte empty_byte[8] =
{
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
GameCtrl	game_ctrl = GameCtrl(1);

/*
** Writes if the coordinates are valid
*/

void	write_cond(int x, int y, int content)
{
	if ((y == 0 || y == 1) && x >= 0 && x < X_MAX)
	{
		lcd.setCursor(x, y);
		lcd.write(content);
	}
}

void	setup_lcd()
{
	lcd.createChar(RACE_CAR_FR, race_car_front);
	lcd.createChar(RACE_CAR_BK, race_car_back);
	lcd.createChar(EMPTY_BYTE, empty_byte);
	lcd.begin(16, 2);
}

void	setup_hardware()
{
	int		i;

	setup_lcd();
	for (i = 0; i < NR_OF_BTNS; i++)
		pinMode(i, INPUT);
}

void setup()
{
	setup_hardware();

	Serial.begin(9600);
	randomSeed(analogRead(0));

	game_ctrl.start_formula_one(1);
}

void loop()
{
	game_ctrl.random_enemy_spawn();
	game_ctrl.move_enemies();
	game_ctrl.check_player();
	game_ctrl.custom_delay();
	game_ctrl.player.points += 1;
	game_ctrl.update_disp_score();
}

