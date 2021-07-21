#include "./include/controladores/FabricaControladores.h"
#include "./DatoPrueba.cpp"

void modificarFecha(){
    FabricaControladores *fabrica = FabricaControladores::getInstancia();
    IModificarFecha *controladorUsuario = fabrica->getIModificarFecha();
    cout << "Fecha y hora en el sistema: ";
    DtFechaHora *fecha = controladorUsuario->getFechaSistema();
    cout << *fecha << "\n";

    cout << "Ingrese la fecha y hora actual: \n";
    int dia, mes, anio, hora, minutos;

    cout << "Ingrese dia: ";
    cin >> dia;

    cout << "Ingrese mes: ";
    cin >> mes;

    cout << "Ingrese año: ";
    cin >> anio;

    cout << "Ingrese hora: ";
    cin >> hora;

    cout << "Ingrese minuto: ";
    cin >> minutos;

    DtFechaHora *fechaActual = new DtFechaHora(dia, mes, anio, hora, minutos);
    controladorUsuario->modificarFechaSistema(fechaActual);

}

void informacionVideojuegos(){
    FabricaControladores *fabrica = FabricaControladores::getInstancia();
    IInformacionVideojuego *controladorVideojuego = fabrica->getIInformacionVideojuego();
    map<string,DtVideojuego*> listaVideojuegos = controladorVideojuego->listarVideojuegosSistema();
    map<string,DtVideojuego*>::iterator it;
    string nombreVideojuego;

    cout << "\n";
    cout << "┌───────────────────────────────────────────────┐\n";
    cout << "│ Ver información de videojuego                 │\n";
    cout << "└───────────────────────────────────────────────┘\n";
    cout << "\n";

    cout << "Videojuegos disponibles:\n\n";

    for(it = listaVideojuegos.begin(); it != listaVideojuegos.end(); it++)
        cout << it->first << "\n";

    cout << "\n";
    cout << "Inserte el nombre del videojuego al cual quiere asignar un puntaje: ";
    cin.ignore();
    getline(cin, nombreVideojuego);

    it = listaVideojuegos.find(nombreVideojuego);

    if (it != listaVideojuegos.end()) {
        cout << *(it->second);
    } else {
        cout << "¡No existe el videojuego con ese nombre!\n";
    }
}

void imprimirCuadroOpciones(list<string> opciones) {
    list<string>::iterator it;
    int largoLista = opciones.size();
    int index = 1;

    cout << "\n";
    cout << "┌───┬───────────────────────────────────────────┐\n";
    for (it = opciones.begin(); it != opciones.end(); it++) {
        int largoPalabra = it->length();

        cout << "│ " << index << " │ " << *it;
        for(int i = 0; i < 42 - largoPalabra; i++) cout << " ";
        cout << "│\n";

        index++;
        if (index != largoLista) continue;

        cout << "├───┼───────────────────────────────────────────┤\n";
    }
    cout << "└───┴───────────────────────────────────────────┘\n";
    cout << "\n";
}

