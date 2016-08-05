#include <stdlib.h>
#include <check.h>
#include "roman.h"

START_TEST(test_roman2integer)
{
	ck_assert_int_eq(roman2integer("III"),3);
	ck_assert_int_eq(roman2integer("X"),10);
	ck_assert_int_eq(roman2integer("XII"),12);
	ck_assert_int_eq(roman2integer("XL"),40);
}
END_TEST

START_TEST(test_integer2roman)
{
	ck_assert_str_eq(integer2roman(55),"LV");
	ck_assert_str_eq(integer2roman(115),"CXV");
	ck_assert_str_eq(integer2roman(99),"XCIX");
	ck_assert_str_eq(integer2roman(48),"XLVIII");
}
END_TEST

START_TEST(test_roman_addition)
{
	ck_assert_str_eq(romanAddition("II","II"),"IV");
	ck_assert_str_eq(romanAddition("XX","XX"),"XL");
	ck_assert_str_eq(romanAddition("V","V"),"X");
	ck_assert_str_eq(romanAddition("XV","XV"),"XXX");	
}
END_TEST

START_TEST(test_roman_subtraction)
{	
	ck_assert_str_eq(romanSubtraction("XX","X"),"X");
	ck_assert_str_eq(romanSubtraction("XX","II"),"XVIII");
	ck_assert_str_eq(romanSubtraction("C","I"),"XCIX");	
	ck_assert_str_eq(romanSubtraction("II","II"),"NULL");
}
END_TEST

START_TEST(test_roman_validate)
{
	ck_assert_int_eq(isvalidroman("I"),1);
	ck_assert_int_eq(isvalidroman("II"),1);
	ck_assert_int_eq(isvalidroman("III"),1);
	ck_assert_int_eq(isvalidroman("IV"),1);
	ck_assert_int_eq(isvalidroman("V"),1);
	ck_assert_int_eq(isvalidroman("VI"),1);
	ck_assert_int_eq(isvalidroman("VII"),1);
	ck_assert_int_eq(isvalidroman("VIII"),1);
	ck_assert_int_eq(isvalidroman("IX"),1);
	ck_assert_int_eq(isvalidroman("X"),1);
	ck_assert_int_eq(isvalidroman("XI"),1);
	ck_assert_int_eq(isvalidroman("XII"),1);
	ck_assert_int_eq(isvalidroman("XIII"),1);
	ck_assert_int_eq(isvalidroman("XIV"),1);
	ck_assert_int_eq(isvalidroman("XV"),1);
	ck_assert_int_eq(isvalidroman("XVI"),1);
	ck_assert_int_eq(isvalidroman("XVII"),1);
	ck_assert_int_eq(isvalidroman("XVIII"),1);
	ck_assert_int_eq(isvalidroman("XIX"),1);	
	ck_assert_int_eq(isvalidroman("XX"),1);
	ck_assert_int_eq(isvalidroman("XXI"),1);
	ck_assert_int_eq(isvalidroman("XXII"),1);
	ck_assert_int_eq(isvalidroman("XXIII"),1);
	ck_assert_int_eq(isvalidroman("XXIV"),1);
	ck_assert_int_eq(isvalidroman("XXV"),1);
	ck_assert_int_eq(isvalidroman("XXVI"),1);
	ck_assert_int_eq(isvalidroman("XXVII"),1);
	ck_assert_int_eq(isvalidroman("XXVIII"),1);
	ck_assert_int_eq(isvalidroman("XXIX"),1);
	ck_assert_int_eq(isvalidroman("XXX"),1);
	ck_assert_int_eq(isvalidroman("XXXI"),1);
	ck_assert_int_eq(isvalidroman("XXXII"),1);
	ck_assert_int_eq(isvalidroman("XXXIII"),1);
	ck_assert_int_eq(isvalidroman("XXXIV"),1);
	ck_assert_int_eq(isvalidroman("XXXV"),1);
	ck_assert_int_eq(isvalidroman("XXXVI"),1);
	ck_assert_int_eq(isvalidroman("XXXVII"),1);
	ck_assert_int_eq(isvalidroman("XXXVIII"),1);
	ck_assert_int_eq(isvalidroman("XXXIX"),1);
	ck_assert_int_eq(isvalidroman("XL"),1);
	ck_assert_int_eq(isvalidroman("XLI"),1);
	ck_assert_int_eq(isvalidroman("XLII"),1);
	ck_assert_int_eq(isvalidroman("XLIII"),1);
	ck_assert_int_eq(isvalidroman("XLIV"),1);
	ck_assert_int_eq(isvalidroman("XLV"),1);
	ck_assert_int_eq(isvalidroman("XLVI"),1);
	ck_assert_int_eq(isvalidroman("XLVII"),1);
	ck_assert_int_eq(isvalidroman("XLVIII"),1);
	ck_assert_int_eq(isvalidroman("XLIX"),1);
	ck_assert_int_eq(isvalidroman("L"),1);
	ck_assert_int_eq(isvalidroman("XC"),1);
	ck_assert_int_eq(isvalidroman("XCI"),1);
	ck_assert_int_eq(isvalidroman("XCII"),1);
	ck_assert_int_eq(isvalidroman("XCIII"),1);
	ck_assert_int_eq(isvalidroman("XCIV"),1);
	ck_assert_int_eq(isvalidroman("XCV"),1);
	ck_assert_int_eq(isvalidroman("XCVI"),1);
	ck_assert_int_eq(isvalidroman("XCVII"),1);
	ck_assert_int_eq(isvalidroman("XCVIII"),1);
	ck_assert_int_eq(isvalidroman("XCIX"),1);
	ck_assert_int_eq(isvalidroman("C"),1);
	ck_assert_int_eq(isvalidroman("CC"),1);
	ck_assert_int_eq(isvalidroman("CCC"),1);
	ck_assert_int_eq(isvalidroman("CD"),1);
	ck_assert_int_eq(isvalidroman("D"),1);
	ck_assert_int_eq(isvalidroman("DC"),1);
	ck_assert_int_eq(isvalidroman("DCC"),1);
	ck_assert_int_eq(isvalidroman("DCCC"),1);
	ck_assert_int_eq(isvalidroman("CM"),1);
	ck_assert_int_eq(isvalidroman("M"),1);
}
END_TEST 

