// Incluimos el archivo de cabecera solo una vez
#ifndef FUNCIONESPROVEEDOR_H_INCLUDED
#define FUNCIONESPROVEEDOR_H_INCLUDED

// Funcion para listar todos los proveedores
void listarProveedor(){
    archivoProveedor obj1;
    obj1.listarRegistros(); // Llama al metodo para listar todos los registros de proveedores
}

// Funcion para modificar un proveedor existente
void modificarProveedor(){
    archivoProveedor obj1 ("proveedor.dat");
    int num;
    cout << "Ingrese el numero de proveedor: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num); // Busca el registro del proveedor por su numero
    if(pos<0){
        cout << "Proveedor no encontrado" << endl;
        return;
    }
    Proveedor obj;
    obj= obj1.leerRegistro(pos); // Lee el registro del proveedor encontrado
    int cod;
    cout << "Ingrese el nuevo codigo de proveedor: ";
    cin >> cod;
    obj.setCodProveedor(cod); // Establece el nuevo codigo del proveedor
    obj1.modificarRegistro(obj, pos); // Modifica el registro en la posicion encontrada
    if(obj.getEstado()==false){
        cout << "No se pudo modificar el registro" << endl;
    }
    else{
        cout << "Registro modificado exitosamente" << endl;
    }
}

// Funcion para dar de baja a un proveedor
void bajaProveedor(){
    archivoProveedor obj1;
    int num;
    cout << "Ingrese el numero de proveedor a eliminar: ";
    cin >> num;
    int pos= obj1.buscarRegistro(num); // Busca el registro del proveedor por su numero
    if(pos<0){
        cout << "Proveedor no encontrado" << endl;
        return;
    }
    Proveedor obj;
    obj= obj1.leerRegistro(pos); // Lee el registro del proveedor encontrado
    obj.setEstado(false); // Cambia el estado del proveedor a false (baja)
    obj1.modificarRegistro(obj, pos); // Modifica el registro en la posicion encontrada
    cout << "Proveedor eliminado" << endl;
}

// Funcion para dar de alta a un nuevo proveedor
void altaProveedor(){
    archivoProveedor obj1("proveedor.dat");
    Proveedor obj;
    obj.cargar(); // Carga los datos del nuevo proveedor
    int pos= obj1.buscarRegistro(obj.getCodProveedor()); // Busca si el proveedor ya existe
    if(pos !=-1){
        cout << "Ese Proveedor ya existe" << endl;
        obj.setEstado(false); // Si ya existe, cambia su estado a false
    }
    if (obj.getEstado()==true){
        obj1.grabarRegistro(obj); // Graba el nuevo registro si el estado es true
        cout << "Registro grabado" << endl;
    }else {
        cout << "No se pudo grabar el registro" << endl;
    }
}

// Funcion para buscar un proveedor por su codigo
void buscarProveedor(){
    int num;
    cout << "Ingrese el Cod de Proveedor: ";
    cin >> num;
    archivoProveedor obj1;
    Proveedor obj;
    int pos= obj1.buscarRegistro(num); // Busca el registro del proveedor por su codigo
    if(pos<0){
        cout << "Proveedor no encontrado" << endl;
        return;
    }
    obj= obj1.leerRegistro(pos); // Lee el registro del proveedor encontrado
    system("cls"); // Limpia la pantalla
    obj.mostrar(); // Muestra los datos del proveedor
}

// Funcion para limpiar el archivo de proveedores
void limpiarProveedor(){
    archivoProveedor obj1;
    obj1.limpiarArchivo(); // Llama al metodo para limpiar el archivo de proveedores
    cout << "Archivo borrado" << endl;
}

#endif // FUNCIONESPROVEEDOR_H_INCLUDED