void sesionJugador() {
    FabricaControladores *fabrica = FabricaControladores::getInstancia();
    char auxchar = '0';

    while (auxchar != '8') {
        cout << "\n";
        cout << "┌───────────────────────────────────────────────┐\n";
        cout << "│               Menu jugador                    │\n";
        cout << "├───┬───────────────────────────────────────────┤\n";
        cout << "│ 1 │ Suscribirse a videojuego                  │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 2 │ Asignar puntaje a videojuego              │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 3 │ Iniciar partida                           │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 4 │ Abandonar partida multijugador            │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 5 │ Finalizar partida                         │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 6 │ Ver información de videojuego             │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 7 │ Modificar fecha del sistema               │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 8 │ Salir                                     │\n";
        cout << "└───┴───────────────────────────────────────────┘\n";
        cout << "\n--> ";

        cin >> auxchar;

        switch (auxchar) {
            case '1': {
                ISuscripcionVideojuegos * controladorUsuario = fabrica->getISuscripcionVideojuegos();
                list<DtVideojuego*>::iterator it;
                string nombreVideojuego;

                list<DtVideojuego*> videojuegosConSuscripcion = controladorUsuario->listarVideojuegosConSuscripcionActiva();
                list<DtVideojuego*> videojuegosNoSuscriptos = controladorUsuario->listarVideojuegosNoSuscriptos();

                cout << "Lista de juegos con suscripcion:\n";
                for(it = videojuegosConSuscripcion.begin(); it != videojuegosConSuscripcion.end(); it++)
                    cout << **it << "\n";

                cout << "\nLista de juegos sin suscripcion:\n";
                for(it = videojuegosNoSuscriptos.begin(); it != videojuegosNoSuscriptos.end(); it++)
                    cout << **it << "\n";

                cout << "Inserte el nombre del videojuego al cual quiere suscribirse: ";
                cin.ignore();
                getline(cin, nombreVideojuego);

                map<string,float> costos = controladorUsuario->getCostosVideojuego(nombreVideojuego);

                if (costos.empty()) {
                    cout << "¡El videojuego al que quiere suscribirse, no existe!\n";
                    break;
                }

                StatusSuscripcion statusSuscripcion = controladorUsuario->getStatusSuscripcionVideojuego(nombreVideojuego);

                if (statusSuscripcion == Temporal) {
                    char opcion = '0';
                    while (opcion != '1' && opcion != '2') {
                        cout << "\n¿Desea cancelar su suscripcion temporal?\n\n";
                        cout << "┌───┬────────────────┐\n";
                        cout << "│ 1 │ Si             │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 2 │ No             │\n";
                        cout << "└───┴────────────────┘\n";
                        cout << "\n--> ";
                        cin >> opcion;

                        if (opcion != '1' && opcion != '2')
                            cout << "¡Opcion invalida! Intente nuevamente.\n";
                    }

                    if (opcion == '1') {
                        statusSuscripcion = Ninguna;
                        controladorUsuario->cancelarSuscripcion(nombreVideojuego);
                    }
                }

                if (statusSuscripcion == Ninguna) {
                    char tipoSuscripcion = '0';

                    while (tipoSuscripcion != '1' && tipoSuscripcion != '2' &&
                           tipoSuscripcion != '3' && tipoSuscripcion != '4') {
                        cout << "\n¿Que suscripcion desea contratar?\n\n";
                        cout << "┌───┬────────────────┐\n";
                        cout << "│ 1 │ Mensual        │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 2 │ Trimestral     │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 3 │ Anual          │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 4 │ Vitalicia      │\n";
                        cout << "└───┴────────────────┘\n";
                        cout << "\n--> ";
                        cin >> tipoSuscripcion;

                        if (tipoSuscripcion != '1' && tipoSuscripcion != '2' &&
                            tipoSuscripcion != '3' && tipoSuscripcion != '4') {
                            cout << "¡Opcion invalida! Intente nuevamente.\n";
                        }
                    }

                    char metodoDePago = '0';
                    while (metodoDePago != '1' && metodoDePago != '2') {
                        cout << "\n¿Que metodo de pago quiere usar?\n\n";
                        cout << "┌───┬────────────────┐\n";
                        cout << "│ 1 │ Tarjeta        │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 2 │ Paypal         │\n";
                        cout << "└───┴────────────────┘\n";
                        cout << "\n--> ";
                        cin >> metodoDePago;

                        if (metodoDePago != '1' && metodoDePago != '2')
                            cout << "¡Opcion invalida! Intente nuevamente.\n";
                    }

                    char confirmar = '0';
                    while (confirmar != '1' && confirmar != '2') {
                        cout << "\n¿Desea confirmar la suscripcion al videojuego?\n\n";
                        cout << "┌───┬────────────────┐\n";
                        cout << "│ 1 │ Si             │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 2 │ No             │\n";
                        cout << "└───┴────────────────┘\n";
                        cout << "\n--> ";
                        cin >> confirmar;

                        if (confirmar != '1' && confirmar != '2')
                            cout << "¡Opcion invalida! Intente nuevamente.\n";
                    }

                    if (confirmar == '1') {
                        DtSuscripcion * suscripcion = NULL;
                        TipoPago tipoPago;
                        float pago;
                        int mesesValida;


                        switch(tipoSuscripcion) {
                            case '1':
                                pago = costos.find("mensual")->second;
                                mesesValida = 1;
                                break;
                            case '2':
                                pago = costos.find("trimestral")->second;
                                mesesValida = 3;
                                break;
                            case '3':
                                pago = costos.find("anual")->second;
                                mesesValida = 12;
                                break;
                            case '4':
                                pago = costos.find("vitalicia")->second;
                                break;
                        }

                        if (metodoDePago == '1') {
                            tipoPago = Tarjeta;
                        } else {
                            tipoPago = Paypal;
                        }

                        if (tipoSuscripcion == '1' || tipoSuscripcion == '2' || tipoSuscripcion == '3') {
                            suscripcion = new DtSuscripcionTemporal(
                                controladorUsuario->getFechaSistema(),
                                tipoPago,
                                pago,
                                true,
                                mesesValida,
                                false
                            );
                        } else {
                            suscripcion = new DtSuscripcionVitalicia(
                                controladorUsuario->getFechaSistema(),
                                tipoPago,
                                pago,
                                true
                            );
                        }

                        controladorUsuario->confirmarSuscripcion(nombreVideojuego, suscripcion);
                    }
                } else if (statusSuscripcion == Vitalicia) {
                    cout << "¡Usted ya posee una suscripcion vitalicia a ese videojuego!";
                }

                break;
            }

            case '2': {
                IAsignarPuntajeVideojuego * controladorUsuario = fabrica->getIAsignarPuntajeVideojuego();
                map<string,DtVideojuego*> listaVideojuegos = controladorUsuario->listarVideojuegosSistema();
                map<string,DtVideojuego*>::iterator it;

                string nombreVideojuego;
                int puntaje = 0;

                cout << "\n";
                cout << "┌───────────────────────────────────────────────┐\n";
                cout << "│ Asignar puntaje a videojuego                  │\n";
                cout << "└───────────────────────────────────────────────┘\n";
                cout << "\n";

                cout << "Videojuegos disponibles:\n\n";

                for(it = listaVideojuegos.begin(); it != listaVideojuegos.end(); it++) {
                    cout << "Nombre: " << it->second->getNombre() << "\n";
                    cout << "Descripcion: " << it->second->getDescripcion() << "\n\n";
                }

                char cancelar;
                bool existeVideojuego = false;

                while (!existeVideojuego) {
                    cancelar = '0';

                    cout << "\nInserte el nombre del videojuego al cual quiere asignar un puntaje: ";
                    cin.ignore();
                    getline(cin, nombreVideojuego);

                    existeVideojuego = listaVideojuegos.find(nombreVideojuego) != listaVideojuegos.end();

                    if (!existeVideojuego) {
                        cout << "\n¡No existe ese videojuego!\n";

                        while (cancelar != '1' && cancelar != '2') {
                            cout << "¿Desea cancelar la operacion?\n\n";
                            cout << "┌───┬────────────────┐\n";
                            cout << "│ 1 │ Si             │\n";
                            cout << "├───┼────────────────┤\n";
                            cout << "│ 2 │ No             │\n";
                            cout << "└───┴────────────────┘\n";
                            cout << "\n--> ";
                            cin >> cancelar;

                            if (cancelar != '1' && cancelar != '2')
                                cout << "¡Opcion invalida! Intente nuevamente.\n";
                        }

                        if (cancelar == '1') break;
                    }
                }

                if (cancelar == '1') break;

                while (puntaje < 1 || puntaje > 5) {
                    cout << "Inserte el puntaje: ";
                    cin >> puntaje;

                    if (puntaje < 1 || puntaje > 5)
                        cout << "El puntaje debe de ser un numero entre 1 y 5.\n";
                }

                controladorUsuario->asignarPuntaje(nombreVideojuego, puntaje);
                cout << "Se asigno un puntaje de " << puntaje << " a " << nombreVideojuego << "\n";

                break;
            }

            case '3': {
                IIniciarPartida *controladorPartida = fabrica->getIIniciarPartida();
                IModificarFecha *controladorFecha = fabrica->getIModificarFecha();
                list<DtVideojuego*>::iterator it;
                string nombreVideojuego;
                DtPartidaIndividual * partidaInd;
                DtPartidaMultijugador * partidaMul;


                list<DtVideojuego*> videojuegosConSuscripcion = controladorPartida->listarVideojuegosConSuscripcionActiva();

                for(it = videojuegosConSuscripcion.begin(); it != videojuegosConSuscripcion.end(); it++)

                    cout << "\n" << **it;

                cout << "\n";
                cout << "\nInserte el nombre del videojuego del cual quiere iniciar partida: ";
                cin >> nombreVideojuego;

                char tipoPartida = '0';
                while (tipoPartida != '1' && tipoPartida != '2') {
                    cout << "¿Que tipo de partida desea iniciar?\n";
                    cout << "┌───┬────────────────┐\n";
                    cout << "│ 1 │ Individual     │\n";
                    cout << "├───┼────────────────┤\n";
                    cout << "│ 2 │ Multijugador   │\n";
                    cout << "└───┴────────────────┘\n";
                    cout << "\n";
                    cin >> tipoPartida;

                    if (tipoPartida != '1' && tipoPartida != '2')
                            cout << "¡Opcion invalida! Intente nuevamente.";
                }

                if (tipoPartida == '1') {
                    int PartidaQueContinua = 0;
                    char continuacion = '0';
                    while (continuacion != '1' && continuacion != '2') {
                        cout << "¿Es la partida continuacion de una anterior?\n";
                        cout << "┌───┬────────────────┐\n";
                        cout << "│ 1 │ Si             │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 2 │ No             │\n";
                        cout << "└───┴────────────────┘\n";
                        cout << "\n";
                        cin >> continuacion;

                        if (continuacion != '1' && continuacion != '2')
                                cout << "¡Opcion invalida! Intente nuevamente.";
                    }

                    if (continuacion == '1') {
                        map<float, DtPartida *> partidasAContinuar = controladorPartida->listarPartidasIndividuales(nombreVideojuego);
                        map<float, DtPartida *>::iterator itParInd;
                        for(itParInd =partidasAContinuar.begin(); itParInd != partidasAContinuar.end(); itParInd++){
                            DtPartida * dtPartida = itParInd->second;
                            cout << "\n" << dtPartida;
                        }//ARREGLAR CON LOS PI

                        cout << "\n";
                        cout << "Ingrese el indentificador de la partida que desea continuar: ";
                        cin >> PartidaQueContinua;
                    }
                    else{

                    }
                    int id = controladorPartida->getIdentificador() + 1;
                    controladorPartida->setIdentificador(controladorPartida->getIdentificador() + 1);
                    string noimporta;
                    bool continua = (continuacion == '1');
                    partidaInd = new DtPartidaIndividual(id,controladorFecha->getFechaSistema(),noimporta,continua, PartidaQueContinua);
                } else {
                    char transmitidaEnVivo = '0';
                    while (transmitidaEnVivo != '1' && transmitidaEnVivo != '2') {
                        cout << "¿Sera la partida transmitida en vivo?\n";
                        cout << "┌───┬────────────────┐\n";
                        cout << "│ 1 │ Si             │\n";
                        cout << "├───┼────────────────┤\n";
                        cout << "│ 2 │ No             │\n";
                        cout << "└───┴────────────────┘\n";
                        cout << "\n";
                        cin >> transmitidaEnVivo;

                        if (transmitidaEnVivo != '1' && transmitidaEnVivo != '2')
                                cout << "¡Opcion invalida! Intente nuevamente.";
                    }
                    list<string> nicknames = controladorPartida->listarNicknames(nombreVideojuego);
                    list<string>::iterator iter;
                    set<string> nicknamesElegidos;
                    set<string>::iterator  itnick;
                    string participante;
                    cout << "Lista de jugadores habilitados para unirse a su partida: \n";

                    for(iter = nicknames.begin(); iter != nicknames.end(); iter++)

                                 cout << "\n" << *iter;

                    char validacion = 'S';
                    while (validacion != 'N') {
                        if(validacion == 'S'){
                            cout << "\n Por favor, ingrese un jugador que ingresara a su partida: \n";
                            cin >> participante;
                            nicknamesElegidos.insert(participante);
                            cout << "¿Desea agregar otro jugador? (S/N): \n";
                            cin >> validacion;
                        }
                        else if (validacion != 'S' && validacion != 'N' ){
                            cout << "¡Opcion invalida! Intente nuevamente. \n";
                            cin >> validacion;
                        }

                    }

                    list<string> nicknamesFinales;
                    set<string>::iterator iter2;
                    for(iter2 = nicknamesElegidos.begin(); iter2 != nicknamesElegidos.end(); iter2++){
                        string nickname = iter2->data();
                        nicknamesFinales.push_back(nickname);
                    }

                    int id = controladorPartida->getIdentificador() + 1;
                    controladorPartida->setIdentificador(controladorPartida->getIdentificador() + 1);
                    string noimporta;
                    bool transmitida= (transmitidaEnVivo = '1');

                    partidaMul = new DtPartidaMultijugador(id,controladorFecha->getFechaSistema(),noimporta,transmitida,nicknamesFinales);
                }

                char confirmar = '0';
                while (confirmar != '1' && confirmar != '2') {
                    cout << "¿Desea confirmar el inicio de partida?\n";
                    cout << "┌───┬────────────────┐\n";
                    cout << "│ 1 │ Si             │\n";
                    cout << "├───┼────────────────┤\n";
                    cout << "│ 2 │ No             │\n";
                    cout << "└───┴────────────────┘\n";
                    cout << "\n";
                    cin >> confirmar;

                    if (confirmar != '1' && confirmar != '2')
                        cout << "¡Opcion invalida! Intente nuevamente. \n";
                }

                if (confirmar == '1') {
                    if (tipoPartida == '1'){
                         controladorPartida->confirmarPartida(partidaInd ,nombreVideojuego);
                         cout << "¡Su partida fue creada! \n";
                    }
                    else {
                        controladorPartida->confirmarPartida(partidaMul ,nombreVideojuego);
                        cout << "¡Su partida fue creada! \n";
                    }

                }
                else{
                    // if(tipoPartida == 1)
                    //     delete partidaInd;
                    // else
                    //     delete partidaMul;
                }
                break;
            }

            case '4': {
                IAbandonarPartidaMultijugador * controladorPartida = fabrica->getIAbandonarPartidaMultijugador();
                list<DtPartidaMultijugador*> listaPartidas = controladorPartida->listarPartidasNoFinalizadasMultijugador();
                list<DtPartidaMultijugador*>::iterator it;
                list<DtPartidaMultijugador*>::iterator iter;
                int identificador;

                cout << "Partidas multijugador no finalizadas:\n";

                for(iter = listaPartidas.begin(); iter != listaPartidas.end(); iter++)
                    cout << "\n" << *iter;

                cout << "\n";

                it = listaPartidas.end();

                while(it == listaPartidas.end()) {
                    cout << "Inserte el identificador de la partida a finalizar: ";
                    cin >> identificador;
                    for(iter = listaPartidas.begin(); iter != listaPartidas.end(); iter++){
                        if ((*iter)->getId() == identificador) it = iter;

                    }


                    if (it == listaPartidas.end()) {
                        cout << "¡No existe partida asociada a ese identificador!\n";

                        char confirmar = '0';
                        while (confirmar != '1' && confirmar != '2') {
                            cout << "¿Desea ingresar nuevamente el identificador?\n";
                            cout << "┌───┬────────────────┐\n";
                            cout << "│ 1 │ Si             │\n";
                            cout << "├───┼────────────────┤\n";
                            cout << "│ 2 │ No             │\n";
                            cout << "└───┴────────────────┘\n";
                            cout << "\n";
                            cin >> confirmar;

                            if (confirmar != '1' && confirmar != '2')
                                cout << "¡Opcion invalida! Intente nuevamente.";
                        }

                        if (confirmar == '2') break;
                    }
                }

                controladorPartida->abandonarPartidaMultijugador(identificador);

                break;
            }
            case '5': {
                IFinalizarPartida * controladorUsuario = fabrica->getIFinalizarPartida();
                list<DtPartida*> listaPartidas = controladorUsuario->listarPartidasNoFinalizadasDelJugador();
                list<DtPartida* >::iterator it;
                int identificador;
                listaPartidas.size();
                cout << "Partidas no finalizadas:\n";

                for(it = listaPartidas.begin(); it != listaPartidas.end(); it++)
                    cout << "\n" << *it;

                cout << "\n";
                cout << "Inserte el identificador de la partida a finalizar: ";
                cin >> identificador;

                map<int, Partida *> partidas = controladorUsuario->getPartidas();

                if (partidas.find(identificador) == partidas.end()) {
                    cout << "¡No existe partida asociada a ese identificador!";
                } else {
                    controladorUsuario->finalizarPartida(identificador);
                    cout << "¡Su Partida se ha finalizado con exito!";
                }

                break;
            }
            case '6': {
                informacionVideojuegos();
                break;
            }
            case '7': {
                modificarFecha();
                break;
            }
            default: {
                cout << "Inserte una opción válida.\n";
                break;
            }
        }
    }
}


