package mr.fmr.controller;

import mr.fmr.model.Personalidade;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.io.File;
import java.io.FileWriter;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;
import java.util.stream.IntStream;

@RestController
@RequestMapping
public class InteligenciaComputacionalController {

    private final int MAX_ANSWER = 10;
    //private final Long MAX_ANSWER_TO_SAVE = 1000000L;
    private Long MAX_ANSWER_TO_SAVE = 1000000L;
    private final String JSON_PATH = "/home/marcos/19.2/Inteligência Computacional/TP/personality_random_1000000.data";
    //private final String JSON_PATH = "/media/marcos/MARCOS/Personality/personality_#.data";
    //private final String JSON_PATH = "/media/marcos/Xico/Personality/personality_#.data";

    private int count = 0;
    private Long registred = 0L;

    private final String split = "__", delimit = ",", newLine = "\n";

    @GetMapping(value = "/ic")
    public String getPayloads() {
        run();
        return "Arquivos gerados";
    }

    @GetMapping(value = "/ic/{id}")
    public String getPayloads(Long count) {
        this.MAX_ANSWER_TO_SAVE = count;
        run();
        return "Arquivos gerados";
    }

    private void run() {
        List<Payload> payloads = new ArrayList<>();
        Payload initial = new Payload();
        PerguntaEResposta[] initialPergunta = new PerguntaEResposta[MAX_ANSWER];

        for (int i = 0; i < initialPergunta.length; i++) {
            initialPergunta[i] = new PerguntaEResposta();
            initialPergunta[i].pergunta = i + 1;
            initialPergunta[i].resposta = 1;
        }

        initial.perguntasRespostas = initialPergunta;
        initial.personalidade = calcularPersonalidade(initial.perguntasRespostas);
        payloads.add(initial);
        Payload payload, lastPayload = initial;

        while(true) {
            payload = new Payload();

            //payload.perguntasRespostas = generateNextAnswers(lastPayload.perguntasRespostas);
            payload.perguntasRespostas = generateRandomAnswer();

            if (payload.perguntasRespostas == null) {
                count++;
                save(payloads);
                break;
            }

            payload.personalidade = calcularPersonalidade(payload.perguntasRespostas);

            payloads.add(payload);

            if (payloads.size() >= MAX_ANSWER_TO_SAVE) {
                count++;
                save(payloads);
                payloads.clear();
                break;
            }
            lastPayload = payload;
        }
    }

