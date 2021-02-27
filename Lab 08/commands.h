#ifndef COMMANDS_H
#define COMMANDS_H

extern struct node *first_instruction;
extern struct node *current_instruction;

extern uint8_t byte;

extern bool verbose;

void do_step(void);
void do_continue(void);
void do_print(void);
void do_list(void);

#endif