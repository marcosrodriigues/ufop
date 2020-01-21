package mr.fmr.service.impl;

import mr.fmr.model.*;
import mr.fmr.repository.RepublicaRepository;
import mr.fmr.service.EstudanteService;
import mr.fmr.service.RepublicaService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service("republicaService")
public class RepublicaServiceImpl implements RepublicaService {

    @Autowired
    private RepublicaRepository repository;
    @Autowired
    private EstudanteService estudanteService;

    @Autowired
    private PasswordEncoder passwordEncoder;

    private final int _CINCO= 5;
    private final int _QUATRO = 4;

    @Override
    public Republica save(User user) {
        if (user.getId() == null) {
            Republica rep = new Republica(user);
            return repository.save(rep);
        }

        Republica other = repository.findById(user.getId()).get();

        if (!other.getPassword().equals(user.getPassword()))
            user.setPassword(passwordEncoder.encode(user.getPassword()));

        return repository.save((Republica) user);
    }

    @Override
    public List<Republica> findAll() {
        return repository.findAll();
    }

    @Override
    public Republica findOne(long id) {
        Republica rep = repository.findById(id).get();
        return rep;
    }

    @Override
    public void delete(long id) {
        repository.deleteById(id);
    }

    @Override
    public List<Republica> findByCity(String city) {
        return repository.findByEndereco_Cidade(city);
    }

    @Override
    public List<Republica> findByUf(String uf) {
        return repository.findByEndereco_Uf(uf);
    }

    @Override
    public List<Republica> findByUfAndCity(String uf, String city) {
        return repository.findByEndereco_UfAndEndereco_Cidade(uf, city);
    }

    @Override
    public List<Estudante> findMoradores(Republica republica) {
        Republica rep = repository.findById(republica.getId()).get();
        System.out.println(rep.getNome());
        return getApprovedMoradores(rep);
    }

    @Override
    public List<Estudante> findPendentes(Republica republica) {
        List<Estudante> pendentes = new ArrayList<>();

        for (MoradorRepublica estudante : republica.getMoradores())
            if (!estudante.isAprovado()) pendentes.add(estudante.getMorador());

        return pendentes;
    }

    @Override
    public Republica createPersonality(Republica republica) {
        List<Estudante> moradores = findMoradores(republica);
        Personalidade personalityModa = personalidadePelaModa(moradores);
        Personalidade personality = new Personalidade();

        personality.setAbertura(personalityModa.getAbertura());
        personality.setConsciencia(personalityModa.getConsciencia());
        personality.setConcordancia(personalityModa.getConcordancia());
        personality.setExtroversao(personalityModa.getExtroversao());
        personality.setNeuroticismo(personalityModa.getNeuroticismo());

        Perfil perfil = new Perfil();
        perfil.setPersonalidade(personality);

        republica.setPerfil(perfil);

        return save(republica);
    }

    //private methods
    private List<Estudante> getApprovedMoradores(Republica republica) {
        if (republica.getMoradores().isEmpty()) return null;

        List<Estudante> moradores = new ArrayList<>();

        for (MoradorRepublica mr : republica.getMoradores())
            if (mr.isAprovado()) moradores.add(mr.getMorador());

        return moradores;
    }

    /***
     * Calcula a personalidade da república através da média aritmética dos seus moradores
     * @param personalidades Lista de personalidades
     * @return Personalidade
     */
    private Personalidade personalidadePelaMedia(List<Personalidade> personalidades) {
        Personalidade personality = new Personalidade();

        personalidades.forEach(m -> {
            personality.setAbertura(personality.getAbertura() + m.getAbertura());
            personality.setNeuroticismo(personality.getNeuroticismo() + m.getNeuroticismo());
            personality.setConsciencia(personality.getConsciencia() + m.getConsciencia());
            personality.setConcordancia(personality.getConcordancia() + m.getConcordancia());
            personality.setExtroversao(personality.getExtroversao() + m.getExtroversao());
        });

        personality.setAbertura(personality.getAbertura() / personalidades.size());
        personality.setNeuroticismo(personality.getNeuroticismo() / personalidades.size());
        personality.setConsciencia(personality.getConsciencia() / personalidades.size());
        personality.setConcordancia(personality.getConcordancia() / personalidades.size());
        personality.setExtroversao(personality.getExtroversao() / personalidades.size());

        return personality;
    }

