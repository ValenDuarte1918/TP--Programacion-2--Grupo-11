PROYECTO SISTEMA DE GESTION LOCAL DE COMIDAS RAPIDAS- TP FINAL - PROGRAMACION II - GRUPO 11 

INTRODUCCIÓN
  El sistema propuesto estará enfocado en la gestión de las operaciones de locales de comida rápida, con especial atención a las ventas y el control del inventario. A través de un menú principal y varios submenús, se ofrecerá una interfaz amigable que permitirá la administración eficiente de pedidos, clientes, productos y proveedores. La finalidad es optimizar el manejo de los recursos, mejorar el servicio al cliente y facilitar la supervisión de las actividades diarias del negocio.
  Descripción del Sistema de Gestión
1. Contexto y Propósito del Sistema
  El Sistema de Gestión está diseñado para integrar y optimizar las operaciones de stock, ventas y tareas de mantenimiento dentro de un local de comidas rápidas. El sistema permite llevar un control detallado de los productos almacenados, gestionar las tareas de mantenimiento en diferentes áreas y coordinar las ventas y el seguimiento de los productos en stock.
  Este sistema tiene como objetivo centralizar la información, mejorar la eficiencia operativa y facilitar la toma de decisiones sobre el manejo del inventario y las ventas, así como planificar el mantenimiento preventivo de los equipos.
2. Módulo de Stock
  El módulo de stock se divide en dos categorías:
  Actual: representa el inventario presente en la organización.
  Ingresante: indica lo que está por ingresar al stock.
Dentro del stock actual, los productos se agrupan en diversas categorías como:
  Papelería.
  Salsas.
  Fritos.
  Carnes.
  Bebidas.
  Papas.
  Panes.
Cada uno de estos productos es gestionado a través de una planilla que incluye:
  El nombre del producto.
  La cantidad disponible en stock.
  Además, se cuenta con una planilla del freezer para el control de productos perecederos, donde se registra:
  La fecha de ingreso del producto.
  La fecha de vencimiento.
3. Módulo de Ventas
  El módulo de ventas permite gestionar las transacciones del local. Está integrado con el módulo de stock para que, con cada venta realizada, se realice automáticamente un descuento en el inventario. Este proceso incluye:
  La emisión de un tícket para el cliente.
  El registro de la comanda.
  Un programa de seguimiento que se encarga de monitorear las ventas realizadas y su impacto en el stock.
4. Módulo de Tareas de Mantenimiento
  El módulo de mantenimiento está orientado a la planificación y gestión de las tareas de cuidado y preservación de las instalaciones. Se organiza en base a un calendario semanal, y las actividades se clasifican en:
  Mantenimiento de equipos.
  Mantenimiento del local en general.
  Cada una de estas tareas es registrada para asegurar que se lleven a cabo de manera eficiente y en el momento adecuado, evitando fallos imprevistos en los equipos o el deterioro de las instalaciones.
5. Integración del Sistema
  El sistema interrelaciona los diferentes módulos, permitiendo que los datos de stock, ventas y mantenimiento se actualicen en tiempo real. De esta manera, los administradores pueden tener una visión clara del estado del inventario, las ventas realizadas y las tareas de mantenimiento pendientes.
Salidas Del Sistema
  Nuestro sistema de gestión utilizará consultas, informes.
Consultas
  Consulta de empleado
  Por DNI del empleado
  Por Días de actividad
  Por Rol en la organización
Consulta de productos
  Por Categoría
  Por Stock
  Por Precios de los productos
  Consulta de ventas
  Por Ganancia mensual
  Por Productividad del empleado
  Por Producto más solicitado
Informes
  Información que brinda nuestro sistema es:
  Recaudación anual
  Recaudación total de cada empleado
  Cantidad de productos más consumidos
    Recaudación anual:
      El usuario al seleccionar la recaudación anual, tendrá que ingresar el año correspondiente para que se pueda mostrar el informe de ese año. 

Recaudación total de cada empleado:
  El usuario al seleccionar recaudación total de cada empleado deberá ingresar el DNI del empleado (ingresando en número 0 mostrará todos los empleado son sus respectivas recaudaciones) mostrará la recaudación que tuvo el empleado pero solo la del último mes. 

Cantidad de productos más consumidos:
  El usuario al seleccionar la cantidad más vendida de los productos, se le mostrará el listado de productos que fueron más consumidos el último mes. 

Configuraciones
  El sistema incluirá un menú de configuración que permitirá realizar copias de seguridad, restaurar copias de seguridad y la exportación de copias de seguridad generando archivos CSV (valores separados por comas) para cada uno de los documentos que administre el sistema de gestión. 

Realizar copia de seguridad
  El sistema dispone de un menú que permite elegir el archivo específico para crear una copia de seguridad. Asimismo, cuenta con una opción para generar una copia de seguridad de todos los archivos simultáneamente. Las copias de seguridad se guardarán en una carpeta llamada "copia de seguridad", mientras que los archivos de datos se almacenarán en una carpeta llamada "datos” ambas dentro de una carpeta base “archivos_sistema”. 

Restaurar copia de seguridad
  El sistema incluye un menú que permite seleccionar un archivo para restaurar su copia de seguridad. También dispone de una opción para restaurar todas las copias de seguridad de manera simultánea. Antes de proceder con la restauración, se solicitará al usuario que ingrese un código de seguridad alfanumérico que se generará automáticamente.
   
Exportar copias de seguridad
  El sistema ofrece un menú que permite seleccionar un archivo para exportarlo como un archivo CSV. Además, cuenta con una opción que permite generar todos los archivos CSV de forma simultánea. 
