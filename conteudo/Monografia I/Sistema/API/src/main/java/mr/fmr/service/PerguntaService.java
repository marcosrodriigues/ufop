package mr.fmr.service;

import mr.fmr.model.Pergunta;

import java.util.List;

public interface PerguntaService {

    List<Pergunta> findAll();
    Pergunta findOne(int id);
    void initQuestionario();
}
