#include "../../headers/cursor.h"
#include "../../headers/terminal.h"

void cursor_move_right(t_cursor *this)
{
    if (++this->column == VGA_WIDTH)
    {
        this->column = 0;
        if (++this->row == VGA_HEIGHT)
            this->row = 0;
    }
}

void cursor_move_left(t_cursor *this)
{
    if (--this->column < 0)
    {
        this->column = VGA_WIDTH;
        if (--this->row < 0)
            this->row = VGA_HEIGHT;
    }
}

void cursor_move_next_line(t_cursor *term)
{
    term->column = 0;
    if (++term->row == VGA_HEIGHT)
        term->row = 0;
}

void cursor_move(t_cursor *this, enum cursor_move type)
{
    switch (type)
    {
    case CURSOR_MOVE_LEFT:
        this->left(this);
        break;
    case CURSOR_MOVE_NEXT_LINE:
        this->next_line(this);
        break;
    case CURSOR_MOVE_RIGHT:
        this->right(this);
        break;
    default:
        break;
    }

    this->set_cursor_position(this->get_position(this));
}
