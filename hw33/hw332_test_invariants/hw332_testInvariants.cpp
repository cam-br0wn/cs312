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
    CMidiPacket mp1{1000, 0xC0, 11, 10}; // bad length
}

void testConstructorTwoDataBytes()
{
    print_header("testConstructorTwoDataBytes");
    CMidiPacket mp1{1000, 0x80, 11}; 
    CMidiPacket mp2{1000, 0x90, 14}; 
}

void testStringConstructor()
{
    print_header("testStringConstructor");
    CMidiPacket mp3{"1000\t0xC0\n128"}; 
}

// Setters
void test_set_timestamp()
{
    print_header("test_set_timestamp");
    CMidiPacket p{1000, 0x80, 100, 0};
    p.set_timestamp(-20); 
}

void test_set_status()
{
    print_header("test_set_status");
     p1.set_status(0x7F); 
}

void test_set_data1()
{
    print_header("test_set_data1");
    CMidiPacket p{1000, 0x90, 60, 100};
    p.set_data1(-1); 
}

void test_set_data2()
{
    print_header("test_set_data2");

    CMidiPacket p2{1000, 0xC0, 80};
    p1.set_data2(128); 
}

void test_set_midi_channel()
{
    print_header("test_set_midi_channel");
     CMidiPacket p2{1000, 0x90, 128, 60};
    p2.set_midi_channel(0xFF);
}

// Operator overloads
void test_output_operator()
{
    print_header("test_ouput_operator");
    CMidiPacket p1{10000000, 0x90, 60, 128};
    std::cout << p1 << std::endl;
    // Create one CMidiPacket that will fail this test
    // After first successful compile add several more
    // try to find a false positive (bad data gets through)
}
void test_input_operator()
{
    print_header("test_input_operator");
    print_header("test_input_operator");
    CMidiPacket p{1000, 0x90, 80, 100};
    
    std::stringstream ss;
    ss.str("1000 0x90 100000 100");
    ss>>p1; 
}

void test_operator_equals()
{
    print_header("test_operator_equals");
    CMidiPacket p1{1000, 0xD8, 128, 0};
    CMidiPacket p2{1000, 0xF9, 129, 1};
    std::cout << (p1 < p2) << std::endl;
    
}

void test_operator_less()
{
    print_header("test_operator_less");
    CMidiPacket p1{1000, 0xD8, 128, 0};
    CMidiPacket p2{1000, 0xF9, 100, 1};
    std::cout << (p1 < p2) << std::endl; 
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