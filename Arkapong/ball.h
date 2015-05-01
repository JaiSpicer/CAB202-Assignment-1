#ifndef __BALL_H__
#define __BALL_H__

#include "curses.h"
#include "cab202_simple_sprite.h"
#include "cab202_screen.h"

// INSERT DECLARATIONS OF ANY NEW FUNCTIONS OR GLOBAL VARIABLES HERE
#include "game.h"
void setup_score();

void game_ball();

/*
 *	setup_ball:
 *
 *	Initialises the ball-related aspects of the game,
 *	creating the icon for the ball and initialising other state related
 *	to the ball.
 */

void setup_ball();

/*
 *	reset_ball:
 *
 *	Restores the ball to its original position and appearance.
 */

void reset_ball();

void setup_game_type_three();
void reset_game_type_three();

void setup_game_type_four();
void reset_game_type_four();

void setup_game_type_five();
void reset_game_type_five();

void setup_game_type_six();
void reset_game_type_six();

void setup_game_type_seven();
void reset_game_type_seven();
void update_game_type_seven();

void setup_game_type_eight();
void reset_game_type_eight();

/*
 *	Interprets the key code and updates the position of the ball sprite
 *	accordingly.
 *
 *	Input:
 *		key_code:	an integer that represents a key code.
 *
 *	Output:
 *		Returns TRUE if and only if the ball moved, indicating that the screen
 *		needs to be refreshed.
 */

bool update_ball();

#endif
