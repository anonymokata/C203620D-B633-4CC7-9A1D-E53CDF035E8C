#include <check.h>
#line 1 "calculator-test.check"
#include "single_roman_char_conversion.h"
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
#define size 50
char buffer[size];

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

/*condition to check the string of roman numbers*/
ck_assert_msg(roman_string_to_decimal_value("MD") == 1500,"operation failed to convert roman to decimal of MD");

}
END_TEST

START_TEST(roman_string_to_decimal_1)
{

ck_assert_msg(roman_string_to_decimal_value("MM") == 2000,"operation failed to convert roman to decimal of MM");

}
END_TEST
START_TEST(invalid_roman_string)
{

ck_assert_msg(roman_string_to_decimal_value("DM") == 1500,"wrong format to pass the roman value DM");
}
END_TEST

START_TEST(II_equals_2)
{

ck_assert_msg(roman_string_to_decimal_value("II") == 2,"operation failed to convert roman to decimal of II");
}
END_TEST

START_TEST(IV_equals_4)
{

ck_assert_msg(roman_string_to_decimal_value("IV") == 4,"operation failed to convert roman to decimal of IV");
}
END_TEST

START_TEST(VI_equals_6)
{

ck_assert_msg(roman_string_to_decimal_value("VI") == 6,"operation failed to convert roman to decimal of VI");
}
END_TEST

START_TEST(XXXVII_equals_37)
{

ck_assert_msg(roman_string_to_decimal_value("XXXVII") == 37,"operation failed to convert roman to decimal of XXXVII");
}
END_TEST

START_TEST(invalid_roman_string_1)
{

ck_assert_msg(roman_string_to_decimal_value("XXC") == 80,"invalid roman string XXC");
}
END_TEST

START_TEST(MMCCCXLV_equals_2345)
{

ck_assert_msg(roman_string_to_decimal_value("MMCCCXLV") == 2345,"operation failed to convert roman to decimal of MMCCCXLV");
}
END_TEST

START_TEST(zero_equals_zero)
{

ck_assert_msg(roman_string_to_decimal_value("0") == 0,"Invalid Operation passed zero value");
}
END_TEST

START_TEST(XXXC_equals_70)
{

ck_assert_msg(roman_string_to_decimal_value("XXXC") == 70,"Not a valid roman number");
}
END_TEST

START_TEST(_1000_equals_M)
{

/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1000,buffer),"M") == 0,"Operation failed to convert decimal to roman value: 1000");
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
    tcase_add_test(tc1_1, roman_string_to_decimal_1);
    tcase_add_test(tc1_1, invalid_roman_string);
    tcase_add_test(tc1_1, II_equals_2);
    tcase_add_test(tc1_1, IV_equals_4);
    tcase_add_test(tc1_1, VI_equals_6);
    tcase_add_test(tc1_1, XXXVII_equals_37);
    tcase_add_test(tc1_1, invalid_roman_string_1);
    tcase_add_test(tc1_1, MMCCCXLV_equals_2345);
    tcase_add_test(tc1_1, zero_equals_zero);
    tcase_add_test(tc1_1, XXXC_equals_70);
    tcase_add_test(tc1_1, _1000_equals_M);
    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
