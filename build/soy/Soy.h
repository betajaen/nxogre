#ifndef SOY_H
#define SOY_H

#include <string>
#include <iostream>
#include <sstream>
#include "NxOgre.h"

struct SoyResult
{
 bool        fail;
 int         test_nb;
 std::string test_description;
 std::string case_description;
 std::string fail_message;
};

struct SoyCase
{
 SoyResult R;
};

#define CASES_BEGIN     void Soy() {
#define CASE(TEST_NAME) {SoyResult r = TEST_NAME::Perform();if (r.fail){std::cout << "Test Failed!\n------------------------\n" << r.case_description << "\n---\n#" << r.test_nb << " (" << r.test_description << ")\n>>> " << r.fail_message <<"\n------------------------\n";return;}}
#define CASES_END        std::cout << "** OK\n";}

#define CASE_BEGIN(CASE_NAME) struct CASE_NAME : public SoyCase { static SoyResult Perform() { CASE_NAME c; return c.R; }
#define CASE_END };

#define CASE_DESCRIPTION(CASE_DESCRIPTION) R.test_nb = 0; R.case_description = CASE_DESCRIPTION; R.fail = false;
#define TEST_DESCRIPTION(TEST_DESCRIPTION) R.test_nb++;   R.test_description = TEST_DESCRIPTION;

#define TEST_FAIL_IF(COND, FAIL_MESSAGE) if (COND) {R.fail=true;R.fail_message=FAIL_MESSAGE;return;}

std::string uintToString(unsigned int i)
{
 std::stringstream s;
 s << i;
 return s.str();
}

#endif