#include<ncurses.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int y, x;
    char* label;
} Button;

Button buttons[] = {
    {4, 2, "7"}, {4, 8, "8"}, {4, 14, "9"}, {4, 20, "/"},
    {7, 2, "4"}, {7, 8, "5"}, {7, 14, "6"}, {7, 20, "*"},
    {10, 2, "1"}, {10, 8, "2"}, {10, 14, "3"}, {10, 20, "-"},
    {13, 2, "0"}, {13, 8, "C"}, {13, 14, "="}, {13, 20, "+"}
};

int num_buttons = sizeof(buttons) / sizeof(Button);
char result [20] = "0"; 
int current_button = 0;

void draw_button(WINDOW *win, Button *button, bool highlight) {
    if (highlight)
        wattron(win, A_REVERSE);
    mvwprintw(win, button->y, button->x, "[%s]", button->label);
    if (highlight)
        wattroff(win, A_REVERSE);

}

void draw_calculator(WINDOW *win) {
    wclear(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "Result: %s", result);
    for (int i=0; i < num_buttons; i++) {
        draw_button(win, &buttons[i], i == current_button);
    }
    wrefresh(win);
}

void process_input(char *input) {
    static char operand[20] = "";
    static char operator = 0;

    if(strcmp(input, "C") == 0) {
        strcpy(result, "0");
        operand[0] = '\0';
        operator = 0;
    } else if (strcmp(input, "=") == 0){
        if (operator && operand[0]) {
            int a = atoi(result);
            int b = atoi(operand);
            switch(operator) {
                case '+': sprintf(result, "%d", a + b); break;
                case '-': sprintf(result, "%d", a - b); break;
                case '*': sprintf(result, "%d", a * b); break;
                case '/':
                    if (b != 0) sprintf(result, "%d", a / b);
                    else strcpy(result, "Error");
                    break;
            }
            operand[0] = '\0';
            operator = 0;
        }
    } else if (strchr("+-*/", input[0])) {
            operator = input [0];
    } else {
            if (operator) {
                strcat(operand, input);
            } else {
                if (strcmp(result, "0") == 0)
                    strcpy(result, input);
                else 
                    strcat(result, input);
            }
        }
    }



int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    WINDOW *win = newwin(HEIGHT, WIDTH, (LINES - HEIGHT) / 2, (COLS - WIDTH) / 2);

    while (1) {
        draw_calculator(win);
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                current_button = (current_button - 4 + num_buttons) % num_buttons;
                break;
            case KEY_DOWN:
                current_button = (current_button + 4) % num_buttons;
                break;
            case KEY_LEFT:
                current_button = (current_button - 1 + num_buttons) % num_buttons;
                break;
            case KEY_RIGHT:
                current_button = (current_button + 1) % num_buttons;
                break;
            case 10: //enter key
                process_input(buttons[current_button].label);
                break;
            case 'q':
            case 'Q':
                endwin();
                return 0;
        }

    }
    endwin();
    return 0;
}

