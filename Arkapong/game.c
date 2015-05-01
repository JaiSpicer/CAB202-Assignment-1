#include "game.h"
int gt_one;
int gt_two;
int gt_two_l;
int gt_three;
int gt_four;
int gt_five;
int gt_six;
int gt_seven;
int gt_eight;
int gt_nine;

void info_sreen() {
    // Information Screen content
    setup_score();
    mvprintw(1, 0, "1: OFF");
    mvprintw(1, 7, "2: OFF");
    mvprintw(1, 14, "3: OFF");
    mvprintw(1, 21, "4: OFF");
    mvprintw(1, 28, "5: OFF");
    mvprintw(1, 35, "6: OFF");
    mvprintw(1, 42, "7: OFF");
    mvprintw(1, 49, "8: OFF");
    
}
void info_screen_option() {
    gt_one = 1;
    gt_two = 1;
    gt_three = 1;
    gt_four = 1;
    gt_five = 1;
    gt_six = 0;
    gt_seven = 1;
    gt_eight = 1;
}

void setup_game() {
    auto_refresh_sprites = FALSE;
    auto_sprite_delay = FALSE;
    auto_wrap_sprites = FALSE;
    
    setup_screen();
    info_screen_option();
    
    
    
    // Information Screen Edge
    for(int b = -1;b<79;b++){
        mvaddch(2,b+1, '_');
        
    }
    
    
    // Setting up the rest of the play screen
    info_sreen();
    setup_right_paddle();
    setup_left_paddle();
    setup_ball();
    update_ball();
    reset_right_paddle();
}


void reset_game() {
    reset_screen();
    info_screen_option();
    
    // Information Screen Edge
    for(int b = -1;b<79;b++){
        mvaddch(2,b+1, '_');
        
    }
    
    // Setting up the rest of the play screen
    info_sreen();
    reset_right_paddle();
    reset_left_paddle();
    reset_ball();
    update_ball();
    
    refresh();
}


int play_turn() {
    if ( update_screen() ) {
        reset_game();
        
        return TURN_OK;
    }
    
    update_ball();
    /* If we have a key, process it immediately. */
    int key_code = getch();
    if (key_code == '1') { // Left paddle ai
        if (gt_one == 0) { // Turn the left paddle ai on
            mvprintw(1, 0, "1: ON ");
            update_ball();
            reset_left_paddle();
            gt_one = 1;
        }
        else if (gt_one == 1) { // Turn the left paddle ai off
            mvprintw(1, 0, "1: OFF");
            update_ball();
            reset_left_paddle();
            gt_one = 0;
        }
    }
    else if (key_code == '2') { // Curved paddles
        if (gt_two == 0) { // Turn the left and right paddles into curved ones
            mvprintw(1, 7, "2: OFF");
            update_ball();
            gt_two = 1;
        }
        else if (gt_two == 1) { // Turn the paddles back to there normal state
            mvprintw(1, 7, "2: ON ");
            update_ball();
            gt_two = 0;
        }
    }
    else if (key_code == '3') { // Point blocks
        if (gt_three == 0) { // Turn the point blocks on
            mvprintw(1, 14, "3: OFF");
            update_ball();
            reset_game_type_three();
            gt_three = 1;
        }
        else if (gt_three == 1) { // Turn the point blocks back off
            mvprintw(1, 14, "3: ON ");
            update_ball();
            setup_game_type_three();
            gt_three = 0;
        }
    }
    else if (key_code == '4') { // Increase the paddle length
        if (gt_four == 0) { // Turn the extender on
            mvprintw(1, 21, "4: OFF");
            update_ball();
            reset_game_type_four();
            gt_four = 1;
        }
        else if (gt_four == 1) { // Turn the extender off
            mvprintw(1, 21, "4: ON ");
            update_ball();
            setup_game_type_four();
            gt_four = 0;
        }
    }
    else if (key_code == '5') { // Decrease the paddle length
        if (gt_five == 0) { // Turn the decreaser on
            mvprintw(1, 28, "5: OFF");
            update_ball();
            reset_game_type_five();
            gt_five = 1;
        }
        else if (gt_five == 1) { // Turn the decreaser off
            mvprintw(1, 28, "5: ON ");
            update_ball();
            setup_game_type_five();
            gt_five = 0;
        }
    }
    else if (key_code == '6') { // Splitter block
        if (gt_six == 0) { // Turn the ball splitter on
            mvprintw(1, 35, "6: ON ");
            update_ball();
            gt_six = 1;
        }
        else if (gt_six == 1) { // Turn the ball splitter off
            mvprintw(1, 35, "6: OFF");
            update_ball();
            gt_six = 0;
        }
    }
    else if (key_code == '7') { // Wind block
        if (gt_seven == 0) { // Turn the wind block on
            mvprintw(1, 42, "7: OFF");
            update_ball();
            reset_game_type_seven();
            gt_seven = 1;
        }
        else if (gt_seven == 1) { // Turn the wind block off
            mvprintw(1, 42, "7: ON ");
            update_ball();
            setup_game_type_seven();
            gt_seven = 0;
        }
    }
    else if (key_code == '8') { // Ball muncher
        if (gt_eight == 0) { // Turn the ball muncher on
            mvprintw(1, 49, "8: ON ");
            update_ball();
            reset_game_type_eight();
            update_game_type_seven();
            gt_eight = 1;
        }
        else if (gt_eight == 1) { // Turn the ball muncher off
            mvprintw(1, 49, "8: OFF");
            update_ball();
            setup_game_type_eight();
            gt_eight = 0;
        }
    }
    update_ball();
    update_left_paddle();
    
    if ( key_code == 'q' || key_code == 'Q' ) {
        return TURN_GAME_OVER;
    }
    else if ( key_code == 'r' || key_code == 'R' ) {
        reset_game();
        return TURN_OK;
    }
    
    if ( update_right_paddle( key_code ) ) {
        return TURN_SCREEN_CHANGED;
    }
    
    return TURN_OK;
}
