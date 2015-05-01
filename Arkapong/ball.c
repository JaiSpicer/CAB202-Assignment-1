#include "cab202_simple_sprite.h"
#include "cab202_screen.h"

#include "game.h"
#include "ball.h"
#include "right_paddle.h"
#include "left_paddle.h"



// INSERT GLOBAL VARIABLES HERE
#define POINT_BLOCK_TOTAL (10)

// INSERT SPRITEs
sprite_id ball_id;
sprite_id game_over_id;
sprite_id right_paddle_id;
sprite_id left_paddle_id;
sprite_id point_block_id [POINT_BLOCK_TOTAL];
sprite_id add_paddle_block_id;
sprite_id add_paddle_block_id_clear;
sprite_id minus_paddle_block_id;
sprite_id ball_muncher_id;
sprite_id wind_block;

// INSERT TIMERs
timer_id ball_timer;
timer_id muncher_timer;

// INSERT CHARs
char normal_right_paddle;
char normal_left_paddle;
char right_paddle_scale;

// INSERT INT'S
int gt_two = 0;
int gt_three = 0;
int gt_four = 0;
int gt_five = 0;
int gt_six = 0;
int gt_seven = 1;
int gt_eight = 1;
int left_paddle_height ;
int right_paddle_h = 5;
int ai;
int last_hit;
int score = 0;
int lives = 3;
int i = 0;
int range_x = 75 - 4;
int range_y = 23 - 4;
int range_x_bm = 70 - 4;
int range_y_bm = 18 - 4;
int range_x_w = 60;
int range_y_w = 17;
int x_rand;
int y_rand;
int x_rand_bm;
int y_rand_bm;
int point_block_x [10];
int point_block_y [10];
int left_height = 5;
int right_height = 5;
int muncher_state;
int wind_block_state;

// INSERT CHAR's
char extended_right_paddle[] =
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

char extended_left_paddle[] =
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

char ball_muncher_one[] =
"   ##### "
"  ## ##  "
" ####    "
"  #####  "
"   ##### ";

char ball_muncher_two[] =
"   ####  "
"  ## ### "
" #####   "
"  ###### "
"   ####  ";

char ball_muncher_three[] =
"   ####  "
"  ## ### "
" ########"
"  ###### "
"   ####  ";



//-----------------------------------------------------------------------------
//  Function declarations.
//-----------------------------------------------------------------------------
void setup_ball();
void reset_ball();
void setup_score();
bool update_ball();
void continue_ball();
void reset_game_type_four();
// INSERT DECLARATIONS FOR HELPER FUNCTIONS HERE


//-----------------------------------------------------------------------------
//  Function implementations.
//-----------------------------------------------------------------------------
void setup_score() {
    mvprintw(0, 0, "Score: %d", score);
    refresh();
}

void setup_lives() {
    mvprintw(0, 72, "lives: %d", lives);
}

void setup_ball() {
    
    // INSERT SETUP CODE HERE
    update_ball();
    ball_id = create_sprite(39, 13, 'o', 0);
    int dx = rand() % 2+1;
    int dy = rand() % 2+1;
    set_sprite_direction( ball_id, -dx, dy);
    ball_timer = create_timer(100);
    muncher_timer = create_timer(100);
    score = 0;
    lives = 3;
	
    setup_score();
    setup_lives();

    
}

void reset_ball() {
    
    // INSERT RESET CODE HERE
    update_ball();
    move_sprite_to(ball_id, 39, 13);
    int dx = rand() % 2+1;
    int dy = rand() % 2+1;
    set_sprite_direction( ball_id, -dx, dy);
    ball_timer = create_timer(100);
    score = 0;
    lives = 3;
    
    setup_score();
    setup_lives();
    
}
// This is the function that is called when a ball is lost
void continue_ball() {
    update_ball();
    move_sprite_to(ball_id, 39, 13);
    int dx = rand() % 2+1;
    int dy = rand() % 2+1;
    set_sprite_direction( ball_id, -dx, dy);
    ball_timer = create_timer(100);
    
    setup_score();
    setup_lives();
}

