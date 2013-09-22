all: phoneBook 

phoneBook:
	g++ -Wall -g main.cpp src/core/Core.cpp src/list/List.cpp src/parser/Parser.cpp src/contact/Contact.cpp src/verifier/Verifier.cpp -o phoneBook.exe

clean: 
	rm -f phoneBook.exe
	rm -f src/contact/Contact.o
	rm -f src/contact/Contact.h.gch	
	rm -f src/list/List.h.gch
	rm -f src/list/List.o
	rm -f src/parser/Parser.h.gch
	rm -f src/parser/Parser.o