Suite * roman_suite(void)
{
	Suite *s;
	TCase *tc_romanToInteger;
	TCase *tc_integerToRoman;
	TCase *tc_roman_addition;
	TCase *tc_roman_subtraction;
	TCase *tc_roman_validate;

	s = suite_create("Roman");

	/* Test Case : Roman to Integer */
	tc_romanToInteger = tcase_create("Roman2Integer");

	tcase_add_test(tc_romanToInteger, test_roman2integer);
	suite_add_tcase(s,tc_romanToInteger);

	/* Test Case : Integer to Roman */
	tc_integerToRoman = tcase_create("Integer2Roman");

	tcase_add_test(tc_integerToRoman, test_integer2roman);
	suite_add_tcase(s, tc_integerToRoman);

	/* Test Case : Roman Addition */
	tc_roman_addition = tcase_create("Roman_Addition");

	tcase_add_test(tc_roman_addition, test_roman_addition);
	suite_add_tcase(s, tc_roman_addition);

	/* Test Case : Roman Subtraction */
	tc_roman_subtraction = tcase_create("Roman_Subtraction");

	tcase_add_test(tc_roman_subtraction, test_roman_subtraction);
	suite_add_tcase(s, tc_roman_subtraction);

	/* Test Case : Roman number validation */
	tc_roman_validate = tcase_create("Roman_Validate");

	tcase_add_test(tc_roman_validate, test_roman_validate);
	suite_add_tcase(s, tc_roman_validate);

	return s;
}

int main(void)
{
    int number_failed;
	Suite *s;
	SRunner *sr;

	s = roman_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
