okall: fecha.o direccion.o dtDepartamento.o dtEdificio.o dtMensaje.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o registroMensajes.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o sistema.o usuario.o zona.o main.o
	g++ fecha.o direccion.o dtDepartamento.o dtEdificio.o dtMensaje.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o registroMensajes.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o sistema.o usuario.o zona.o main.o -o programa


# Data types
fecha.o:
	g++ -c "DataTypes/fecha.cpp"

direccion.o:
	g++ -c "DataTypes/direccion.cpp"

dtDepartamento.o:
	g++ -c "DataTypes/dtDepartamento.cpp"

dtEdificio.o:
	g++ -c "DataTypes/dtEdificio.cpp"

dtMensaje.o:
	g++ -c "DataTypes/dtMensaje.cpp"

dtPropiedad.o:
	g++ -c "DataTypes/dtPropiedad.cpp"

dtRespuesta.o:
	g++ -c "DataTypes/dtRespuesta.cpp"

dtZona.o:
	g++ -c "DataTypes/dtZona.cpp"

mensajesPropiedad.o:
	g++ -c "DataTypes/mensajesPropiedad.cpp"

registroMensajes.o:
	g++ -c "DataTypes/registroMensajes.cpp"


# Clases
administrador.o:
	g++ -c administrador.cpp

apartamento.o:
	g++ -c apartamento.cpp

casa.o:
	g++ -c casa.cpp	

chat.o:
	g++ -c chat.cpp	
	
departamento.o:
	g++ -c departamento.cpp	
	
edificio.o:
	g++ -c edificio.cpp	
	
factory.o:
	g++ -c factory.cpp	

inmobiliaria.o: usuario.o propiedad.o direccion.o
	g++ -c inmobiliaria.cpp	
	
interesado.o: usuario.o
	g++ -c interesado.cpp	
	
ISistema.o:
	g++ -c ISistema.cpp	
	
mensaje.o:
	g++ -c mensaje.cpp	
	
propiedad.o:
	g++ -c propiedad.cpp	
	
sistema.o:
	g++ -c sistema.cpp	
	
usuario.o:
	g++ -c usuario.cpp	
	
zona.o:
	g++ -c zona.cpp	


main.o: 
	g++ -c main.cpp


clean:
	rm -f fecha.o direccion.o dtDepartamento.o dtEdificio.o dtMensaje.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o registroMensajes.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o sistema.o usuario.o zona.o main.o -o programa
run:
	make clean
	make
	clear
	./programa