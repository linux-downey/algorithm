TARGET = select_sort
HED_DIR  += ./inc/
LIB_DIR  +=
LIB_NAME +=

#CC= gcc
#CFLAG= -std=gnu99 -Wall 

RM =rm -rf

CC= g++
CFLAG= -std=c++11 -Wall

ifeq ($(SRC_DIR),)
	SRC_DIR=.
endif
ifeq ($(HED_DIR),)
	HED_DIR=.
endif
ifeq ($(TARGET),)
	TARGET=a.out
endif
ifeq ($(LIB_DIR),)
	LIB_DIR=.
endif


HED+=

SRC+= selection_sort.cpp


ifeq ($(LIB_NAME),)
all:
	$(CC) $(CFLAG) $(SRC) -I$(HED_DIR) -o $(TARGET)
else
all:
	$(CC) $(CFLAG) $(SRC) -I$(HED_DIR) -L$(LIB_DIR) $(LIB_NAME) -o $(TARGET)
endif
clean:
	$(RM)  $(TARGET)
