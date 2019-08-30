package mr.fmr.service.impl;

import mr.fmr.model.InventarioPerguntaResposta;
import mr.fmr.repository.InventarioPerguntaRespostaRepository;
import mr.fmr.service.InventarioPerguntaRespostaService;
import mr.fmr.service.PerguntaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class InventarioPerguntaRespostaServiceImpl implements InventarioPerguntaRespostaService {

    @Autowired
    InventarioPerguntaRespostaRepository repository;

    @Autowired
    PerguntaService perguntaService;

    @Override
    public List<InventarioPerguntaResposta> convertPergunta(List<InventarioPerguntaResposta> perguntaRespostas) {
        for (InventarioPerguntaResposta pergunta : perguntaRespostas) {
            pergunta.setPergunta(perguntaService.findOne(pergunta.getPergunta().getId()));
        }
        return perguntaRespostas;
    }

    @Override
    public List<InventarioPerguntaResposta> save(List<InventarioPerguntaResposta> perguntaRespostas) {
        return repository.saveAll(perguntaRespostas);
    }
}
