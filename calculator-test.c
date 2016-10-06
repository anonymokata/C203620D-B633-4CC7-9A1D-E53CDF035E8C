#include <check.h>
#line 1 "calculator-test.check"
#include "limit.h"
#include "roman_string_to_decimal_value.h"
#include "decimal_value_to_roman_string.h"
# include "calculator.h"
#include "validation.h"
#include "error.h"
#define INVALID 0
#define VALID 1
#define INVALID_NEGATIVE -1

#define size 50
char* first_string;
char* second_string;
char final_result[size];


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
ck_assert_msg(roman_to_decimal_digit_value('K') == INVALID_NEGATIVE,"operation failed for passing wrong input");

}
END_TEST

START_TEST(roman_string_to_decimal)
{

/*condition to check the string of roman numbers*/
ck_assert_msg(roman_string_to_decimal_value("MD") == 1500,"operation failed to convert roman to decimal of MD ");

}
END_TEST

START_TEST(roman_string_to_decimal_1)
{

ck_assert_msg(roman_string_to_decimal_value("MM") == 2000,"operation failed to convert roman to decimal of MM");

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

START_TEST(MMCCCXLV_equals_2345)
{

ck_assert_msg(roman_string_to_decimal_value("MMCCCXLV") == 2345,"operation failed to convert roman to decimal of MMCCCXLV");
}
END_TEST

START_TEST(LV_equals_55)
{

ck_assert_msg(roman_string_to_decimal_value("LV") == 55,"valid roman number LV = 55");
}
END_TEST

START_TEST(_1000_equals_M)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1000,final_result),"M") == 0,"Operation failed to convert decimal to roman value: 1000");
}
END_TEST

START_TEST(_500_equals_D)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(500,final_result),"D") == 0,"Operation failed to convert decimal to roman value: 500");
}
END_TEST

START_TEST(_1500_equals_MD)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1500,final_result),"MD") == 0,"Operation failed to convert decimal to roman value: 1500");
}
END_TEST

START_TEST(_1900_equals_MCM)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1900,final_result),"MCM") == 0,"Operation failed to convert decimal to roman value: 1900");
}
END_TEST

START_TEST(_150_equals_CL)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(150,final_result),"CL") == 0,"Operation failed to convert decimal to roman value: 150");
}
END_TEST

START_TEST(_15_equals_XV)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(15,final_result),"XV") == 0,"Operation failed to convert decimal to roman value: 15");
}
END_TEST

START_TEST(_4_equals_IV)
{
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(4,final_result),"IV") == 0,"Operation failed to convert decimal to roman value: 4");
}
END_TEST

START_TEST(_2_equals_II)
{
/*condition to convert back from decimal to roman number*/

ck_assert_msg(strcmp(decimal_number_to_roman_string(2,final_result),"II") == 0,"Operation failed to convert decimal to roman value: 2");

}
END_TEST

START_TEST(roman_addition_M_D_equals_MD)
{
first_string = "M";
second_string = "D";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"MD") == 0,"valid addition :M D");

}
END_TEST

START_TEST(roman_addition_i_X_equals_XI)
{
first_string = "i";
second_string = "X";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"XI") == 0,"valid addition : i X");

}
END_TEST

START_TEST(Invalid_roman_character_A_equals_NULL)
{

ck_assert_msg(is_roman_number_valid("A") == INVALID,"A is not a valid roman character");

}
END_TEST

START_TEST(valid_roman_character_M_equals_1000)
{

ck_assert_msg(is_roman_number_valid("M") == VALID,"M is a valid roman character");

}
END_TEST

START_TEST(roman_addition_I_I_equals_II)
{
first_string = "I";
second_string = "I";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"II") == 0,"valid addition: I I");

}
END_TEST

START_TEST(roman_addition_BAD_XXLL_equals_NULL)
{
first_string = "BAD";
second_string = "XXLL";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"INVALID_STRING") == 0,"invalid addition : BAD XXLL ADD");

}
END_TEST

START_TEST(roman_addition_XX_BAD_equals_NULL)
{
first_string = "XX";
second_string = "BAD";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"INVALID_STRING") == 0,"invalid addition: XX BAD ADD ");

}
END_TEST

START_TEST(roman_addition_BAD_BAD_equals_NULL)
{
first_string = "BAD";
second_string = "BAD";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"INVALID_STRING") == 0,"invalid addition : BAD BAD ADD ");

}
END_TEST

