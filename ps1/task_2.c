#include <karel.h>
#include <superkarel.h>

void turn_right();
void turn_around();

int main (){
    
    turn_on("task_2.kw");
    while (no_beepers_present()){

        set_step_delay(100);
        if (front_is_clear()){
            step();
        }
        if (front_is_blocked()){
            turn_left();
        }
    }
    pick_beeper();
    turn_around();
    

    while (beepers_in_bag()){
        set_step_delay(100);
        if (front_is_clear()){
            step();
        }
        if (front_is_blocked() && right_is_blocked() && left_is_blocked()){
            break;
        }
        if (front_is_blocked()){
            turn_right();
        }
    }

    turn_off();
    return(0);
}
void (turn_right()){
    set_step_delay(10);
    turn_left();
    turn_left();
    set_step_delay(100);
    turn_left();
}
void (turn_around()){
    turn_left();
    turn_left();
}