MovimientoParabólico.png : Ej28.py data.dat dataf.dat
	python Ej28.py

data.dat dataf.dat: Ej28.x
	./Ej28.x

Ej28.x : Ej28f.cpp
	c++ Ej28f.cpp -o Ej28.x
	
clean :
	rm MovimientoParabólico.png data.dat Ej28.x