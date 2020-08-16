CC=g++
CXXFLAGS=-g -Wall
LDFLAGS=-lstdc++fs
TARGET=cloc
OBJS= main.o Language.o LanguageDB.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)
	
clean:
	rm -f $(OBJS) $(TARGET)
	
new:
	make clean
	make


