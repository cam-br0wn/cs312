/***************************************************************
hw222_test_CMidiPacket.cpp
Copyright (c) Carleton College CS312 free open source
Assignment: hw222
Stritzel Matt stritzelm@carleton.edu
Brown Cam brownc@carleton.edu
DATE: 2020-01-22
TIME: 13:38:44
****************************************************************/
#ifndef HW222_TEST_CMidiPacket_H_
#include "hw222_test_CMidiPacket.h"
#endif

#ifndef HW222_CMidiPacket_H_
#include "hw222_CMidiPacket.h"
#endif

#include <iostream>
#include <sstream>
#include <string>

using namespace CMP22;

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

void print_length_message(const std::string &msg, CMidiPacket mp)
{
  std::cout << "----\n"
            << msg << std::endl;
  std::cout << +mp.get_length() << std::endl;
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

  // remove later
  CMidiPacket mp2("1002\tB2\t7\t102");
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

// getters
void test_get_timestamp()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  print_main_message("test_get_timestamp(1001, 91, 60, 101)", mp1);
}
void test_get_status()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  print_main_message("test_get_status(1001, 91, 60, 101)", mp1);
}
void test_get_data1()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  print_main_message("test_get_data1(1001, 91, 60, 101)", mp1);
}
void test_get_data2()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  print_main_message("test_get_data2(1001, 91, 60, 101)", mp1);
}

void test_get_length()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  print_main_message("test_get_length(1001, 91, 60, 101)", mp1);
}

// setters
void test_set_timestamp()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  mp1.set_timestamp(999);
  print_main_message("test_set_timestamp(999)", mp1);
}
void test_set_status_length()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  mp1.set_status_length();
  print_main_message("test_set_status_length(1001, 0x91, 60, 101)", mp1);
  print_length_message("length(1001, 0x91, 60, 101)", mp1);

  CMidiPacket mp2(1001, 0xC1, 60, 100);
  mp2.set_status_length();
  print_sub_message("USING BAD INPUT: test_set_status_length(1001, 0xC1, 60, 100)", mp2);
  print_length_message("USING BAD INPUT: length(1001, 0xC1, 60, 100)", mp2);
}

void test_set_data1()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  mp1.set_data1(99);
  print_main_message("test_set_data1(1001, 0x91, 60, 101) -> 99", mp1);
}
void test_set_data2()
{
  CMidiPacket mp1(1001, 0x91, 60, 101);
  mp1.set_data2(99);
  print_main_message("test_set_data2(1001, 0x91, 60, 101) -> 99", mp1);
}

// Utility functions
void test_is_status_8n()
{
  std::cout << "\n===> test_is_status_8n" << std::endl;
  CMidiPacket mp1(1001, 0x81, 60, 101);
  std::cout << std::boolalpha << mp1.is_status_8n() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x91, 60, 101);
  std::cout << std::boolalpha << mp2.is_status_8n() << std::endl;
  mp2.print();
}

void test_is_status_9n()
{
  std::cout << "\n===> test_is_status_9n" << std::endl;
  CMidiPacket mp1(1001, 0x91, 60, 101);
  std::cout << std::boolalpha << mp1.is_status_9n() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x81, 60, 101);
  std::cout << std::boolalpha << mp2.is_status_9n() << std::endl;
  mp2.print();
}

void test_is_status_An()
{
  std::cout << "\n===> test_is_status_An" << std::endl;
  CMidiPacket mp1(1001, 0xA1, 60);
  std::cout << std::boolalpha << mp1.is_status_An() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x91, 60, 101);
  std::cout << std::boolalpha << mp2.is_status_An() << std::endl;
  mp2.print();
}

void test_is_status_Bn()
{
  std::cout << "\n===> test_is_status_Bn" << std::endl;
  CMidiPacket mp1(1001, 0xB1, 60, 101);
  std::cout << std::boolalpha << mp1.is_status_Bn() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x91, 60, 101);
  std::cout << std::boolalpha << mp2.is_status_Bn() << std::endl;
  mp2.print();
}

void test_is_status_Cn()
{
  std::cout << "\n===> test_is_status_Cn" << std::endl;
  CMidiPacket mp1(1001, 0xC1, 60);
  std::cout << std::boolalpha << mp1.is_status_Cn() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x91, 60, 101);
  std::cout << std::boolalpha << mp2.is_status_Cn() << std::endl;
  mp2.print();
}

void test_is_status_Dn()
{
  std::cout << "\n===> test_is_status_Dn" << std::endl;
  CMidiPacket mp1(1001, 0xD1, 60, 101);
  std::cout << std::boolalpha << mp1.is_status_Dn() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x91, 60, 101);
  std::cout << std::boolalpha << mp2.is_status_Dn() << std::endl;
  mp2.print();
}

void test_is_status_En()
{
  std::cout << "\n===> test_is_status_En" << std::endl;
  CMidiPacket mp1(1001, 0xE1, 60, 101);
  std::cout << std::boolalpha << mp1.is_status_En() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x91, 60, 101);
  std::cout << std::boolalpha << mp2.is_status_En() << std::endl;
  mp2.print();
}

void test_is_status_Fn()
{
  std::cout << "\n===> test_is_status_Fn" << std::endl;
  CMidiPacket mp1(1001, 0xF1, 60, 101);
  std::cout << std::boolalpha << mp1.is_status_Fn() << std::endl;
  mp1.print();
}

void test_is_note_off()
{
  std::cout << "\n===> test_is_note_off" << std::endl;
  CMidiPacket mp1(1001, 0x81, 60, 101);
  std::cout << std::boolalpha << mp1.is_note_off() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x92, 60, 0);
  std::cout << std::boolalpha << mp2.is_note_off() << std::endl;
  mp2.print();

  CMidiPacket mp3(1001, 0x93, 60, 101);
  std::cout << std::boolalpha << mp3.is_note_off() << std::endl;
  mp3.print();

  CMidiPacket mp4(1001, 0xA3, 60, 101);
  std::cout << std::boolalpha << mp4.is_note_off() << std::endl;
  mp4.print();
}

void test_is_note_on()
{
  std::cout << "\n===> test_is_note_on" << std::endl;
  CMidiPacket mp1(1001, 0x92, 60, 101);
  std::cout << std::boolalpha << mp1.is_note_on() << std::endl;
  mp1.print();

  CMidiPacket mp2(1001, 0x92, 60, 0);
  std::cout << std::boolalpha << mp2.is_note_on() << std::endl;
  mp2.print();

  CMidiPacket mp3(1001, 0xB3, 60, 101);
  std::cout << std::boolalpha << mp3.is_note_on() << std::endl;
  mp3.print();
}

void run_CMidiPacket_tests()
{
  test_default_constructor();
  test_constructor_one_data_byte();
  test_constructor_two_data_bytes();
  test_constructor_string();
  test_to_string();
  test_print();
  test_get_timestamp();
  test_get_length();
  test_get_status();
  test_get_data1();
  test_get_data2();
  test_set_timestamp();
  test_set_status_length();
  test_set_data1();
  test_set_data2();
  test_is_status_8n();
  test_is_status_9n();
  test_is_status_An();
  test_is_status_Bn();
  test_is_status_Cn();
  test_is_status_Dn();
  test_is_status_En();
  test_is_status_Fn();
  test_is_note_off();
  test_is_note_on();
}