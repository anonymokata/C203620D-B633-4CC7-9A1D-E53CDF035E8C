#include <check.h>
#line 1 "calculator-test.check"
#include "single_roman_char_conversion.h"
#include "roman_string_to_decimal_value.h"

START_TEST(single_roman_char_conversion)
{
/* checking the conditions for the single roman value*/
ck_assert_msg(roman_to_decimal_digit_value('I') == 1,"operation failed for I");
ck_assert_msg(roman_to_decimal_digit_value('V') == 5,"operation failed for V");
ck_assert_msg(roman_to_decimal_digit_value('X') == 10,"operation failed for X");
ck_assert_msg(roman_to_decimal_digit_value('L') == 50,"operation failed for L");
ck_assert_msg(roman_to_decimal_digit_value('C') == 100,"operation failed for C");
ck_assert_msg(roman_to_decimal_digit_value('D') == 500,"operation failed for D");
ck_assert_msg(roman_to_decimal_digit_value('M') == 1000,"operation failed for M");

}
END_TEST
START_TEST(invalid_roman_digit)
{
#line 27
ck_assert_msg(roman_to_decimal_digit_value('\0') == 0,"operation failed for end of line");
ck_assert_msg(roman_to_decimal_digit_value('K') == -1,"operation failed for passing wrong input");

}
END_TEST

START_TEST(roman_string_to_decimal)
{
#line 31
/*condition to check the string of roman numbers*/
ck_assert_msg(roman_string_to_decimal_value("MD") == 1500,"operation failed to convert roman to decimal of MD");
ck_assert_msg(roman_string_to_decimal_value("MM") == 2000,"operation failed to convert roman to decimal of MM");

}
END_TEST

START_TEST(invalid_roman_string)
{

ck_assert_msg(roman_string_to_decimal_value("DM") == 1500,"wrong format to pass the roman value DM");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, single_roman_char_conversion);
    tcase_add_test(tc1_1, invalid_roman_digit);
    tcase_add_test(tc1_1, roman_string_to_decimal);
    tcase_add_test(tc1_1, invalid_roman_string);
    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
