# Define application name
APPNAME=cmp22

# define the compiler to use
CC=clang++

#define the compiler parameters
CFLAGS=-c -std=c++17 -Wall
# the variables $(CC) $(CFLAGS) expand to clang++ -c -std-c++17 -Wall
# -c  Only run preprocess, compile, and assemble steps but do not link

# define the make command parameter option all, as in: make all
all: $(APPNAME)

# line 1: cmp221 depends on all three object files
# line 2: single TAB followed by linker command, no $(CFLAGS)
$(APPNAME): hw222_main.o hw222_test_CMidiPacket.o hw222_CMidiPacket.o
  $(CC) -g -o $(APPNAME) hw222_main.o hw222_test_CMidiPacket.o hw222_CMidiPacket.o

# line 1: hw222_main.o depends on hw222_test_CMidiPacket.h
# line 2: single TAB followed by compile command
hw222_main.o: hw222_main.cpp hw222_test_CMidiPacket.h
   $(CC) $(CFLAGS) hw222_main.cpp

# line 1: hw222_test_CMidiPacket.o depends on hw222_test_CMidiPacket.h and 1.h
# line 2: single TAB followed by compile command
hw222_test_CMidiPacket.o: hw222_test_CMidiPacket.cpp hw222_test_CMidiPacket.h hw222_CMidiPacket.h
   $(CC) $(CFLAGS) hw222_test_CMidiPacket.cpp

# line 1: hw222_CMidiPacket.o depends on hw222_CMidiPacket.h
# line 2: single TAB followed by compile command
hw222_CMidiPacket.o: hw222_CMidiPacket.cpp hw222_CMidiPacket.h
   $(CC) $(CFLAGS) hw222_CMidiPacket.cpp

# define make command option clean, as in: make clean
# removes all the .o object files
clean:
  rm *.o
  rm ${APPNAME}