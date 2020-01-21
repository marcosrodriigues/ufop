package mr.fmr.service.impl;

import mr.fmr.model.Pergunta;
import mr.fmr.repository.PerguntaRepository;
import mr.fmr.service.PerguntaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class PerguntaServiceImpl implements PerguntaService {

    @Autowired
    private PerguntaRepository repository;

    @Override
    public List<Pergunta> findAll() {
        return repository.findAll();
    }

    @Override
    public Pergunta findOne(int id) {
        return repository.findById(id).get();
    }

    @Override
    public void initQuestionario() {
        repository.save(new Pergunta("É falador(a)."));
        repository.save(new Pergunta("Tende a encontrar os defeitos dos outros."));
        repository.save(new Pergunta("Faz um trabalho exaustivo."));
        repository.save(new Pergunta("É deprimido(a), triste."));
        repository.save(new Pergunta("É original, tem sempre novas ideias."));
        repository.save(new Pergunta("É reservado(a)."));
        repository.save(new Pergunta("É prestável e não inveja os outros."));
        repository.save(new Pergunta("Pode ser um pouco descuidado"));
        repository.save(new Pergunta("É relaxado(a) e lida bem com o stress."));
        repository.save(new Pergunta("Tem curiosidade em relação a várias coisas"));
        repository.save(new Pergunta("Tem muita energia."));
        repository.save(new Pergunta("Inicia muitas disputas com os outros."));
        repository.save(new Pergunta("É um trabalhor(a) de confiança."));
        repository.save(new Pergunta("Pode ficar tenso."));
        repository.save(new Pergunta("É engenhoso(a), um(a) pensador(a) profundo."));
        repository.save(new Pergunta("Gera muito entusiasmo."));
        repository.save(new Pergunta("Perdoa com facilidade."));
        repository.save(new Pergunta("Tende a ser desorganizado(a)."));
        repository.save(new Pergunta("Se preocupa muito."));
        repository.save(new Pergunta("Tem uma imaginação ativa."));
        repository.save(new Pergunta("Tende a ser sossegado(a)."));
        repository.save(new Pergunta("Geralmente é de confiança."));
        repository.save(new Pergunta("Tende a ser preguiçoso(a)."));
        repository.save(new Pergunta("É emocionalmente estável, não se aborrece com facilidade."));
        repository.save(new Pergunta("É inventivo(a)."));
        repository.save(new Pergunta("Tem uma personalidade assertiva."));
        repository.save(new Pergunta("Pode ser frio(a) e indiferente."));
        repository.save(new Pergunta("É perseverante até a tarefa estar concluída."));
        repository.save(new Pergunta("Pode ter um humor instável."));
        repository.save(new Pergunta("Valoriza experiências artísticas, estéticas."));
        repository.save(new Pergunta("As vezes é tímido(a), inibido(a)."));
        repository.save(new Pergunta("É atencioso(a) e gentil com quase todos."));
        repository.save(new Pergunta("Faz as coisas com eficiência."));
        repository.save(new Pergunta("Permanece calmo(a) em situações tensas."));
        repository.save(new Pergunta("Prefere o trabalho rotineiro."));
        repository.save(new Pergunta("É sociável, amigável."));
        repository.save(new Pergunta("As vezes é rude com os outros."));
        repository.save(new Pergunta("Faz planos e cumpre-os."));
        repository.save(new Pergunta("Fica nervoso(a) facilmente."));
        repository.save(new Pergunta("Gosta de refletir, brincar com as ideias."));
        repository.save(new Pergunta("Tem poucos interesses artísticos."));
        repository.save(new Pergunta("Gosta de cooperar com os outros."));
        repository.save(new Pergunta("Se distrai com facilidade."));
        repository.save(new Pergunta("É sofisticado(a) na arte, música ou literatura."));
    }
}