void sesionDesarrollador() {
    FabricaControladores *fabrica = FabricaControladores::getInstancia();
    char auxchar = 'a';

    while (auxchar != '8') {
        cout << "┌───────────────────────────────────────────────┐\n";
        cout << "│              Menu desarrollador               │\n";
        cout << "├───┬───────────────────────────────────────────┤\n";
        cout << "│ 1 │ Agregar categoría                         │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 2 │ Publicar videojuego                       │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 3 │ Eliminar videojuego                       │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 4 │ Seleccionar estadísticas                  │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 5 │ Consultar estadísticas                    │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 6 │ Ver información de videojuego             │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 7 │ Modificar fecha del sistema               │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 8 │ Salir                                     │\n";
        cout << "└───┴───────────────────────────────────────────┘\n";
        cout << "\n--> ";

        cin >> auxchar;

        switch (auxchar) {

        case '1':
        {
            // Agregar categoría

            IAgregarCategoria *controladorVideojuego = fabrica->getIAgregarCategoria();


            list<DtCategoria*> categorias = controladorVideojuego->listarCategorias();
            list<DtCategoria*>::iterator categoria;

            cout << "Lista de categorías:\n";
            for (categoria = categorias.begin(); categoria != categorias.end(); categoria++)
                cout << " - "<< **categoria << "\n";


            string nombre;
            string descripcion;
            TipoCategoria tipoCategoria;
            cout << "\nIngrese el nombre de la nueva categoría: ";
            cin.ignore();
            getline(cin, nombre);

            bool existeCategoria = controladorVideojuego->existeCategoria(nombre);
            if (!existeCategoria && !nombre.empty()) {
                cout << "Ingrese una descripción para la categoría: ";
                getline(cin, descripcion);

                string eleccionCategoria;
                cout << "Ingrese el tipo de categoría:\n";
                cout << "┌───┬────────────────┐\n";
                cout << "│ 1 │ Género         │\n";
                cout << "├───┼────────────────┤\n";
                cout << "│ 2 │ Plataforma     │\n";
                cout << "├───┼────────────────┤\n";
                cout << "│ 3 │ Otro tipo      │\n";
                cout << "└───┴────────────────┘\n";
                cout << "\n";
                cin >> eleccionCategoria;

                string nombreTipoCategoria;
                if (eleccionCategoria == "1" || eleccionCategoria == "2" || eleccionCategoria == "3") {
                    if (eleccionCategoria == "1") {
                        tipoCategoria = Genero;
                        nombreTipoCategoria = "Género";
                    } else if (eleccionCategoria == "2") {
                        tipoCategoria = Plataforma;
                        nombreTipoCategoria = "Plataforma";
                    } else {
                        tipoCategoria = Otro;
                        nombreTipoCategoria = "Otro";
                    }


                    string confirmar;
                    cout << "Se va a crear la categoría con el nombre '" << nombre <<  "' y el tipo '" << nombreTipoCategoria << "'. Ingresa 'c' para confirmar, u otra cosa para cancelar: ";
                    cin >> confirmar;
                    if (confirmar == "c") {
                        DtCategoria *categoria = new DtCategoria(nombre, descripcion, tipoCategoria);
                        controladorVideojuego->crearCategoria(categoria);
                        cout << "Se creó la categoría correctamente.\n";
                    } else {
                        cout << "Cancelando la creación de la categoría...\n";
                    }

                } else {
                    cout << "La opción ingresada es incorrecta. Saliendo...\n";
                }


            } else {
                cout << "El nombre ingresado es incorrecto. Saliendo...\n";
            }


        }
        break;

        case '2':{
            // Publicar videojuego
            IPublicarVideojuego *controladorVideojuego = ControladorVideojuego::getInstancia();


            if (controladorVideojuego->listarCategorias().size() >= 2) {
                string nombre, descripcion;
                float costoMensual, costoTrimestral, costoAnual, costoVitalicio;
                list<string> nombresCategorias;

                cout << "Ingrese el nombre del videojuego: ";
                cin.ignore();
                getline(cin, nombre);

                bool existeVideojuego = controladorVideojuego->existeVideojuego(nombre);

                if (!existeVideojuego) {
                    string costoMensualString, costoTrimestralString, costoAnualString, costoVitalicioString;
                    cout << "Ingrese el costo mensual: ";
                    cin >> costoMensualString;
                    costoMensual = stof(costoMensualString);
                    cout << "Ingrese el costo trimestral: ";
                    cin >> costoTrimestralString;
                    costoTrimestral = stof(costoTrimestralString);
                    cout << "Ingrese el costo anual: ";
                    cin >> costoAnualString;
                    costoAnual = stof(costoAnualString);
                    cout << "Ingrese el costo vitalicio: ";
                    cin >> costoVitalicioString;
                    costoVitalicio = stof(costoVitalicioString);

                    list<DtCategoria*> categorias = controladorVideojuego->listarCategorias();
                    list<DtCategoria*>::iterator categoria;

                    cout << "\nCategorías del sistema:\n";
                    for (categoria = categorias.begin(); categoria != categorias.end(); categoria++)
                        cout << " - " << **categoria << "\n";

                    int cantGeneros = 0;
                    bool masGeneros = true;
                    int cantPlataformas = 0;
                    bool masPlataformas = true;
                    bool masOtrasCategorias = true;

                    cout << "\nIngresar géneros al videojuego...\n";
                    while (cantGeneros < 1 || masGeneros) {
                        string nombreGenero;
                        cout << "Ingresa el nombre del género: ";
                        cin >> nombreGenero;

                        if (controladorVideojuego->esGenero(nombreGenero)) {
                            nombresCategorias.push_back(nombreGenero);
                            cantGeneros++;

                            string otroGenero;
                            cout << "Se agregó el género. Ingresa 'o' para ingresar otro género, u otra cosa para seguir: ";
                            cin >> otroGenero;

                            if (otroGenero != "o") {
                                masGeneros = false;
                            }
                        } else {
                            cout << "No existe un género con ese nombre.\n";

                            if (cantGeneros >= 1) {
                                string otroGenero;
                                cout << "Ingresa 's' si quieres dejar de agregar géneros, u otra cosa para seguir: ";
                                cin >> otroGenero;
                                if (otroGenero == "s") {
                                    masGeneros = false;
                                }
                            }
                        }
                    }

                    cout << "\nIngresar plataformas al videojuego...\n";
                    while (cantPlataformas < 1 || masPlataformas) {
                        string nombrePlataforma;
                        cout << "Ingresa el nombre de la plataforma: ";
                        cin >> nombrePlataforma;

                        if (controladorVideojuego->esPlataforma(nombrePlataforma)) {
                            nombresCategorias.push_back(nombrePlataforma);
                            cantPlataformas++;

                            string otraPlataforma;
                            cout << "Se agregó la plataforma. Ingresa 'o' para ingresar otra plataforma, u otra cosa para seguir: ";
                            cin >> otraPlataforma;

                            if (otraPlataforma != "o") {
                                masPlataformas = false;
                            }
                        } else {
                            cout << "No existe una plataforma con ese nombre.\n";

                            if (cantPlataformas >= 1) {
                                string otraPlataforma;
                                cout << "Ingresa 's' si quieres dejar de agregar plataformas, u otra cosa para seguir: ";
                                cin >> otraPlataforma;
                                if (otraPlataforma == "s") {
                                    masPlataformas = false;
                                }
                            }
                        }
                    }


                    string categoriasOtroTipo;
                    cout << "\nIngresa 's' si quieres agregar otros tipos de categorías al videojuego: ";
                    cin >> categoriasOtroTipo;

                    if (categoriasOtroTipo == "s") {
                        while (masOtrasCategorias) {
                            string nombreOtraCategoria;
                            cout << "Ingresa el nombre de la categoría: ";
                            cin >> nombreOtraCategoria;

                            if (controladorVideojuego->esOtroTipoCategoria(nombreOtraCategoria)) {
                                nombresCategorias.push_back(nombreOtraCategoria);
                                cantPlataformas++;

                                string otraCategoria;
                                cout << "Se agregó la categoría. Ingresa 'o' para ingresar otra categoría, u otra cosa para seguir: ";
                                cin >> otraCategoria;

                                if (otraCategoria != "o") {
                                    masOtrasCategorias = false;
                                }
                            } else {
                                cout << "No existe una categoría de tipo 'Otro tipo' con ese nombre.\n";

                                string otraCategoria;
                                cout << "Ingresa 's' si quieres dejar de agregar categorías, u otra cosa para seguir: ";
                                cin >> otraCategoria;
                                if (otraCategoria == "s") {
                                    masOtrasCategorias = false;
                                }
                            }
                        }

                    }

                    DtVideojuego *datosVideojuego = new DtVideojuego(nombre, descripcion, costoMensual, costoTrimestral, costoAnual, costoVitalicio);

                    string confirmar;
                    cout << "\nSe va a crear el videojuego con los siguientes datos:\n";
                    cout << *datosVideojuego << "\n";
                    cout << "Con las siguientes categorías:\n";

                    list<string>::iterator cat;
                    for (cat = nombresCategorias.begin(); cat != nombresCategorias.end(); cat++)
                        cout << " - " << *cat << "\n";

                    cout << "\nIngresa 'c' para confirmar, u otra cosa para cancelar: ";
                    cin >> confirmar;
                    if (confirmar == "c") {
                        controladorVideojuego->crearVideojuego(datosVideojuego, nombresCategorias);
                        cout << "Se creó el videojuego correctamente.\n";
                    } else {
                        cout << "Cancelando la creación del videojuego...\n";
                    }

                } else {
                    cout << "Ya existe un videojuego con ese nombre. Saliendo...\n";
                }

            } else {
                cout << "No puedes agregar un videojuego porque no hay suficientes categorías en el sistema.\n";
            }


        }
        break;

        case '3':
        {
            // Eliminar videojuego
            IEliminarVideojuego *controladorVideojuego = ControladorVideojuego::getInstancia();

            list<DtVideojuego*> videojuegos = controladorVideojuego->listarVideojuegosSinPartidasActivas();
            list<DtVideojuego*>::iterator videojuego;

            if (videojuegos.size() > 0) {
                cout << "Videojuegos que se pueden eliminar:\n";
                for (videojuego = videojuegos.begin(); videojuego != videojuegos.end(); videojuego++)
                    cout << " - " << (*videojuego)->getNombre() << "\n";

                string nombreVideojuego;
                cout << "\nIngrese el nombre del videojuego que quieres eliminar: ";
                cin.ignore();
                getline(cin, nombreVideojuego);

                if (!controladorVideojuego->tienePartidasActivas(nombreVideojuego)) {
                    controladorVideojuego->eliminarVideojuego(nombreVideojuego);
                    cout << "\nSe eliminó el videojuego.\n";
                } else {
                    cout << "\nNo se puede eliminar el videojuego seleccionado. Verifica que esté en la lista de videojuegos que se pueden eliminar.\n";
                }
            } else {
                cout << "No hay videojuegos que se puedan eliminar. Saliendo...\n";
            }

        }
        break;

        case '4':
        {
            // Seleccionar estadísticas
            ISeleccionarEstadisticas *controladorUsuario = ControladorUsuario::getInstancia();

            list<string> estadisticasSeleccionadas;
            list<DtEstadistica*> estadisticas = controladorUsuario->listarEstadisticas();
            list<DtEstadistica*>::iterator estadistica;

            cout << "Estadísticas disponibles para seleccionar:\n";
            for (estadistica = estadisticas.begin(); estadistica != estadisticas.end(); estadistica++)
                cout << " - " << "Estadística '" << (*estadistica)->getNombre() << "': " << (*estadistica)->getDescripcion() << "\n";

            bool masEstadisticas = true;
            while(masEstadisticas) {
                string nombreEstadistica;
                cout << "\nIngrese el nombre de una estadística para seleccionar: ";
                cin.ignore();
                getline(cin, nombreEstadistica);

                if (controladorUsuario->existeEstadistica(nombreEstadistica)) {
                    estadisticasSeleccionadas.push_back(nombreEstadistica);

                    string otraEstadistica;
                    cout << "\nSe agregó la estadística. Ingresa 'o' para ingresar otra estadística, u otra cosa para seguir: ";
                    cin >> otraEstadistica;

                    if (otraEstadistica != "o") {
                        masEstadisticas = false;
                    }

                } else {
                    cout << "No existe una estadística con ese nombre. Saliendo...\n";
                    break;
                }
            }

            controladorUsuario->seleccionarEstadisticas(estadisticasSeleccionadas);
        }
        break;

        case '5':
        {
            //  Consultar estadísticas
            IConsultarEstadisticas *controladorUsuario = ControladorUsuario::getInstancia();


            list<DtVideojuego*> videojuegos = controladorUsuario->listarVideojuegosDelDesarrollador();
            list<DtVideojuego*>::iterator videojuego;

            if (videojuegos.size() > 0) {

                cout << "Videojuegos del desarrollador:\n";
                for (videojuego = videojuegos.begin(); videojuego != videojuegos.end(); videojuego++) {
                    cout << " - " << (*videojuego)->getNombre() << "\n";
                }

                string nombreVideojuego;
                cout << "\nIngrese el nombre del videojuego a consultar estadísticas: ";
                cin.ignore();
                getline(cin, nombreVideojuego);

                if (controladorUsuario->existeVideojuego(nombreVideojuego)) {
                    list<DtEstadistica*> estadisticas = controladorUsuario->consultarEstadisticas(nombreVideojuego);
                    list<DtEstadistica*>::iterator estadistica;

                    cout << "\nEstadísticas del videojuego '" << nombreVideojuego << "':\n";

                    for (estadistica = estadisticas.begin(); estadistica != estadisticas.end(); estadistica++)
                        cout << " - " << **estadistica << "\n";

                    cout << "\nFinalizando...\n";

                } else {
                    cout << "No existe un videojuego con ese nombre. Saliendo...\n";
                }

            } else {
                cout << "No tienes videojuegos para consultar estadísticas. Saliendo...\n";
            }
        }
        break;

        case '6':
        {
            informacionVideojuegos();
        }
        break;

        case '7':{
            modificarFecha();
        }
        break;

        case '8':
        break;
        default:{
            cout << "Inserte una opción válida.\n";
        }

        }
    }
}
//    //liberar memoria




