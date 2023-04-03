#include "../../headers/kernel.h"

t_cursor *cursor_initialize(void)
{
    t_cursor *cursor;

    cursor->column = 0;
    cursor->row = 0;
    cursor->get_position = &get_position;
    cursor->get_cursor_position = &get_cursor_position;
    cursor->set_cursor_position = &set_cursor_position;
    cursor->left = &cursor_move_left;
    cursor->right = &cursor_move_right;
    cursor->next_line = &cursor_move_next_line;
    cursor->move = &cursor_move;
    return &cursor;
}
