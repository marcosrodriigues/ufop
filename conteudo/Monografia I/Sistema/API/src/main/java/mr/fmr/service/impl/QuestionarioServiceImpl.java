package mr.fmr.service.impl;

import mr.fmr.model.Questionario;
import mr.fmr.repository.QuestionarioRepository;
import mr.fmr.service.QuestionarioService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class QuestionarioServiceImpl implements QuestionarioService {

    @Autowired
    private QuestionarioRepository repository;

    @Override
    public List<Questionario> findAll() {
        return repository.findAll();
    }

    @Override
    public Questionario findOne(int id) {
        return repository.findById(id).get();
    }

    @Override
    public void initQuestionario() {
        repository.save(new Questionario("É falador(a)."));
        repository.save(new Questionario("Tende a encontrar os defeitos dos outros."));
        repository.save(new Questionario("Faz um trabalho exaustivo."));
        repository.save(new Questionario("É deprimido(a), triste."));
        repository.save(new Questionario("É original, tem sempre novas ideias."));
        repository.save(new Questionario("É reservado(a)."));
        repository.save(new Questionario("É prestável e não inveja os outros."));
        repository.save(new Questionario("Pode ser um pouco descuidado"));
        repository.save(new Questionario("É relaxado(a) e lida bem com o stress."));
        repository.save(new Questionario("Tem curiosidade em relação a várias coisas"));
        repository.save(new Questionario("Tem muita energia."));
        repository.save(new Questionario("Inicia muitas disputas com os outros."));
        repository.save(new Questionario("É um trabalhor(a) de confiança."));
        repository.save(new Questionario("Pode ficar tenso."));
        repository.save(new Questionario("É engenhoso(a), um(a) pensador(a) profundo."));
        repository.save(new Questionario("Gera muito entusiasmo."));
        repository.save(new Questionario("Perdoa com facilidade."));
        repository.save(new Questionario("Tende a ser desorganizado(a)."));
        repository.save(new Questionario("Se preocupa muito."));
        repository.save(new Questionario("Tem uma imaginação ativa."));
        repository.save(new Questionario("Tende a ser sossegado(a)."));
        repository.save(new Questionario("Geralmente é de confiança."));
        repository.save(new Questionario("Tende a ser preguiçoso(a)."));
        repository.save(new Questionario("É emocionalmente estável, não se aborrece com facilidade."));
        repository.save(new Questionario("É inventivo(a)."));
        repository.save(new Questionario("Tem uma personalidade assertiva."));
        repository.save(new Questionario("Pode ser frio(a) e indiferente."));
        repository.save(new Questionario("É perseverante até a tarefa estar concluída."));
        repository.save(new Questionario("Pode ter um humor instável."));
        repository.save(new Questionario("Valoriza experiências artísticas, estéticas."));
        repository.save(new Questionario("As vezes é tímido(a), inibido(a)."));
        repository.save(new Questionario("É atencioso(a) e gentil com quase todos."));
        repository.save(new Questionario("Faz as coisas com eficiência."));
        repository.save(new Questionario("Permanece calmo(a) em situações tensas."));
        repository.save(new Questionario("Prefere o trabalho rotineiro."));
        repository.save(new Questionario("É sociável, amigável."));
        repository.save(new Questionario("As vezes é rude com os outros."));
        repository.save(new Questionario("Faz planos e cumpre-os."));
        repository.save(new Questionario("Fica nervoso(a) facilmente."));
        repository.save(new Questionario("Gosta de refletir, brincar com as ideias."));
        repository.save(new Questionario("Tem poucos interesses artísticos."));
        repository.save(new Questionario("Gosta de cooperar com os outros."));
        repository.save(new Questionario("Se distrai com facilidade."));
        repository.save(new Questionario("É sofisticado(a) na arte, música ou literatura."));
    }
}
