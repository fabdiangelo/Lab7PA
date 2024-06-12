okall: fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o sistema.o usuario.o zona.o list.o ICollectible.o main.o
	g++ fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o sistema.o usuario.o zona.o list.o ICollectible.o main.o -o programa


# Data types 👌
fecha.o: #👌
	g++ -c "DataTypes/fecha.cpp"

direccion.o: #👌
	g++ -c "DataTypes/direccion.cpp"

dtDepartamento.o: #👌
	g++ -c "DataTypes/dtDepartamento.cpp"

dtEdificio.o: #👌
	g++ -c "DataTypes/dtEdificio.cpp"

dtInmobiliaria.o: direccion.o #👌
	g++ -c "DataTypes/dtInmobiliaria.cpp"

dtMensaje.o: ICollectible.o #👌
	g++ -c "DataTypes/dtMensaje.cpp"

dtPropiedad.o: direccion.o #👌
	g++ -c "DataTypes/dtPropiedad.cpp"

dtPropiedadInmo.o: direccion.o #👌
	g++ -c "DataTypes/dtPropiedadInmo.cpp"

dtRespuesta.o: #👌
	g++ -c "DataTypes/dtRespuesta.cpp"

dtZona.o: ICollectible#👌
	g++ -c "DataTypes/dtZona.cpp"

mensajesPropiedad.o: dtPropiedad.o #👌
	g++ -c "DataTypes/mensajesPropiedad.cpp"

propZona.o: zona.o #👌
	g++ -c "DataTypes/propZona.cpp"

registroMensajes.o: dtMensaje.o #👌
	g++ -c "DataTypes/registroMensajes.cpp"

zonasDep.o: departamento.o propZona.o
	g++ -c "DataTypes/zonasDep"


# Clases
administrador.o: usuario.o #👌
	g++ -c administrador.cpp

apartamento.o: propiedad.o
	g++ -c apartamento.cpp

casa.o: propiedad.o
	g++ -c casa.cpp	

chat.o: mensaje.o fecha.o registroMensajes.o interesado.o IIterator.o #👌
	g++ -c chat.cpp	
	
departamento.o: zona.o list.o dtZona.o #👌
	g++ -c departamento.cpp	
	
edificio.o: OrderedDictionary.o IKey.o String.o ICollectible.o #👌
	g++ -c edificio.cpp	
	
factory.o: sistema.o
	g++ -c factory.cpp	

inmobiliaria.o: usuario.o casa.o apartamento.o zonasDep.o#👌
	g++ -c inmobiliaria.cpp	
	
interesado.o: usuario.o #👌
	g++ -c interesado.cpp	
	
ISistema.o:
	g++ -c ISistema.cpp	
	
mensaje.o: ICollectible.o #👌
	g++ -c mensaje.cpp	
	
propiedad.o: direccion.o list.o registroMensajes.o chat.o
	g++ -c propiedad.cpp	
	
sistema.o:
	g++ -c sistema.cpp	
	
usuario.o: #👌
	g++ -c usuario.cpp	
	
zona.o: list.o edificio.o departamento.o mensajesPropiedad.o #👌
	g++ -c zona.cpp	


# LISTAS:
list.o:
	g++ -c "ICollection/collections/List.cpp"

ICollectible.o:
	g++ -c "ICollection/interfaces/ICollectible.cpp"



main.o: 
	g++ -c main.cpp


clean:
	rm -f fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o sistema.o usuario.o zona.o list.o ICollectible.o main.o
run:
	make clean
	make
	clear
	./programa