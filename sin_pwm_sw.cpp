#define THETA_0   (0x2D000000 >> 1)
#define THETA_1   (0x1A90A731 >> 1)
#define THETA_2   (0x0E094740 >> 1)
#define THETA_3   (0x07200112 >> 1)
#define THETA_4   (0x03938AA6 >> 1)
#define THETA_5   (0x01CA3794 >> 1)
#define THETA_6   (0x00E52A1A >> 1)
#define THETA_7   (0x007296D7 >> 1)
#define THETA_8   (0x00394BA5 >> 1)
#define THETA_9   (0x001CA5D9 >> 1)
#define THETA_10  (0x000E52ED >> 1)
#define THETA_11  (0x00072976 >> 1)
#define THETA_12  (0x000394BB >> 1)
#define THETA_13  (0x0001CA5D >> 1)
#define THETA_14  (0x0000E52E >> 1)
#define THETA_15  (0x00007297 >> 1)
#define THETA_16  (0x0000394B >> 1)
#define THETA_17  (0x00001CA5 >> 1)
#define R17_INV   (0x009B74ED >> 1)

#define WIDTH   32
#define INT     9
#define FRA     23

#include <iostream>
#include <cstdint>

uint8_t sin(uint8_t theta) {
    uint8_t duty;
    uint8_t _theta;

    uint32_t x;
    uint32_t y;

    uint32_t x_buf;
    uint32_t y_buf;

    uint32_t duty_buf;

    uint32_t buffer;
    
    if(theta > 90) {
        _theta = theta - 90;
    } else {
        _theta = theta;
    }
    {
        buffer = THETA_0 - (_theta << FRA);
        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = (100 << FRA) + ((100 << FRA) >> 1);
            y_buf = (100 << FRA) - ((100 << FRA) >> 1);
            buffer = buffer - THETA_1;
        } else {
            x_buf = (100 << FRA) - ((100 << FRA) >> 1);
            y_buf = (100 << FRA) + ((100 << FRA) >> 1);
            buffer = buffer + THETA_1;
        }
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 2);
            y_buf = y - ((int32_t)x >> 2);
            buffer = buffer - THETA_2;
        } else {
            x_buf = x - ((int32_t)y >> 2);
            y_buf = y + ((int32_t)x >> 2);
            buffer = buffer + THETA_2;
        }
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 3);
            y_buf = y - ((int32_t)x >> 3);
            buffer = buffer - THETA_3;
        } else {
            x_buf = x - ((int32_t)y >> 3);
            y_buf = y + ((int32_t)x >> 3);
            buffer = buffer + THETA_3;
        }
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 4);
            y_buf = y - ((int32_t)x >> 4);
            buffer = buffer - THETA_4;
        } else {
            x_buf = x - ((int32_t)y >> 4);
            y_buf = y + ((int32_t)x >> 4);
            buffer = buffer + THETA_4;
        }
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 5);
            y_buf = y - ((int32_t)x >> 5);
            buffer = buffer - THETA_5;
        } else {
            x_buf = x - ((int32_t)y >> 5);
            y_buf = y + ((int32_t)x >> 5);
            buffer = buffer + THETA_5;
        }
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 6);
            y_buf = y - ((int32_t)x >> 6);
            buffer = buffer - THETA_6;
        } else {
            x_buf = x - ((int32_t)y >> 6);
            y_buf = y + ((int32_t)x >> 6);
            buffer = buffer + THETA_6;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 7);
            y_buf = y - ((int32_t)x >> 7);
            buffer = buffer - THETA_7;
        } else {
            x_buf = x - ((int32_t)y >> 7);
            y_buf = y + ((int32_t)x >> 7);
            buffer = buffer + THETA_7;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 8);
            y_buf = y - ((int32_t)x >> 8);
            buffer = buffer - THETA_8;
        } else {
            x_buf = x - ((int32_t)y >> 8);
            y_buf = y + ((int32_t)x >> 8);
            buffer = buffer + THETA_8;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 9);
            y_buf = y - ((int32_t)x >> 9);
            buffer = buffer - THETA_9;
        } else {
            x_buf = x - ((int32_t)y >> 9);
            y_buf = y + ((int32_t)x >> 9);
            buffer = buffer + THETA_9;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 10);
            y_buf = y - ((int32_t)x >> 10);
            buffer = buffer - THETA_10;
        } else {
            x_buf = x - ((int32_t)y >> 10);
            y_buf = y + ((int32_t)x >> 10);
            buffer = buffer + THETA_10;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 11);
            y_buf = y - ((int32_t)x >> 11);
            buffer = buffer - THETA_11;
        } else {
            x_buf = x - ((int32_t)y >> 11);
            y_buf = y + ((int32_t)x >> 11);
            buffer = buffer + THETA_11;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 12);
            y_buf = y - ((int32_t)x >> 12);
            buffer = buffer - THETA_12;
        } else {
            x_buf = x - ((int32_t)y >> 12);
            y_buf = y + ((int32_t)x >> 12);
            buffer = buffer + THETA_12;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 13);
            y_buf = y - ((int32_t)x >> 13);
            buffer = buffer - THETA_13;
        } else {
            x_buf = x - ((int32_t)y >> 13);
            y_buf = y + ((int32_t)x >> 13);
            buffer = buffer + THETA_13;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 14);
            y_buf = y - ((int32_t)x >> 14);
            buffer = buffer - THETA_14;
        } else {
            x_buf = x - ((int32_t)y >> 14);
            y_buf = y + ((int32_t)x >> 14);
            buffer = buffer + THETA_14;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 15);
            y_buf = y - ((int32_t)x >> 15);
            buffer = buffer - THETA_15;
        } else {
            x_buf = x - ((int32_t)y >> 15);
            y_buf = y + ((int32_t)x >> 15);
            buffer = buffer + THETA_15;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 16);
            y_buf = y - ((int32_t)x >> 16);
            buffer = buffer - THETA_16;
        } else {
            x_buf = x - ((int32_t)y >> 16);
            y_buf = y + ((int32_t)x >> 16);
            buffer = buffer + THETA_16;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if((buffer & 0x80000000) == 0x00000000) {
            x_buf = x + ((int32_t)y >> 17);
            y_buf = y - ((int32_t)x >> 17);
            buffer = buffer - THETA_17;
        } else {
            x_buf = x - ((int32_t)y >> 17);
            y_buf = y + ((int32_t)x >> 17);
            buffer = buffer + THETA_17;
        }   
        x = x_buf;
        y = y_buf;
        //printf("0x%08x, 0x%08x\n", x, y);

        if(theta > 90) {
            duty_buf = (int32_t)(((int64_t)x * (int64_t)R17_INV) >> FRA);
        } else {
            duty_buf = (int32_t)(((int64_t)y * (int64_t)R17_INV) >> FRA);
        }
        duty = (duty_buf & 0xff000000) >> FRA;
    }
    return duty;
}

int main() {

    for(uint8_t i = 0; i <= 180; i++) {
        //printf("%d , %d\n", i, sin(i));
        printf("%d\n", sin(i));
        //printf("%d\n", i);
    }

    printf("%d , %d\n", 86, sin(86));
    printf("0xa4100000 - (0xfff8300000 >> 4) = %08x\n", 0xa4100000 - ((int32_t)0xf8300000 >> 4));
    printf("0x0a4100000 - 0x1ff830000 = %09x\n", 0x0a4100000 - 0x1ff830000);

}
