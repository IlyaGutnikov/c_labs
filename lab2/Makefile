#
# Makefile для второго задания курса Язык программирования C.
#

#
# ЗАМЕЧАНИЕ: При копировании этого файл из окна браузера в текстовый редактор,
#       символы табуляции в начале строк команд почти всегда заменяются
#       на восемь пробелов.  Вы ДОЛЖНЫ преобразовать их обратно в один символ 
#       табуляции, или этот файл не будет работать!  "make" очень зависит от
#       этого: строки команд должны начинаться с одного символа табуляции,
#       не больше и не меньше, и никаких пробелов.  Лучше всего сохранить этот файл
#       (то есть, нажав сочетание клавиш Сontrol+S в mozilla или firefox).
#       Удалите этот комментарий из Makefile прежде чем отправить его на проверку.
#

CC              = gcc
INFILE          = years.in
OUTFILE         = easter_dates.out
CORRECT_OUTFILE = correct_easter_dates.out


easter: easter.o
	$(CC) easter.o -o easter

easter.o: easter.c
	$(CC) -Wall -Wstrict-prototypes -ansi -pedantic -c easter.c

test:
	./easter < $(INFILE) > $(OUTFILE)
	./run_test $(OUTFILE) $(CORRECT_OUTFILE)

check:
	c_style_check easter.c

clean:

	rm -f easter easter.o

# Здесь вы должны добавить цель clean ...


