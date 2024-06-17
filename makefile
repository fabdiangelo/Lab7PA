okall: mensaje.o usuario.o administrador.o interesado.o chat.o departamento.o edificio.o zona.o propiedad.o apartamento.o casa.o inmobiliaria.o sistema.o ISistema.o factory.o main.o fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o String.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o
	g++ mensaje.o usuario.o administrador.o interesado.o chat.o departamento.o edificio.o zona.o propiedad.o apartamento.o casa.o inmobiliaria.o sistema.o ISistema.o factory.o main.o fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o String.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o -o programa

# Clases
apartamento.o: edificio.o propiedad.o
	g++ -c apartamento.cpp

casa.o: propiedad.o
	g++ -c casa.cpp

inmobiliaria.o: zonasDep.o usuario.o propiedad.o
	g++ -c inmobiliaria.cpp

propiedad.o: chat.o direccion.o zona.o IDictionary.o
	g++ -c propiedad.cpp

mensaje.o: ICollectible.o
	g++ -c mensaje.cpp

usuario.o: ICollectible.o
	g++ -c usuario.cpp

administrador.o: usuario.o
	g++ -c administrador.cpp

interesado.o: usuario.o
	g++ -c interesado.cpp

chat.o: mensaje.o fecha.o registroMensajes.o interesado.o
	g++ -c chat.cpp

departamento.o: IDictionary.o
	g++ -c departamento.cpp

edificio.o: OrderedDictionary.o String.o
	g++ -c edificio.cpp

zona.o: edificio.o departamento.o
	g++ -c zona.cpp


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

registroMensajes.o: dtMensaje.o List.o IIterator.o
	g++ -c "DataTypes/registroMensajes.cpp"

zonasDep.o: propZona.o departamento.o
	g++ -c "DataTypes/zonasDep.cpp"


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

List.o: ICollection.o ListIterator.o
	g++ -c "ICollection/collections/List.cpp"

ListIterator.o: ListNode.o
	g++ -c "ICollection/collections/ListIterator.cpp"

ListNode.o: ICollectible.o
	g++ -c "ICollection/collections/ListNode.cpp"

OrderedDictionary.o: OrderedDictionaryEntry.o ListNode.o IDictionary.o
	g++ -c "ICollection/collections/OrderedDictionary.cpp"

OrderedDictionaryEntry.o: OrderedKey.o ICollectible.o
	g++ -c "ICollection/collections/OrderedDictionaryEntry.cpp"



# SISTEMA:
factory.o: ISistema.o sistema.o
	g++ -c factory.cpp	

ISistema.o:
	g++ -c ISistema.cpp

sistema.o: ISistema.o dtRespuesta.o direccion.o registroMensajes.o dtPropiedad.o dtInmobiliaria.o dtPropiedadInmo.o OrderedDictionary.o usuario.o departamento.o
	g++ -c sistema.cpp

main.o: ISistema.o factory.o
	g++ -c main.cpp


clean:
	rm -f fecha.o direccion.o dtDepartamento.o dtEdificio.o dtInmobiliaria.o dtMensaje.o dtPropiedadInmo.o dtPropiedad.o dtRespuesta.o dtZona.o mensajesPropiedad.o propZona.o registroMensajes.o zonasDep.o administrador.o apartamento.o casa.o chat.o departamento.o edificio.o factory.o interesado.o ISistema.o mensaje.o propiedad.o inmobiliaria.o sistema.o usuario.o zona.o main.o String.o ICollectible.o ICollection.o IDictionary.o IIterator.o IKey.o OrderedKey.o List.o ListIterator.o ListNode.o OrderedDictionary.o OrderedDictionaryEntry.o
run:
	make clean
	make
	clear
	./programa