CPP    = g++
WINDRES= windres
RM     = rm -f
OBJS   = main.o \
         AppResource.res

LIBS   = -mwindows -static -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32
CFLAGS = -DGLUT_STATIC

.PHONY: FlappyBird.exe clean clean-after

all: FlappyBird.exe

clean:
	$(RM) $(OBJS) FlappyBird.exe

clean-after:
	$(RM) $(OBJS)

FlappyBird.exe: $(OBJS)
	$(CPP) -Wall -s -o $@ $(OBJS) $(LIBS)

main.o: main.cpp
	$(CPP) -Wall -s -c $< -o $@ $(CFLAGS)

AppResource.res: AppResource.rc
	$(WINDRES) -i AppResource.rc -J rc -o AppResource.res -O coff

