package mr.fmr.service;

import mr.fmr.model.Estudante;
import mr.fmr.model.MoradorRepublica;
import mr.fmr.model.Republica;

public interface MoradorRepublicaService {

    MoradorRepublica vincular(Estudante estudante, Republica republica);
}
