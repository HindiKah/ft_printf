#ifndef MACRO_H
# define MACRO_H

# define MAX(x, y)   ((x) >= (y) ? (x) : (y))
# define MIN(x, y)   ((x) <= (y) ? (x) : (y))
# define ABS(x)   ((x) < 0 ? (-(x)) : (x))
# define NINT(x)   ((x) < 0 ? ((long)(x-0.5)) : ((long)(x+0.5)))
# define SQ(x)   ((x) * (x))
# define is_num(c)   (('0' <= c && c <= '9') ? 1 : 0)
# define is_alphanum(c)   (('0' >= c || c >= '9') ? 1 : 0)
# define is_true(val)   (ft_strcmp(val,"true") == 0 ? 1 : 0)
# define is_false(val)   (ft_strcmp(val,"false") == 0 ? 1 : 0)
# define is_set(val)   (ft_strcmp(val,"NULL") != 0 ? 1 : 0)
# define is_unset(val)   (ft_strcmp(val,"NULL") == 0 ? 1 : 0)
# define MALLOC_ERROR exit(ft_printf("Allocation error"))
# define TRUE 1
# define FALSE 0

#endif