void setup_game_type_three(){ // Creates the 10 add blocks
    int point_block_x [10];
    int point_block_y [10];
    
    for (int i = 0; i < 10; i++) {
        show_sprite(point_block_id[i]);
    }
    
    
    while ( i < 10) {
        show_sprite(point_block_id[i]);
        x_rand = 4 + (rand() % range_x);
        y_rand = 4 + (rand() % range_y);
        
        point_block_x[i] = x_rand;
        point_block_y[i] = y_rand;
        
        char point_block[] =
        "##"
        "##";
        
        point_block_id[i] = create_big_sprite(point_block_x[i], point_block_y[i], 2, 2, point_block);
        i++;
    }
}
void reset_game_type_three() { // Hides the 10 add blocks
    for (int i = 0; i < 10; i++) {
        hide_sprite(point_block_id[i]);
    }
}

void setup_game_type_four() { // Creates the add length sprite at a random location
    x_rand = 4 + (rand() % range_x);
    y_rand = 4 + (rand() % range_y);
        
    char add_paddle_block[] =
        "+++++";
    add_paddle_block_id = create_big_sprite(x_rand, y_rand, 5, 1, add_paddle_block);
    show_sprite(right_paddle_id);
    
}
void reset_game_type_four() { // Hides the add length sprite
    hide_sprite(add_paddle_block_id);
    show_sprite(right_paddle_id);
}

void setup_game_type_five() { // Creates the minus length sprite at a random location
    x_rand = 4 + (rand() % range_x);
    y_rand = 4 + (rand() % range_y);
    
    char minus_paddle_block[] =
    "-----";
    minus_paddle_block_id = create_big_sprite(x_rand, y_rand, 5, 1, minus_paddle_block);
    show_sprite(right_paddle_id);
    
}
void reset_game_type_five() { // Hides the minus length sprite
    hide_sprite(minus_paddle_block_id);
    show_sprite(right_paddle_id);
}

void setup_game_type_six() {
    
}

void reset_game_type_six() {
    
}

void setup_game_type_seven() {
    x_rand = 4 + (rand() % range_x_bm);
    y_rand = 4 + (rand() % range_y_bm);
    
    char wind_add_block[] =
    " |---| "
    " | + | "
    " | + | "
    " |---| ";
    wind_block = create_big_sprite(x_rand, y_rand, 7, 4, wind_add_block);
    wind_block_state = 0;
}
void reset_game_type_seven() {
    hide_sprite(wind_block);
    show_sprite(right_paddle_id);
}
void update_game_type_seven() {
}

void setup_game_type_eight() {
    x_rand_bm = 4 + (rand() % range_x_bm);
    y_rand_bm = 4 + (rand() % range_y_bm);
    muncher_state = 0;
    
    ball_muncher_id = create_big_sprite(x_rand_bm, y_rand_bm, 9, 5, ball_muncher_one);
    hide_sprite(ball_muncher_id);
    show_sprite(right_paddle_id);
}

void reset_game_type_eight() {
    hide_sprite(ball_muncher_id);
    show_sprite(right_paddle_id);
}

