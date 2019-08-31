package mr.fmr.service.impl;

import mr.fmr.model.InventarioPerguntaResposta;
import mr.fmr.model.Perfil;
import mr.fmr.model.Personalidade;
import mr.fmr.model.User;
import mr.fmr.repository.PersonalidadeRepository;
import mr.fmr.service.PerfilService;
import mr.fmr.service.PersonalidadeService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Arrays;
import java.util.List;

@Service
public class PersonalidadeServiceImpl implements PersonalidadeService {

    @Autowired
    private PersonalidadeRepository repository;
    @Autowired
    private PerfilService perfilService;

    @Override
    public Personalidade getByUser(User user) {
        return user.getPerfil().getPersonalidade();
    }

    @Override
    public Personalidade calcularPersonalidade(Perfil profile) {
        if (profile.getInventario() == null)
            return null;

        Personalidade personalidade = new Personalidade();

        /*
        *   E: Extroversion         -> Extroversão
        *   A: Agreeableness,       -> Concordância
        *   C: Conscientiousness,   -> Consciência
         *  N: Neuroticism,         -> Neuroticismo
         *  O: Openness             -> Abertura
        * */

        List<Integer> extroversao = getListExtroversao();
        List<Integer> reverseExtroversao = getListReverseExtroversao();
        List<Integer> concordancia = getListConcordancia();
        List<Integer> reverseConcordancia = getListReverseConcordancia();
        List<Integer> consciencia = getListConsciencia();
        List<Integer> reverseConsciencia = getListReverseConsciencia();
        List<Integer> neuroticismo = getListNeuroticismo();
        List<Integer> reverseNeuroticismo = getListReverseNeuroticismo();
        List<Integer> abertura = getListAbertura();
        List<Integer> reverseAbertura = getListReverseAbertura();


        for (InventarioPerguntaResposta pergunta : profile.getInventario().getPerguntasRespostas()) {
            if (extroversao.contains(pergunta.getPergunta().getId())) {
                personalidade.setExtroversao(personalidade.getExtroversao() + pergunta.getResposta());
            } else if (reverseExtroversao.contains(pergunta.getPergunta().getId())) {
                personalidade.setExtroversao(personalidade.getExtroversao() + reverse_scored(pergunta.getResposta()));
            } else if (concordancia.contains(pergunta.getPergunta().getId())) {
                personalidade.setConcordancia(personalidade.getConcordancia() + pergunta.getResposta());
            } else if (reverseConcordancia.contains(pergunta.getPergunta().getId())) {
                personalidade.setConcordancia(personalidade.getConcordancia() + reverse_scored(pergunta.getResposta()));
            } else if (consciencia.contains(pergunta.getPergunta().getId())) {
                personalidade.setConsciencia(personalidade.getConsciencia() + pergunta.getResposta());
            } else if (reverseConsciencia.contains(pergunta.getPergunta().getId())) {
                personalidade.setConsciencia(personalidade.getConsciencia() + reverse_scored(pergunta.getResposta()));
            } else if (neuroticismo.contains(pergunta.getPergunta().getId())) {
                personalidade.setNeuroticismo(personalidade.getNeuroticismo() + pergunta.getResposta());
            } else if (reverseNeuroticismo.contains(pergunta.getPergunta().getId())) {
                personalidade.setNeuroticismo(personalidade.getNeuroticismo() + reverse_scored(pergunta.getResposta()));
            } else if (abertura.contains(pergunta.getPergunta().getId())) {
                personalidade.setAbertura(personalidade.getAbertura() + pergunta.getResposta());
            } else if (reverseAbertura.contains(pergunta.getPergunta().getId())) {
                personalidade.setAbertura(personalidade.getAbertura() + reverse_scored(pergunta.getResposta()));
            }
        }

        return personalidade;
    }

    private List<Integer> getListExtroversao() {
        return Arrays.asList(1, 11, 16, 26, 36);
    }

    private List<Integer> getListReverseExtroversao() {
        return Arrays.asList(6, 21, 31);
    }

    private List<Integer> getListConcordancia() {
        return Arrays.asList(7, 17, 22, 32, 42);
    }

    private List<Integer> getListReverseConcordancia() {
        return Arrays.asList(2, 12, 27, 37);
    }

    private List<Integer> getListConsciencia() {
        return Arrays.asList(3, 13, 28, 33, 38);
    }

    private List<Integer> getListReverseConsciencia() {
        return Arrays.asList(8, 18, 23, 43);
    }

    private List<Integer> getListNeuroticismo() {
        return Arrays.asList(4, 14, 19, 29, 39);
    }

    private List<Integer> getListReverseNeuroticismo() {
        return Arrays.asList(9, 24, 34);
    }

    private List<Integer> getListAbertura() {
        return Arrays.asList(5, 10, 15, 20, 25, 30, 40, 44);
    }

    private List<Integer> getListReverseAbertura() {
        return Arrays.asList(35, 41);
    }

    private int reverse_scored(int score) {
        if (score == 1) return 5;
        if (score == 2) return 4;
        if (score == 4) return 2;
        if (score == 5) return 1;
        return 3;
    }
}
