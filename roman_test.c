#include <stdlib.h>
#include <check.h>
#include "roman.h"

START_TEST(test_roman)
{
#line 4
	fail_unless(sum(3, 2) == 5, "sum function borked");
	fail_unless(sum(-3, 2) == -1, "sum function borked");
	fail_unless(sum(3, -2) == 1, "sum function borked");
	fail_unless(sum(-3, -2) == -5, "sum function borked");
}
END_TEST

Suite * roman_suite(void)
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Roman");

	/* Core Test Case */
	tc_core = tcase_create("Core");

	tcase_add_test(tc_core, test_roman);
	suite_add_tcase(s,tc_core);

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