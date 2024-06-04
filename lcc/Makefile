# Wedit Makefile for project vokabel_quiz
SRCDIR=d:\hse\edv_2
CFLAGS=-I"c:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	vokabel_quiz.res \
	vokabel_quiz.obj \
	meine_unterprogramme.obj \

LIBS=c:\lcc\lib\weditres.lib
EXE=vokabel_quiz.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\vokabel_quiz.exe $(OBJS) $(LIBS)

# Build vokabel_quiz.res
VOKABEL_QUIZ_RC=\
	$(SRCDIR)\vokabel_quizres.h\

vokabel_quiz.res:	$(VOKABEL_QUIZ_RC) $(SRCDIR)\vokabel_quiz.rc
	$(LCCROOT)\bin\lrc.exe -I$(SRCDIR) -I"c:\lcc\include"  $(SRCDIR)\vokabel_quiz.rc

# Build vokabel_quiz.c
VOKABEL_QUIZ_C=\
	$(SRCDIR)\vokabel_quizres.h\
	$(SRCDIR)\prototypen.h\

vokabel_quiz.obj: $(VOKABEL_QUIZ_C) $(SRCDIR)\vokabel_quiz.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\vokabel_quiz.c

# Build meine_unterprogramme.c
MEINE_UNTERPROGRAMME_C=\
	$(SRCDIR)\vokabel_quizres.h\
	$(SRCDIR)\prototypen.h\

meine_unterprogramme.obj: $(MEINE_UNTERPROGRAMME_C) $(SRCDIR)\meine_unterprogramme.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\meine_unterprogramme.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\vokabel_quiz.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) vokabel_quiz.exe
