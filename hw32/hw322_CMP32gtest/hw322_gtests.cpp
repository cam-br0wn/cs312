/***************************************************************
 hw322_gtests.cpp
 Copyright(c) Carleton College CS312 free open source
 Assignment : hw322
 Stritzel Matt stritzelm@carleton.edu
 Brown Cam brownc2@carleton.edu
 DATE : 2020-01-28
 TIME: 14:45:47
 ***************************************************************/
#ifndef hw322_CMIDIPACKET_H_
#include "hw322_CMidiPacket.h"
#endif

#include <iostream>
#include <string>
#include <sstream>
// #include <exception>

#include "gtest/gtest.h"

using namespace CMP32;

/////////////////////////////////
// D O    N O T   M O D I F Y
/////////////////////////////////

// JE functions for CMidiPacket
void CMP_EQUALS(const CMidiPacket &mp, uint32_t ts, uint8_t st, uint8_t d1)
{
  EXPECT_EQ(ts, mp.get_timestamp());
  EXPECT_EQ(st, mp.get_status());
  EXPECT_EQ(d1, mp.get_data1());
  EXPECT_EQ(2, mp.get_length());
}

void CMP_EQUALS(const CMidiPacket &mp, uint32_t ts, uint8_t st, uint8_t d1, uint8_t d2)
{
  EXPECT_EQ(ts, mp.get_timestamp());
  EXPECT_EQ(st, mp.get_status());
  EXPECT_EQ(d1, mp.get_data1());
  EXPECT_EQ(d2, mp.get_data2());
  EXPECT_EQ(3, mp.get_length());
}

bool CMP_EQUALS(const CMidiPacket &mp1, const CMidiPacket &mp2)
{
  // clang-format off
    if ((mp1.get_timestamp() == mp2.get_timestamp())
            && (mp1.get_status() == mp2.get_status()) 
            && (mp1.get_data1() == mp2.get_data1()) 
            && (mp1.get_data2() == mp2.get_data2()) 
            && (mp1.get_length() == mp2.get_length()))
        return true;
    return false;
  // clang-format on
}
// END JE functions for CMidiPacket

// dc group
TEST(dc, default_constructor)
{
  CMidiPacket mp;
  CMP_EQUALS(mp, 0, 0x80, 0, 0);
}

// big6 group
TEST(big6, copy_constructor1)
{
  CMidiPacket A{1234, 0xC0, 11};
  CMidiPacket B{A};
  EXPECT_TRUE(CMP_EQUALS(A, B));
}

TEST(big6, copy_constructor2)
{
  CMidiPacket C{5678, 0x98, 99, 100};
  CMidiPacket D(C);
  EXPECT_TRUE(CMP_EQUALS(C, D));
}

TEST(big6, assignment_operator1)
{
  CMidiPacket A{1234, 0xC0, 11};
  CMidiPacket B = A;
  EXPECT_TRUE(CMP_EQUALS(A, B));
}

TEST(big6, assignment_operator2)
{
  CMidiPacket C{5678, 0x89, 87, 86};
  CMidiPacket D = C;
  EXPECT_TRUE(CMP_EQUALS(C, D));
}

TEST(big6, move_copy_constructor1)
{
  CMidiPacket A{1001, 0x91, 61, 101};
  CMidiPacket B(std::move(A));
  EXPECT_TRUE(CMP_EQUALS(A, B));
}

TEST(big6, move_assignment_operator2)
{
  CMidiPacket A{1001, 0x91, 61, 101};
  CMidiPacket B;
  B = std::move(A);
  EXPECT_TRUE(CMP_EQUALS(A, B));
}

// constructor overload group
TEST(overload, constructor_one_data_byte)
{
  CMidiPacket mp{100, 0xc0, 11};
  CMP_EQUALS(mp, 100, 0xc0, 11);
}

// example
TEST(overload, constructor_two_data_bytes)
{
  CMidiPacket mp{1001, 0x91, 61, 101};
  CMP_EQUALS(mp, 1001, 0x91, 61, 101);
}

TEST(overload, constructor_string1)
{
  CMidiPacket mp("100\tc0\t11");
  CMP_EQUALS(mp, 100, 0xc0, 11);
}

TEST(overload, constructor_string2)
{
  CMidiPacket mp1("1001\t91\t61\t101");
  CMP_EQUALS(mp1, 1001, 0x91, 61, 101);
}

