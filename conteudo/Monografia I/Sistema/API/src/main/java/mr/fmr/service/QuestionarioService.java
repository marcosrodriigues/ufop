package mr.fmr.service;

import mr.fmr.model.Questionario;

import java.util.List;

public interface QuestionarioService {

    List<Questionario> findAll();
    Questionario findOne(int id);
    void initQuestionario();
}
