// hw332_testInvariants.cpp

#ifndef HW332_CMIDIPACKET_H_
#include "hw332_CMidiPacket.h"
#endif

#ifndef HW332_TESTINVARIANTS_H
#include "hw332_testInvariants.h"
#endif

#include <iostream>
#include <sstream>

using namespace CMP33;

void print_header(const std::string msg)
{
    std::cout << "\n===> " << msg << " <====" << std::endl;
}

// Constructors
void testConstructorOneDataByte()
{
    // Example - you implement others
    // Deliberately enter bad data
    // Enter several tests
    // Try to find a false positive where bad data gets through
    // Test bad bad timestamp, status, data1, data2, length
    print_header("testConstructorOneDataByte");
    CMidiPacket mp1{1000, 0xC0, 11, 100}; // bad length
}

void testConstructorTwoDataBytes()
{
    print_header("testConstructorTwoDataBytes");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
    CMidiPacket mp2{1000, 0xA0, 127, 100};
}

void testStringConstructor()
{
    print_header("testStringConstructor");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
    CMidiPacket mp3{"1000\t0xC0\n30\t120"};
}

// Setters
void test_set_timestamp()
{
    print_header("test_set_timestamp");
    CMidiPacket p{1000, 0x80, 100, 0};
    p.set_timestamp(kMAX_TIMESTAMP + 1);
    // make up more bad data
    CMidiPacket q{0, 0x90, 100, 0};
    p.set_timestamp(-1000);
}

void test_set_status()
{
    print_header("test_set_status");
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
    CMidiPacket r{0, 0x80, 100, 0};
    r.set_status(0x70);
    CMidiPacket s{0, 0x90, 100, 0};
    s.set_status(64);
    CMidiPacket t{0, 0xA0, 100, 0};
    t.set_status(0b01011110);
}

void test_set_data1()
{
    print_header("test_set_data1");
    CMidiPacket p{1000, 0x90, 60, 100};
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
    CMidiPacket r{0, 0x80, 100, 0};
    r.set_data1(0b1000);
    CMidiPacket s{0, 0x90, 100, 0};
    s.set_data1(-120);
    CMidiPacket t{0, 0xA0, 100, 0};
    t.set_data1(0b1);
}

void test_set_data2()
{
    print_header("test_set_data2");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
}

void test_set_midi_channel()
{
    print_header("test_set_midi_channel");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
}

// Operator overloads
void test_output_operator()
{
    print_header("test_ouput_operator");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
}

void test_input_operator()
{
    print_header("test_input_operator");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
}

void test_operator_equals()
{
    print_header("test_operator_equals");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
}

void test_operator_less()
{
    print_header("test_operator_less");
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
}
void testInvariants()
{
    testConstructorOneDataByte();
    testConstructorTwoDataBytes();
    testStringConstructor();
    test_set_timestamp();
    test_set_status();
    test_set_data1();
    test_set_data2();
    test_set_midi_channel();
    test_output_operator();
    test_input_operator();
    test_operator_equals();
    test_operator_less();
}