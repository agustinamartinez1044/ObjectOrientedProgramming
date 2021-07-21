#include "./include/controladores/FabricaControladores.h"

void cargarDatos() {
    //AGREGAR CATEGORIAS
    FabricaControladores *fabrica = FabricaControladores::getInstancia();
    IAltaUsuario *altaUsuaario = fabrica->getIAltaUsuario();

    DtJugador *datosJugador;

    datosJugador = new DtJugador("gamer@mail.com", "123", "gamer","");;
    altaUsuaario->crearUsuario(datosJugador);
    delete datosJugador;

    datosJugador = new DtJugador("ari@mail.com", "123", "ari","");;
    altaUsuaario->crearUsuario(datosJugador);
    delete datosJugador;

    datosJugador = new DtJugador("ibai@mail.com", "123", "ibai","");;
    altaUsuaario->crearUsuario(datosJugador);
    delete datosJugador;

    datosJugador = new DtJugador("camila@mail.com", "123", "camila","");;
    altaUsuaario->crearUsuario(datosJugador);
    delete datosJugador;

    DtDesarrollador *datosDesarrollador;;

    datosDesarrollador = new DtDesarrollador("ironhide@mail.com", "123", "Ironhide Game Studio");
    altaUsuaario->crearUsuario(datosDesarrollador);
    delete datosDesarrollador;

    datosDesarrollador = new DtDesarrollador("epic@mail.com", "123", "Epic Games");
    altaUsuaario->crearUsuario(datosDesarrollador);
    delete datosDesarrollador;

    datosDesarrollador = new DtDesarrollador("mojang@mail.com", "123", "Mojang Studios");
    altaUsuaario->crearUsuario(datosDesarrollador);
    delete datosDesarrollador;

    datosDesarrollador = new DtDesarrollador("ea@mail.com", "123","EA Sports");
    altaUsuaario->crearUsuario(datosDesarrollador);
    delete datosDesarrollador;

    IAgregarCategoria *agregarCategoria = fabrica->getIAgregarCategoria();
    DtCategoria *categoria;

    categoria = new DtCategoria("PC","", Plataforma);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("PS4","", Plataforma);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Xbox One","", Plataforma);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Deporte","Género", Genero);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Supervivencia","Género", Genero);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Estrategia","Género", Genero);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Teen","Su contenido está dirigido a jóvenes de 13 años enadelante.", Otro);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("E","Su contenido está dirigido para todo público.", Otro);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Acción", "", Genero);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Aventura", "", Genero);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Switch","", Plataforma);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("Xbox X","", Plataforma);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    categoria = new DtCategoria("PS5","", Plataforma);
    agregarCategoria->crearCategoria(categoria);
    delete categoria;

    //PUBLICAR VIDEOJUEGOS
    IPublicarVideojuego *publicarVideojuego = fabrica->getIPublicarVideojuego();
    ControladorUsuario * cu = ControladorUsuario::getInstancia();
    DtVideojuego *datosVideojuego;
    list<string> categorias;
    Usuario *usuario;

    usuario = cu->buscarUsuario("ironhide@mail.com");
    cu->setUsuario(usuario);
    datosVideojuego = new DtVideojuego("KingdomRush", "", 1, 2, 7, 14);
    categorias.push_back("PC");
    categorias.push_back("PS4");
    categorias.push_back("Estrategia");
    categorias.push_back("E");
    publicarVideojuego->crearVideojuego(datosVideojuego, categorias);
    cu->cerrarSecion();
    categorias.clear();
    delete datosVideojuego;

    usuario = cu->buscarUsuario("epic@mail.com");
    cu->setUsuario(usuario);
    datosVideojuego = new DtVideojuego("Fortnite", "", 3, 8, 30, 60);
    categorias.push_back("PC");
    categorias.push_back("PS4");
    categorias.push_back("Xbox One");
    categorias.push_back("Supervivencia");
    categorias.push_back("Teen");
    publicarVideojuego->crearVideojuego(datosVideojuego, categorias);
    cu->cerrarSecion();
    categorias.clear();
    delete datosVideojuego;

    usuario = cu->buscarUsuario("mojang@mail.com");
    cu->setUsuario(usuario);
    datosVideojuego = new DtVideojuego("Minecraft", "", 2, 5, 20, 40);
    categorias.push_back("PC");
    categorias.push_back("Supervivencia");
    categorias.push_back("E");
    publicarVideojuego->crearVideojuego(datosVideojuego, categorias);
    cu->cerrarSecion();
    categorias.clear();
    delete datosVideojuego;

    usuario = cu->buscarUsuario("ea@mail.com");
    cu->setUsuario(usuario);
    datosVideojuego = new DtVideojuego("FIFA 21", "", 3, 8, 28, 50);
    categorias.push_back("PC");
    categorias.push_back("PS4");
    categorias.push_back("Xbox One");
    categorias.push_back("Deporte");
    categorias.push_back("E");
    publicarVideojuego->crearVideojuego(datosVideojuego, categorias);
    cu->cerrarSecion();
    categorias.clear();
    delete datosVideojuego;

    //SUSCRIPCION A VIDEOJUEGOS
    // DtSuscripcion * suscripcion;
    // ISuscripcionVideojuegos * suscripcionVideojuegos = fabrica->getISuscripcionVideojuegos();

    // suscripcion = new DtSuscripcionTemporal(cu->getFechaSistema(), Paypal, 1, true, 3, false);
    // usuario = cu->buscarUsuario("gamer");
    // cu->setUsuario(usuario);
    // suscripcionVideojuegos->confirmarSuscripcion("KingdomRush", suscripcion);
    // cu->cerrarSecion();
    // delete suscripcion;

    // suscripcion = new DtSuscripcionTemporal(cu->getFechaSistema(), Tarjeta, 1, true, 3, false);
    // usuario = cu->buscarUsuario("gamer");
    // cu->setUsuario(usuario);
    // suscripcionVideojuegos->confirmarSuscripcion("Fortnite", suscripcion);
    // cu->cerrarSecion();
    // delete suscripcion;

    // suscripcion = new DtSuscripcionTemporal(cu->getFechaSistema(), Paypal, 1, true, 1, false);
    // usuario = cu->buscarUsuario("ari");
    // cu->setUsuario(usuario);
    // suscripcionVideojuegos->confirmarSuscripcion("Fortnite", suscripcion);
    // cu->cerrarSecion();
    // delete suscripcion;

    // suscripcion = new DtSuscripcionTemporal(cu->getFechaSistema(), Tarjeta, 1, true, 12, false);
    // usuario = cu->buscarUsuario("ari");
    // cu->setUsuario(usuario);
    // suscripcionVideojuegos->confirmarSuscripcion("Minecraft", suscripcion);
    // cu->cerrarSecion();
    // delete suscripcion;

    // suscripcion = new DtSuscripcionTemporal(cu->getFechaSistema(), Tarjeta, 1, true, 1, false);
    // usuario = cu->buscarUsuario("ibai");
    // cu->setUsuario(usuario);
    // suscripcionVideojuegos->confirmarSuscripcion("Fortnite", suscripcion);
    // cu->cerrarSecion();
    // delete suscripcion;


    // suscripcion = new DtSuscripcionVitalicia(cu->getFechaSistema(), Tarjeta, 1, true);
    // usuario = cu->buscarUsuario("ibai");
    // cu->setUsuario(usuario);
    // suscripcionVideojuegos->confirmarSuscripcion("Minecraft", suscripcion);
    // cu->cerrarSecion();
    // delete suscripcion;

    //PUNTAJE A VIDEOJUEGOS
    usuario = cu->buscarUsuario("gamer");
    cu->setUsuario(usuario);
    cu->asignarPuntaje("KingdomRush",4);
    cu->cerrarSecion();

    usuario = cu->buscarUsuario("gamer");
    cu->setUsuario(usuario);
    cu->asignarPuntaje("Fortnite", 5);
    cu->cerrarSecion();

    usuario = cu->buscarUsuario("ari");
    cu->setUsuario(usuario);
    cu->asignarPuntaje("Fortnite", 5);
    cu->cerrarSecion();

    usuario = cu->buscarUsuario("ari");
    cu->setUsuario(usuario);
    cu->asignarPuntaje("Minecraft", 3);
    cu->cerrarSecion();

//     //PARTIDAS INDIVIDUALES

}