bool update_ball() {
    // timer for ball speed
    if( timer_expired(ball_timer) ) {
        
        screen_position ball_pos = get_sprite_screen_loc( ball_id );
        screen_dimensions screen = get_screen_size();
        screen_position right_paddle_pos = get_sprite_screen_loc(right_paddle_id);
//        screen_dimensions right_paddle_dim = get_screen_size(right_paddle_id);
        screen_position left_paddle_pos = get_sprite_screen_loc(left_paddle_id);

        bool bounced = FALSE;
        move_sprite_forward(ball_id);
        if (gt_two == 0) { // Curved paddles are turn on
            if (ball_pos.x >= right_paddle_pos.x - 1 && ball_pos.y >= right_paddle_pos.y) {
                score = score + 1;
                setup_score();
                move_sprite_backward( ball_id );
                bounce_sprite_vertical( ball_id );
                turn_sprite(ball_id, 20);
                last_hit = 1;
                bounced = TRUE;
            }
            if (ball_pos.x <= left_paddle_pos.x + 1 && ball_pos.y >= left_paddle_pos.y) {
                score = score + 1;
                setup_score();
                move_sprite_backward( ball_id );
                bounce_sprite_vertical( ball_id );
                turn_sprite(ball_id, 20);
                last_hit = 0;
                bounced = TRUE;
            }
        }
        else if (gt_two == 1) { // Curved paddles are turn off
            if (ball_pos.x >= right_paddle_pos.x - 1 && ball_pos.y >= right_paddle_pos.y) {
                score = score + 1;
                setup_score();
                move_sprite_backward( ball_id );
                bounce_sprite_vertical( ball_id );
                last_hit = 1;
                bounced = TRUE;
                }
            if (ball_pos.x <= left_paddle_pos.x + 1 && ball_pos.y >= left_paddle_pos.y) {
                score = score + 1;
                setup_score();
                move_sprite_backward( ball_id );
                bounce_sprite_vertical( ball_id );
                last_hit = 0;
                bounced = TRUE;
                }
            }
        // keep ball bouncing between y borders
        if ( ball_pos.y <= 3 || ball_pos.y >= screen.height - 1 ) {
            move_sprite_backward( ball_id );
            bounce_sprite_horizontal( ball_id );
            bounced = TRUE;
        }

        if (gt_three == 0) { // Point block collison detection and mover
            for(int i = 0; i<10;i++) {
                screen_position point_block_loc = get_sprite_screen_loc(point_block_id[i]);
                if ((point_block_loc.x == ball_pos.x && point_block_loc.y == ball_pos.y) || (point_block_loc.x + 1 == ball_pos.x && point_block_loc.y == ball_pos.y) || (point_block_loc.x == ball_pos.x && point_block_loc.y + 1 == ball_pos.y) || (point_block_loc.x + 1 == ball_pos.x && point_block_loc.y + 1 == ball_pos.y)){
                    score = score + 1;
                    setup_score();
                    x_rand = 4 + (rand() % range_x);
                    y_rand = 4 + (rand() % range_y);
                    
                    point_block_x[i] = x_rand;
                    point_block_y[i] = y_rand;
                    
                    move_sprite_to(point_block_id[i],point_block_x[i] ,point_block_y[i]);
                    move_sprite_backward( ball_id );
                    bounce_sprite_vertical( ball_id );
                    bounced = TRUE;
                }
            }
        }
        if (gt_four == 0) { // Add paddle length block collision and mover
            screen_position add_paddle_block_loc = get_sprite_screen_loc(add_paddle_block_id);
            
            if (ball_pos.x >= add_paddle_block_loc.x && ball_pos.x <= add_paddle_block_loc.x + 4 && ball_pos.y >= add_paddle_block_loc.y && ball_pos.y < add_paddle_block_loc.y + 1) {

                x_rand = 4 + (rand() % range_x);
                y_rand = 4 + (rand() % range_y);
                
                move_sprite_to(add_paddle_block_id, x_rand, y_rand);
                move_sprite_backward(ball_id);
                bounce_sprite_vertical(ball_id);
                if (last_hit == 0 && right_paddle_h > 21) {
                    left_paddle_height = left_paddle_height + 2;
                    set_sprite_image(left_paddle_id, 1, left_paddle_height, extended_left_paddle);
                    
                }
                else if (last_hit == 1 && right_paddle_h > 21) {
                    right_paddle_h = right_paddle_h + 2;
                    set_sprite_image(right_paddle_id, 1, right_paddle_h, extended_left_paddle);
                }
                //add_paddle_length();
                bounced = TRUE;
            }
        }
        if (gt_five == 0) { // Minus paddle length block collision and mover
            screen_position minus_paddle_block_loc = get_sprite_screen_loc(minus_paddle_block_id);
            
            if (ball_pos.x >= minus_paddle_block_loc.x && ball_pos.x <= minus_paddle_block_loc.x + 4 && ball_pos.y >= minus_paddle_block_loc.y && ball_pos.y < minus_paddle_block_loc.y + 1) {
                
                x_rand = 4 + (rand() % range_x);
                y_rand = 4 + (rand() % range_y);
                
                move_sprite_to(minus_paddle_block_id, x_rand, y_rand);
                move_sprite_backward(ball_id);
                bounce_sprite_vertical(ball_id);
                if (last_hit == 0 && left_paddle_height < 3) {
                    left_paddle_height = left_paddle_height - 2;
                    set_sprite_image(left_paddle_id, 1, left_paddle_height, extended_right_paddle);
                    
                }
                else if (last_hit == 1 && right_paddle_h < 3) {
                    right_paddle_h = right_paddle_h - 2;
                    set_sprite_image(right_paddle_id, 1, right_paddle_h, extended_right_paddle);
                }
                //add_paddle_length();
                bounced = TRUE;
            }
        }
        if (gt_seven == 0) {
            x_rand_bm = 4 + (rand() % range_x_bm);
            y_rand_bm = 4 + (rand() % range_y_bm);
            screen_position wind_block_loc = get_sprite_screen_loc(wind_block);
            simple_sprite_t ball_dir = get_sprite(ball_id);
            
            
            if (ball_pos.x >= wind_block_loc.x && ball_pos.x <= wind_block_loc.x + 7 && ball_pos.y >= wind_block_loc.y && ball_pos.y < wind_block_loc.y + 4) {
                move_sprite_to(wind_block,x_rand_bm ,y_rand_bm);
                if (wind_block_state == 0) {
                    wind_block_state = wind_block_state + 1;
                    mvprintw(1, 56, "Wind Direction: RIGHT ");
                }
                else if (wind_block_state == 1) {
                    wind_block_state = wind_block_state + 1;
                    mvprintw(1, 56, "Wind Direction: UP    ");
                }
                else if (wind_block_state == 2) {
                    wind_block_state = wind_block_state + 1;
                    mvprintw(1, 56, "Wind Direction: DOWN  ");
                }
                else if (wind_block_state == 3) {
                    wind_block_state = 0;
                    mvprintw(1, 56, "Wind Direction: LEFT  ");
                }
                else {
                    wind_block_state = 0;
                    mvprintw(1, 56, "Wind Direction: LEFT  ");
                }
            }
            else {
                if (wind_block_state == 0) { //wind left
                    if (ball_pos.x < wind_block_loc.x) {
                        move_sprite(ball_id, ball_dir.direction.dx * 2, ball_dir.direction.dy);
                    }
                    else if (ball_pos.x > wind_block_loc.x) {
                        move_sprite(ball_id, ball_dir.direction.dx / 2, ball_dir.direction.dy);
                    }
                }
                else if (wind_block_state == 1) { //wind right
                    if (ball_pos.x > wind_block_loc.x) {
                        move_sprite(ball_id, ball_dir.direction.dx * 2, ball_dir.direction.dy);
                    }
                    else if (ball_pos.x < wind_block_loc.x) {
                        move_sprite(ball_id, ball_dir.direction.dx / 2, ball_dir.direction.dy);
                    }
                }
                else if (wind_block_state == 2) { //wind up
                    if (ball_pos.y > wind_block_loc.y) {
                        move_sprite(ball_id, ball_dir.direction.dx * 2, ball_dir.direction.dy);
                    }
                    else if (ball_pos.y < wind_block_loc.y) {
                        move_sprite(ball_id, ball_dir.direction.dx / 2, ball_dir.direction.dy);
                    }
                }
                else if (wind_block_state == 3) { //wind down
                    if (ball_pos.y > wind_block_loc.y) {
                        move_sprite(ball_id, ball_dir.direction.dx * 2, ball_dir.direction.dy);
                    }
                    else if (ball_pos.y < wind_block_loc.y) {
                        move_sprite(ball_id, ball_dir.direction.dx / 2, ball_dir.direction.dy);
                    }
                }
            }
        
        if ((gt_eight == 0 && score >= 25) || (gt_eight == 0 && score >= 50) || (gt_eight == 0 && score >= 75) || (gt_eight == 0 && score >= 100) || (gt_eight == 0 && score >= 125) || (gt_eight == 0 && score >= 150) || (gt_eight == 0 && score >= 175) || (gt_eight == 0 && score >= 200)) {
            screen_position ball_muncher_pos = get_sprite_screen_loc(ball_muncher_id);
            show_sprite(ball_muncher_id);
            
            if (ball_pos.x >= ball_muncher_pos.x && ball_pos.x <= ball_muncher_pos.x + 9 && ball_pos.y >= ball_muncher_pos.y && ball_pos.y < ball_muncher_pos.y + 5) {
                move_sprite(ball_id, 0, 4);
                if (muncher_state == 0) {
                    set_sprite_image(ball_muncher_id, 9, 5, ball_muncher_one);
                    muncher_state = 1;
                }
                else if (muncher_state == 1) {
                    set_sprite_image(ball_muncher_id, 9, 5, ball_muncher_two);
                    muncher_state = 2;
                }
                else if (muncher_state == 2) {
                    set_sprite_image(ball_muncher_id, 9, 5, ball_muncher_three);
                }
                move_sprite(ball_muncher_id, +1, 0);
                            }
            else {
                if (muncher_state == 0) {
                    set_sprite_image(ball_muncher_id, 9, 5, ball_muncher_one);
                    muncher_state = 1;
                }
                else if (muncher_state == 1) {
                    set_sprite_image(ball_muncher_id, 9, 5, ball_muncher_two);
                    muncher_state = 2;
                }
                else if (muncher_state == 2) {
                    set_sprite_image(ball_muncher_id, 9, 5, ball_muncher_three);
                    muncher_state = 0;
                }
                move_sprite(ball_muncher_id, +1, 0);
            }
            
        }
        }

        // lose a life
        if ( lives > 0) {
            if (ball_pos.x >= 78 || ball_pos.x <= 2) {
            lives = lives - 1;
            continue_ball();
            }
        }
        else if (lives == 0) {
            clear();
            ai = 0;
            move_sprite_to(ball_id, -10, -10);
            hide_sprite(right_paddle_id);
            hide_sprite(left_paddle_id);
            char game_over[] =
            "  ####   ###   #   #   ##### "
            " #      #   #  ## ##  #      "
            " # ###  #   #  # # #  #####  "
            " #   #  #####  # # #  #      "
            "  ####  #   #  #   #   ##### "
            "                             "
            "  ###   #   #   #####  ####  "
            " #   #  #   #  #       #   # "
            " #   #  #   #  #####   ####  "
            " #   #   # #   #       #  #  "
            "  ###     #     #####  #   # ";
            game_over_id = create_big_sprite(25, 2, 29, 11, game_over);
            mvprintw(14, 31, "Your high score: %d", score);
            mvprintw(15, 24, "To reset the game press the r or R key");
            mvprintw(16, 25, "To quit the game press the q or Q key");
        }

        // keep ball moving if bounced
       if ( bounced ) {
            move_sprite_forward( ball_id );
        }
 
        return TRUE;
    }		
    return FALSE;
}


// INSERT HELPER FUNCIONS HERE
