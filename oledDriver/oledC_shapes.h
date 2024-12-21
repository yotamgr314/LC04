#ifndef OLEDC_SHAPES_H
#define	OLEDC_SHAPES_H

#include <stdbool.h>
#include <stdint.h>

enum OLEDC_SHAPE 
{
    OLED_SHAPE_CIRCLE,
    OLED_SHAPE_RING,
    OLED_SHAPE_RECTANGLE,
    OLED_SHAPE_LINE,
    OLED_SHAPE_POINT,
    OLED_SHAPE_CHARACTER,
    OLED_SHAPE_STRING,
    OLED_SHAPE_BITMAP,
};

typedef union shape_params_t 
{
    struct 
    {
        uint16_t color;
        uint8_t x;
        uint8_t y;
    } point;
    struct 
    {
        uint16_t color;
        uint8_t xc;
        uint8_t yc;
        uint8_t radius;
    } circle;
    struct 
    {
        uint16_t color;
        uint8_t x0;
        uint8_t y0;
        uint8_t radius;
        uint8_t width;
    } ring;
    struct 
    {
        uint16_t color;
        uint8_t xs;
        uint8_t ys;
        uint8_t xe;
        uint8_t ye;
    } rectangle;
    struct 
    {
        uint16_t color;
        uint8_t xs;
        uint8_t ys;
        uint8_t width;
        uint8_t xe;
        uint8_t ye;
    } line;
    struct 
    {
        uint16_t color;
        uint8_t x;
        uint8_t y;
        uint8_t scale_x;
        uint8_t scale_y;
        uint8_t character;
    } character;
    struct 
    {
        uint16_t color;
        uint8_t x;
        uint8_t y;
        uint8_t scale_x;
        uint8_t scale_y;
        uint8_t *string;
    } string;
    struct 
    {
        uint16_t color;
        uint8_t x;
        uint8_t y;
        uint8_t sx;
        uint8_t sy;
        uint32_t *bit_array;
        uint8_t array_length;
    } bitmap;
} shape_params_t;

typedef struct shape 
{
    uint8_t _type;
    void (*draw)(struct shape*);
    shape_params_t params;
    bool active;
} shape_t;

void oledC_createShape(enum OLEDC_SHAPE shape_type, shape_params_t *params, shape_t *newShape);

void oledC_DrawCircle(uint8_t center_x, uint8_t center_y, uint8_t radius, uint16_t color);
void oledC_DrawRing(uint8_t center_x, uint8_t center_y, uint8_t radius, uint8_t width, uint16_t color);
void oledC_DrawRectangle(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y, uint16_t color);
void oledC_DrawLine(uint8_t start_x, uint8_t start_y, uint8_t end_x, uint8_t end_y, uint8_t width, uint16_t color);
void oledC_DrawPoint(uint8_t x, uint8_t y, uint16_t color);
uint16_t oledC_ReadPoint(uint8_t x, uint8_t y);
void oledC_DrawThickPoint(uint8_t center_x, uint8_t center_y, uint8_t width, uint16_t color);
void oledC_DrawCharacter(uint8_t x, uint8_t y, uint8_t sx, uint8_t sy, uint8_t ch, uint16_t color);
void oledC_DrawString(uint8_t x, uint8_t y, uint8_t sx, uint8_t sy, uint8_t *string, uint16_t color);
void oledC_DrawBitmap(uint8_t x, uint8_t y, uint16_t color, uint8_t sx, uint8_t sy, uint32_t *bit_array, uint8_t array_width);

#endif	/* OLEDC_SHAPES_H */
