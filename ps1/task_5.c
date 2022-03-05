# include <superkarel.h>
void turn_around();
void find_center();
void do_frame();
void go_on_otherside();
void go_around();
void turn_right();


int main (){
    turn_on("task_5.kw");

    set_step_delay(50);
   
    
 do { 
        if(facing_north()){
            if(front_is_clear()){
            if (front_is_clear() && right_is_blocked()){
                turn_around();
                    while (front_is_clear()){
                        step();
                    }
                    turn_around(); 
                   
            } 

            if (right_is_clear() && front_is_clear()){
                turn_around();
                while (front_is_clear()){
                    step();
                }
                turn_left();
                while(front_is_clear()){
                    step();
                }
                turn_left();
            } break;
            }
        } else {
            turn_left();
        }
        while (not_facing_south()){
            turn_left();
        }
        while(front_is_clear()){
            step();
        }
        
        if (front_is_blocked()){
            while(front_is_blocked()){
                turn_left();
            }
            
        do{
            step();
        } while(front_is_clear());
        }
       if (not_facing_north()){
            turn_left();
        } break;
    } while (front_is_clear() && right_is_blocked() && facing_north());
    
   
    find_center();
    
    do_frame();
    
    pick_beeper();
    go_on_otherside();
    turn_around();
    
    
    find_center();
    while (not_facing_north()){
        turn_left();
    }
    
    put_beeper();
    turn_left();
    while(front_is_clear()){
        step();
    }
    
    put_beeper();
    
    turn_around();
    step();
    while(no_beepers_present()){
        step();
    }
    pick_beeper();
    put_beeper();
    step();
    if (no_beepers_present()){
        while (front_is_clear()){
            step();
        }
        
    } else put_beeper();
    if(no_beepers_present()){
        put_beeper();
    }
    
    turn_around();
    step();
    while(no_beepers_present()){
        step();
    }
    if(beepers_present()){
        pick_beeper();
        while(not_facing_north()){
            turn_left();
        }
    }
  
    turn_off();
    return 0;
}

void (find_center()){

    while (front_is_clear()){
        put_beeper();
        step();
    }
    turn_around();
    while (front_is_clear()){
        step();
    }
    turn_around();


    while(beepers_present()){
        pick_beeper();
        step();
        while(beepers_present()){
            step();
        }
        turn_around();
        step();
        
    }

    
}
void (turn_right()){
    turn_left();
    turn_left();
    turn_left();
}

void (do_frame()){
    while(no_beepers_present()){
        if (front_is_clear()){
            put_beeper();
            step();
        } else {
            turn_left();
        }
    }
}
void (turn_around()){
    turn_left();
    turn_left();
}
void(go_on_otherside()){
    if(facing_north()){
        turn_left();
        while (front_is_clear() && not_facing_east()){
            while(front_is_clear()){
                step();
                if (beepers_present()){
                    pick_beeper();
                }
            }   
            turn_around();
            while (front_is_clear()){
                step();
                if (beepers_present()){
                    pick_beeper();
                }
            }
        }
    }
}
void (go_around()){
    while (beepers_present()){
        step();
     
        
        if(front_is_blocked()){
            turn_left();
        }
    }
    if (no_beepers_present()){
        put_beeper();
       
    }
    
}