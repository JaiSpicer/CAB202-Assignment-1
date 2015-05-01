#include "cab202_simple_sprite.h"
#include "cab202_screen.h"

#include "left_paddle.h"
#include "ball.h"
#include "game.h"


// INSERT GLOBAL VARIABLES HERE
sprite_id left_paddle_id;
sprite_id ball_id;
int left_paddle_mid;
int left_paddle_height;
int gt_one;
int ai = 0;
int adder;

char normal_left_paddle;

//-----------------------------------------------------------------------------
//  Function declarations.
void setup_left_paddle();
void reset_left_paddle();
//-----------------------------------------------------------------------------

// INSERT DECLARATIONS FOR HELPER FUNCTIONS HERE


//-----------------------------------------------------------------------------
//  Function implementations.
//-----------------------------------------------------------------------------


void setup_left_paddle() {
    
    // INSERT SETUP CODE HERE
    if (gt_one == 1) {
        char normal_left_paddle[] =
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|";
        left_paddle_id = create_big_sprite(3, 3, 1, 21, normal_left_paddle);
        ai = 0;
        left_paddle_height = 5;
    }
    else if (gt_one == 0) {
        char ai_left_paddle[] =
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|"
        "|";
        left_paddle_id = create_big_sprite(3, 12, 1, left_paddle_height, ai_left_paddle);
        ai = 1;
    }
    
}


void reset_left_paddle() {
    
    // INSERT RESET CODE HERE
    hide_sprite(left_paddle_id);
    setup_left_paddle();
    
}
bool update_left_paddle() {
    bool left_paddle_moved = FALSE;
    // INSERT UPDATE CODE HERE
    if (ai == 1){
        screen_position left_paddle_pos = get_sprite_screen_loc(left_paddle_id);
        screen_position ball_pos = get_sprite_screen_loc(ball_id);
        screen_dimensions left_paddle_size = get_sprite_size(left_paddle_id);
        
        left_paddle_mid = (left_paddle_size.height/2);
        
        if(24 > (left_paddle_pos.y + left_paddle_size.height) && ball_pos.y > left_paddle_pos.y && ball_pos.y <= 21 && ball_pos.x < 40) {
            move_sprite(left_paddle_id, 0, + 1);
        }
        else if(ball_pos.y < left_paddle_pos.y && left_paddle_pos.y > 3 && ball_pos.x < 40 ){
            move_sprite(left_paddle_id, 0, - 1);
        }
        
    }
    return left_paddle_moved;
}



// INSERT HELPER FUNCIONS HERE
