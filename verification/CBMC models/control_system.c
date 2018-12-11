#include <stdio.h>

/****STATE DEFINES****/
#define HARD_LEFT 	0
#define SOFT_LEFT 	1
#define CENTER 		2
#define SOFT_RIGHT	3
#define HARD_RIGHT	4

/****DIRECTION DEFINES****/
#define LEFT 		0
#define RIGHT 		1

/****SLOPE LIMITS****/
#define MAX_CENTER	2
#define MAX_SOFT	6


typedef struct state{
	int current_state, prev_state;
} state_t;


state_t state_control(int error, int dir, state_t state);


int main(int argc, char *argv[]){
	state_t state;
	state.current_state =	CENTER;
	state.prev_state = 		CENTER;

	state = state_control(9, RIGHT, state);
	
	printf("Current State: %d\n", state.current_state);

	return 0;
}

state_t state_control(int slope, int dir, state_t state){
    
    int i, j;

    // This is the general form that tests all transitions, to test each individually you can just replace i, j with state names like CENTER or SOFT_RIGHT
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            assert(state.current_state == i && state.prev_state == j);
        }
    }
	
	
	if(slope < MAX_CENTER){
		state.current_state = CENTER;
	}
	else if(slope < MAX_SOFT){
		if(dir == LEFT){
			state.current_state = SOFT_LEFT;
		}
		if(dir == RIGHT){
			state.current_state = SOFT_RIGHT;
		}
	}
	else{
		if(dir == LEFT){
			state.current_state = HARD_LEFT;
		}
		if(dir == RIGHT){
			state.current_state = HARD_RIGHT;
		}
	}
	
	if(state.current_state != state.prev_state){
		if(state.current_state == CENTER){
			if(state.prev_state == HARD_LEFT){
				printf("turn right 2\n");
			}
			if(state.prev_state == SOFT_LEFT){
				printf("turn right 1\n");
			}
			if(state.prev_state == SOFT_RIGHT){
				printf("turn left 1\n");
			}
			if(state.prev_state == HARD_RIGHT){
				printf("turn left 2\n");
			}
		}
		if(state.current_state == SOFT_RIGHT){
			if(state.prev_state == HARD_LEFT){
				printf("turn right 1\n");
			}
			if(state.prev_state == CENTER){
				printf("turn left 1\n");
			}
			if(state.prev_state == SOFT_RIGHT){
				printf("turn left 2\n");
			}
			if(state.prev_state == HARD_RIGHT){
				printf("turn left 3\n");
			}
		}
		if(state.current_state == HARD_LEFT){
			if(state.prev_state == SOFT_LEFT){
				printf("turn left 1\n");
			}
			if(state.prev_state == CENTER){
				printf("turn left 2\n");
			}
			if(state.prev_state == SOFT_RIGHT){
				printf("turn left 3\n");
			}
			if(state.prev_state == HARD_RIGHT){
				printf("turn left 4\n");
			}
		}
		if(state.current_state == SOFT_RIGHT){
			if(state.prev_state == HARD_LEFT){
				printf("turn right 3\n");
			}
			if(state.prev_state == SOFT_LEFT){
				printf("turn right 2\n");
			}
			if(state.prev_state == CENTER){
				printf("turn right 1\n");
			}
			if(state.prev_state == HARD_RIGHT){
				printf("turn left 1\n");
			}
		}
		if(state.current_state == HARD_RIGHT){
			if(state.prev_state == HARD_LEFT){
				printf("turn right 4\n");
			}
			if(state.prev_state == SOFT_LEFT){
				printf("turn right 3\n");
			}
			if(state.prev_state == CENTER){
				printf("turn right 2\n");
			}
			if(state.prev_state == SOFT_RIGHT){
				printf("turn right 1\n");
			}
		}
	}

	return state;
}
