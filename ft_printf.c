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

int     power_to_dec(int);
void    init_format(format *);
int is_str_valid(const char *);
const char    *fill_format(const char *, format *, const char *);
const char    *print_format(const char *, format *, va_list);
void    print_str(const char *, const char *, va_list);
int ft_printf(const char *, ...);

int     power_to_dec(int power)
{
    int temp;

    if (power == 0)
        return (1);
    temp = 1;
    while (power)
    {
        temp *= 10;
        power--;
    }
    return (temp);
}

void    init_format(format *tempFormat)
{
    tempFormat->hash = 0;
    tempFormat->space = 0;
    tempFormat->plus = 0;
    tempFormat->minus = 0;
    tempFormat->zero = 0;
    tempFormat->dot = 0;
    tempFormat->width = 0;
    tempFormat->precision = 0;
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
        if (*str == '%')
        {
            temp = fill_format(str, &checkFormat, "cspdiuxX");
            if (temp == NULL)
                return (0);
        }
        else if (*str)
            str++;
    }
    return (1);
}

const char    *fill_format(const char *head, format *tempFormat, const char *typeSet)
{
    int i;

    if (*(head + 1) == '%')
        head += 2;
    while ((*head != '\0') || (*head != '%'))
    {
        if (*head == '#')
            tempFormat->hash = 1;
        else if (*head == ' ')
            tempFormat->space = 1;
        else if (*head == '+')
            tempFormat->plus = 1;
        else if (*head == '-')
            tempFormat->minus = 1;
        else if (*head == '0')
        {
            if (*(head + 1) != '.')
                tempFormat->zero = 1;
        }
        else if (*head == '.')
        {
            if (tempFormat->dot == 1)
                return (0);
            tempFormat->dot = 1;
            i = 0;
            while (ft_isdigit(*(head - ++i)))
                tempFormat->width += (*(head - i) - '0') * power_to_dec(i - 1);
            i = 0;
            while (ft_isdigit(*(head + ++i)))
                tempFormat->precision = 10 * tempFormat->precision + (*(head - i) - '0');
            head += i;
        }
        else if (*ft_strchr(typeSet, *head))
            return (tempFormat->type = *head, ++head);
        else
            return (0);
        head++;
    }
    return (head);
}

const char    *print_format(const char *head, format *tempFormat, va_list ap)
{
    head = fill_format(head, tempFormat, "cspdiuxX");
    if (*(head - 1) == '%')
        return (write(1, head - 1, 1), head);
    else
    {
        if (tempFormat->type == 'c')
            return (print_type_c(tempFormat, ap), head);
        else if (tempFormat->type == 's')
            return (print_type_s(tempFormat, ap), head);
        else if (tempFormat->type == 'p')
            return (print_type_p(tempFormat, ap), head);
        else if (tempFormat->type == 'd')
            return (print_type_d(tempFormat, ap), head);
        else if (tempFormat->type == 'i')
            return (print_type_i(tempFormat, ap), head);
        else if (tempFormat->type == 'u')
            return (print_type_u(tempFormat, ap), head);
        else if (tempFormat->type == 'x')
            return (print_type_x(tempFormat, ap), head);
        else if (tempFormat->type == 'X')
            return (print_type_X(tempFormat, ap), head);
    }
    return (0);
}

void    print_str(const char *str, const char *head, va_list ap)
{
    format tempFormat;
    
    while (*head)
    {
        init_format(&tempFormat);
        if (*head == '%')
            head = print_format(head, &tempFormat, ap);
        else
        {
            while ((*head != '%') || (*head != '\0'))
                head++;
            if (head != str)
            {
                write(1, str, head - str);
                str = head;
            }
        }
    }
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    char    *head;
    int     check;
    
    // 1. 포맷검사
    check = is_str_valid(str);
    if (check == 0)
        return (0);

    // 2. va_start
    va_start(ap, str);

    // 3. %갯수만큼 반복하여 va_arg 호출
    head = (char *)str;
    print_str(str, head, ap);

    va_end(ap);

    return (0);
}