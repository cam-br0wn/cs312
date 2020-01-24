// hw222_test_CMidiPacket.cpp
#ifndef HW312_TEST_CMIDIPACKET_H_
#include "hw312_test_CMidiPacket.h"
#endif

#ifndef HW312_CMIDIPACKET_H_
#include "hw312_CMidiPacket.h"
#endif

#include <iostream>
#include <sstream>
#include <string>

using namespace CMP31;

void print_main_message(const std::string &msg, CMidiPacket mp)
{
  std::cout << "\n===> " << msg << std::endl;
  mp.print();
}

void print_sub_message(const std::string &msg, CMidiPacket mp)
{
  std::cout << "----\n"
            << msg << std::endl;
  mp.print();
}

void test_default_constructor()
{
  CMidiPacket mp;
  print_main_message("test_default_constructor()\n(0, 80, 0, 0)", mp);
}

void test_constructor_one_data_byte()
{
  CMidiPacket mp{100, 0xc0, 11};
  print_main_message("test_constructor_one_data_byte\n(100, 0xc0, 11)", mp);

  CMidiPacket mp1{100, 0xF2, 11};
  print_sub_message("(100, 0xF2, 11)", mp1);
}

void test_constructor_two_data_bytes()
{
  CMidiPacket mp{1001, 0x91, 61, 101};
  print_main_message("test_constructor_ts_two_data_bytes\n(1001, 0x91, 61, 101)", mp);

  CMidiPacket mp1{100, 0xB4, 11, 0};
  print_sub_message("(100, 0xB4, 11, 0)", mp1);
}

void test_constructor_string()
{
  CMidiPacket mp("100\tc0\t11");
  print_main_message("test_constructor_string\n(100\tc0\t11)", mp);

  CMidiPacket mp1("1001\t91\t61\t101");
  print_sub_message("(1001\t91\t61\t101)", mp1);

  CMidiPacket mp2("1002 B2 7 102");
  print_sub_message("NO TABS: (1002 B2 7 102)", mp2);
}

void test_to_string()
{
  CMidiPacket mp(100, 0xC0, 11);
  print_main_message("test_to_string\n(100, 0xC0, 11)", mp);

  CMidiPacket mp1(1001, 0x91, 60, 101);
  print_sub_message("(1001, 91, 60, 101)", mp1);

  CMidiPacket mp2(2002, 0xB2, 7, 102);
  print_sub_message("(2002, 0xB2, 7, 102)", mp2);
}

void test_print()
{
  CMidiPacket mp(100, 0xC0, 11);
  print_main_message("test_print\n(100, 0xC0, 11)", mp);

  CMidiPacket mp1(1001, 0x91, 60, 101);
  print_sub_message("(1001, 91, 60, 101)", mp1);

  CMidiPacket mp2(2002, 0xB2, 7, 102);
  print_sub_message("(2002, B2, 7, 102)", mp2);
}

void test_output_operator()
{
  CMidiPacket mp(100, 0x90, 60, 100);

  std::cout << "\n===> test output operator<<()\n";
  std::cout << "# " << mp; // automatic std::endl

  std::ostringstream oss;
  oss << mp << std::endl;
  std::cout << "oss.str(): " << oss.str();
  std::cout << "# ---------------------------\n";
}

void test_input_operator()
{
  std::cout << "\n===> test input operator >>() from a istringstream\n";
  std::istringstream iss;
  std::string mpstr = "100\t90\t60\t100";
  iss.str(mpstr);

  CMidiPacket mp;
  iss >> mp;
  std::cout << mp;
  std::cout << "# ---------------------------\n";
}

void test_operator_equals()
{
  std::cout << "\n===> test_operator_equals\n";

  CMidiPacket a{1000, 0x90, 60, 100};
  CMidiPacket b{1000, 0x90, 60, 100};
  CMidiPacket c{1000, 0x80, 60, 0};
  CMidiPacket d{1000, 0xc0, 11};

  std::cout << "a: " << a;
  std::cout << "b: " << b;
  std::cout << "c: " << c;
  std::cout << "d: " << d;

  std::cout << "\na == b " << std::boolalpha << (a == b) << std::endl;
  std::cout << "a == c " << std::boolalpha << (a == c) << std::endl;
  std::cout << "d == b " << std::boolalpha << (d == b) << std::endl;
  std::cout << "# ---------------------------\n";
}

void run_CMidiPacket_tests()
{
  test_default_constructor();
  test_constructor_one_data_byte();
  test_constructor_two_data_bytes();
  test_constructor_string();
  test_to_string();
  test_print();

  test_output_operator();
  test_input_operator();
  test_operator_equals();
}
