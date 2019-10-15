package mr.fmr.payload;

import mr.fmr.model.Personalidade;
import mr.fmr.model.Republica;

public class RepublicaPorPersonalidadePayload {

    private Long id;
    private String nome;
    private Personalidade personalidade;
    private int distanciaGeral;
    private int somaPersonalidade;

    public RepublicaPorPersonalidadePayload(Republica rep) {
        this.id = rep.getId();
        nome = rep.getNome();
        personalidade = rep.getPerfil().getPersonalidade();
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Personalidade getPersonalidade() {
        return personalidade;
    }

    public void setPersonalidade(Personalidade personalidade) {
        this.personalidade = personalidade;
    }

    public int getDistanciaGeral() {
        return distanciaGeral;
    }

    public void setDistanciaGeral(int distanciaGeral) {
        this.distanciaGeral = distanciaGeral;
    }

    public int getSomaPersonalidade() {
        return somaPersonalidade;
    }

    public void setSomaPersonalidade(int somaPersonalidade) {
        this.somaPersonalidade = somaPersonalidade;
    }
}
