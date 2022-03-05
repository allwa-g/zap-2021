#include <superkarel.h>
#include <karel.h>

void turn_right();
void turn_around();

int main (){

    turn_on("task_1.kw");
    set_step_delay(50);
    put_beeper();
    if(front_is_clear()){
        step();
    } else if (right_is_clear()){
        turn_right();
        step();
    } else if (left_is_clear()){
        turn_left();
        step();
    }
    while (no_beepers_present())
    {
        if (front_is_clear() && right_is_blocked())
        {
            step();
        }
        if (right_is_clear()){
            turn_right();
            step();
        }
        if (front_is_blocked() && right_is_blocked() && left_is_blocked()){
            turn_around();
        }   
        if (front_is_blocked() && right_is_blocked()){
            turn_left();
        }
        if (beepers_present()){
            pick_beeper();
            break;
        }
    }
   // pick_beeper();
   // if (front_is_blocked()){
   //     turn_around();
   //     step();
   // } 
    turn_around();
    //step();
    while (no_beepers_present()){

        if (front_is_clear() && left_is_blocked()){
            step();
        }
        if (front_is_blocked() && right_is_blocked() && left_is_blocked()){
            turn_around();
            //step();
        }
        if (left_is_clear()){
            turn_left();
            step();
        }
        if (front_is_blocked() && left_is_blocked()){
            turn_right();
        }
        
        
    }
    if (beepers_present()){
        pick_beeper();
    }
    while (not_facing_west()){
        turn_left();
    }
    turn_off();
    return 0;
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(200);
    turn_left();
}
void turn_around(){
    set_step_delay(0);
    turn_left();
    set_step_delay(200);
    turn_left();
}