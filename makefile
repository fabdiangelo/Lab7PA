okall: fecha.o direccion.o dtEmpleado.o dtEmpresa.o dtExtranjera.o dtNacional.o empresa.o nacional.o extranjera.o empleado.o relacion_laboral.o main.o
	g++ fecha.o direccion.o dtEmpleado.o dtEmpresa.o dtExtranjera.o dtNacional.o empresa.o nacional.o extranjera.o empleado.o relacion_laboral.o main.o -o programa


# Data types
fecha.o:
	g++ -c "DataTypes/fecha.cpp"

direccion.o:
	g++ -c "DataTypes/direccion.cpp"

dtEmpleado.o:
	g++ -c "DataTypes/dtEmpleado.cpp"

dtEmpresa.o:
	g++ -c "DataTypes/dtEmpresa.cpp"

dtExtranjera.o: dtEmpresa.o
	g++ -c "DataTypes/dtExtranjera.cpp"

dtNacional.o: dtEmpresa.o
	g++ -c "DataTypes/dtNacional.cpp"


# Clases
empresa.o: direccion.o
	g++ -c empresa.cpp

nacional.o: empresa.o
	g++ -c nacional.cpp

extranjera.o: empresa.o
	g++ -c extranjera.cpp	

empleado.o: direccion.o
	g++ -c empleado.cpp	
	
relacion_laboral.o: empresa.o empleado.o fecha.o
	g++ -c relacion_laboral.cpp	


main.o: 
	g++ -c main.cpp


clean:
	rm -f fecha.o direccion.o dtEmpleado.o dtEmpresa.o dtExtranjera.o dtNacional.o empresa.o nacional.o extranjera.o empleado.o relacion_laboral.o main.o programa
run:
	make clean
	make
	clear
	./programa