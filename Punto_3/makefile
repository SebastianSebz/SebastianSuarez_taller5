caos.pdf: datos_caos_cambio_s.txt caos.py
	python caos.py
	rm datos_caos_cambio_s.txt datos_caos.txt

datos_caos_cambio_s.txt: caos.x
	./caos.x > datos_caos_cambio_s.txt

caos.x: caos.cpp
	c++ caos.cpp -o caos.x
