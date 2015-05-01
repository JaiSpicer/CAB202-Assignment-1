#include "cab202_simple_sprite.h"
#include "cab202_screen.h"

#include "right_paddle.h"

#include "ball.h"


// INSERT GLOBAL VARIABLES HERE
sprite_id right_paddle_id;
sprite_id right_two_paddle_id;
int right_paddle_h;

//-----------------------------------------------------------------------------
//  Function declarations.
void setup_right_paddle();
void reset_right_paddle();
//-----------------------------------------------------------------------------

// INSERT DECLARATIONS FOR HELPER FUNCTIONS HERE


//-----------------------------------------------------------------------------
//  Function implementations.
//-----------------------------------------------------------------------------
void update_right_paddle_height() {
    
}

void setup_right_paddle() {

	// INSERT SETUP CODE HERE
    
    show_sprite(right_paddle_id);
        char normal_right_paddle[] =
    "|"
    "|"
    "|"
    "|"
    "|";
        right_paddle_id = create_big_sprite(76, 12, 1, right_paddle_h, normal_right_paddle);
    }


void reset_right_paddle() {

	// INSERT RESET CODE HERE
    show_sprite(right_paddle_id);
    move_sprite_to(right_paddle_id, 76, 12);

}
bool update_right_paddle( int key_code ) {
	bool right_paddle_moved = FALSE;

	// INSERT UPDATE CODE HERE
    screen_position right_paddle_pos = get_sprite_screen_loc(right_paddle_id);
    
    if (key_code == KEY_UP && right_paddle_pos.y > 3) {
        move_sprite(right_paddle_id, 0, - 1);
        right_paddle_moved = TRUE;
    }
    else if (key_code == KEY_DOWN && right_paddle_pos.y < 19) {
        move_sprite(right_paddle_id, 0, + 1);
        right_paddle_moved = TRUE;
    }
    
    return right_paddle_moved;
}




// INSERT HELPER FUNCIONS HERE
