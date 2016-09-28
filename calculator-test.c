#include <check.h>
#line 1 "calculator-test.check"
#include "single_roman_char_conversion.h"

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


int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, single_roman_char_conversion);
    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
