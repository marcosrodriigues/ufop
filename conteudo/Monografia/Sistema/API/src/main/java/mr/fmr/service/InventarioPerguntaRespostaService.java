package mr.fmr.service;

import mr.fmr.model.InventarioPerguntaResposta;
import mr.fmr.model.User;

import java.util.List;

public interface InventarioPerguntaRespostaService {

    List<InventarioPerguntaResposta> convertPergunta(List<InventarioPerguntaResposta> perguntaRespostas);
    List<InventarioPerguntaResposta> save(User user, List<InventarioPerguntaResposta> perguntaRespostas);
}
