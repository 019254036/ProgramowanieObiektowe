arkusz: main.o menu.o tablica.o cell.o intCell.o 
	g++ main.o menu.o tablica.o cell.o intCell.o -o arkusz

menu.o: menu.cpp
	g++ -c menu.cpp

tablica.o: tablica.cpp
	g++ -c tablica.cpp
	
cell.o: cell.cpp
	g++ -c cell.cpp

intCell.o:
	g++ -c intCell.cpp

main.o: main.cpp
	g++ -c main.cpp

clean :
	rm *.o 
