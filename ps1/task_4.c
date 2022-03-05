#include <superkarel.h>

void turn_right();
void turn_around();
void stairs_up();
void stairs_down();
void do_pillar();
void back_pillar();
void stairs();
int main (){
    turn_on("task_4.kw");
    set_step_delay(10);
   do{
    while (not_facing_north()){
        turn_left();
    }
        
        while (beepers_in_bag()){
            set_step_delay(10);
            if (front_is_clear()){
                 step();
            }
           
            if (facing_south() && front_is_blocked() && left_is_blocked()){
                turn_left();
                turn_off();
            }
        
            if(front_is_blocked() && no_beepers_present() && facing_south() && left_is_clear()){
                //turn_around();
                
                turn_left();
                step();
                turn_left();
            
              
                
                while(front_is_blocked()){
                    turn_left();
                }
                while(front_is_clear()){
                    step();
                }
                turn_around();
            
                
                
            } else if (front_is_blocked() && facing_south() && left_is_blocked() && beepers_present()){
                turn_left();
                turn_off();
            }
            /*
            if(front_is_blocked() && beepers_present() && facing_south() && left_is_clear()){
                turn_left();
                turn_off();
            }
            */
                
            
            
            if (front_is_blocked()){
                turn_around();
            } else if (facing_south() && left_is_blocked() && front_is_blocked()){
                turn_off();
            }
            if (beepers_present()){
                
                do_pillar();
                do_pillar();
                do_pillar();
                
                while(front_is_blocked()){
                if (front_is_blocked() && facing_north()){
                    turn_around();
                    do_pillar();

                }
                if(front_is_blocked() && left_is_blocked() && facing_south()){
                    turn_left();
                    turn_off();
                }
               
                if ((front_is_blocked() && facing_south() && left_is_clear())){
                    turn_left();
                    step();
                    turn_left();
                } else if (front_is_blocked() && right_is_blocked()){
                    turn_around();
                    while(front_is_clear()){
                        step();
                    }
                    turn_left();
                    turn_off();
                }
                if (front_is_blocked() && facing_north()){
                    turn_around();
                    while (front_is_clear()){
                        step();
                    }
                    turn_left();
                    step();
                    turn_left();
                }
                }
            }else if (front_is_blocked() && right_is_blocked() && facing_south()){
 
                    turn_left();
                    turn_off();
                }
            /*
            if (front_is_blocked() && facing_east()){
                turn_right();
                step();
                turn_left();
                step();
                turn_right();
            }
            */
        }

        
   

   } while(front_is_blocked() && left_is_blocked() && facing_south());
    turn_off();
    return 0;
}



void (turn_right()){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(200);
    turn_left();
    }
void(turn_around()){
    set_step_delay(0);
    turn_left();
    set_step_delay(200);
    turn_left();
}


void (do_pillar()){
    set_step_delay(10);
    
    while (front_is_clear()){
       if (no_beepers_present()){
           put_beeper();
           step();
       } else{
           step();
       }
       
       if (front_is_blocked()&& no_beepers_present()){
           put_beeper();
           turn_around();
       } 
    } 
    turn_around();
    while (front_is_clear()&& beepers_present()){
        step();
    }
}  