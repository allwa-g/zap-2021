#include <superkarel.h>


int main(){
    set_step_delay(100);
    turn_on("task_6.kw"); 

    while(no_beepers_present()){
        step();
    }

        while(beepers_present()){
        if (beepers_present()){
        pick_beeper();
        if (no_beepers_present()){
            while (not_facing_north()){
                turn_left();
            }
            while(no_beepers_present()){
                step();
            }
        } else if (beepers_present()){
            pick_beeper();
            if(no_beepers_present()){
                while(not_facing_west()){
                    turn_left();
                }    
                while(no_beepers_present()){
                    step();
                }
            }else if (beepers_present()){
                pick_beeper();
                if(no_beepers_present()){
                    while (not_facing_south()){
                        turn_left();
                    }
                    while(no_beepers_present()){
                        step();
                    }
                        

                }else if (beepers_present()){
                    pick_beeper();
                    if (no_beepers_present()){
                        while (not_facing_east()){
                            turn_left();
                        }
                        while(no_beepers_present()){
                            step();
                        }
                    } else if (beepers_present()){
                        pick_beeper();
                        turn_off();
                        
                    }
                    
                }
            }
        }
        }
        }


    turn_off();
    return 0;
    
}
