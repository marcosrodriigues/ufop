package mr.fmr.service;

import mr.fmr.model.Estudante;
import mr.fmr.model.Republica;
import mr.fmr.model.User;

import java.util.List;

public interface EstudanteService {

    Estudante save(User user);
    List<Estudante> findAll();
    Estudante findOne(long id);
    void delete(long id);
}
