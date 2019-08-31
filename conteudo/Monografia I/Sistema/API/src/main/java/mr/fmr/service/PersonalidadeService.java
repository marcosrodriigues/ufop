package mr.fmr.service;

import mr.fmr.model.Perfil;
import mr.fmr.model.Personalidade;
import mr.fmr.model.User;

public interface PersonalidadeService {

    Personalidade getByUser(User user);
    Personalidade calcularPersonalidade(Perfil profile);
}
