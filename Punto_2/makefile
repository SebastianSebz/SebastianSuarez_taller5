cuerda.gif: data.txt animacion.py
	python animacion.py
	rm data.txt cuerda

data.txt: cuerda
	./cuerda > data.txt

cuerda: cuerda.cpp
	c++ cuerda.cpp -o cuerda
	
