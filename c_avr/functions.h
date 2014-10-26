
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

extern int function01 (int);
extern int function02 (int);
extern void send_result(void);
extern void calculate_result(unsigned int, unsigned char);

extern struct outgoing_message {
     unsigned int y_value;
     unsigned char fill_byte;
     unsigned char stop_byte;
};

#endif
