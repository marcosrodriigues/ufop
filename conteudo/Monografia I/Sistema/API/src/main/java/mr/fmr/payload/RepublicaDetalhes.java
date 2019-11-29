package mr.fmr.payload;

import mr.fmr.model.Perfil;
import mr.fmr.model.Republica;

public class RepublicaDetalhes {

    private Long id;
    private String nome;
    private String cidade;
    private String uf;
    private Integer sizeMoradores;
    private Perfil perfil;
    private String image;
    private String email;
    private String carater;
    private String descricao;

    public RepublicaDetalhes(Republica republica) {
        this.id = republica.getId();
        this.nome = republica.getNome();
        this.cidade = republica.getEndereco().getCidade();
        this.uf = republica.getEndereco().getUf();
        this.sizeMoradores = republica.getMoradores().size();
        this.perfil = republica.getPerfil();
        this.image = republica.getFotoUrl();
        this.email = republica.getEmail();
        this.carater = republica.getCarater() != null ? republica.getCarater().name() : "Não informado";
        this.descricao = !String.valueOf(republica.getDescricao()).isEmpty() ? republica.getDescricao() : "Não informado";

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

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getUf() {
        return uf;
    }

    public void setUf(String uf) {
        this.uf = uf;
    }

    public Integer getSizeMoradores() {
        return sizeMoradores;
    }

    public void setSizeMoradores(Integer sizeMoradores) {
        this.sizeMoradores = sizeMoradores;
    }

    public Perfil getPerfil() {
        return perfil;
    }

    public void setPerfil(Perfil perfil) {
        this.perfil = perfil;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getCarater() {
        return carater;
    }

    public String getDescricao() {
        return this.descricao;
    }
}
