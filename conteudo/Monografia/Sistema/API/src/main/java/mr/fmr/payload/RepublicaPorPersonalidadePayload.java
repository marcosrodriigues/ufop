package mr.fmr.payload;

import mr.fmr.CaraterRepublica;
import mr.fmr.model.Personalidade;
import mr.fmr.model.Republica;

public class RepublicaPorPersonalidadePayload {

    private Long id;
    private String nome;
    private Personalidade personalidade;
    private CaraterRepublica carater;
    private String fotoUrl;
    private String bairro;
    private int distanciaGeral;
    private int somaPersonalidade;


    public RepublicaPorPersonalidadePayload(Republica rep) {
        this.id = rep.getId();
        this.carater = rep.getCarater();
        this.nome = rep.getNome();
        this.fotoUrl = rep.getFotoUrl();

        if (rep.getPerfil() != null) this.personalidade = rep.getPerfil().getPersonalidade();
        if (rep.getEndereco() != null) this.bairro = rep.getEndereco().getBairro();
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

    public CaraterRepublica getCarater() {
        return carater;
    }

    public void setCarater(CaraterRepublica carater) {
        this.carater = carater;
    }

    public String getFotoUrl() {
        return fotoUrl;
    }

    public void setFotoUrl(String fotoUrl) {
        this.fotoUrl = fotoUrl;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }
}