TEST(overload, constructor_string3)
{
  CMidiPacket mp2("1002\tB2\t7\t102");
  CMP_EQUALS(mp2, 1002, 0xb2, 7, 102);
}

// tostring group
TEST(to_string, to_string1)
{
  CMidiPacket mp{100, 0xc0, 11};
  EXPECT_EQ(mp.to_string(), "100\tc0\t11");
}

// example
TEST(to_string, to_string2)
{
  CMidiPacket mp1(1001, 0x91, 61, 101);
  EXPECT_EQ(mp1.to_string(), "1001\t91\t61\t101");
}

TEST(to_string, to_string3)
{
  CMidiPacket mp2{2002, 0xb2, 7, 102};
  EXPECT_EQ(mp2.to_string(), "2002\tb2\t7\t102");
}

// get group
TEST(get, get_timestamp)
{
  CMidiPacket mp1(1001, 0x91, 61, 101);
  EXPECT_EQ(mp1.get_timestamp(), 1001);
}

// example
TEST(get, get_status)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_EQ(mp2.get_status(), 0x91);
}

TEST(get, get_data1)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_EQ(mp2.get_data1(), 61);
}

TEST(get, get_data2)
{
  CMidiPacket mp1(1001, 0x91, 61, 101);
  EXPECT_TRUE(mp1.get_data2() == 101);
}

TEST(get, get_data2B)
{
  CMidiPacket mp2(1000, 0x95, 60, 100);
  EXPECT_EQ(mp2.get_data2(), 100);
}

TEST(get, get_length)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_EQ(mp2.get_length(), 3);
}

TEST(get, get_midi_channel)
{
  CMidiPacket mp2(1001, 0x9C, 61, 101);
  EXPECT_EQ(mp2.get_midi_channel(), 12);
}

// set group
TEST(set, set_timestamp)
{
  CMidiPacket mp(1001, 0x91, 61, 101);
  mp.set_timestamp(999);
  EXPECT_EQ(mp.get_timestamp(), 999);
}

TEST(set, set_status_length1)
{
  CMidiPacket mp1(1001, 0x91, 61, 101);
  mp1.set_status_length();
  EXPECT_EQ(mp1.get_length(), 3);
  EXPECT_EQ(mp1.get_status(), 0x91);
}

// example
TEST(set, set_status_length2)
{
  CMidiPacket mp2(1001, 0xC1, 11);
  mp2.set_status_length();
  EXPECT_EQ(mp2.get_length(), 2);
  EXPECT_EQ(mp2.get_status(), 0xC1);
}

TEST(set, set_data1)
{
  CMidiPacket mp(1001, 0x91, 61, 101);
  mp.set_data1(99);
  EXPECT_EQ(mp.get_data1(), 99);
}

TEST(set, set_data2)
{
  CMidiPacket mp(1001, 0x91, 61, 101);
  mp.set_data2(100);
  EXPECT_EQ(mp.get_data2(), 100);
}

// is group
// example
TEST(is_status, is_status_8n1)
{
  CMidiPacket mp1(1001, 0x81, 61, 101);
  EXPECT_TRUE(mp1.is_status_8n());
}

TEST(is_status, is_status_8n2)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_FALSE(mp2.is_status_8n());
}

TEST(is_status, is_status_9n1)
{
  CMidiPacket mp1(1001, 0x91, 61, 101);
  EXPECT_TRUE(mp1.is_status_9n());
}

TEST(is_status, is_status_9n2)
{
  CMidiPacket mp2(1001, 0x81, 61, 101);
  EXPECT_FALSE(mp2.is_status_9n());
}

TEST(is_status, is_status_An1)
{
  CMidiPacket mp1(1001, 0xA1, 61, 101);
  // std::cout << mp1.get_status() << std::endl;
  // std::cout << (mp1.get_status() & 0xF0) << std::endl;
  EXPECT_TRUE(mp1.is_status_An());
}

TEST(is_status, is_status_An2)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_FALSE(mp2.is_status_An());
}

TEST(is_status, is_status_Bn1)
{
  CMidiPacket mp1(1001, 0xB1, 61, 101);
  EXPECT_TRUE(mp1.is_status_Bn());
}

TEST(is_status, is_status_Bn2)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_FALSE(mp2.is_status_Bn());
}

TEST(is_status, is_status_Cn1)
{
  CMidiPacket mp1(1001, 0xC1, 61);
  EXPECT_TRUE(mp1.is_status_Cn());
}

