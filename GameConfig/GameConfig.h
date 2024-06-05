#pragma once

/* ------- ���� ���� �ĺ� -------- */
#define WINDOW_WIDTH	IMG_BACKGROUND_WIDTH
#define WINDOW_HEIGHT	IMG_BACKGROUND_HEIGHT


/* ------- ���� IMG �ĺ� -------- */
#define IMG_BACKGROUND_WIDTH 400		
#define IMG_BACKGROUND_HEIGHT 740

#define IMG_GROUND_WIDTH	400	
#define IMG_GROUND_HEIGHT	354
#define IMG_GROUND_POS_Y (IMG_BACKGROUND_HEIGHT-IMG_GROUND_HEIGHT)*3/2-7

#define IMG_COLUMN_WIDTH	78
#define IMG_COLUMN_HEIGHT	1200

#define IMG_BIRD_WIDTH		56
#define IMG_BIRD_HEIGHT		48

#define IMG_HALF_COLUMN_HEIGHT	524
#define IMG_COLUMN_DOWN_Y		673

/* ------- ���� TIMER �ĺ� -------- */
#define TIMER_GROUND_MOVE_TIMERID	1
#define TIMER_GROUND_MOVE_INTERVAL	20
#define TIMER_GROUND_MOVE_STEP		3

#define TIMER_RAND_NEW_TIMERID	2
#define TIMER_RAND_NEW_INTERVAL	5

#define TIMER_NEW_COLUMN_TIMERID	3
#define TIMER_NEW_COLUMN_INTERVAL	3000

#define TIMER_BIRD_CHANGE_TIMERID	4
#define TIMER_BIRD_CHANGE_INTERVAL	100

#define TIMER_BIRD_SHOW_TIMERID		5
#define TIMER_BIRD_SHOW_INTERVAL	10

#define TIMER_BIRD_POSITION_TIMERID		6
#define TIMER_BIRD_POSITION_INTERVAL	30

/* -------- ���� Bird ���еĲ��� -------- */
#define BIRD_STARTSPEED			-10
#define BIRD_A					1
#define BIRD_MAX_DOWN_SPEED		11

#define BIRD_POS_X				166
#define BIRD_POS_Y				226


#define BUTTON_POS_X_1			166
#define BUTTON_POS_Y_1			300
#define BUTTON_POS_X_2			228
#define BUTTON_POS_Y_2			376

#define BUTTON2_POS_X_1			133
#define BUTTON2_POS_Y_1			332
#define BUTTON2_POS_X_2			281
#define BUTTON2_POS_Y_2			407
