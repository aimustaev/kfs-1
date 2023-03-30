#ifndef VGA_H
#define VGA_H

#include "types.h"
/* Hardware text mode color constants. */
enum vga_color
{
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
	VGA_COLOR_WHITE = 15,
};

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;


typedef struct Terminal
{
	size_t row;
	size_t column;
	uint8_t color;
	uint16_t *buffer;
} t_terminal;

// TERMINAL
void terminal_setcolor(t_terminal *term, uint8_t color);
t_terminal terminal_initialize(void);
void set_value_by_position(t_terminal *term, char c);
void move_cursor_left(t_terminal *term);
void move_cursor_down(t_terminal *term);
void move_cursor_next_line(t_terminal *term);
uint16_t get_cursor_position(void);
void set_cursor_position(uint16_t position);
//VGA
uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg);
uint16_t vga_entry(unsigned char uc, uint8_t color);

#endif