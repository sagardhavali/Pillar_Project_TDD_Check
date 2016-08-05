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

Suite * roman_suite(void)
{
	Suite *s;
	TCase *tc_romanToInteger;
	TCase *tc_integerToRoman;
	TCase *tc_roman_addition;

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

	return s;
}

int main(void)
{
    int number_failed;
	Suite *s;
	SRunner *sr;

	s = roman_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
