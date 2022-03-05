#include <superkarel.h>
void pick_all();
void turn_around();
void sort_beepers();
void step_down();
void turn_right();
int main() {
    turn_on("task_3.kw");
    set_step_delay(50);
    while (front_is_clear() && right_is_clear()){
        pick_all();
        sort_beepers();
    }
    if (front_is_clear() && right_is_blocked() && facing_east()){
        pick_all();
        sort_beepers();
    }
  
    while(not_facing_north()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    } //ked zastane, otoci sa a pojde na povod poziciu
    turn_around();
    while(no_beepers_present()){
        turn_left();
        while (no_beepers_present()){
            step();
            if (no_beepers_present() && front_is_blocked()){
                turn_around();
                while(front_is_clear()){
                    step();
                }
                turn_left();
                step();
                turn_left();
                //break;
            }
        } //vrati sa na povodnu  poziciu ked trafi beeper
        if (beepers_present()){
            turn_around();
            while(front_is_clear()){
                step();
            }
            turn_around();
            turn_off();
        } 
    }

    turn_off();
    return 0;
}
void (pick_all()){
    while (facing_east() && front_is_clear()){
        if (beepers_present()){
            pick_beeper();
            
        }else if (no_beepers_present() && front_is_clear()){
            step();
        }
    }
    if (front_is_blocked() && beepers_present()){
        pick_beeper();
    }
    turn_around(); 
}
void (turn_around()){
    turn_left();
    turn_left();
}
void (sort_beepers()){

    while(front_is_clear()){
      
      if(front_is_blocked() && facing_west()){
          step_down();
      }
        if(right_is_blocked() && facing_west() && beepers_in_bag()){
            if (no_beepers_present()){
                put_beeper();
            }
            
            step();
        } 
        if (no_beepers_in_bag() && front_is_clear()){
            step();
        }
        if(right_is_clear()){
            while(right_is_clear()&& front_is_clear()){
                turn_right();
                step();
                if(beepers_present()){
                    turn_around();
                    step();
                    turn_right();
                    if (beepers_in_bag() && no_beepers_present()){
                        put_beeper();
                    } else {
                        turn_around();
                        turn_around();
                    }
                    if (front_is_clear()){
                       step(); 
                    } else step_down();
                    
                } else {
                turn_around();
                step();
                turn_right();
                step();
                }
            }

        }
  
    }
    if (right_is_clear()){
        step_down();
    } else turn_off();
} 
void (step_down()){
    if(front_is_blocked()&& left_is_clear()){
        turn_left();
        step();
        turn_left();
    }else (turn_right());
}
void (turn_right()){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(50);
    turn_left();
}