#include "../datatypes/DtFechaHora.h"

class IModificarFecha{
    public:
        virtual ~IModificarFecha() = 0;
        virtual DtFechaHora *getFechaSistema() = 0;
        virtual void modificarFechaSistema(DtFechaHora *) = 0; 
};