START_TEST(roman_addition_MM_MM_equals_MMMM)
{
first_string = "MM";
second_string = "MM";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"LIMIT_OVERFLOW") == 0,"Limit exceeds(3999): 4000 ");

}
END_TEST

START_TEST(roman_addition_MMCCC_MMCCC_equals_MMMMDC)
{
first_string = "MMCCC";
second_string = "MMMMDC";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"LIMIT_OVERFLOW") == 0,"Limit exceeds(3999): 4600 ");

}
END_TEST

START_TEST(roman_addition_0_0_equals_0)
{
first_string = "0";
second_string = "0";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"INVALID_STRING") == 0,"Invalid addition: 0 0 ");

}
END_TEST

START_TEST(roman_addition_III_III_equals_VI)
{
first_string = "III";
second_string = "III";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"VI") == 0,"operation failed to return : VI");

}
END_TEST

START_TEST(roman_subtraction_III_I_equals_II)
{
first_string = "III";
second_string = "i";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"II") == 0,"valid subtraction: III i ");

}
END_TEST

START_TEST(roman_subtraction_II_II_equals_INVALID)
{
first_string = "II";
second_string = "II";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"NULL_VALUE") == 0,"invalid subtraction, returns 0:II II  ");

}
END_TEST

START_TEST(roman_subtraction_IiI_II_equals_I)
{
first_string = "IiI";
second_string = "II";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"I") == 0,"valid subtraction: IiI I ");

}
END_TEST

START_TEST(roman_limit_sum_3_equals_VALID)
{

ck_assert_msg(check_limit_of_added_numbers(3) == VALID,"input number is with in the limit : 3");

}
END_TEST

START_TEST(roman_limit_sum_4500_equals_INVALID)
{

ck_assert_msg(check_limit_of_added_numbers(4500) == INVALID,"input number is out of limit : 4500");

}
END_TEST

START_TEST(roman_limit_subtract_3700_equals_VALID)
{

ck_assert_msg(check_limit_of_subtracted_numbers(3700) == VALID,"input number is in limit : 3700");

}
END_TEST

START_TEST(roman_limit_subtract_4900_equals_INVALID)
{

ck_assert_msg(check_limit_of_subtracted_numbers(4900) == INVALID,"input number is out of limit : 4900");

}
END_TEST

START_TEST(roman_subtraction_0_0_equals_INVALID)
{
first_string = "0";
second_string = "0";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"INVALID_STRING") == 0,"invalid subtraction: 0 0");

}
END_TEST

START_TEST(roman_subtraction_0_XX_equals_INVALID)
{
first_string = "0";
second_string = "XX";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"INVALID_STRING") == 0,"invalid subtraction: 0 XX");

}
END_TEST

START_TEST(roman_subtraction_I_0_equals_INVALID)
{
first_string = "I";
second_string = "0";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"INVALID_STRING") == 0,"invalid subtraction: I 0");

}
END_TEST

START_TEST(roman_subtraction_IzzX_IisD_equals_INVALID)
{
first_string = "IzzX";
second_string = "IisD";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"INVALID_STRING") == 0,"invalid subtraction: IzzX IisD ");

}
END_TEST

START_TEST(roman_addition_IzzX_IisD_equals_INVALID)
{
first_string = "IzzX";
second_string = "IisD";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"INVALID_STRING") == 0,"invalid addition: IzzX IisD ");

}
END_TEST
/*final checks of addtion and subtraction operation*/

START_TEST(roman_addition_V_V_equals_X)
{
first_string = "V";
second_string = "V";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"X") == 0,"passed valid strings : V V = X ");

}
END_TEST

START_TEST(roman_addition_Vzx_V_equals_Invalid)
{
first_string = "Vzx";
second_string = "V";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"INVALID_STRING") == 0,"invalid valid strings : Vzx V");

}
END_TEST

START_TEST(roman_addition_V0x_0_equals_Invalid)
{
first_string = "V0x";
second_string = "0";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"INVALID_STRING") == 0,"Invalid valid strings : V0x 0");

}
END_TEST

START_TEST(roman_addition_iiI_v_equals_VIII)
{
first_string = "iiI";
second_string = "v";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,ADD,final_result),"VIII") == 0,"valid strings : iiI v = VIII");

}
END_TEST

START_TEST(roman_subtraction_abcd_abcd_equals_INVALID)
{
first_string = "abcd";
second_string = "abcd";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"INVALID_STRING") == 0,"invalid subtraction: abcd abcd ");

}
END_TEST

START_TEST(roman_subtraction_iii_i_equals_II)
{
first_string = "iii";
second_string = "i";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"II") == 0,"valid subtraction:iii i");

}
END_TEST