TEST(is_status, is_status_Cn2)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_FALSE(mp2.is_status_Cn());
}

TEST(is_status, is_status_Dn1)
{
  CMidiPacket mp1(1001, 0xD1, 61);
  EXPECT_TRUE(mp1.is_status_Dn());
}

TEST(is_status, is_status_Dn2)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_FALSE(mp2.is_status_Dn());
}

TEST(is_status, is_status_En1)
{
  CMidiPacket mp1(1001, 0xE1, 61, 101);
  EXPECT_TRUE(mp1.is_status_En());
}

TEST(is_status, is_status_En2)
{
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_FALSE(mp2.is_status_En());
}

// example
TEST(is_status, is_status_Fn1)
{
  // EXPECT_TRUE case will be caught in Bad data tests
  // 0xFn messages not supported
  CMidiPacket mp2(1001, 0x91, 61, 101);
  EXPECT_FALSE(mp2.is_status_Fn());
}

TEST(is_status, is_note_off1)
{
  CMidiPacket mp1(1001, 0x81, 61, 101);
  EXPECT_TRUE(mp1.is_note_off());
}

TEST(is_status, is_note_off2)
{
  CMidiPacket mp2(1001, 0x91, 61, 0);
  EXPECT_TRUE(mp2.is_note_off());
}

TEST(is_status, is_note_on)
{
  CMidiPacket mp2(1001, 0x81, 61, 0);
  EXPECT_TRUE(mp2.is_note_off());
}

// io_out group
TEST(io_out, operator_output1)
{
  CMidiPacket A{0, 0xC0, 11};
  std::ostringstream oss;
  oss << A;
  EXPECT_EQ(oss.str(), "0\tc0\t11\n");
}

TEST(io_out, operator_output2)
{
  CMidiPacket B{1001, 0x91, 61, 101};
  std::ostringstream oss;
  oss << B;
  EXPECT_EQ(oss.str(), "1001\t91\t61\t101\n");
}

// io_in group
TEST(io_in, operator_input1)
{
  CMidiPacket A{100, 0xC0, 11};
  std::string s = A.to_string() + "\n";
  std::istringstream iss(s);
  CMidiPacket B;
  iss >> B;
  EXPECT_TRUE(A == B);
}

TEST(io_in, operator_input1a)
{
  std::string s = "100\t0xC0\t11";
  std::istringstream iss(s);
  CMidiPacket A;
  iss >> A;
  s = "100\tc0\t11";
  EXPECT_EQ(A.to_string(), s);
}

TEST(io_in, operator_input2)
{
  std::string s = "1000\t90\t60\t100";
  std::istringstream iss(s);
  CMidiPacket A;
  iss >> A;
  EXPECT_EQ(A.to_string(), s);
}

TEST(io_in, operator_input3)
{
  std::string s = "1000 90 60 100";
  std::istringstream iss(s);
  CMidiPacket A;
  iss >> A;
  EXPECT_EQ(A.to_string(), "1000\t90\t60\t100");
}

// eq group
TEST(eq, operator_equals1)
{
  CMidiPacket A{999, 0xC0, 11};
  CMidiPacket B{999, 0xC0, 11};
  EXPECT_TRUE(A == B);
}

// example
TEST(eq, operator_equals2)
{
  CMidiPacket C{1001, 0x91, 61, 101};
  CMidiPacket D{1001, 0x91, 61, 101};
  EXPECT_TRUE(C == D);
}

TEST(eq, operator_equals3)
{
  CMidiPacket C{1001, 0x91, 61, 101};
  CMidiPacket D{1002, 0x91, 61, 101};
  EXPECT_FALSE(C == D);
}

TEST(eq, operator_equals4)
{
  CMidiPacket C{1001, 0x91, 61, 101};
  CMidiPacket D{1001, 0x92, 61, 101};
  EXPECT_FALSE(C == D);
}

TEST(eq, operator_equals5)
{
  CMidiPacket C{1001, 0x91, 61, 101};
  CMidiPacket D{1001, 0x91, 62, 101};
  EXPECT_FALSE(C == D);
}

TEST(eq, operator_equals6)
{
  CMidiPacket C{1001, 0x91, 61, 101};
  CMidiPacket D{1001, 0x91, 61, 102};
  EXPECT_FALSE(C == D);
}

