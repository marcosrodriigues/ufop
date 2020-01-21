package mr.fmr.service.impl;

import mr.fmr.model.Personalidade;
import mr.fmr.model.Republica;
import mr.fmr.model.User;
import mr.fmr.payload.RepublicaPorPersonalidadePayload;
import mr.fmr.service.RecomendacaoService;
import org.springframework.stereotype.Service;

import java.util.Comparator;
import java.util.List;

@Service
public class RecomendacaoServiceImpl implements RecomendacaoService {

    @Override
    public int somaPersonalidade(Personalidade p) {
        int soma = 0;

        soma += p.getAbertura();
        soma += p.getConcordancia();
        soma += p.getConsciencia();
        soma += p.getExtroversao();
        soma += p.getNeuroticismo();

        return soma;
    }

    @Override
    public int calculaDistanciaGeral(User user, Republica republica) {
        int distancia = 0;

        distancia += (Math.abs(republica.getPerfil().getPersonalidade().getAbertura() - user.getPerfil().getPersonalidade().getAbertura()));
        distancia += (Math.abs(republica.getPerfil().getPersonalidade().getConcordancia() - user.getPerfil().getPersonalidade().getConcordancia()));
        distancia += (Math.abs(republica.getPerfil().getPersonalidade().getConsciencia() - user.getPerfil().getPersonalidade().getConsciencia()));
        distancia += (Math.abs(republica.getPerfil().getPersonalidade().getExtroversao() - user.getPerfil().getPersonalidade().getExtroversao()));
        distancia += (Math.abs(republica.getPerfil().getPersonalidade().getNeuroticismo() - user.getPerfil().getPersonalidade().getNeuroticismo()));

        return distancia;
    }

    @Override
    public List<RepublicaPorPersonalidadePayload> ordenar(List<RepublicaPorPersonalidadePayload> republicas) {
        republicas.sort(Comparator.comparing(RepublicaPorPersonalidadePayload::getDistanciaGeral));
        return republicas;
    }

    @Override
    public Personalidade convertPersonalityIntoPercentage(Personalidade personalidade) {
        if (personalidade == null) return null;

        personalidade.setAbertura(personalidade.getAbertura() / 50 * 100);
        personalidade.setConsciencia(personalidade.getConsciencia() / 45 * 100);
        personalidade.setConcordancia(personalidade.getConcordancia() / 45 * 100);
        personalidade.setExtroversao(personalidade.getExtroversao() / 40 * 100);
        personalidade.setNeuroticismo(personalidade.getNeuroticismo() / 40 * 100);

        return personalidade;
    }

}
