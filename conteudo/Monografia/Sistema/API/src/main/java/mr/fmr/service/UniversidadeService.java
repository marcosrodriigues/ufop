package mr.fmr.service;

import mr.fmr.model.Universidade;

import java.util.List;

public interface UniversidadeService {

    List<Universidade> findAll();
    Universidade save(Universidade universidade);
}
