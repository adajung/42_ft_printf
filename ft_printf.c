/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:55:56 by hwalee            #+#    #+#             */
/*   Updated: 2026/01/23 14:55:58 by hwalee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    init_format(format *);
int is_str_valid(const char *);
const char    *fill_format(const char *, format *, const char *);
const char    *print_format(const char *, format *, va_list, int *);
int    print_str(const char *, const char *, va_list);
int ft_printf(const char *, ...);

void    init_format(format *tempFormat)
{
    tempFormat->hash = 0;
    tempFormat->space = 0;
    tempFormat->plus = 0;
    tempFormat->minus = 0;
    tempFormat->zero = 0;
    tempFormat->width = 0;
    tempFormat->precision = -1;
    tempFormat->type = 0;
}

int is_str_valid(const char *str)
{
    format  checkFormat;
    const char    *temp;

    if (str == NULL)
        return (0);
    while (*str)
    {
        init_format(&checkFormat);
        while ((*str) && (*str != '%'))
            str++;
        if (!*str)
            return (1);
        else if (*str == '%')
        {
            temp = fill_format(str++, &checkFormat, "cspdiuxX");
            if (temp == NULL)
                return (0);
            str = temp;
        }
    }
    return (1);
}

const char    *fill_format(const char *head, format *tf, const char *typeSet)
{
    if (*(head++ + 1) == '%')
        return (head + 1);
    while (*head == '#' || *head == ' ' || *head == '+' || 
        *head == '-' || *head == '0')
    {
        if (*head == '#')
            tf->hash = 1;
        if (*head == ' ')
            tf->space = 1;
        if (*head == '+')
            tf->plus = 1;
        if (*head == '-')
            tf->minus = 1;
        if (*(head++) == '0')
            tf->zero = 1;
    }
    if (tf->minus == 1)
        tf->zero = 0;
    if (ft_strchr(typeSet, *head))
        return (tf->type = *head, ++head);
    return (0);
}

const char    *print_format(const char *head, format *tf, va_list ap, int *l)
{
    head = fill_format(head, tf, "cspdiuxX");
    if (*(head - 1) == '%')
    {   
        write(1, head - 1, 1);
        return (*l += 1, head);
    }
    if (tf->type == 'c')
        return (*l += print_type_c(tf, ap), head);
    else if (tf->type == 's')
        return (*l += print_type_s(tf, ap), head);
    else if (tf->type == 'p')
        return (*l += print_type_p(tf, ap), head);
    else if (tf->type == 'd')
        return (*l += print_type_d(tf, ap), head);
    else if (tf->type == 'i')
        return (*l += print_type_i(tf, ap), head);
    else if (tf->type == 'u')
        return (*l += print_type_u(tf, ap), head);
    else if (tf->type == 'x')
        return (*l += print_type_x(tf, ap), head);
    else if (tf->type == 'X')
        return (*l += print_type_X(tf, ap), head);
    return (0);
}

int    print_str(const char *str, const char *head, va_list ap)
{
    format tempFormat;
    int     l;
    
    l = 0;
    while (*head)
    {
        init_format(&tempFormat);
        if (*head == '%')
        {
            head = print_format(head, &tempFormat, ap, &l);
            str = head;
        }
        else
        {
            while ((*head != '%') && (*head != '\0'))
                head++;
            if (head != str)
            {
                write(1, str, head - str);
                l += head - str;
                str = head;
            }
        }
    }
    return (l);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    char    *head;
    int     temp;
    
    temp = is_str_valid(str);
    if (temp == 0)
        return (0);

    va_start(ap, str);

    head = (char *)str;
    temp = print_str(str, head, ap);

    va_end(ap);

    return (temp);
}
