package mr.fmr.service;

import mr.fmr.model.Republica;
import mr.fmr.model.User;

import java.util.List;

public interface RepublicaService {

    Republica save(User user);
    List<Republica> findAll();
    Republica findOne(long id);
    void delete(long id);
}