int main() {
    FabricaControladores *fabrica = FabricaControladores::getInstancia();
    IModificarFecha *fecha = fabrica->getIModificarFecha();
    DtFechaHora *dtFecha = new DtFechaHora(21, 6, 2021, 4, 43);
    fecha->modificarFechaSistema(dtFecha);
    IIniciarPartida *controladorPartida = fabrica->getIIniciarPartida();
    controladorPartida->setIdentificador(0);
    char auxchar = 'a';


    cout << "█████████████████████████████████████████████████████████████████\n";
    cout << "█▄─▄▄─█▄─▄█████─▄▄▄▄██▀▄─██─▄─▄─█─▄▄─████▀▄─██░▄▄░▄█▄─██─▄█▄─▄███\n";
    cout << "██─▄█▀██─██▀███─██▄─██─▀─████─███─██─████─▀─███▀▄█▀██─██─███─██▀█\n";
    cout << "▀▄▄▄▄▄▀▄▄▄▄▄▀▀▀▄▄▄▄▄▀▄▄▀▄▄▀▀▄▄▄▀▀▄▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▄▀▀▄▄▄▄▀▀▄▄▄▄▄▀\n";
    cout << "\n";

    while (auxchar != '4') {
        cout << "┌───────────────────────────────────────────────┐\n";
        cout << "│                Menu principal                 │\n";
        cout << "├───┬───────────────────────────────────────────┤\n";
        cout << "│ 1 │ Alta de usuario                           │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 2 │ Iniciar sesión                            │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 3 │ Cargar datos de prueba                    │\n";
        cout << "├───┼───────────────────────────────────────────┤\n";
        cout << "│ 4 │ Salir                                     │\n";
        cout << "└───┴───────────────────────────────────────────┘\n";
        cout << "\n--> ";

        cin >> auxchar;
        switch (auxchar)
        {
            case '1':
                // Alta de usuario
            {
                IAltaUsuario *controladorUsuario = fabrica->getIAltaUsuario();

                char b = '1';
                string email;
                string contrasena;
                bool cancelar = false;

                while (!cancelar) {
                    cout << "Ingresar email: ";
                    cin >> email;
                    bool emailValido = controladorUsuario->emailValido(email);

                    if(emailValido && !cancelar) {
                        cout << "Ingresar contraseña: ";
                        cin >> contrasena;
                        cancelar = true;
                    }
                    else {
                        cout << "Email invalido.";
                        cout << "\n\t1)Intentar de nuevo.\n\t2)Cancelar intento.\n--> ";
                        cin >> b;

                        if(b == '2'){
                            cancelar = true;
                        }
                        //Si ingresa otro valor da otra oportunidad
                    }
                }
                if(b == '2')
                    break;

                char opcion;
                cout << "Seleccione el tipo de usuario: \n\t1) Jugador.\n\t2) Desarrollador.\n--> ";
                cin >> opcion;

                switch (opcion) {
                    case '1': {
                        bool nuevoIntento = true;
                        string nickname;
                        string descripcion;

                        while (nuevoIntento) {
                            cout << "Ingresar nickname: ";
                            cin >> nickname;
                            bool nicknameValido = controladorUsuario->nicknameValido(nickname);

                            if(nicknameValido && nuevoIntento) {
                                cout << "Ingresar descripcion: ";
                                cin >> descripcion;
                                nuevoIntento = false;
                            }
                            else {
                                cout << "Nombre invalido.";
                                cout << "\n\t1)Intentar de nuevo.\n\t2)Cancelar intento.\n--> ";
                                cin >> b;

                                if(b == '2'){
                                    nuevoIntento = false;
                                }//Si ingresa otro valor da otra oportunidad
                            }
                        }

                        if(b != '2'){
                            DtJugador *datos = new DtJugador(email, contrasena, nickname, descripcion);
                            controladorUsuario->crearUsuario(datos);
                            delete datos;
                        }
                    }
                    break;

                    case '2': {
                        string empresa;
                        cout << "Ingresar empresa: ";
                        cin >> empresa;
                        DtDesarrollador *datos = new DtDesarrollador(email, contrasena, empresa);
                        controladorUsuario->crearUsuario(datos);
                        delete datos;
                    }
                    break;
                }
            }
            break;
            //Iniciar sesión
            case '2':
            {
                IIniciarSesion *controladorUsuario = fabrica->getIIniciarSesion();
                bool cancelar = false;
                char b = '1';
                string email;
                string contrasena;

                while (!cancelar) {
                    cout << "Ingresar email: ";
                    cin >> email;
                    cout << "Ingresar contraseña: ";
                    cin >> contrasena;
                    bool inicioCorrecto = controladorUsuario->confirmarDatosSesion(email, contrasena);

                    if(!cancelar && !inicioCorrecto) {
                        cout << "Email o contraseña invalida.";
                        cout << "\n\t1)Intentar de nuevo.\n\t2)Cancelar intento.\n--> ";
                        cin >> b;
                        if(b == '2'){
                            cancelar = true;
                            cout << "Inicio de sesion cancelado.\n";
                        }
                    }
                    else {
                        cout << "Inicio de sesion correcto.\n";
                        cancelar = true;
                    }
                }

                Usuario *usuario = controladorUsuario->buscarUsuario(email);

                if(usuario != NULL && usuario->getTipo() == 'j') {
                    controladorUsuario->setUsuario(usuario);
                    sesionJugador();
                }
                else if(usuario) {
                    controladorUsuario->setUsuario(usuario);
                    sesionDesarrollador();
                }

                break;
            }

            case '3': {
                cout << "Cargando datos...\n";
                cargarDatos();
                cout << "¡Datos cargados existosamente!\n\n";

                break;
            }

            case '4':
            break;

            default:
            cout << "Inserte una opción válida.\n";
        }
    }
    return 0;
}
