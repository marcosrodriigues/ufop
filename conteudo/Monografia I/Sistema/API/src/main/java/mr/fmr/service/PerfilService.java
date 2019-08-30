package mr.fmr.service;

import mr.fmr.model.Perfil;
import mr.fmr.model.User;

public interface PerfilService {

    Perfil findByUser(User user);
    Perfil save(Perfil perfil);
}