START_TEST(roman_subtraction_v_v_equals_invalid)
{
first_string = "v";
second_string = "v";
ck_assert_msg(strcmp(calculate_roman_numbers(first_string,second_string,SUBTRACT,final_result),"NULL_VALUE") == 0,"valid subtraction, returns 0:v v");

}
END_TEST

START_TEST(roman_subtraction_0_equals_null)
{

ck_assert_msg(is_subtracted_number_null(0) == INVALID,"passed zero for subtraction as input");

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, roman_limit_sum_3_equals_VALID);
    tcase_add_test(tc1_1, roman_limit_sum_4500_equals_INVALID);
    tcase_add_test(tc1_1, roman_limit_subtract_3700_equals_VALID);
    tcase_add_test(tc1_1, roman_limit_subtract_4900_equals_INVALID);
    tcase_add_test(tc1_1, roman_addition_BAD_BAD_equals_NULL);
    tcase_add_test(tc1_1, roman_addition_MM_MM_equals_MMMM);
    tcase_add_test(tc1_1, roman_addition_MMCCC_MMCCC_equals_MMMMDC);
    tcase_add_test(tc1_1, roman_addition_0_0_equals_0);
    tcase_add_test(tc1_1, roman_addition_III_III_equals_VI);
    tcase_add_test(tc1_1, roman_subtraction_III_I_equals_II);
    tcase_add_test(tc1_1, roman_subtraction_II_II_equals_INVALID);
    tcase_add_test(tc1_1, roman_subtraction_IiI_II_equals_I);
    tcase_add_test(tc1_1, valid_roman_character_M_equals_1000);
    tcase_add_test(tc1_1, Invalid_roman_character_A_equals_NULL);
    tcase_add_test(tc1_1, single_roman_char_conversion);
    tcase_add_test(tc1_1, invalid_roman_digit);
    tcase_add_test(tc1_1, roman_string_to_decimal);
    tcase_add_test(tc1_1, roman_string_to_decimal_1);
    tcase_add_test(tc1_1, II_equals_2);
    tcase_add_test(tc1_1, IV_equals_4);
    tcase_add_test(tc1_1, VI_equals_6);
    tcase_add_test(tc1_1, XXXVII_equals_37);
    tcase_add_test(tc1_1, MMCCCXLV_equals_2345);
    tcase_add_test(tc1_1, LV_equals_55);
    tcase_add_test(tc1_1, _1000_equals_M);
    tcase_add_test(tc1_1, _500_equals_D);
    tcase_add_test(tc1_1, _1500_equals_MD);
    tcase_add_test(tc1_1, _1900_equals_MCM);
    tcase_add_test(tc1_1, _150_equals_CL);
    tcase_add_test(tc1_1, _15_equals_XV);
    tcase_add_test(tc1_1, _4_equals_IV);
    tcase_add_test(tc1_1, _2_equals_II);
    tcase_add_test(tc1_1, roman_addition_M_D_equals_MD);
    tcase_add_test(tc1_1, roman_addition_i_X_equals_XI);
    tcase_add_test(tc1_1, roman_addition_I_I_equals_II);
    tcase_add_test(tc1_1, roman_addition_BAD_XXLL_equals_NULL);
    tcase_add_test(tc1_1, roman_addition_XX_BAD_equals_NULL);
    tcase_add_test(tc1_1, roman_subtraction_0_0_equals_INVALID);
    tcase_add_test(tc1_1, roman_subtraction_0_XX_equals_INVALID);
    tcase_add_test(tc1_1, roman_subtraction_I_0_equals_INVALID);
    tcase_add_test(tc1_1, roman_subtraction_IzzX_IisD_equals_INVALID);
    tcase_add_test(tc1_1, roman_addition_IzzX_IisD_equals_INVALID);
    tcase_add_test(tc1_1, roman_addition_V_V_equals_X);
    tcase_add_test(tc1_1, roman_addition_Vzx_V_equals_Invalid);
    tcase_add_test(tc1_1, roman_addition_V0x_0_equals_Invalid);
    tcase_add_test(tc1_1, roman_addition_iiI_v_equals_VIII);
    tcase_add_test(tc1_1, roman_subtraction_abcd_abcd_equals_INVALID);
    tcase_add_test(tc1_1, roman_subtraction_iii_i_equals_II);
    tcase_add_test(tc1_1, roman_subtraction_v_v_equals_invalid);
    tcase_add_test(tc1_1, roman_subtraction_0_equals_null);


    
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