    private void save(List<Payload> payloads) {
        try {
            File file = createOrLoadFile(JSON_PATH);
            saveListToFile(payloads, file);
            registred = MAX_ANSWER_TO_SAVE * count;
            System.out.println("Arquivo " + file.getName() + " criado. Total de " + MAX_ANSWER_TO_SAVE * count + " registros salvos.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    PerguntaEResposta[] generateNextAnswers(PerguntaEResposta[] perguntaERespostas) {
        PerguntaEResposta[] perg = new PerguntaEResposta[MAX_ANSWER];

        IntStream.range(0, perg.length).forEach(i -> {
            perg[i] = new PerguntaEResposta();
            perg[i].resposta = perguntaERespostas[i].resposta;
            perg[i].pergunta = perguntaERespostas[i].pergunta;
        });

        int changeIndex = perg.length - 1;

        while (perg[changeIndex].resposta == 5) {
            perg[changeIndex].resposta = 1;
            changeIndex--;
            if (changeIndex < 0) return null;
        }

        perg[changeIndex].resposta++;

        return perg;
    }

    PerguntaEResposta[] generateRandomAnswer() {
        PerguntaEResposta[] perg = new PerguntaEResposta[MAX_ANSWER];
        Random rand = new Random();

        for (int i = 0; i < perg.length; i++) {
            perg[i] = new PerguntaEResposta();
            perg[i].pergunta = (i + 1);
            perg[i].resposta = (rand.nextInt(5)) + 1;
        }

        return perg;
    }

    private File createOrLoadFile(String path) throws Exception {
        path = path.replace("#", String.valueOf(count));
        File file = new File(path);
        if (file.exists()) return file;
        file.createNewFile();
        return file;
    }

    private void saveListToFile(List<Payload> payloads, File file) throws Exception {
        if (!file.exists())
            file = createOrLoadFile(file.getPath());

        String header = "";

        for (int i = 1; i <= MAX_ANSWER; i++) {
            header += i;;
            if (i != MAX_ANSWER)
                header+=delimit;
        }
        header+=split;
        header+="abertura" + delimit;
        header+="concordancia" + delimit;
        header+="consciencia" + delimit;
        header+="extroversao" + delimit;
        header+="neuroticismo";


        FileWriter writer = new FileWriter(file.getPath());

        writer.append(header + newLine);
        for (int i = 0; i < payloads.size(); i++)
            writer.append(payloads.get(i).toString()+ newLine);

        writer.flush();
        writer.close();
    }

    private class Payload {
        private PerguntaEResposta perguntasRespostas[] = new PerguntaEResposta[MAX_ANSWER];
        private Personalidade personalidade;

        public Payload() {

        }

        public Payload(PerguntaEResposta[] perguntas) {
            this.perguntasRespostas = perguntas;
        }

        public PerguntaEResposta[] getPerguntasRespostas() {
            return perguntasRespostas;
        }

        public void setPerguntasRespostas(PerguntaEResposta[] perguntasRespostas) {
            this.perguntasRespostas = perguntasRespostas;
        }

        public Personalidade getPersonalidade() {
            return personalidade;
        }

        public void setPersonalidade(Personalidade personalidade) {
            this.personalidade = personalidade;
        }

        @Override
        public String toString() {
            String q = "", p = "";
            for (int i = 0; i < perguntasRespostas.length; i++) {
                q += perguntasRespostas[i].resposta;
                if (i + 1 != perguntasRespostas.length) q+=delimit;
            }

            p += personalidade.getAbertura() + delimit;
            p += personalidade.getConcordancia() + delimit;
            p += personalidade.getConsciencia() + delimit;
            p += personalidade.getExtroversao() + delimit;
            p += personalidade.getNeuroticismo();

            return q + split + p;
        }
    }

    private class PerguntaEResposta implements Serializable {
        int pergunta;
        int resposta;

        public int getPergunta() {
            return pergunta;
        }

        public void setPergunta(int pergunta) {
            this.pergunta = pergunta;
        }

        public int getResposta() {
            return resposta;
        }

        public void setResposta(int resposta) {
            this.resposta = resposta;
        }
    }

    public Personalidade calcularPersonalidade(PerguntaEResposta[] perguntas) {
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


        for (PerguntaEResposta pergunta : perguntas) {
            if (extroversao.contains(pergunta.getPergunta())) {
                personalidade.setExtroversao(personalidade.getExtroversao() + pergunta.getResposta());
            } else if (reverseExtroversao.contains(pergunta.getPergunta())) {
                personalidade.setExtroversao(personalidade.getExtroversao() + reverse_scored(pergunta.getResposta()));
            } else if (concordancia.contains(pergunta.getPergunta())) {
                personalidade.setConcordancia(personalidade.getConcordancia() + pergunta.getResposta());
            } else if (reverseConcordancia.contains(pergunta.getPergunta())) {
                personalidade.setConcordancia(personalidade.getConcordancia() + reverse_scored(pergunta.getResposta()));
            } else if (consciencia.contains(pergunta.getPergunta())) {
                personalidade.setConsciencia(personalidade.getConsciencia() + pergunta.getResposta());
            } else if (reverseConsciencia.contains(pergunta.getPergunta())) {
                personalidade.setConsciencia(personalidade.getConsciencia() + reverse_scored(pergunta.getResposta()));
            } else if (neuroticismo.contains(pergunta.getPergunta())) {
                personalidade.setNeuroticismo(personalidade.getNeuroticismo() + pergunta.getResposta());
            } else if (reverseNeuroticismo.contains(pergunta.getPergunta())) {
                personalidade.setNeuroticismo(personalidade.getNeuroticismo() + reverse_scored(pergunta.getResposta()));
            } else if (abertura.contains(pergunta.getPergunta())) {
                personalidade.setAbertura(personalidade.getAbertura() + pergunta.getResposta());
            } else if (reverseAbertura.contains(pergunta.getPergunta())) {
                personalidade.setAbertura(personalidade.getAbertura() + reverse_scored(pergunta.getResposta()));
            }
        }

        return personalidade;
    }

    private List<Integer> getListExtroversao() {
        return Arrays.asList(6);
    }

    private List<Integer> getListReverseExtroversao() {
        return Arrays.asList(1);
    }

    private List<Integer> getListConcordancia() {
        return Arrays.asList(2);
    }

    private List<Integer> getListReverseConcordancia() {
        return Arrays.asList(7);
    }

    private List<Integer> getListConsciencia() {
        return Arrays.asList(8);
    }

    private List<Integer> getListReverseConsciencia() {
        return Arrays.asList(3);
    }

    private List<Integer> getListNeuroticismo() {
        return Arrays.asList(9);
    }

    private List<Integer> getListReverseNeuroticismo() {
        return Arrays.asList(4);
    }

    private List<Integer> getListAbertura() {
        return Arrays.asList(10);
    }

    private List<Integer> getListReverseAbertura() {
        return Arrays.asList(5);
    }

    private int reverse_scored(int score) {
        if (score == 1) return 5;
        if (score == 2) return 4;
        if (score == 4) return 2;
        if (score == 5) return 1;
        return 3;
    }
}