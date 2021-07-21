#pragma once

#include <iostream>

class DtFechaHora {
	private:
		int dia, mes, anio, hora, minutos;

	public:
		DtFechaHora();
		DtFechaHora(int dia, int mes, int anio, int hora, int minutos);
		~DtFechaHora();
		int getDia() const;
		int getMes() const;
		int getAnio() const;
		int getHora() const;
		int getMinutos() const;

		friend std::ostream &operator<<(std::ostream &os, DtFechaHora const &fecha);
};
