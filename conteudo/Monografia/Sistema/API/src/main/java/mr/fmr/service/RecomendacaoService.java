package mr.fmr.service;

import mr.fmr.model.Personalidade;
import mr.fmr.model.Republica;
import mr.fmr.model.User;
import mr.fmr.payload.RepublicaPorPersonalidadePayload;

import java.util.List;

public interface RecomendacaoService {

    int somaPersonalidade(Personalidade personalidade);
    int calculaDistanciaGeral(User user, Republica republica);
    List<RepublicaPorPersonalidadePayload>  ordenar(List<RepublicaPorPersonalidadePayload> republicas);
    Personalidade convertPersonalityIntoPercentage(Personalidade personalidade);
}
