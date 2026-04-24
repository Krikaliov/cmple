#ifndef DATE_H
#define DATE_H

#ifdef __cplusplus
extern "C" {
#endif

#define DATE_MAXLENGTH 32

/**
 * Date string format function.
 * @param str_dest string pointer of the destination buffer
 * @param years [YYYY]
 * @param months [MM]
 * @param days [DD]
 * @param hours [hh]
 * @param minutes [mm]
 * @param seconds [ss]
 * @param ms milliseconds [mss]
 * @return String date: "[YYYY]-[MM]-[DD]T[hh]:[mm]:[ss].[mss]Z"
 */
int format_date(char* str_dest, int years, int months, int days, int hours, int minutes, int seconds, int ms);

#define STRINGFY_DATE(var, years, months, days, hours, minutes, seconds, ms) \
char var [DATE_MAXLENGTH] = "0"; \
format_date(var, years, months, days, hours, minutes, seconds, ms)

#ifdef __cplusplus
}
#endif

#endif // DATE_H