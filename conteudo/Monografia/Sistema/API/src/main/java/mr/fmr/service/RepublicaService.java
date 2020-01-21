package mr.fmr.service;

import mr.fmr.model.Estudante;
import mr.fmr.model.MoradorRepublica;
import mr.fmr.model.Republica;
import mr.fmr.model.User;

import java.security.Principal;
import java.util.List;

public interface RepublicaService {

    Republica save(User user);
    List<Republica> findAll();
    Republica findOne(long id);
    void delete(long id);
    List<Republica> findByCity(String city);
    List<Republica> findByUf(String uf);
    List<Republica> findByUfAndCity(String uf, String city);
    List<Estudante> findMoradores(Republica republica);
    List<Estudante> findPendentes(Republica republica);
    Republica createPersonality(Republica republica);
}