// less_helper group
TEST(less_helper, is_timestamp_equal1)
{
  CMidiPacket A{1000, 0xC0, 11};
  CMidiPacket B{1000, 0x91, 61, 101};
  EXPECT_TRUE(A.get_timestamp() == B.get_timestamp());
}

// example
TEST(less_helper, is_timestamp_equal2)
{
  CMidiPacket C{999, 0xC0, 11};
  CMidiPacket D{1001, 0x91, 61, 101};
  EXPECT_FALSE(C.get_timestamp() == D.get_timestamp());
}

// example
TEST(less_helper, is_status_equal3)
{
  CMidiPacket A{1001, 0x91, 61, 101};
  CMidiPacket B{1000, 0x91, 62, 110};
  EXPECT_TRUE(A.get_status() == B.get_status());
}

TEST(less_helper, is_status_equal4)
{
  CMidiPacket A = {1001, 0x91, 61, 101};
  CMidiPacket B = {1000, 0x90, 60, 100};
  EXPECT_FALSE(A.get_status() == B.get_status());
}

TEST(less_helper, is_status_equal5)
{
  CMidiPacket C{1000, 0xC0, 11};
  CMidiPacket D{1001, 0x91, 61, 101};
  EXPECT_FALSE(C.get_status() == D.get_status());
}

// less group
TEST(less, lessthan1)
{
  std::cout << "===> case 1: A == B" << std::endl;
  CMidiPacket A{1001, 0x91, 61, 101};
  CMidiPacket B{1001, 0x91, 61, 101};
  EXPECT_FALSE(A < B);
}

// example
TEST(less, lessthan2)
{
  std::cout << "===> case 2 timestamp A < timestamp B" << std::endl;
  CMidiPacket A = {999, 0x90, 60, 100};
  CMidiPacket B = {1001, 0x91, 61, 101};
  EXPECT_TRUE(A < B);
}

TEST(less, lessthan3)
{
  // ORDER IMPORTANT from here down
  std::cout << "===> case 3 timestamps equal, A is 0x8n NOF" << std::endl;
  CMidiPacket A = {1000, 0x8f, 60, 127};
  CMidiPacket B = {1001, 0x91, 61, 101};
  EXPECT_TRUE(A < B);
}

TEST(less, lessthan4)
{
  CMidiPacket A = {1001, 0x91, 61, 101};
  CMidiPacket B = {1000, 0x91, 60, 0};
  EXPECT_FALSE(A < B);
}

TEST(less, lessthan5)
{
  CMidiPacket A = {1000, 0x99, 60, 0};
  CMidiPacket B = {1001, 0x91, 61, 101};
  EXPECT_TRUE(A < B);
}

// example
TEST(less, lessthan6)
{
  CMidiPacket A = {1000, 0xC0, 1};
  CMidiPacket B = {1000, 0xC0, 7};
  EXPECT_FALSE(A < B);
}

TEST(less, lessthan7)
{
  CMidiPacket A = {1000, 0x90, 60, 99};
  CMidiPacket B = {1000, 0x90, 60, 101};
  EXPECT_FALSE(A < B);
}

// example
TEST(less, lessthan8)
{
  CMidiPacket A = {1000, 0xC0, 11};
  CMidiPacket B = {1001, 0x91, 61, 101};
  EXPECT_TRUE(A < B);
}

TEST(less, lessthan9)
{
  CMidiPacket A = {1000, 0x91, 60, 0};
  CMidiPacket B = {1000, 0x91, 61, 101};
  EXPECT_TRUE(A < B);
}

TEST(less, lessthan10)
{
  CMidiPacket A = {1000, 0x91, 61, 101};
  CMidiPacket B = {1000, 0xC0, 11};
  EXPECT_FALSE(A < B);
}

TEST(less, lessthan11)
{
  CMidiPacket A = {1000, 0xC0, 7};
  CMidiPacket B = {1000, 0xA0, 60, 100};
  EXPECT_TRUE(A < B);
}

TEST(less, lessthan12)
{
  CMidiPacket A = {1000, 0xC0, 60};
  CMidiPacket B = {1000, 0xB0, 7, 100};
  EXPECT_TRUE(A < B);
}

TEST(less, lessthan13)
{
  CMidiPacket A = {1000, 0xC0, 60};
  CMidiPacket B = {1000, 0x90, 7, 100};
  EXPECT_TRUE(A < B);
}
