#include<sstream>
#include "Horario.h"

Horario::Horario(int inicio, DiaSemana diaDaSemana) {

    inicio = (inicio - 7) + (int)diaDaSemana * 16;
    id = (inicio - 7) + (int)diaDaSemana * 16;
    if (!(inicio >= 7 && inicio <= 22)) {
        throw new exception;
    }
}

Horario::Horario(int inicio, int diaDaSemana) {
    inicio = (inicio - 7) + diaDaSemana * 16;
    id = (inicio - 7) + diaDaSemana * 16;
    if (!(inicio >= 7 && inicio <= 22)) {
        throw new exception;
    }
}

Turno Horario::checaTurno(int horario) {
    int hora = (horario % 16) + 7;

    if (horario >= 7 && horario < 12) {
        return MANHA;
    }
    if (horario >= 12 && horario < 19) {
        return TARDE;
    }
    if (horario >= 19 && horario < 23) {
        return NOITE;
    }
    return ERRO;
}

int Horario::checaDia(int horario) {
    return horario / 16;
}

int Horario::getDiaSemana() {
    return inicio / 16;
}

int Horario::getInicio() {
    return inicio - (16 * getDiaSemana()) + 7;
}

int Horario::getID() {
    return id;
}

Turno Horario::getTurno() {
    int auxInicio = getInicio();
    if (auxInicio >= 7 && auxInicio < 12) {
        return MANHA;
    }

    if (auxInicio >= 12 && auxInicio < 18) {
        return TARDE;
    }

    if (auxInicio >= 18 && auxInicio < 23) {
        return NOITE;
    }
    return ERRO;
}

string Horario::toString() {
    string diaSemana = "";
    switch (getDiaSemana()) {
        case (0):
            diaSemana = "SEG";
            break;
        case (1):
            diaSemana = "TER";
            break;
        case (2):
            diaSemana = "QUA";
            break;
        case (3):
            diaSemana = "QUI";
            break;
        case (4):
            diaSemana = "SEX";
            break;
        case (5):
            diaSemana = "SAB";
            break;
    }


    string result1;
    string result2;
    stringstream convert;

    convert << getInicio();
    result1 = convert.str();
    convert << getInicio()+1;
    result2 = convert.str();

    return diaSemana + " (" + result1 + " - " + result2 + ")";
}


int Horario::getTurnoInt() {
    int auxInicio = getInicio();
    if (auxInicio >= 7 && auxInicio < 12) {
        return 0;
    }

    if (auxInicio >= 12 && auxInicio < 18) {
        return 1;
    }

    if (auxInicio >= 18 && auxInicio < 23) {
        return 2;
    }
    return -1;

}


int Horario::fim() {
    return inicio + 1;
}

bool Horario::colide(Horario horario) {
    if (getDiaSemana() != horario.getDiaSemana()) {
        return false;
    } else if (inicio == horario.inicio || fim() == horario.fim()) {
        return true;
    } else {
        return (inicio >= horario.inicio && inicio < horario.fim())
                || (fim() > horario.inicio && fim() <= horario.fim())
                || (horario.inicio >= inicio && horario.inicio < fim())
                || (horario.fim() > inicio && horario.fim() <= fim());
    }
}
