package mr.fmr.service;

import mr.fmr.model.InventarioPerguntaResposta;

import java.util.List;

public interface InventarioPerguntaRespostaService {

    List<InventarioPerguntaResposta> convertPergunta(List<InventarioPerguntaResposta> perguntaRespostas);
    List<InventarioPerguntaResposta> save(List<InventarioPerguntaResposta> perguntaRespostas);
}