    /**
     * Calcula a Personalidade da República utilizando a regra da Moda da Estatística.
     * @param moradores moradores da república
     * @return personalidade da república
     */
    private Personalidade personalidadePelaModa(List<Estudante> moradores) {
        //vetores que contam a quantidade de personalidades
        int[] countAberturas = new int[5];
        int[] countConcordancia = new int[5];
        int[] countConsciencia = new int[5];
        int[] countExtroversao = new int[5];
        int[] countNeuroticismo = new int[5];

        List<Personalidade> personalityAberturas[] = new ArrayList[5];
        List<Personalidade> personalityConcordancia[] = new ArrayList[5];
        List<Personalidade> personalityConsciencia[] = new ArrayList[5];
        List<Personalidade> personalityExtroversao[] = new ArrayList[5];
        List<Personalidade> personalityNeuroticismo[] = new ArrayList[5];

        for(int i = 0; i < 5; i++) {
            personalityAberturas[i] = new ArrayList<>();
            personalityConcordancia[i] = new ArrayList<>();
            personalityConsciencia[i] = new ArrayList<>();
            personalityExtroversao[i] = new ArrayList<>();
            personalityNeuroticismo[i] = new ArrayList<>();
        }


        Personalidade p;
        for (Estudante m : moradores) {
            if (m.getPerfil().getPersonalidade() == null) continue;;

            p = m.getPerfil().getPersonalidade();
            //pra cada morador, ele entra numa contagem das personalidades
            int[] indexGrupos = getGruposDaPersonalidade(p);


            countAberturas[indexGrupos[0]]++;
            countConcordancia[indexGrupos[1]]++;
            countConsciencia[indexGrupos[2]]++;
            countExtroversao[indexGrupos[3]]++;
            countNeuroticismo[indexGrupos[4]]++;

            personalityAberturas[indexGrupos[0]].add(p);
            personalityConcordancia[indexGrupos[1]].add(p);
            personalityConsciencia[indexGrupos[2]].add(p);
            personalityExtroversao[indexGrupos[3]].add(p);
            personalityNeuroticismo[indexGrupos[4]].add(p);
        }

        //indexs das maiores personalidades
        int[] indexs = new int[5];

        indexs[0] = getIndexDoMaior(countAberturas);
        indexs[1] = getIndexDoMaior(countConcordancia);
        indexs[2] = getIndexDoMaior(countConsciencia);
        indexs[3] = getIndexDoMaior(countExtroversao);
        indexs[4] = getIndexDoMaior(countNeuroticismo);

        Personalidade person = new Personalidade();

        person.setAbertura(personalidadePelaMedia(personalityAberturas[indexs[0]]).getAbertura());
        person.setConcordancia(personalidadePelaMedia(personalityConcordancia[indexs[1]]).getConcordancia());
        person.setConsciencia(personalidadePelaMedia(personalityConsciencia[indexs[2]]).getConsciencia());
        person.setExtroversao(personalidadePelaMedia(personalityExtroversao[indexs[3]]).getExtroversao());
        person.setNeuroticismo(personalidadePelaMedia(personalityNeuroticismo[indexs[4]]).getNeuroticismo());

        return person;
    }

    /***
     * Determina, a partir de uma Personalidade, quais intervalos da Moda a personalidade faz parte.
     * @param personalidade Personalidade do morador
     * @return Array de posições pra ser usado na Moda:
     *  i=0 -> abertura;
     *  i=1 -> concordancia;
     *  i=2 -> consciencia;
     *  i=3 -> extroversao;
     *  i=4 -> neuroticismo
     */
    private int[] getGruposDaPersonalidade (Personalidade personalidade) {
        int[] indexs = new int[5];

        if (personalidade == null) return indexs;

        //indexs = obtainIndexSemPersonalidadeNormalizada(personalidade);
        indexs = obtainIndexComPersonalidadeNormalizada(normalizePersonalidadePorBaixo(personalidade));

        return indexs;
    }

    private int getIndexDoMaior(int... scores) {
        int maior = 0;
        int index = 0;
        boolean empate = false;
        int length = scores.length;
        int[] indexsEmpate = new int[length];

        for (int i = 0; i < length; i++) {
            if (scores[i] >= maior) {
//                if (scores[i] == maior) {
//                    empate = true;
//                    indexsEmpate[indexsEmpate.length] = i;
//                } else {
//                    empate = false;
//                    indexsEmpate = new int[length];
//                }

                maior = scores[i];
                index = i;
            }
        }
//
//        if (empate) {
//            boolean go = false;
//            maior = 0; index = 0;
//            for (int i = 0; i < length; i++) {
//                for (int j = 0; j < indexsEmpate.length; j++) {
//                    if (i == j)
//                        go = true;
//                }
//                if (go) {
//                    go = false;
//                    continue;
//                }
//
//                if (scores[i] >= maior) {
//                    maior = scores[i];
//                    index = i;
//                }
//            }
//        }

        return index;
    }

