#include "osheader.h"

#include "utils.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

#define ASSERT(check, failprnt) if (check) cout << "PASS"; else cout << "FAIL: " << failprnt;

#define TEST_INIT() size_t failcount = 0;
#define TEST_FINALIZE() if (failcount == 0) cout << "ALL TESTS PASSED." << endl; else cout << failcount << " TESTS FAILED!" << endl;

#define TEST_SECTION_BEGIN(string) { cout << "SECTION " << string << ":" << endl; size_t sec_failcount = 0;
#define TEST_SECTION_END() if (sec_failcount == 0) cout << "ALL SECTION TESTS PASSED." << endl; else cout << sec_failcount << " SECTION TESTS FAILED!" << endl; failcount += sec_failcount;}

#define TEST_BEGIN(string) { cout << " * " << string << ": " << endl;
#define TEST_FINISH(check, failprnt) ASSERT(check, failprnt); cout << endl; }

int main(int argc, char* argv[])
{
	cout << "Testing libg2extutils..." << endl;

	TEST_INIT();

	TEST_SECTION_BEGIN("cstr( ... )");

	TEST_BEGIN("cstr(\"\")");
	char* res = cstr("");
	TEST_FINISH(strcmp(res, "") == 0, res);

	TEST_BEGIN("cstr(\"str1\")");
	char* res = cstr("str1");
	TEST_FINISH(strcmp(res, "str1") == 0, res);

	TEST_BEGIN("cstr(\"str1\", \"str2\")");
	char* res = cstr("str1", "str2");
	TEST_FINISH(strcmp(res, "str1str2") == 0, res);

	TEST_BEGIN("cstr(\"str1\", \"\", \"str2\")");
	char* res = cstr("str1", "", "str2");
	TEST_FINISH(strcmp(res, "str1") == 0, res);

	TEST_BEGIN("cstr(\"str1\", NULL, \"str2\")");
	char* res = cstr("str1", NULL, "str2");
	TEST_FINISH(strcmp(res, "str1") == 0, res);

	TEST_BEGIN("cstr(str1, \"str2\")");
	char str1[] = "str1";
	char* res = cstr(str1, "str2");
	TEST_FINISH(strcmp(res, "str1str2") == 0, res);

	TEST_BEGIN("cstr(str1, \"\", \"str2\")");
	char str1[] = "str1";
	char* res = cstr(str1, "", "str2");
	TEST_FINISH(strcmp(res, "str1") == 0, res);

	TEST_BEGIN("cstr(str1, NULL, \"str2\")");
	char str1[] = "str1";
	char* res = cstr(str1, NULL, "str2");
	TEST_FINISH(strcmp(res, "str1") == 0, res);

	TEST_BEGIN("cstr(\"str1\", str2)");
	char str2[] = "str2";
	char* res = cstr("str1", str2);
	TEST_FINISH(strcmp(res, "str1str2") == 0, res);
	
	TEST_BEGIN("cstr(\"str1\", \"\", str2)");
	char str2[] = "str2";
	char* res = cstr("str1", "", str2);
	TEST_FINISH(strcmp(res, "str1") == 0, res);

	TEST_BEGIN("cstr(\"str1\", NULL, str2)");
	char str2[] = "str2";
	char* res = cstr("str1", NULL, str2);
	TEST_FINISH(strcmp(res, "str1") == 0, res);

	TEST_BEGIN("cstr(str1, str2)");
	char str1[] = "str1";
	char str2[] = "str2";
	char* res = cstr(str1, str2);
	TEST_FINISH(strcmp(res, "str1str2") == 0, res);
	
	TEST_BEGIN("cstr(str1, \" \", str3)");
	char str1[] = "Hello";
	char str3[] = "World";
	char* res = cstr(str1, " ", str3);
	TEST_FINISH(strcmp(res, "Hello World") == 0, res);
	
	TEST_SECTION_END();

	TEST_SECTION_BEGIN("cwcs( ... )");

	TEST_BEGIN("cwcs(L\"\")");
	wchar_t* res = cwcs(L"");
	TEST_FINISH(wcscmp(res, L"") == 0, res);

	TEST_BEGIN("cwcs(L\"str1\")");
	wchar_t* res = cwcs(L"str1");
	TEST_FINISH(wcscmp(res, L"str1") == 0, res);

	TEST_BEGIN("cwcs(L\"str1\", L\"str2\")");
	wchar_t* res = cwcs(L"str1", L"str2");
	TEST_FINISH(wcscmp(res, L"str1str2") == 0, res);

	TEST_BEGIN("cwcs(L\"str1\", L\"\", L\"str2\")");
	wchar_t* res = cwcs(L"str1", L"", L"str2");
	TEST_FINISH(wcscmp(res, L"str1") == 0, res);

	TEST_BEGIN("cwcs(L\"str1\", NULL, L\"str2\")");
	wchar_t* res = cwcs(L"str1", NULL, L"str2");
	TEST_FINISH(wcscmp(res, L"str1") == 0, res);

	TEST_BEGIN("cwcs(str1, L\"str2\")");
	wchar_t str1[] = L"str1";
	wchar_t* res = cwcs(str1, L"str2");
	TEST_FINISH(wcscmp(res, L"str1str2") == 0, res);

	TEST_BEGIN("cwcs(str1, L\"\", L\"str2\")");
	wchar_t str1[] = L"str1";
	wchar_t* res = cwcs(str1, L"", L"str2");
	TEST_FINISH(wcscmp(res, L"str1") == 0, res);

	TEST_BEGIN("cwcs(str1, NULL, L\"str2\")");
	wchar_t str1[] = L"str1";
	wchar_t* res = cwcs(str1, NULL, L"str2");
	TEST_FINISH(wcscmp(res, L"str1") == 0, res);

	TEST_BEGIN("cwcs(L\"str1\", str2)");
	wchar_t str2[] = L"str2";
	wchar_t* res = cwcs(L"str1", str2);
	TEST_FINISH(wcscmp(res, L"str1str2") == 0, res);
	
	TEST_BEGIN("cwcs(L\"str1\", L\"\", str2)");
	wchar_t str2[] = L"str2";
	wchar_t* res = cwcs(L"str1", L"", str2);
	TEST_FINISH(wcscmp(res, L"str1") == 0, res);

	TEST_BEGIN("cwcs(L\"str1\", NULL, str2)");
	wchar_t str2[] = L"str2";
	wchar_t* res = cwcs(L"str1", NULL, str2);
	TEST_FINISH(wcscmp(res, L"str1") == 0, res);

	TEST_BEGIN("cwcs(str1, str2)");
	wchar_t str1[] = L"str1";
	wchar_t str2[] = L"str2";
	wchar_t* res = cwcs(str1, str2);
	TEST_FINISH(wcscmp(res, L"str1str2") == 0, res);
	
	TEST_BEGIN("cwcs(str1, L\" \", str3)");
	wchar_t str1[] = L"Hello";
	wchar_t str3[] = L"World";
	wchar_t* res = cwcs(str1, L" ", str3);
	TEST_FINISH(wcscmp(res, L"Hello World") == 0, res);
	
	TEST_SECTION_END();

	TEST_SECTION_BEGIN("substr(str, begin, len)");

	TEST_BEGIN("substr(\"\", 0, 0)");
	char* res = substr("", 0, 0);
	TEST_FINISH(strcmp(res, "") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 99, 0)");
	char* res = substr("Hello World", 99, 0);
	TEST_FINISH(strcmp(res, "") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 99, 99)");
	char* res = substr("Hello World", 99, 99);
	TEST_FINISH(strcmp(res, "") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 0, 99)");
	char* res = substr("Hello World", 0, 99);
	TEST_FINISH(strcmp(res, "") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 6, 99)");
	char* res = substr("Hello World", 6, 99);
	TEST_FINISH(strcmp(res, "") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 0, 11)");
	char* res = substr("Hello World", 0, 11);
	TEST_FINISH(strcmp(res, "Hello World") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 0, 0)");
	char* res = substr("Hello World", 0, 0);
	TEST_FINISH(strcmp(res, "Hello World") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 0, 5)");
	char* res = substr("Hello World", 0, 5);
	TEST_FINISH(strcmp(res, "Hello") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 6, 5)");
	char* res = substr("Hello World", 6, 5);
	TEST_FINISH(strcmp(res, "World") == 0, res);

	TEST_BEGIN("substr(\"Hello World\", 6, 0)");
	char* res = substr("Hello World", 6, 0);
	TEST_FINISH(strcmp(res, "World") == 0, res);

	TEST_SECTION_END();

	TEST_SECTION_BEGIN("subwcs(str, begin, len)");

	TEST_BEGIN("subwcs(L\"\", 0, 0)");
	wchar_t* res = subwcs(L"", 0, 0);
	TEST_FINISH(wcscmp(res, L"") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 99, 0)");
	wchar_t* res = subwcs(L"Hello World", 99, 0);
	TEST_FINISH(wcscmp(res, L"") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 99, 99)");
	wchar_t* res = subwcs(L"Hello World", 99, 99);
	TEST_FINISH(wcscmp(res, L"") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 0, 99)");
	wchar_t* res = subwcs(L"Hello World", 0, 99);
	TEST_FINISH(wcscmp(res, L"") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 6, 99)");
	wchar_t* res = subwcs(L"Hello World", 6, 99);
	TEST_FINISH(wcscmp(res, L"") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 0, 11)");
	wchar_t* res = subwcs(L"Hello World", 0, 11);
	TEST_FINISH(wcscmp(res, L"Hello World") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 0, 0)");
	wchar_t* res = subwcs(L"Hello World", 0, 0);
	TEST_FINISH(wcscmp(res, L"Hello World") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 0, 5)");
	wchar_t* res = subwcs(L"Hello World", 0, 5);
	TEST_FINISH(wcscmp(res, L"Hello") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 6, 5)");
	wchar_t* res = subwcs(L"Hello World", 6, 5);
	TEST_FINISH(wcscmp(res, L"World") == 0, res);

	TEST_BEGIN("subwcs(L\"Hello World\", 6, 0)");
	wchar_t* res = subwcs(L"Hello World", 6, 0);
	TEST_FINISH(wcscmp(res, L"World") == 0, res);

	TEST_SECTION_END();

	TEST_FINALIZE();
}