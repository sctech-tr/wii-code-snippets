// from sctech-tr/wcalc
#include <wiiuse/wpad.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gccore.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

// Initialize video and input
VIDEO_Init();
WPAD_Init();
rmode = VIDEO_GetPreferredMode(NULL);
xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIX_SZ);
VIDEO_Configure(rmode);
VIDEO_SetNextFramebuffer(xfb);
VIDEO_SetBlack(false);
VIDEO_Flush();
VIDEO_WaitVSync();
if (rmode->viTVMode & VI_NON_INTERLACE) VIDEO_WaitVSync();

printf("\x1b[2;0H");
char num1[80] = "";

printf("The controls are:\n");
printf("HOME = 0\n");
printf("1 = 1\n");
printf("2 = 2\n");
printf("A = 3\n");
printf("up = 4\n");
printf("down = 5\n");
printf("left = 6\n");
printf("right = 7\n");
printf("+ = 8\n");
printf("- = 9\n");
printf("B = backspace\n");
printf("please enter the number:\n");

while (1) {
    VIDEO_WaitVSync();
    WPAD_ScanPads();
    
    if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) { 
        strcat(num1, "0");
        printf("\rnumber 1: %s\n", num1);
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_1) { 
        strcat(num1, "1"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_2) { 
        strcat(num1, "2"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_A) { 
        strcat(num1, "3"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_UP) { 
        strcat(num1, "4"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_DOWN) { 
        strcat(num1, "5"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_LEFT) { 
        strcat(num1, "6"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_RIGHT) { 
        strcat(num1, "7"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_PLUS) {
        strcat(num1, "8"); 
        printf("\rnumber 1: %s\n", num1); 
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_MINUS) { 
        strcat(num1, "9"); 
        printf("\rnumber 1: %s\n", num1);  
    } else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_B) { 
        if (strlen(num1) > 0) {
            num1[strlen(num1) - 1] = '\0';
            printf("\rnumber 1: %s\n", num1);
        }
    }
}
