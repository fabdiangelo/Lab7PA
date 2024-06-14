okall: fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o interesado.o mensaje.o propiedad.o sistema.o usuario.o zona.o main.o String.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o list.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o
	g++ fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o interesado.o mensaje.o propiedad.o sistema.o usuario.o zona.o main.o String.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o list.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o -o programa


# Data types
direccion.o:
	g++ -c "DataTypes/direccion.cpp"

dtDepartamento.o:
	g++ -c "DataTypes/dtDepartamento.cpp"

dtEdificio.o:
	g++ -c "DataTypes/dtEdificio.cpp"

dtInmobiliaria.o: direccion.o
	g++ -c "DataTypes/dtInmobiliaria.cpp"

dtMensaje.o: ICollectible.o
	g++ -c "DataTypes/dtMensaje.cpp"

dtPropiedad.o: direccion.o
	g++ -c "DataTypes/dtPropiedad.cpp"

dtPropiedadInmo.o: direccion.o
	g++ -c "DataTypes/dtPropiedadInmo.cpp"

dtRespuesta.o:
	g++ -c "DataTypes/dtRespuesta.cpp"

dtZona.o: ICollectible.o
	g++ -c "DataTypes/dtZona.cpp"

fecha.o:
	g++ -c "DataTypes/fecha.cpp"

mensajesPropiedad.o: dtPropiedad.o ICollectible.o
	g++ -c "DataTypes/mensajesPropiedad.cpp"

propZona.o: zona.o
	g++ -c "DataTypes/propZona.cpp"

registroMensajes.o: dtMensaje.o list.o IIterator.o
	g++ -c "DataTypes/registroMensajes.cpp"

zonasDep.o: departamento.o propZona.o
	g++ -c "DataTypes/zonasDep"


# Clases
administrador.o: usuario.o
	g++ -c administrador.cpp

apartamento.o: propiedad.o
	g++ -c apartamento.cpp

casa.o: propiedad.o
	g++ -c casa.cpp

chat.o: mensaje.o fecha.o registroMensajes.o interesado.o
	g++ -c chat.cpp

departamento.o: zona.o IDictionary.o
	g++ -c departamento.cpp

edificio.o: apartamento.o OrderedDictionary.o String.o
	g++ -c edificio.cpp

# factory.o: sistema.o
# 	g++ -c factory.cpp	

inmobiliaria.o: usuario.o casa.o apartamento.o zonasDep.o
	g++ -c inmobiliaria.cpp

interesado.o: usuario.o
	g++ -c interesado.cpp

# ISistema.o:
# 	g++ -c ISistema.cpp	

mensaje.o: ICollectible.o
	g++ -c mensaje.cpp

propiedad.o: chat.o direccion.o inmobiliaria.o
	g++ -c propiedad.cpp

sistema.o: dtRespuesta.o direccion.o registroMensajes.o dtPropiedad.o dtInmobiliaria.o dtPropiedadInmo.o OrderedDictionary.o inmobiliaria.o administrador.o interesado.o
	g++ -c sistema.cpp

usuario.o: ICollectible.o
	g++ -c usuario.cpp

zona.o: edificio.o
	g++ -c zona.cpp


# ICOLLECTION:
String.o: ICollectible.o OrderedKey.o
	g++ -c "ICollection/String.cpp"

ICollectible.o:
	g++ -c "ICollection/interfaces/ICollectible.cpp"

ICollection.o: IIterator.o
	g++ -c "ICollection/interfaces/ICollection.cpp"

IDictionary.o: IKey.o ICollectible.o IIterator.o
	g++ -c "ICollection/interfaces/IDictionary.cpp"

IIterator.o: ICollectible.o
	g++ -c "ICollection/interfaces/IIterator.cpp"

IKey.o: ListNode.o
	g++ -c "ICollection/interfaces/IKey.cpp"

OrderedKey.o: IKey.o
	g++ -c "ICollection/interfaces/OrderedKey.cpp"

list.o: ICollection.o ListIterator.o
	g++ -c "ICollection/collections/List.cpp"

ListIterator.o: ListNode.o
	g++ -c "ICollection/collections/ListIterator.cpp"

ListNode.o: ICollectible.o
	g++ -c "ICollection/collections/ListNode.cpp"

OrderedDictionary.o: OrderedDictionaryEntry.o ListNode.o IDictionary.o
	g++ -c "ICollection/collections/OrderedDictionary.cpp"

OrderedDictionaryEntry.o: OrderedKey.o ICollectible.o
	g++ -c "ICollection/collections/OrderedDictionaryEntry.cpp"


main.o:
	g++ -c main.cpp


clean:
	rm -f fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o sistema.o usuario.o zona.o main.o String.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o list.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o
run:
	make clean
	make
	clear
	./programa