    /**
     * Normaliza a Personalidade por baixo, isto é, a pontuação mínima possível de cada faceta de personalidade é considerada como 0 no gráfico.
     * Na prática, subtraio o valor da pontuação máxima pelo valor da pontuação mínima da personalidade e considero esses novos valores obtidos como a personalidade.
     * @param person Personalidade a ser normalizada
     * @return Personalidade normalizada por baixo
     */
    private Personalidade normalizePersonalidadePorBaixo(Personalidade person) {
        if (person == null) return null;

        Personalidade personalidade = new Personalidade();

        personalidade.setAbertura(person.getAbertura() - 10);
        personalidade.setConcordancia(person.getConcordancia() - 9);
        personalidade.setConsciencia(person.getConsciencia() - 9);
        personalidade.setExtroversao(person.getExtroversao() - 8);
        personalidade.setNeuroticismo(person.getNeuroticismo() - 8);

        return personalidade;
    }

    private int[] obtainIndexSemPersonalidadeNormalizada(Personalidade personalidade) {
        int[] indexs = new int[5];

        if (personalidade.getAbertura() <= 10)          indexs[0] = 0;
        else if (personalidade.getAbertura() <= 20)     indexs[0] = 1;
        else if (personalidade.getAbertura() <= 30)     indexs[0] = 2;
        else if (personalidade.getAbertura() <= 40)     indexs[0] = 3;
        else if (personalidade.getAbertura() <= 50)     indexs[0] = 4;

        if (personalidade.getConcordancia() <= 9)       indexs[1] = 0;
        else if (personalidade.getConcordancia() <= 18) indexs[1] = 1;
        else if (personalidade.getConcordancia() <= 27) indexs[1] = 2;
        else if (personalidade.getConcordancia() <= 36) indexs[1] = 3;
        else if (personalidade.getConcordancia() <= 45) indexs[1] = 4;

        if (personalidade.getConsciencia() <= 9)        indexs[2] = 0;
        else if (personalidade.getConsciencia() <= 18)  indexs[2] = 1;
        else if (personalidade.getConsciencia() <= 27)  indexs[2] = 2;
        else if (personalidade.getConsciencia() <= 36)  indexs[2] = 3;
        else if (personalidade.getConsciencia() <= 45)  indexs[2] = 4;

        if (personalidade.getExtroversao() <= 8)        indexs[3] = 0;
        else if (personalidade.getExtroversao() <= 16)  indexs[3] = 1;
        else if (personalidade.getExtroversao() <= 24)  indexs[3] = 2;
        else if (personalidade.getExtroversao() <= 32)  indexs[3] = 3;
        else if (personalidade.getExtroversao() <= 40)  indexs[3] = 4;

        if (personalidade.getNeuroticismo() <= 8)       indexs[4] = 0;
        else if (personalidade.getNeuroticismo() <= 16) indexs[4] = 1;
        else if (personalidade.getNeuroticismo() <= 24) indexs[4] = 2;
        else if (personalidade.getNeuroticismo() <= 32) indexs[4] = 3;
        else if (personalidade.getNeuroticismo() <= 40) indexs[4] = 4;

        return indexs;
    }

    private int[] obtainIndexComPersonalidadeNormalizada(Personalidade personalidade) {
        int[] indexs = new int[5];

        if (personalidade.getAbertura() <= 10)          indexs[0] = 0;
        else if (personalidade.getAbertura() <= 20)     indexs[0] = 1;
        else if (personalidade.getAbertura() <= 30)     indexs[0] = 2;
        else if (personalidade.getAbertura() <= 40)     indexs[0] = 3;

        if (personalidade.getConcordancia() <= 9)       indexs[1] = 0;
        else if (personalidade.getConcordancia() <= 18) indexs[1] = 1;
        else if (personalidade.getConcordancia() <= 27) indexs[1] = 2;
        else if (personalidade.getConcordancia() <= 36) indexs[1] = 3;

        if (personalidade.getConsciencia() <= 9)        indexs[2] = 0;
        else if (personalidade.getConsciencia() <= 18)  indexs[2] = 1;
        else if (personalidade.getConsciencia() <= 27)  indexs[2] = 2;
        else if (personalidade.getConsciencia() <= 36)  indexs[2] = 3;

        if (personalidade.getExtroversao() <= 8)        indexs[3] = 0;
        else if (personalidade.getExtroversao() <= 16)  indexs[3] = 1;
        else if (personalidade.getExtroversao() <= 24)  indexs[3] = 2;
        else if (personalidade.getExtroversao() <= 32)  indexs[3] = 3;

        if (personalidade.getNeuroticismo() <= 8)       indexs[4] = 0;
        else if (personalidade.getNeuroticismo() <= 16) indexs[4] = 1;
        else if (personalidade.getNeuroticismo() <= 24) indexs[4] = 2;
        else if (personalidade.getNeuroticismo() <= 32) indexs[4] = 3;

        return indexs;
    }
}
