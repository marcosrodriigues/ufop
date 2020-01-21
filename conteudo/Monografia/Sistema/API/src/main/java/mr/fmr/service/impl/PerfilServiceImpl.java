package mr.fmr.service.impl;

import mr.fmr.model.Perfil;
import mr.fmr.model.User;
import mr.fmr.repository.PerfilRepository;
import mr.fmr.service.PerfilService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class PerfilServiceImpl implements PerfilService {

    @Autowired
    private PerfilRepository repository;

    @Override
    public Perfil findByUser(User user) {
        return repository.findByUser(user);
    }

    @Override
    public Perfil save(Perfil perfil) {
        return repository.save(perfil);
    }
}
