/*
Exercise 4-4. Add the commands to print the top elements of the stack without popping, to duplicate it
and to swap the top two elements. Add a command to clear the stack.
*/


#include <stdio.h>
#include <stdlib.h>     /* for atof() */
#include <ctype.h>      

#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */
#define BUFSIZE 100
#define MAXVAL  100     /* maximum depth of val stack */

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* stack stuff */
int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* buffer for ungetch */
char buf[BUFSIZE];
int bufp = 0;

/* added commands from 4-4 */
void print_top(void);
void duplicate(void);
void swap_top_two(void);
void clear_stack(void);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    printf("RPN Calculator (4-3 + 4-4) ready. Commands: ?(top) d(up) s(wap) c(lear)\n");
    printf("Enter expressions (q to quit)\n\n");
    //Tbh I used so many switch cases and don't know if this is necessay or best practice 

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':                   /* bonus modulus if you want */
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;

            /* Exercise 4-4 commands */
            case '?':
                print_top();
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap_top_two();
                break;
            case 'c':
                clear_stack();
                break;

            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;       /* not a number */

    i = 0;
    if (c == '-') {     /* could be negative number or minus op */
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;     /* it's a negative number */
        } else {
            ungetch(c);
            return '-';     /* it's the minus operator */
        }
    }

    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* getch and ungetch from 4-3 */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* ────────────────────────────────────── */
/* Exercise 4-4 implementations           */
/* ────────────────────────────────────── */

void print_top(void)
{
    if (sp > 0)
        printf("top (without pop): %.8g\n", val[sp-1]);
    else
        printf("stack empty - nothing to show\n");
}

void duplicate(void)
{
    if (sp == 0) {
        printf("error: stack empty - can't duplicate\n");
        return;
    }
    if (sp >= MAXVAL) {
        printf("error: stack full - can't duplicate\n");
        return;
    }
    push(val[sp-1]);
}

void swap_top_two(void)
{
    if (sp < 2) {
        printf("error: need at least 2 elements to swap\n");
        return;
    }
    double temp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = temp;
}

void clear_stack(void)
{
    sp = 0;
    printf("stack cleared\n");
}